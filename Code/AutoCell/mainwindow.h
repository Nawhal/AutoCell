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

    protected:
        void closeEvent(QCloseEvent *event);

    private:
        Ui::MainWindow *ui;

    private slots:
        void configureElementaryAutomaton ();
        void configureGameOfLifeAutomaton ();
        void configureDayAndNightAutomaton ();
};

#endif // MAINWINDOW_H
