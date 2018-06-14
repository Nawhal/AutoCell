/**
 * AutoCell
 * @file State.h
 * A state of the Automaton, composed of unit cells.
 *
 * The State class groups every cell of an automaton at a specific moment.
 */


#ifndef _STATE_H
#define _STATE_H

#include "Cell.h"
#include <iostream>

/**
 * @brief The StateException class treats the exceptions for the State class.
 */
class StateException {
    public:
        /**
         * Constructor that receives a string containing an error message.
         *
         * @param message Error message.
         */
        StateException (const std::string& message) : info(message) {}

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
 * @brief The State class holds every cell of a specific moment.
 */
class State {
    private:
        const unsigned int nbLine;
        const unsigned int nbColumn;
        Cell** cells;

    public:
        /**
         * Constructor that sets the number of lines and columns on a state.
         *
         * @param col Number of columns of a state.
         * @param lin Number of lines of a state.
         */
        State (const unsigned int lin, const unsigned int col);

        /**
         * Copy constructor.
         *
         * @param st The state to copy.
         */
        State (const State& st);

        /**
         * Destructor.
         *
         */
        ~State ();

        /**
         * Returns number of living neighbors around a cell on line line and column column.
         *
         * @param cell The cell around which the neighbors are counted.
         * @return The number of living neighbors.
         */
        unsigned int getNbOfLivingNeighbors (int line, int column) const;

        /**
         * Returns number of lines in the cell grid.
         *
         * @return The number of lines.
         */
        int getNbLine () const { return this->nbLine;}

        /**
         * Returns number of columns in the cell grid.
         *
         * @return The number of columns.
         */
        int getNbColumn () const { return this->nbColumn;}

        /**
         * Tests if a position is valid on the state's grid.
         *
         * @param line The line to test.
         * @param column The column to test.
         * @return True if valid, false if invalid.
         */
        bool isInGrid (int line, int column) const { return (line<this->getNbLine() && line>=0 && column<this->getNbColumn() && column>=0); }

        /**
         * Tries to get the value of a state's cell.
         *
         * @param line The line of the cell to get.
         * @param column The column of the cell to get.
         * @return The value of the cell if in the grid or false if not.
         */
        bool getCellValue (int line, int column) const{
            if (isInGrid(line,column)) {
                return cells[line][column].getValue();
            } else return false;
        }

        /**
         * Changes a cell, if the cell isn't in the grid, raises an exception.
         *
         * @param line The line of the cell to change.
         * @param column The column of the cell to change.
         * @param newCell The new cell to put in the state.
         */
        void changeCell (unsigned int line, unsigned int column, const Cell newCell) {
            if(isInGrid(line,column)){
                cells[line][column]=Cell(newCell);
            }else{
                throw StateException("dimensions hors de l'état");
            }
        }

        /**
         * @brief The Iterator for the State class.
         */
        class Iterator{
            friend class State;

            const State* state;
            unsigned int currentLine;
            unsigned int currentColumn;

            /**
             * Iterator's constructor to a specific position of a State class.
             *
             * @param s The state on which to iterate.
             * @param l The line to begin iterating.
             * @param c The column to begin iterating.
             */
            Iterator(const State* s,unsigned int l,unsigned c):state(s),currentLine(l),currentColumn(c){}

        public:
            /**
             * Default constructor that sets the iterator to the first line and column.
             *
             */
            Iterator():state(0),currentLine(0),currentColumn(0){}

            /**
             * Indirection operator overload.
             *
             * @return The value of the cell.
             */
            const bool operator*() const { return state->getCellValue(currentLine,currentColumn); }

            /**
             * Get the current line of the iterator.
             *
             * @return The current line.
             */
            unsigned int getCurrentLine(){return this->currentLine;}

            /**
             * Get the current column of the iterator.
             *
             * @return The current column.
             */
            unsigned int getCurrentColumn(){return this->currentColumn;}

            /**
             * Increment operator overload.
             *
             * @return A reference to the iterator.
             */
            Iterator& operator++() {
                currentColumn++;
                if(currentColumn==state->getNbColumn()){
                    currentColumn=0;
                    currentLine++;
                }
                return *this;
            }

            /**
             * Inequality operator overload.
             *
             * @param it The iterator to compare to.
             * @return True if the iterators are different.
             */
            bool operator!=(Iterator it) const { return currentLine!=it.getCurrentLine() || currentColumn!=it.getCurrentColumn(); }

        };

        /**
         * Gets an iterator to the first position of the state.
         *
         * @return An iterator to the fisrt position.
         */
        Iterator begin() const { return Iterator(this,0,0); }

        //column gets restarted when at tab[size] not line
        /**
         * Gets an iterator to the last position of the state.
         *
         * @return An iterator to the last position.
         */
        Iterator end() const { return Iterator(this,nbLine,nbColumn-1); }

        /**
         * Assignment operator overload.
         *
         * @param o The out stream to write to.
         * @param s The state to write.
         * @return The out stream with the state written to.
         */
        friend std::ostream& operator<< (std::ostream& o, const State& s);
};

#endif //_STATE_H
