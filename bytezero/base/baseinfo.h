#ifndef BZINFO_H
#define BZINFO_H

#include <QObject>
#include <QUrl>
#include <QJSEngine>
#include <QJSValue>

class BaseInfo
{
public:
    virtual ~BaseInfo() {}
    virtual QJSValue toJSValue(QJSEngine*) const = 0;
    virtual void fromJSValue(const QJSValue& value) = 0;
};

#endif // BZINFO_H
