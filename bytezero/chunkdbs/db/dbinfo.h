#ifndef DBINFO_H
#define DBINFO_H

#include "base/baseinfo.h"

//=================DbInfo============================
class DbInfo: public BaseInfo
{
public:
    DbInfo() {}
    explicit DbInfo(const QUrl& url);
    virtual ~DbInfo() {}
    virtual QJSValue toJSValue(QJSEngine *) const override;
    virtual void fromJSValue(const QJSValue &value) override;

    QString path = "";
    QString name = "";
    qint64 size = 0;
    qint64 alignSize = 0;
    qint64 createTime = 0;
    qint64 lastTime = 0;
};

#endif // DBINFO_H
