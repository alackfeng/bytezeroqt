#include "config.h"
#include "utils/utils.h"

Config::Config(QObject *parent) : QObject(parent)
{
    QString folder = Utils::getAppDataPath();
    folder.append("config.ini");
    m_setting = new QSettings(folder, QSettings::IniFormat);
}

Config::~Config()
{
}

int Config::appMode()
{
    if(!check()) return 0;
    m_setting->beginGroup("Environment");
    int productOnline = m_setting->value("App").toInt();
    if(productOnline == 0) {
        productOnline = 2;
        m_setting->setValue("App", productOnline);
    }
    m_setting->endGroup();
    return productOnline;
}

QString Config::appLanguage()
{
    if(!check()) return "";
    m_setting->beginGroup("Environment");
    QString lang = m_setting->value("Lang").toString();
    m_setting->endGroup();
    return lang;
}

void Config::setAppLanguage(QString lang)
{
    if(!check()) return;
    m_setting->beginGroup("Environment");
    m_setting->setValue("Lang", lang);
    m_setting->endGroup();
}

bool Config::check()
{
    return m_setting != 0;
}
