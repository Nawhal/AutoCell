/**
 * AutoCell
 * @file elementaryAutomaton.h
 * The ElementaryAutomaton determines how to update its state.
 *
 *
 */

#ifndef ELEMENTARYAUTOMATON_H
#define ELEMENTARYAUTOMATON_H

#include <automaton.h>
#define E20 1 // 2^0
#define E21 2 // 2^1
#define E22 4 // 2^2
#define E27 128 //2^7
#define E28 256 //2^8

/**
 * @brief The ElementaryAutomaton class holds the information of how to treat the current state to
 *          arrive at the next state of the elementary case.
 */
class ElementaryAutomaton : public Automaton
{
    private:
        static const unsigned int stateMaxNbLine = 1;
        static const unsigned int stateMaxNbColumn = 1000;
        static const unsigned int stateWorkingLine = 0;
        static const unsigned int lastRuleIndex = 7;

        // short unsigned int maxNbState; // nb etats, a mettre dans simul
        unsigned int ruleNumber; // regle de transition
        bool ruleTab[lastRuleIndex];

    public:
        /**
         * Constructor that sets the rule number.
         *
         * @param ruleN The rule number of the automaton.
         */
        ElementaryAutomaton (unsigned int ruleN);

        /**
         * Copy constructor.
         *
         * @param e The elementary automaton to copy.
         */
        ElementaryAutomaton (const ElementaryAutomaton& e);

        /**
         * Default destructor.
         *
         */
        ~ElementaryAutomaton () {}

        /**
         * Method to calculate the life expectancy of a cell in an elementary automaton.
         *
         * @param left The cell to the left of the one of interest.
         * @param mid The cell of interest.
         * @param right The cell to the right of the one of interest.
         * @return Value from 0 to 7 representing the cell's life expectancy.
         */
        static unsigned int lifeExpectancy (bool left, bool mid, bool right);

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

        /**
         * Update the current state to the next based on the elementary automaton's rules.
         *
         * @param currentState The current state of the elementary automaton.
         */
        virtual void applyTransition (State& currentState) const;

        /**
         * Returns the elementary automaton's rule number as an integer.
         *
         * @return The rule number.
         */
        unsigned int getRuleNumber () const{ return this->ruleNumber; }

        /**
         * Returns the table of the rule (the rule number in binary).
         *
         * @return The rule's table as a vector of booleans.
         */
        const bool* getRuleTab () const { return this->ruleTab; }

        /**
         * Sets the rule number and its corresponding table.
         *
         * @param ruleN The new rule number to be set.
         */
        void setRule (int ruleN);

        /**
         * @brief print
         * @param os
         */
        virtual void print (std::ostream& os) const;
};

#endif // ELEMENTARYAUTOMATON_H
