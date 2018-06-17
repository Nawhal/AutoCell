/**
 * AutoCell
 * @file xmlautomatondatamanager.h
 * The manager to read and write automata and states to a XML file.
 *
 * The XmlDataManager class groups every method necessary to read and write both automaton and state to
 * an external XML file.
 */


#ifndef XMLAUTOMATONDATAMANAGER_H
#define XMLAUTOMATONDATAMANAGER_H

#include <QtXml>
#include <QString>
#include <tuple>
#include "state.h"
#include "elementaryAutomaton.h"
#include "gameOfLifeAutomaton.h"

/**
 * @brief The XmlDataManagerException class treats the exceptions for the XmlDataManager class.
 */
class XmlDataManagerException {
    public:
        /**
         * Constructor that receives a string containing an error message.
         *
         * @param message Error message.
         */
        XmlDataManagerException (const std::string& message) : info(message) {}

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
 * @brief The XmlAutomatonDataManager class is an implementation of a singleton that
 * holds the methods necessary to treat the reading and writing to external XML file.
 */
class XmlAutomatonDataManager
{
    private:

        /**
         * Default constructor.
         *
         */
        XmlAutomatonDataManager(){}

        /**
         * Default destructor.
         *
         */
        ~XmlAutomatonDataManager(){}

        /**
         * Default copy constructor.
         *
         * @param xmc The XmlAutomatonDataManager to copy.
         */
        XmlAutomatonDataManager(const XmlAutomatonDataManager& xmc){}

        /**
         * Default basic assignment operator overload.
         *
         * @param xmc The XmlAutomatonDataManager to be assigned.
         * @return The XmlAutomatonDataManager assigned.
         */
        XmlAutomatonDataManager& operator=(const XmlAutomatonDataManager& xmc){}

        static XmlAutomatonDataManager* instance;

        /**
         * Sets the contents of a file into a document to be read.
         *
         * @param path The path of the file to read.
         * @param filename The name of the file to read.
         * @param document The document to read to.
         */
        void openFileInDocument(QString path,QString filename,QDomDocument& document);

        /**
         * Writes the contents of a document into a text file.
         *
         * @param path The path of the file to write.
         * @param filename The name of the file to write.
         * @param document The document to be written.
         */
        void writeDocumentInFile(QString path,QString filename,QDomDocument& document);

    public:
        /**
         * Returns the only instance of the XmlAutomatonDataManager class.
         *
         * @return The single object of XmlAutomatonDataManager.
         */
        static XmlAutomatonDataManager& getInstance();

        /**
         * The method to delete the only instance of XmlAutomatonDataManager.
         *
         */
        static void freeInstance();

        /**
         * Writes an instance of State to an external XML file.
         *
         * @param s The state to be written.
         * @param path The path of the file to write.
         * @param filename The name of the file to write.
         */
        void writeState(State& s, QString path, QString filename);

        /**
         * Reads an instance of State from an external XML file.
         *
         * @param path The path of the file to be read.
         * @param filename The name of the file to be read.
         * @return The state read.
         */
        State readState(QString path, QString filename);

        /**
         * Writes an instance of Elementary Automaton to an external XML file.
         *
         * @param e The elementary automaton to be written.
         * @param path The path of the file to write.
         * @param filename The name of the file to write.
         */
        void writeElementaryAutomaton(ElementaryAutomaton& e, QString path, QString filename);

        /**
         * Reads an instance of Elementary Automaton from an external XML file.
         *
         * @param path The path of the file to be read.
         * @param filename The name of the file to be read.
         * @return The elementary automaton read.
         */
        ElementaryAutomaton readElementaryAutomaton(QString path, QString filename);

        /**
         * Writes an instance of Game of Life Automaton to an external XML file.
         *
         * @param g The game of life automaton to be written.
         * @param path The path of the file to write.
         * @param filename The name of the file to write.
         */
        void writeGameOfLifeAutomaton(GameOfLifeAutomaton& g, QString path, QString filename);

        /**
         * Reads an instance of Game of Life Automaton from an external XML file.
         *
         * @param path The path of the file to be read.
         * @param filename The name of the file to be read.
         * @return The game of life automaton read.
         */
        GameOfLifeAutomaton readGameOfLifeAutomaton(QString path, QString filename);

        /**
         * Writes the parameters of a day and night automaton to an external XML file.
         *
         * @param colNb The number of columns of the automaton.
         * @param lineNb The number of lines of the automaton.
         * @param path The path of the file to write.
         * @param filename The name of the file to write.
         */
        void writeDayAndNightAutomatonConfig(unsigned int colNb, unsigned int lineNb, QString path, QString filename);

        /**
         * Reads the parameters of a day and night automaton from an external XML file.
         *
         * @param path The path of the file to be read.
         * @param filename The name of the file to be read.
         * @return The parameters read.
         */
        std::tuple<unsigned int, unsigned int> readDayAndNightAutomatonConfig(QString path, QString filename);

        /**
         * Writes the parameters of a game of life automaton to an external XML file.
         *
         * @param colNb The number of columns of the automaton.
         * @param lineNb The number of lines of the automaton.
         * @param minDeath
         * @param maxDeath
         * @param path The path of the file to write.
         * @param filename The name of the file to write.
         */
        void writeGameOfLifeAutomatonConfig(unsigned int colNb, unsigned int lineNb, unsigned int minDeath, unsigned int maxDeath, QString path, QString filename);

        /**
         * Reads the parameters of a game of life automaton from an external XML file.
         *
         * @param path The path of the file to be read.
         * @param filename The name of the file to be read.
         * @return The parameters read.
         */
        std::tuple<unsigned int, unsigned int, unsigned int, unsigned int> readGameOfLifeAutomatonConfig(QString path, QString filename);

        /**
         * Writes the parameters of an elementary automaton to an external XML file.
         *
         * @param cellNb The number of cells of the automaton.
         * @param stateNb The number of states of the automaton.
         * @param ruleNb
         * @param path The path of the file to write.
         * @param filename The name of the file to write.
         */
        void writeElementaryAutomatonConfig(unsigned int cellNb, unsigned int stateNb, unsigned int ruleNb, QString path, QString filename);

        /**
         * Reads the parameters of an elementary automaton from an external XML file.
         *
         * @param path The path of the file to be read.
         * @param filename The name of the file to be read.
         * @return The parameters read.
         */
        std::tuple<unsigned int, unsigned int, unsigned int> readElementaryAutomatonConfig(QString path, QString filename);

};

#endif // XMLAUTOMATONDATAMANAGER_H
