/**
 * AutoCell
 * @file xmlautomatondatamanager.cpp
 */


#include "xmlautomatondatamanager.h"
#include <functional>

/**
 * XmlAutomatonDataManager implementation.
 */

XmlAutomatonDataManager* XmlAutomatonDataManager::instance = nullptr;

/**
 * getInstance method implementation.
 *
 */
XmlAutomatonDataManager& XmlAutomatonDataManager::getInstance(){
    if(XmlAutomatonDataManager::instance==nullptr){
        XmlAutomatonDataManager::instance = new XmlAutomatonDataManager();
    }
    return *(XmlAutomatonDataManager::instance);
}

/**
 * freeInstance method implementation.
 *
 */
void XmlAutomatonDataManager::freeInstance(){
    if(nullptr!=XmlAutomatonDataManager::instance){
        delete XmlAutomatonDataManager::instance;
        XmlAutomatonDataManager::instance=nullptr;
    }
}

/**
 * writeState method implementation.
 *
 */
void XmlAutomatonDataManager::writeState(State& s,QString path,QString filename){
    // Creates a document to write XML
    QDomDocument document;
    document.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"utf-8\"");

    // Making the root element of state
    QDomElement root = document.createElement("State");

    // Adding the root element to the docuemnt
    document.appendChild(root);

    // size of state
    QDomElement size = document.createElement("Size");
    size.setAttribute("nbLine",s.getNbLine());
    size.setAttribute("nbColumn",s.getNbColumn());
    root.appendChild(size);

    // living cells
    QDomElement livingCells = document.createElement("LivingCells");
    root.appendChild(livingCells);

    for(State::Iterator it=s.begin(); it!=s.end(); ++it){
        if(*it){
            QDomElement lCell = document.createElement("Alive");
            lCell.setAttribute("line",it.getCurrentLine());
            lCell.setAttribute("column",it.getCurrentColumn());
            livingCells.appendChild(lCell);
        }
    }

    // Writing to a file
    writeDocumentInFile(path,filename,document);
}

/**
 * readState method implementation.
 *
 */
State XmlAutomatonDataManager::readState(QString path,QString filename){
    // opens the document into document
    QDomDocument document;
    openFileInDocument(path,filename,document);

    // Getting root element
    QDomElement root = document.firstChildElement();
    QDomElement size  = root.firstChildElement();
    unsigned int ln = size.attribute("nbLine","0").toUInt();
    unsigned int cl = size.attribute("nbColumn","0").toUInt();

    State res(ln,cl);

    QDomElement livingCells = size.nextSiblingElement();
    QDomNodeList cellNodes = livingCells.elementsByTagName("Alive");

    for(int i = 0; i < cellNodes.count(); i++){
        QDomNode singleCellNode = cellNodes.at(i);
        if(singleCellNode.isElement()){
            QDomElement singleCellElement = singleCellNode.toElement();
            unsigned int cln = singleCellElement.attribute("line","-1").toUInt(); // cell line
            unsigned int ccl = singleCellElement.attribute("column","-1").toUInt(); // cell column
            try{
                res.changeCell(cln,ccl,Cell(true));
            }catch (StateException s){
                //nothing, only if bad xml
            }

        }
    }

    return res;

}

/**
 * writeElementaryAutomaton method implementation.
 *
 */
void XmlAutomatonDataManager::writeElementaryAutomaton(ElementaryAutomaton& e,QString path,QString filename){
    // Creates a document to write XML
    QDomDocument document;
    document.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"utf-8\"");

    // Making the root element of state
    QDomElement root = document.createElement("ElementaryAutomaton");

    // Adding the root element to the docuemnt
    document.appendChild(root);

    // rule of elementary automaton
    QDomElement ruleNb = document.createElement("RuleNumber");
    ruleNb.setAttribute("value",e.getRuleNumber());
    root.appendChild(ruleNb);

    //write to file
    writeDocumentInFile(path,filename,document);

}

/**
 * readElementaryAutomaton method implementation.
 *
 */
ElementaryAutomaton XmlAutomatonDataManager::readElementaryAutomaton(QString path,QString filename){
    // opens the document into document
    QDomDocument document;
    openFileInDocument(path,filename,document);

    // Getting root element
    QDomElement root = document.firstChildElement();
    QDomElement ruleNB  = root.firstChildElement();
    unsigned int rule = ruleNB.attribute("value","0").toUInt();

    return ElementaryAutomaton(rule);
}

/**
 * writeGameOfLifeAutomaton method implementation.
 *
 */
void XmlAutomatonDataManager::writeGameOfLifeAutomaton(GameOfLifeAutomaton& g,QString path,QString filename){
    // Creates a document to write XML
    QDomDocument document;
    document.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"utf-8\"");

    // Making the root element of state
    QDomElement root = document.createElement("GameOfLifeAutomaton");

    // Adding the root element to the docuemnt
    document.appendChild(root);

    // size of state
    QDomElement neighbors = document.createElement("SurvivalNeighborhood");
    neighbors.setAttribute("min",g.getMinToNotDie());
    neighbors.setAttribute("max",g.getMaxToNotDie());
    root.appendChild(neighbors);

    //write to file
    writeDocumentInFile(path,filename,document);
}

/**
 * readGameOfLifeAutomaton method implementation.
 *
 */
