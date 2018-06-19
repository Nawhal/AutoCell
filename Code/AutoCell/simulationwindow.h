#ifndef SIMULATIONWINDOW_H
#define SIMULATIONWINDOW_H

#include <QWidget>
#include <qtsimulator.h>
#include <vector>
#include <qtimer>
#include <string>
#include <cxxabi.h>

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
        void returnToMainWindow();
        void playPause ();
        void stepByStep ();
        void stop ();
        void run();
        void saveAutomaton ();
        void loadAutomaton ();
        void updateSpeed ();
        void cellActivation(const QModelIndex &index);
};

template <typename T>
bool isOfType(const T &value, const char* typeName) {
    return strcmp(abi::__cxa_demangle(typeid(value).name(), 0, 0, 0), typeName) == 0;
}

#endif // SIMULATIONWINDOW_H
