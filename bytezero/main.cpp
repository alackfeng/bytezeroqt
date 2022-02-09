#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSharedPointer>
#include <QTranslator>
#include <QLocale>
#include <QDebug>

#include "chunkdbs/chunkdbsdk.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QCoreApplication::setOrganizationName("bytezero");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.addImportPath(":/components");
    engine.addImportPath(":/components/Bytezero");
    engine.addImportPath(":/components/Bytezero/Theme");
    engine.addImportPath(":/components/Bytezero/Utils");
    engine.addImportPath(":/components/Bytezero/Navigator");
    engine.addImportPath(":/components/Bytezero/Control");
    engine.addImportPath(":/components/ChunkDB");


    QSharedPointer<ChunkDBSdk> sdk(new ChunkDBSdk());
    sdk->init(&engine);

    QTranslator translator;
    sdk->loadLanguage(&translator);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
