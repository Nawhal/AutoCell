/**
 * AutoCell
 * @file automaton.h
 * The Automaton determines how to update the state.
 *
 *
 */


#ifndef AUTOMATON_H
#define AUTOMATON_H

#include "state.h"
#include <string>

/**
 * @brief The AutomatonException class treats the exceptions for the Automaton class.
 */
class AutomatonException {
    public:
        /**
         * Constructor that receives a string containing an error message.
         *
         * @param message Error message.
         */
        AutomatonException (const std::string& message) : info(message) {}

        /**
         * Get the error message.
         *
         * @return The error message.
         */
        std::string getInfo () const { return info; }

    private:
        std::string info;
};

/**
 * @brief The Automaton class holds the information of how to treat the current state to
 *          arrive at the next state.
 */
class Automaton
{
    private:

    public:
        /**
         * Default constructor.
         *
         */
        Automaton() {}

        /**
         * Pure virtual destructor.
         *
         */
        virtual ~Automaton () = 0; // pure virtual, abstract class

        /**
         * Update the current state to the next based on the automaton's rules.
         *
         * @param currentState The current state of the automaton.
         */
        virtual void applyTransition (State& currentState) const = 0;

        /**
         * @brief print
         * @param os
         */
        virtual void print (std::ostream& os) const = 0;

};

/**
 * Assignment operator overload.
 *
 * @param o The out stream to write to.
 * @param s The automaton to write.
 * @return The out stream with the automaton written to.
 */
inline std::ostream& operator<< (std::ostream &o, const Automaton& a) {
    a.print(o);
    return o;
}

#endif // AUTOMATON_H
