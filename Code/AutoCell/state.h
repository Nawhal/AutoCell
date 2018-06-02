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

        class Iterator{
            friend class State;

            const State* state;
            unsigned int currentLine;
            unsigned int currentColumn;


            Iterator(const State* s,unsigned int l,unsigned c):state(s),currentLine(l),currentColumn(c){}

        public:
            Iterator():state(0),currentLine(0),currentColumn(0){}
            const bool operator*() const { return state->getCellValue(currentLine,currentColumn); }

            unsigned int getCurrentLine(){return this->currentLine;}
            unsigned int getCurrentColumn(){return this->currentColumn;}

            Iterator& operator++() {
                currentColumn++;
                if(currentColumn==state->getNbColumn()){
                    currentColumn=0;
                    currentLine++;
                }
                return *this;
            }
            bool operator!=(Iterator it) const { return currentLine!=it.getCurrentLine() || currentColumn!=it.getCurrentColumn(); }

        };

        Iterator begin() const { return Iterator(this,0,0); }
        //column gets restarted when at tab[size] not line
        Iterator end() const { return Iterator(this,nbLine,nbColumn-1); }

        friend std::ostream& operator<< (std::ostream& o, const State& s);
};





#endif //_STATE_H
