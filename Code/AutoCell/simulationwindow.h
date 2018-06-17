#ifndef SIMULATIONWINDOW_H
#define SIMULATIONWINDOW_H

#include <QWidget>

namespace Ui {
    class SimulationWindow;
}

class SimulationWindow : public QWidget
{
    Q_OBJECT

    public:
        explicit SimulationWindow(QWidget *parent = 0);
        ~SimulationWindow();

    protected:
        void closeEvent(QCloseEvent *event);

    private:
        Ui::SimulationWindow *ui;

    private slots:
        void saveAutomaton ();
};

#endif // SIMULATIONWINDOW_H
