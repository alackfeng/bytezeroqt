#ifndef CHUNKDBSDK_H
#define CHUNKDBSDK_H

#include <QObject>
#include "storages/bytezerosdk.h"
#include "chunkdbs/bytezerodb.h"


class ChunkDBSdk : public BytezeroSdk
{
    Q_OBJECT

public:
    explicit ChunkDBSdk(QObject *parent = nullptr);
    virtual ~ChunkDBSdk();

signals:

public:
    // Bytezero interface
    virtual bool is_online() override;
    virtual bool db_online(const db_access_func &) override;

private:
    // BytezeroSdk interface
    void registerContexts() override;
    void registerModels() override;

private:
    BytezeroDB* m_bytezero_db = 0;
    chunk_db::db* m_chunk_db = 0;


};

#endif // CHUNKDBSDK_H
