#include "dbinfo.h"
#include <QFileInfo>
#include <QDateTime>

static const char* jsvalue_f_path = "path";
static const char* jsvalue_f_name = "name";
static const char* jsvalue_f_size = "size";
static const char* jsvalue_f_alignSize = "alignSize";
static const char* jsvalue_f_createTime = "createTime";
static const char* jsvalue_f_lastTime = "lastTime";

//=================DbInfo============================
DbInfo::DbInfo(const QUrl &url)
{
    QFileInfo info(url.toLocalFile());
    if(!info.exists()) {
        path = url.toLocalFile();
        name = url.toLocalFile();
        return;
    }
    path = info.filePath();
    name = info.baseName();
    size = info.size();
    alignSize = info.size();
    createTime = info.birthTime().toMSecsSinceEpoch();
    lastTime = info.lastModified().toMSecsSinceEpoch();
}

QJSValue DbInfo::toJSValue(QJSEngine *engine) const
{
    QJSValue value = engine->newObject();
    value.setProperty(jsvalue_f_path, path);
    value.setProperty(jsvalue_f_name, name);
    value.setProperty(jsvalue_f_size, QString::number(size));
    value.setProperty(jsvalue_f_alignSize, QString::number(alignSize));
    value.setProperty(jsvalue_f_createTime, QString::number(createTime));
    value.setProperty(jsvalue_f_lastTime, QString::number(lastTime));
    return value;
}

void DbInfo::fromJSValue(const QJSValue &value)
{
    path = value.property(jsvalue_f_path).toString();
    name = value.property(jsvalue_f_name).toString();
    size = value.property(jsvalue_f_size).toString().toLongLong();
    alignSize = value.property(jsvalue_f_alignSize).toString().toLongLong();
    createTime = value.property(jsvalue_f_createTime).toString().toLongLong();
    lastTime = value.property(jsvalue_f_lastTime).toString().toLongLong();
}
