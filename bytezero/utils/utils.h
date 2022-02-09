#ifndef UTILS_H
#define UTILS_H

// qt header.
#include <QObject>
#include <QDebug>
#include <QList>
#include <QMap>
#include <QVector>
#include <QThread>
#include <QThreadPool>
#include <QRunnable>
#include <QUrl>
#include <QMetaType>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QJSEngine>
#include <QJSValue>
#include <QDateTime>
#include <QImage>
#include <QReadWriteLock>
#include <QReadLocker>
#include <QWriteLocker>
#include <QTranslator>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QGuiApplication>
#include <QStandardPaths>

class Utils : public QObject
{
    Q_OBJECT
public:
    explicit Utils(QObject *parent = nullptr);
    virtual ~Utils();

    static QString getAppDataPath();


signals:

};

#endif // UTILS_H
