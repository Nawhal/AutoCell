#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private:
        Ui::MainWindow *ui;

    private slots:
        void configureElementaryAutomaton ();
        void configureGameOfLifeAutomaton ();
        void configureDayAndNightAutomaton ();
        void quit ();
};

#endif // MAINWINDOW_H
