#ifndef BYTEZERO_H
#define BYTEZERO_H

#include "utils/utils.h"
#include "utils/config.h"
#include "base/baselistmodel.h"

namespace sdk { namespace plugins { class bytezero_network_sdk; }}
using sdk::plugins::bytezero_network_sdk;
typedef std::function<bool(bytezero_network_sdk*, bool)> device_access_func;

namespace chunk_db { class db; }
using chunk_db::db;
typedef std::function<bool(chunk_db::db*, bool)> db_access_func;


#define BZ_INSTANCE(BZ_Class) (qApp->property(#BZ_Class).value<BZ_Class*>())
#define BZ_CHUNKDBSDK_INSTANCE() ChunkDBSdk* m_bzChunk = BZ_INSTANCE(ChunkDBSdk)
#define BZ_BZDB_INSTANCE() BytezeroDB* m_bzDb = BZ_INSTANCE(BytezeroDB)

typedef long BZ_HANDLE;
#define BZ_THIS (BZ_HANDLE)(this)
#define BZ_MYSELF(handle) if(BZ_THIS!=handle) { \
  qDebug() << handle << " BZ_MYSELF is not me" << this; \
  return; \
}

class Bytezero {
public:
    virtual ~Bytezero() {}
    virtual bool is_online() = 0;
    virtual bool device_online(const device_access_func&) = 0;
    virtual bool db_online(const db_access_func&) = 0;
};


#endif // BYTEZERO_H
