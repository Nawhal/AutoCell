/**
 * AutoCell
 * @file gameOfLifeAutomaton.h
 * The GameOfLifeAutomaton determines how to update its state.
 *
 *
 */


#ifndef GAMEOFLIFEAUTOMATON_H
#define GAMEOFLIFEAUTOMATON_H

#include <Automaton.h>

/**
 * @brief The GameOfLifeAutomaton class holds the information of how to treat the current state to
 *          arrive at the next state of the game of life case.
 */
class GameOfLifeAutomaton : public Automaton
{
    private:
        static const short unsigned int stateMaxNbLine = 1000;
        static const short unsigned int stateMaxNbColumn = 1000;
        static const unsigned int nbToBeBorn = 3;

        unsigned int minToNotDie;
        unsigned int maxToNotDie;

        /**
         * Returns the number of living neighbours necessary to a new cell's value become 1.
         *
         * @return The number necessary to a cell be born.
         */
        static unsigned int getNbToBeBorn () { return GameOfLifeAutomaton::nbToBeBorn; }

        /**
         * Returns the maximum number of lines in a state.
         *
         * @return The maximum number of lines.
         */
        static unsigned int getStateMaxNbLine () { return stateMaxNbLine; }

        /**
         * Returns the maximum number of columns in a state.
         *
         * @return The maximum number of columns.
         */
        static unsigned int getStateMaxNbColumn () { return stateMaxNbColumn; }

    public:
        /**
         * Constructor that sets the minimun number of neighbours to die and the maximum number of neighbours not to die.
         *
         * @param minNd The minimun number of neighbours to die.
         * @param maxNd The maximum number of neighbours not to die.
         */
        GameOfLifeAutomaton (unsigned int minNd, unsigned int maxNd) : minToNotDie (minNd), maxToNotDie (maxNd) { if(minNd>maxNd){throw AutomatonException("Minimum value superior than maximum value");}}

        /**
         * Default destructor.
         *
         */
        virtual ~GameOfLifeAutomaton () {}

        /**
         * Tests if a state is not in range.
         *
         * @param currentState The state to test.
         * @return True if not in range, false otherwise.
         */
        bool isNotInRange(const State& currentState) const;

        /**
         * @brief print
         * @param os
         */
        virtual void print (std::ostream& os) const;

        /**
         * Update the current state to the next based on the automaton's rules.
         *
         * @param currentState The current state of the automaton.
         */
        virtual void applyTransition (State& currentState) const;

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

        /**
         * Returns the minimum value necessary for a cell to not die.
         *
         * @return The minimum value to not die.
         */
        unsigned int getMinToNotDie () const { return this->minToNotDie; }

        /**
         * Returns the maximum value necessary for a cell to not die.
         *
         * @return The maximum value to not die.
         */
        unsigned int getMaxToNotDie () const { return this->maxToNotDie; }
};

#endif // GAMEOFLIFEAUTOMATON_H
