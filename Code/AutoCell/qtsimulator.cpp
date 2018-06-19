#include "qtsimulator.h"
#include <vector>

void QtSimulator::display()
{
    std::vector< std::vector<bool> > values;
    unsigned int currentLine = 0;
    values.push_back(std::vector<bool>());
    for (State::Iterator it = currentState.begin(); it != currentState.end(); ++it){
        if (it.getCurrentLine() != currentLine) {
            values.push_back(std::vector<bool>());
            currentLine = it.getCurrentLine();
        }
        values[it.getCurrentLine()].push_back(*it);
    }
    simulationWindow->setDisplayedAutomatonValues(values);
}
