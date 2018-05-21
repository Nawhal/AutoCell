/**
 * AutoCell
 * @file State.h
 * A state of the Automaton, composed of unit cells.
 *
 * The State class implements
 */


#ifndef _STATE_H
#define _STATE_H

#include "Cell.h"
#include <iostream>

class State {
    private:
        const unsigned int nbLine;
        const unsigned int nbColumn;
        Cell** cells;

    public:
        /**
         * Constructor.
         *
         * @param col
         * @param lin
         */
        State(const unsigned int lin, const unsigned int col);

        /**
         * Copy constructor.
         *
         * @param st : the state to copy
         */
        State(const State& st);

        /**
         * Destructor.
         *
         */
        ~State();

        /**
         * Returns number of living neighbors around a cell on line line and column column
         * @param cell surrounded
         * @return the living neighbors number
         */
        unsigned int getNbOfLivingNeighbors(unsigned int line, unsigned int column) const;

        /**
         * Returns number of lines in the cell grid
         *
         */
        unsigned int getNbLine() const { return this->nbLine;}

        /**
         * Returns number of columns in the cell grid
         *
         */
        unsigned int getNbColumn() const { return this->nbColumn;}

        /**
         * @param line
         * @param column
         * @return true is the coordinates are in cell grid
         */
        bool isInGrid (unsigned int line, unsigned int column) const { return(line < this->getNbLine() && column < this->getNbColumn());}


        /**
         * @param line
         * @param column
         * @return return the value of the cell if in the grid else returns false
         */
        bool getCellValue(unsigned int line, unsigned int column) const{
            if (isInGrid(line, column)) {
                return cells[line][column].getValue();
            } else return false;
        }

        /**
         * @param line
         * @param column
         * @param newCell
         */
        void changeCell(unsigned int line, unsigned int column, const Cell newCell) { cells[line][column] = Cell(newCell); }

        friend std::ostream& operator<<(std::ostream& o, const State& s);
};



#endif //_STATE_H
