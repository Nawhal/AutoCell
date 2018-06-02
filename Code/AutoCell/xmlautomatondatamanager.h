#ifndef XMLAUTOMATONDATAMANAGER_H
#define XMLAUTOMATONDATAMANAGER_H

#include <QtXml>
#include <QString>
#include "state.h"
#include "elementaryAutomaton.h"
#include "gameOfLifeAutomaton.h"

class XmlDataManagerException {
    public:
        XmlDataManagerException (const std::string& message) : info(message) {}
        std::string getInfo () const { return info; }

    private:
        std::string info;
};

class XmlAutomatonDataManager
{
private:


    XmlAutomatonDataManager(){}
    ~XmlAutomatonDataManager(){}
    XmlAutomatonDataManager(const XmlAutomatonDataManager& xmc){}
    XmlAutomatonDataManager& operator=(const XmlAutomatonDataManager& xmc){}

    static XmlAutomatonDataManager* instance;
    // sets content of file into document to be read
    void openFileInDocument(QString path,QString filename,QDomDocument& document);
    // sets content of document into text file
    void writeDocumentInFile(QString path,QString filename,QDomDocument& document);

public:
    static XmlAutomatonDataManager& getInstance();
    static void endInstance();

    void writeState(State& s,QString path,QString filename);
    State readState(QString path,QString filename);

    void writeElementaryAutomaton(ElementaryAutomaton& e,QString path,QString filename);
    ElementaryAutomaton readElementaryAutomaton(QString path,QString filename);

    void writeGameOfLifeAutomaton(GameOfLifeAutomaton& g,QString path,QString filename);
    GameOfLifeAutomaton readGameOfLifeAutomaton(QString path,QString filename);

};

#endif // XMLAUTOMATONDATAMANAGER_H
