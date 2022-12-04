//
// Created by George Welson on 28-Nov-22.
//
#include "Node.h"
/*
 this function initialize the nodes to null
 */
Node::Node(string name): pos(name), visited(false){
    for(int i=0;i<8;i++)
        this->nextK[i]=NULL;
    for(int i=0;i<13;i++)
        this->nextB[i]=NULL;
    for(int i=0;i<2;i++)
        this->nextP[i]=NULL;
}
Node::Node(){

}
/*


 */
void Node::display(ostream &out) const {
    out<<"Node Position: "<<this->pos<<endl;
    out<<"Next Nodes for White Knight:\n";
    for(int i=0;i<8;i++){
        if(this->nextK[i] == NULL)
            continue;
        else
            out << this->nextK[i]->pos << endl;
    }
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


ostream & operator<< (ostream & out, const Node & aNode)
{
    aNode.display(out);
    return out;
}