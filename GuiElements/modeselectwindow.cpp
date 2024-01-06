#include "modeselectwindow.h"

#include <QHBoxLayout>

ModeSelectWindow::ModeSelectWindow(QWidget* parent) : QWidget(parent)
{
    setupServerButton();
    setupClientButton();

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(m_makeServerButton);
    layout->addWidget(m_makeClientButton);
}

void ModeSelectWindow::closeEvent(QCloseEvent* event)
{
    Q_UNUSED(event);

    emit closedWithoutAction();
    close();
}

void ModeSelectWindow::setupServerButton()
{
    m_makeServerButton = new QPushButton("Server");
    connect(m_makeServerButton, &QPushButton::clicked, this, &ModeSelectWindow::serverModeSelected);
    connect(m_makeServerButton, &QPushButton::clicked, this, &ModeSelectWindow::close);
}

void ModeSelectWindow::setupClientButton()
{
    m_makeClientButton = new QPushButton("Client");
    connect(m_makeClientButton, &QPushButton::clicked, this, &ModeSelectWindow::clientModeSelected);
    connect(m_makeClientButton, &QPushButton::clicked, this, &ModeSelectWindow::close);
}
