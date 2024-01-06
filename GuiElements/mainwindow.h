#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class MainWindow : public QWidget
{
public:
    MainWindow(QWidget* parent = nullptr);

    void runAsServer();
    void runAsClient();
};

#endif // MAINWINDOW_H
