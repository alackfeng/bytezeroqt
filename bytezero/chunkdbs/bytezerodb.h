#ifndef BYTEZERODB_H
#define BYTEZERODB_H

#include <QObject>
#include "storages/bytezero.h"

class BytezeroDB : public QObject
{
    Q_OBJECT
public:
    explicit BytezeroDB(QObject *parent = nullptr);
    virtual ~BytezeroDB();

    BytezeroDB* init(Bytezero*);
    BytezeroDB* reset();

    virtual bool createDb(BZ_HANDLE, const QList<QUrl>&);

signals:
    void sCreateDb(BZ_HANDLE, const QList<QUrl>&);
    void rCreateDb(BZ_HANDLE, const QList<QUrl>&);

private slots:
    void oCreateDb(BZ_HANDLE, const QList<QUrl>&);

private:
    Bytezero* m_bz = 0;
};

#endif // BYTEZERODB_H
