#include "utils.h"

Utils::Utils(QObject *parent) : QObject(parent)
{

}

Utils::~Utils()
{
}

QString Utils::getAppDataPath()
{
    const QDir dbDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    return dbDir.absolutePath() + "/";
}
