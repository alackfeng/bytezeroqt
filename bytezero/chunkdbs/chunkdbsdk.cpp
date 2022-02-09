#include "chunkdbsdk.h"
#include <cores/chunk_db/db.hpp>
#include "chunkdbs/db/dbcreatelistmodel.h"

ChunkDBSdk::ChunkDBSdk(QObject *parent) : BytezeroSdk(parent), m_bytezero_db(new BytezeroDB(parent))
{
    m_chunk_db = chunk_db::db::instance();
    qDebug() << "ChunkDBSdk::ChunkDBSdk - chunkdb version " << QString::fromStdString(m_chunk_db->get_db_version());

    m_bytezero_db->init(this);
}

ChunkDBSdk::~ChunkDBSdk()
{
    if(m_bytezero_db) {
        delete m_bytezero_db;
        m_bytezero_db = 0;
    }
}

bool ChunkDBSdk::is_online()
{
    return true;
}

bool ChunkDBSdk::db_online(const db_access_func &db_access)
{
    if(!is_online()) {
        return false;
    }
    return db_access(m_chunk_db, true);
}

void ChunkDBSdk::registerContexts()
{
    BytezeroSdk::registerContexts();
    qDebug() << "ChunkDBSdk::registerContexts - call.";

    qApp->setProperty("ChunkDBSdk", QVariant::fromValue(this));
    qApp->setProperty("BytezeroDB", QVariant::fromValue(m_bytezero_db));
}

void ChunkDBSdk::registerModels()
{
    BytezeroSdk::registerModels();
    qmlRegisterType<DbCreateListModel>("Bytezero.Model", 1, 0, "DbCreateListModel");

    qDebug() << "ChunkDBSdk::registerModels - call.";
}
