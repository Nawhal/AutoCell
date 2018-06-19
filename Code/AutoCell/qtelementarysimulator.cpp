#include "qtelementarysimulator.h"

void QtElementarySimulator::display()
{
    std::vector< std::vector<bool> > values;
    unsigned int currentLine = 0;
    for (std::vector<State>::iterator stateIt = states.begin(); stateIt != states.end(); ++stateIt, ++currentLine) {
        values.push_back(std::vector<bool>());
        for (State::Iterator it = (*stateIt).begin(); it != (*stateIt).end(); ++it){
            values[currentLine].push_back(*it);
        }
    }
    if (values.size() < stateNb) {
        for (unsigned int i = values.size()-1; i < stateNb-1; ++i) {
            values.push_back(std::vector<bool>());
        }
    }
    simulationWindow->setDisplayedAutomatonValues(values);
}