GameOfLifeAutomaton XmlAutomatonDataManager::readGameOfLifeAutomaton(QString path,QString filename){
    // opens the document into document
    QDomDocument document;
    openFileInDocument(path,filename,document);

    // Getting root element
    QDomElement root = document.firstChildElement();
    QDomElement neighborsToSurvive  = root.firstChildElement();
    unsigned int minNeighbors = neighborsToSurvive.attribute("min","0").toUInt();
    unsigned int maxNeighbors = neighborsToSurvive.attribute("max","0").toUInt();

    return GameOfLifeAutomaton(minNeighbors,maxNeighbors);
}

/**
 * writeDayAndNightAutomatonConfig method implementation.
 */
void XmlAutomatonDataManager::writeDayAndNightAutomatonConfig(unsigned int colNb, unsigned int lineNb, QString path, QString filename)
{
    // Creates a document to write XML
    QDomDocument document;
    document.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"utf-8\"");

    // Making the root element of state
    QDomElement root = document.createElement("parameters");
    root.setAttribute("colNb", colNb);
    root.setAttribute("lineNb", lineNb);

    // Adding the root element to the docuemnt
    document.appendChild(root);

    // Write to file
    writeDocumentInFile(path,filename,document);
}

/**
 * readDayAndNightAutomatonConfig method implementation.
 */
std::tuple<unsigned int, unsigned int> XmlAutomatonDataManager::readDayAndNightAutomatonConfig(QString path, QString filename)
{
    // opens the document into document
    QDomDocument document;
    openFileInDocument(path, filename, document);

    // Getting root element
    QDomElement root = document.firstChildElement();
    unsigned int colNb = root.attribute("colNb","0").toUInt();
    unsigned int lineNb = root.attribute("lineNb","0").toUInt();

    return std::make_tuple(colNb, lineNb);
}

/**
 * writeDayAndNightAutomatonConfig method implementation.
 */
void XmlAutomatonDataManager::writeGameOfLifeAutomatonConfig(unsigned int colNb, unsigned int lineNb,
        unsigned int minDeath, unsigned int maxDeath, QString path, QString filename)
{
    // Creates a document to write XML
    QDomDocument document;
    document.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"utf-8\"");

    // Making the root element of state
    QDomElement root = document.createElement("parameters");
    root.setAttribute("colNb", colNb);
    root.setAttribute("lineNb", lineNb);
    root.setAttribute("minDeath", minDeath);
    root.setAttribute("maxDeath", maxDeath);

    // Adding the root element to the docuemnt
    document.appendChild(root);

    // Write to file
    writeDocumentInFile(path,filename,document);
}

/**
 * readDayAndNightAutomatonConfig method implementation.
 */
std::tuple<unsigned int, unsigned int, unsigned int, unsigned int> XmlAutomatonDataManager::readGameOfLifeAutomatonConfig(QString path, QString filename)
{
    // opens the document into document
    QDomDocument document;
    openFileInDocument(path, filename, document);

    // Getting root element
    QDomElement root = document.firstChildElement();
    unsigned int colNb = root.attribute("colNb","0").toUInt();
    unsigned int lineNb = root.attribute("lineNb","0").toUInt();
    unsigned int minDeath = root.attribute("minDeath","0").toUInt();
    unsigned int maxDeath = root.attribute("maxDeath","0").toUInt();

    return std::make_tuple(colNb, lineNb, minDeath, maxDeath);
}

void XmlAutomatonDataManager::writeElementaryAutomatonConfig(unsigned int cellNb, unsigned int stateNb, unsigned int ruleNb, QString path, QString filename)
{
    // Creates a document to write XML
    QDomDocument document;
    document.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"utf-8\"");

    // Making the root element of state
    QDomElement root = document.createElement("parameters");
    root.setAttribute("cellNb", cellNb);
    root.setAttribute("stateNb", stateNb);
    root.setAttribute("ruleNb", ruleNb);

    // Adding the root element to the docuemnt
    document.appendChild(root);

    // Write to file
    writeDocumentInFile(path,filename,document);
}

std::tuple<unsigned int, unsigned int, unsigned int> XmlAutomatonDataManager::readElementaryAutomatonConfig(QString path, QString filename)
{
    // opens the document into document
    QDomDocument document;
    openFileInDocument(path, filename, document);

    // Getting root element
    QDomElement root = document.firstChildElement();
    unsigned int cellNb = root.attribute("cellNb","0").toUInt();
    unsigned int stateNb = root.attribute("stateNb","0").toUInt();
    unsigned int ruleNb = root.attribute("ruleNb","0").toUInt();

    return std::make_tuple(cellNb, stateNb, ruleNb);
}

/**
 * writeDocumentInFile method implementation.
 *
 */
void XmlAutomatonDataManager::writeDocumentInFile(QString path,QString filename,QDomDocument& document){
    QString fullName = path+"/"+filename;
    QFile file(fullName);
    if(file.exists()){
        file.remove();
    }
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        throw XmlDataManagerException("Cannot open file to write state");
    }
    else{
        QTextStream stream(&file);
        stream << document.toString();
        file.close();
    }
}

/**
 * openFileInDocument method implementation.
 *
 */
void XmlAutomatonDataManager::openFileInDocument(QString path,QString filename,QDomDocument& document){
    QString fullName = path+"/"+filename;;

    // Open a file for reading
    QFile file(fullName);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw XmlDataManagerException("Cannot open file at specified location");
    }
    else {
        // loading
        if(!document.setContent(&file)){
            file.close();
            throw XmlDataManagerException("Cannot set document content");
        }
        file.close();
    }
}
