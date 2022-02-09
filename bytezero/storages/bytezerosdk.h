#ifndef BYTEZEROSDK_H
#define BYTEZEROSDK_H

#include "storages/bytezero.h"

class BytezeroSdk : public QObject, public Bytezero
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title NOTIFY titleChanged)
    Q_PROPERTY(QString version READ version NOTIFY versionChanged)
    Q_PROPERTY(QString language READ language WRITE setLanguage NOTIFY languageChanged)

public:
    explicit BytezeroSdk(QObject *parent = nullptr);
    virtual ~BytezeroSdk();

    BytezeroSdk* reset();
    BytezeroSdk* init(QQmlApplicationEngine*);
    BytezeroSdk* loadLanguage(QTranslator* translator);

public:
    // Bytezero interface
    virtual bool is_online() override;
    virtual bool device_online(const device_access_func &) override;
    virtual bool db_online(const db_access_func &) override;

public:
    QString version() const;
    QString title() const;
    QString language() const;
    void setLanguage(QString);

signals:
    void titleChanged();
    void versionChanged();
    void languageChanged();

protected:
    virtual void registerContexts();
    virtual void registerModels();

protected:
    QQmlContext* rootContext = 0;
    QQmlApplicationEngine* engine = 0;
    QTranslator* m_translator = 0;
    QString m_language = "";
    int m_appMode = 0; // 1-test env, 2-product-online.
    Config* m_config = 0;



};

#endif // BYTEZEROSDK_H
