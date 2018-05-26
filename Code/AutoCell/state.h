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

class StateException {
    public:
        StateException (const std::string& message) : info(message) {}
        std::string getInfo () const { return info; }

    private:
        std::string info;
};

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
        State (const unsigned int lin, const unsigned int col);

        /**
         * Copy constructor.
         *
         * @param st : the state to copy
         */
        State (const State& st);

        /**
         * Destructor.
         *
         */
        ~State ();

        /**
         * Returns number of living neighbors around a cell on line line and column column
         * @param cell surrounded
         * @return the living neighbors number
         */
        unsigned int getNbOfLivingNeighbors (int line, int column) const;

        /**
         * Returns number of lines in the cell grid
         *
         */
        int getNbLine () const { return this->nbLine;}

        /**
         * Returns number of columns in the cell grid
         *
         */
        int getNbColumn () const { return this->nbColumn;}

        /**
         * @param line
         * @param column
         * @return true is the coordinates are in cell grid
         */
        bool isInGrid (int line, int column) const { return (line<this->getNbLine() && line>=0 && column<this->getNbColumn() && column>=0);}


        /**
         * @param line
         * @param column
         * @return return the value of the cell if in the grid else returns false
         */
        bool getCellValue (int line, int column) const{
            if (isInGrid(line,column)) {
                return cells[line][column].getValue();
            } else return false;
        }

        /**
         * @param line
         * @param column
         * @param newCell
         */
        void changeCell (unsigned int line, unsigned int column, const Cell newCell) {
            if(isInGrid(line,column)){
                cells[line][column]=Cell(newCell);
            }else{
                throw StateException("dimensions hors de l'état");
            }
        }

        friend std::ostream& operator<< (std::ostream& o, const State& s);
};





#endif //_STATE_H
