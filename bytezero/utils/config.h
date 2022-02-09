#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include <QSettings>

class Config : public QObject
{
    Q_OBJECT
public:
    explicit Config(QObject *parent = nullptr);
    virtual ~Config();

    int appMode();
    QString appLanguage();
    void setAppLanguage(QString lang);

signals:

private:
    bool check();
private:
    QSettings* m_setting = 0;
};

#endif // CONFIG_H
