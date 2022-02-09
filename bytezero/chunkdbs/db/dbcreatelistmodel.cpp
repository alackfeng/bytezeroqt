#include "dbcreatelistmodel.h"
#include "chunkdbs/bytezerodb.h"

DbCreateListModel::DbCreateListModel(QObject *parent)
    : BaseListModel(parent)
{
    bind(false);
}

DbCreateListModel::~DbCreateListModel()
{
}

void DbCreateListModel::bind(bool)
{
    BZ_BZDB_INSTANCE();
    connect(m_bzDb, &BytezeroDB::rCreateDb, this, &DbCreateListModel::rCreateDb);
}

void DbCreateListModel::unbind()
{
}

int DbCreateListModel::rowCount(const QModelIndex &parent) const
{
    qDebug() << "DbCreateListModel::rowCount - " << parent.isValid() << ",count " << m_infos.count() << ", " << this;
    return m_infos.count();
}

QVariant DbCreateListModel::data(const QModelIndex &index, int role) const
{
    qDebug() << "DbCreateListModel::data - " << index.isValid() << ", role " << role << ", " << this;
    if (!index.isValid() || index.row() < 0 || index.row() >= rowCount())
        return QVariant();
    switch (role) {
    case DisplayRole: return m_infos.at(index.row()).path;
    case NameRole: return m_infos.at(index.row()).name;
    case SizeRole: return m_infos.at(index.row()).size;
    case AlignSizeRole: return m_infos.at(index.row()).alignSize;
    case CreateTimeRole: return m_infos.at(index.row()).createTime;
    case LastTimeRole: return m_infos.at(index.row()).lastTime;
    default: return QVariant();
    }
    return QVariant();
}

QHash<int, QByteArray> DbCreateListModel::roleNames() const
{
    qDebug() << "DbCreateListModel::roleNames - " << this;
    static const QHash<int, QByteArray> roles = {
        { DisplayRole, "displayName" },
        { NameRole, "name" },
        { SizeRole, "size" },
        { AlignSizeRole, "alignSize" },
        { CreateTimeRole, "createTime"},
        { LastTimeRole, "lastTime"},
    };
    return roles;
}

bool DbCreateListModel::setData(const QModelIndex &index, const QVariant &/*value*/, int role)
{
    qDebug() << "DbCreateListModel::setData - " << index.isValid() << ", role " << role << ", " << this;
    if (!index.isValid() || index.row() < 0 || index.row() >= rowCount())
        return false;
    return true;
}

bool DbCreateListModel::canFetchMore(const QModelIndex &parent) const
{
    qDebug() << "DbCreateListModel::canFetchMore - " << parent.isValid() << ", " << this;
    return true;
}

void DbCreateListModel::fetchMore(const QModelIndex &parent)
{
    qDebug() << "DbCreateListModel::fetchMore - " << parent.isValid() << ", " << this;
}

void DbCreateListModel::create(const QList<QUrl> &rockPaths)
{
    qDebug() << "DbCreateListModel::create - paths: " << rockPaths;
    BZ_BZDB_INSTANCE();
    m_bzDb->createDb(BZ_THIS, rockPaths);

    beginInsertRows(QModelIndex(), rowCount(), rowCount() + rockPaths.count() - 1);
    for(int i = 0; i < rockPaths.count(); ++i) {
        DbInfo info(rockPaths.at(i));
        m_infos.append(info);
    }
    endInsertRows();

}

void DbCreateListModel::rCreateDb(BZ_HANDLE handle, const QList<QUrl> &)
{
    BZ_MYSELF(handle)
    qDebug() << "DbCreateListModel::rCreateDb - handle " << handle;
}

