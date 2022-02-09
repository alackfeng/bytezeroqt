#include "bytezerodb.h"
#include <cores/chunk_db/db.hpp>

BytezeroDB::BytezeroDB(QObject *parent) : QObject(parent)
{
}

BytezeroDB::~BytezeroDB()
{
}

BytezeroDB *BytezeroDB::init(Bytezero* bz)
{
    m_bz = bz;
    connect(this, &BytezeroDB::sCreateDb, this, &BytezeroDB::oCreateDb);
    return this;
}

BytezeroDB *BytezeroDB::reset()
{
    return this;
}

bool BytezeroDB::createDb(BZ_HANDLE handle, const QList<QUrl> &rockPaths)
{
    if(!m_bz->is_online()) {
        return false;
    }
    emit sCreateDb(handle, rockPaths);
    return true;
}

void BytezeroDB::oCreateDb(BZ_HANDLE handle, const QList<QUrl> &rockPaths)
{
    bool ret = m_bz->db_online([&](chunk_db::db* access, bool)->bool{
        if(rockPaths.count() < 1) {
            return false;
        }
        QString path = rockPaths[0].toLocalFile();
        if(false == access->create_v4(path.toStdString())) {
            return false;
        }
        std::vector<std::string> paths;
        for(int i = 1; i<rockPaths.count(); ++i) {
            paths.emplace_back(rockPaths.at(i).toLocalFile().toStdString());
        }
        access->add_rock_file_v4(paths);
        emit rCreateDb(handle, rockPaths);
        return true;
    });
    if(!ret) emit rCreateDb(handle, rockPaths);
}
