#ifndef SIMULATIONWINDOW_H
#define SIMULATIONWINDOW_H

#include <QWidget>
#include <qtsimulator.h>
#include <vector>
#include <qtimer>

namespace Ui {
    class SimulationWindow;
}

class SimulationWindow : public QWidget
{
    Q_OBJECT

    public:
        explicit SimulationWindow(QWidget *parent = 0);
        ~SimulationWindow();
        void setup(Simulator* sim, unsigned int nbLines, unsigned int nbCol);
        void setDisplayedAutomatonValues(std::vector< std::vector<bool> > values);

    protected:
        void closeEvent(QCloseEvent *event);

    private:
        QTimer *timer;
        Ui::SimulationWindow *ui;
        Simulator* simulator;
        void setupTable(unsigned int nbCol, unsigned int nbLines);
        void setupSimulation();

    private slots:
        void playPause ();
        void stepByStep ();
        void stop ();
        void run();
        void saveAutomaton ();
        void loadAutomaton ();
        void cellActivation(const QModelIndex &index);
};

#endif // SIMULATIONWINDOW_H
