#ifndef BASELISTMODEL_H
#define BASELISTMODEL_H

#include <QAbstractListModel>

class BaseListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit BaseListModel(QObject *parent = nullptr);
    virtual ~BaseListModel();

    enum BaseListRole {
        DisplayRole = Qt::UserRole,
        NameRole,
        SizeRole,
        AlignSizeRole,
        CreateTimeRole,
        LastTimeRole,
    };
    Q_ENUM(BaseListRole)

    virtual void bind(bool) {}
    virtual void unbind() {}

private:
};

#endif // BASELISTMODEL_H
