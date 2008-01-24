#ifndef GENERATOR_H
#define GENERATOR_H

#include <QtXml>
#include <QDomDocument>
#include <QDomElement>
#include <QDomNode>
#include <QFile.h>
#include <QDir.h>

#include "entity.h"

class Category;

// the generator itself
class Generator
{
public:
    Generator( QStringList );
    ~Generator();

private:

    static const int NUM = 1;

    int untitled;
    int objectsCount;

    void parseFile( QString );
    void parseEnum( QDomNode );
    void parseNode( QDomNode );
    void parseEdge( QDomNode );
    
    void parseGeneralizations ( Entity*, QDomNode );
    void parseProperties      ( Entity*, QDomNode );
    void parseAssociations    ( Entity*, QDomNode, bool isNode = false );
    //void parseNodeAssociations( Entity*, QDomNode );
    void parseSVG             ( Entity*, QDomNode );
    void parsePorts           ( Node*,   QDomNode );
    void parseLabels          ( Entity*, QDomNode );
    void parseEdgeGraphics    ( Edge*,   QDomNode );

    void genEnums();
    void genSQLScripts();
    void genClasses();
    void genFactory();
    void genRealRepoInfo();
    void genEdgesFunction();

    void propagateAll();
    void propagateProperties( Entity* );
    void propagateAssocs( Edge* );
    void propagateParents( Entity* );
//    void findChildren( Entity*, QString );

    int position( QString );
    
    QDomDocument* doc;

    Entity* find( QString id );
    Edge* findEdge( QString id );

    QList< Entity* > objects; 
    QList< Edge* > edges;

    QList < Category* > categories;

    QMap<QString, QStringList> enumerations;

    QString res;
    QString resources;

    QDir dir;
};

class Category{
public:
    QString name;
    QList<int> objects;
};

#endif
