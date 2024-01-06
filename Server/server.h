#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(QObject* parent = nullptr);

    void start(quint16 port);

public slots:
    //

signals:
    void clientDisconnected(const QString& name);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private slots:
    void onReadyRead();
    void onClientDisconnected();

private:
    QMap<QTcpSocket*, QString> m_clients;

    QString generateRandomName() const;
};

#endif // SERVER_H
