//
// Created by George Welson on 28-Nov-22.
//
#include "Node.h"
/*
 this function initialize the nexts pointers of the node to null
 */
Node::Node(string name): pos(name), visited(false){
    for(int i=0;i<8;i++)
        this->nextK[i]=NULL;
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
}


ostream & operator<< (ostream & out, const Node & aNode)
{
    aNode.display(out);
    return out;
}
