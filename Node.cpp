//
// Created by George Welson on 28-Nov-22.
//
#include "Node.h"
/*
 this function initialize the nexts pointers of the node to null
 */
Node::Node(string name): pos(name), safe(true),visited(false), distanceToTargetK(-1),distanceToTargetB(-1){
    for(int i=0;i<8;i++)
        this->nextK[i]=NULL;
    for(int i=0;i<13;i++)
        this->nextB[i]=NULL;
    for(int i=0;i<2;i++)
        this->nextP[i]=NULL;
    this->getColour();
}



Node::Node(){

}
/*
This function formats the printing of the nodes
 */
void Node::display(ostream &out) const {
    out<<"Node Position: "<<this->pos<<endl;
    out<<"Next Nodes for Knight:\n";
    for(int i=0;i<8;i++){
        if(this->nextK[i] == NULL)
            continue;
        else
            out << this->nextK[i]->pos << endl;
    }
    out << "Distance to Target for a Knight:\n" << this->distanceToTargetK << endl;
    out<<"Next Nodes for White Bishop:\n";
    for(int i=0;i<13;i++){
        if(this->nextB[i] == NULL)
            continue;
        else
            out << this->nextB[i]->pos << endl;
    }
    out<<"Next Nodes for Black Pawn1:\n";
    for(int i=0;i<2;i++){
        if(this->nextP[i] == NULL)
            continue;
        else
            out << this->nextP [i]->pos << endl;
    }
}

void Node::getColour() {
    if (pos[0] == 'a' || pos[0] == 'c' || pos[0] == 'e' || pos[0] == 'g')
    {
        if (pos[1] == '1' || pos[1] == '3' || pos[1] == '5' || pos[1] == '7')
            colour=B;
        else
            colour=W;
    }
    else {
        if (pos[1] == '1' || pos[1] == '3' || pos[1] == '5' || pos[1] == '7')
            colour=W;
        else
            colour=B;
    }
}


ostream & operator<< (ostream & out, const Node & aNode)
{
    aNode.display(out);
    return out;
}
