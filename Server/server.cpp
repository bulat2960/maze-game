#include "server.h"

#include <QRandomGenerator>

#include <QDebug> // TODO: Remove me

Server::Server(QObject *parent) : QTcpServer(parent)
{

}

void Server::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << "New connection";

    QTcpSocket* socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);

    qDebug() << "Client connected" << socket->peerPort() << socket->peerAddress();

    m_clients.insert(socket, generateRandomName());

    connect(socket, &QTcpSocket::readyRead, this, &Server::onReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &Server::onClientDisconnected);
}

void Server::onClientDisconnected()
{
    QTcpSocket* socket = dynamic_cast<QTcpSocket*>(QObject::sender());
    QString name = m_clients[socket];

    m_clients.remove(socket);

    emit clientDisconnected(name);
}

void Server::onReadyRead()
{
    // TODO: Describe exchange protocol
}

QString Server::generateRandomName() const
{
    QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    int randomStringLength = 6;

    QString randomString;
    for (int i = 0; i < randomStringLength; i++)
    {
        int index = QRandomGenerator::global()->bounded(possibleCharacters.size());
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }

    return randomString;
}
