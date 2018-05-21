/**
 * AutoCell
 * @file State.cpp
 */


#include "state.h"

/**
 * State implementation
 */


State::State(const unsigned int lin, const unsigned int col) : nbLine(lin), nbColumn(col) {
    cells = new Cell*[nbLine];
    for (unsigned int i = 0; i < nbLine; ++i) {
        cells[i] = new Cell[nbColumn];
    }
}

State::State(const State& st) : nbLine(st.nbLine), nbColumn(st.nbColumn) {
    //create same size state
    cells = new Cell*[st.nbLine];
    for (unsigned int i = 0; i < st.nbLine; ++i) {
        cells[i] = new Cell[st.nbColumn];
    }
    // copy st into this
    for (unsigned int i = 0; i < st.nbLine; ++i) {
        for(unsigned int j = 0; j < st.nbColumn; ++j) {
            cells[i][j] = st.cells[i][j];
        }
    }
}

unsigned int State::getNbOfLivingNeighbors(unsigned int line, unsigned int column) const {
    unsigned int nbL = 0;
    unsigned int firstNeighborLine = line-1;
    unsigned int lastNeighborLine = line+1;
    unsigned int firstNeighborColumn = column-1;
    unsigned int lastNeighborColumn = column+1;

    for (unsigned int i = firstNeighborLine; i <= lastNeighborLine; ++i) {
        for (unsigned int j = firstNeighborColumn; j <= lastNeighborColumn; ++j) {
            if (this->getCellValue(i,j) && (i != line || j != column)) {
                nbL++;
            }
        }
    }

    return nbL;
}


State::~State() {
    for (unsigned int i = 0; i < nbLine; ++i) {
        delete [] cells[i];
    }
    delete[] cells;
}

std::ostream& operator<<(std::ostream& o, const State& s) {
    o << "\nState :\n";
    for(unsigned int i = 0; i < s.getNbLine(); ++i) {
        for(unsigned int j = 0; j < s.getNbColumn(); ++j) {
            o << s.cells[i][j] << ' ';
        }
        o << "\n";
    }
    return o;
}
