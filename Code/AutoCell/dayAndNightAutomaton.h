#ifndef DAYANDNIGHTAUTOMATON_H
#define DAYANDNIGHTAUTOMATON_H

#include <gameOfLifeAutomaton.h>

class DayAndNightAutomaton : public GameOfLifeAutomaton
{

    private :
        static const unsigned int minToNotDie1 = 3;
        static const unsigned int maxToNotDie1 = 4;
        static const unsigned int minToNotDie2 = 6;
        static const unsigned int maxToNotDie2 = 8;
        static const unsigned int nbToBeBornTabSize = 4;
        static const int nbToBeBornTab[DayAndNightAutomaton::nbToBeBornTabSize];

        GameOfLifeAutomaton gol34 = GameOfLifeAutomaton(DayAndNightAutomaton::minToNotDie1,DayAndNightAutomaton::maxToNotDie1);

        virtual bool willBeBorn (unsigned int line, unsigned int column,State& s) const;
        virtual bool willDie (unsigned int line, unsigned int column,State& s) const;

    public:
        DayAndNightAutomaton(): GameOfLifeAutomaton(DayAndNightAutomaton::minToNotDie2,DayAndNightAutomaton::maxToNotDie2){}

};

#endif // DAYANDNIGHTAUTOMATON_H
