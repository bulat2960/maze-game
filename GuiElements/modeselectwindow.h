#ifndef MODESELECTWINDOW_H
#define MODESELECTWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QCloseEvent>

class ModeSelectWindow : public QWidget
{
    Q_OBJECT

public:
    ModeSelectWindow(QWidget* parent = nullptr);

protected:
    void closeEvent(QCloseEvent* event) override;

signals:
    void serverModeSelected();
    void clientModeSelected();
    void closedWithoutAction();

private:
    QPushButton* m_makeServerButton {nullptr};
    QPushButton* m_makeClientButton {nullptr};

    void setupServerButton();
    void setupClientButton();
};

#endif // MODESELECTWINDOW_H
