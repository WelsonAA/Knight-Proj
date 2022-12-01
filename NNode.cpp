//
// Created by George Welson on 28-Nov-22.
//
#include "NNode.h"
NNode::NNode(string name):pos(name),visited(false){
    for(int i=0;i<8;i++)
        this->nextK[i]=NULL;
    for(int i=0;i<13;i++)
        this->nextK[i]=NULL;
}
NNode::NNode(){

}

void NNode::display(ostream &out) const {
    out<<"Node Position: "<<this->pos<<endl;
    out<<"Next Nodes for Knight:\n";
    for(int i=0;i<8;i++){
        if(this->nextK[i] == NULL)
            continue;
        else
            out << this->nextK[i]->pos << endl;
    }
    out<<"Next Nodes for Bishop:\n";
    for(int i=0;i<13;i++){
        if(this->nextB[i] == NULL)
            continue;
        else
            out << this->nextB[i]->pos << endl;
    }
}


ostream & operator<< (ostream & out, const NNode & aNode)
{
    aNode.display(out);
    return out;
}