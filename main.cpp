#include <QApplication>

#include "GuiElements/mainwindow.h"
#include "GuiElements/modeselectwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow* mainWindow = new MainWindow;

    ModeSelectWindow* modeSelectWindow = new ModeSelectWindow;
    QObject::connect(modeSelectWindow, &ModeSelectWindow::serverModeSelected, mainWindow, &MainWindow::show);
    QObject::connect(modeSelectWindow, &ModeSelectWindow::clientModeSelected, mainWindow, &MainWindow::show);

    modeSelectWindow->show();


    return a.exec();
}
