/**
 * AutoCell
 * @file dayAndNightAutomaton.h
 * The Day and Night Automaton determines how to update its state.
 *
 *
 */


#ifndef DAYANDNIGHTAUTOMATON_H
#define DAYANDNIGHTAUTOMATON_H

#include <gameOfLifeAutomaton.h>

/**
 * @brief The DayAndNightAutomaton class holds the information of how to treat the current state to
 *          arrive at the next state.
 */
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

        /**
         * Tests if the value of a cell will become true.
         *
         * @param line The line of the cell to test.
         * @param column The column of the cell to test.
         * @param s The state in which the cell is contained.
         * @return True if the cell's value will become true.
         */
        virtual bool willBeBorn (unsigned int line, unsigned int column,State& s) const;

        /**
         * Tests if the value of a cell will become false.
         *
         * @param line The line of the cell to test.
         * @param column The column of the cell to test.
         * @param s The state in which the cell is contained.
         * @return True if the cell's value will become false.
         */
        virtual bool willDie (unsigned int line, unsigned int column,State& s) const;

    public:
        /**
         * Default constructor.
         *
         */
        DayAndNightAutomaton(): GameOfLifeAutomaton(DayAndNightAutomaton::minToNotDie2,DayAndNightAutomaton::maxToNotDie2){}

};

#endif // DAYANDNIGHTAUTOMATON_H
