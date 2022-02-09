#include "bytezerosdk.h"


static const char* BYTEZERO_SDK_VERSION = "v1.0.0";
static QString BYTEZERO_APP_NAME = QObject::tr("bytezero");
static QString BYTEZERO_APP_TEST_NAME = QObject::tr("bytezero_test");

BytezeroSdk::BytezeroSdk(QObject *parent) : QObject(parent), m_config(new Config())
{
    QThreadPool::globalInstance()->setMaxThreadCount(3);
    m_appMode = m_config->appMode();

    qDebug() << "BytezeroSdk::BytezeroSdk - sdk." << this << ", app " << m_appMode << ", " << Utils::getAppDataPath();
}

BytezeroSdk::~BytezeroSdk()
{

}

BytezeroSdk *BytezeroSdk::reset()
{
    return this;
}

BytezeroSdk *BytezeroSdk::init(QQmlApplicationEngine *qmlEngine)
{
    engine = qmlEngine;
    rootContext = engine->rootContext();
    registerContexts();
    registerModels();
    return this;
}

BytezeroSdk *BytezeroSdk::loadLanguage(QTranslator *translator)
{
    m_translator = translator;
    QLocale locale;
    QString languageName = m_config->appLanguage();
    if(languageName == "") {
        languageName = locale.name();
    }
    setLanguage(languageName);
    return this;
}

bool BytezeroSdk::is_online()
{
    return false;
}

bool BytezeroSdk::device_online(const device_access_func &)
{
    return false;
}

bool BytezeroSdk::db_online(const db_access_func &)
{
    return false;
}

QString BytezeroSdk::version() const
{
    return BYTEZERO_SDK_VERSION;
}

QString BytezeroSdk::title() const
{
    return (m_appMode == 2) ? QObject::tr("bytezero") : QObject::tr("bytezero_test");
}

QString BytezeroSdk::language() const
{
    return m_language;
}

void BytezeroSdk::setLanguage(QString lang)
{
    if(m_language == lang) return;
    if(m_translator) {
        QString langBaseName = ":/i18n/bytezero_";
        if(lang == "zh_CN") {
            langBaseName += lang;
        } else {
            langBaseName += "en";
        }
        if (m_translator->load(langBaseName)) {
            QGuiApplication::instance()->installTranslator(m_translator);
            engine->retranslate();
            m_language = lang;
        } else {
            qWarning() << "BytezeroSdk::setLanguage - language file load failed." << langBaseName << ", " << QGuiApplication::applicationDirPath();
        }
    }
    m_config->setAppLanguage(m_language);
    emit languageChanged();
}

void BytezeroSdk::registerContexts()
{
//    qDebug() << "BytezeroSdk::registerContexts - call.";
    if(0 == engine) {
        return;
    }
    rootContext->setContextProperty("bzSdk", this);
}

void BytezeroSdk::registerModels()
{
//    qDebug() << "BytezeroSdk::registerModels - call.";
}
