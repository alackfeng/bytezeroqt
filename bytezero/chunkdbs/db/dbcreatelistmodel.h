#ifndef DBCREATELISTMODEL_H
#define DBCREATELISTMODEL_H

#include "storages/bytezero.h"
#include "dbinfo.h"

class DbCreateListModel : public BaseListModel
{
    Q_OBJECT

public:
    explicit DbCreateListModel(QObject *parent = nullptr);
    virtual ~DbCreateListModel();
    virtual void bind(bool);
    virtual void unbind();
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    virtual QHash<int, QByteArray> roleNames() const override;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Q_INVOKABLE virtual bool canFetchMore(const QModelIndex &parent) const override;
    Q_INVOKABLE virtual void fetchMore(const QModelIndex &parent) override;

    Q_INVOKABLE virtual void create(const QList<QUrl>&);


public slots:
    void rCreateDb(BZ_HANDLE, const QList<QUrl>&);

private:
    QList<DbInfo> m_infos;
};

#endif // DBCREATELISTMODEL_H
