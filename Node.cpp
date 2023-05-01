//
// Created by George Welson on 28-Nov-22.
//
#include "Node.h"

#include <cstdlib>
/*
 this function initialize the nexts pointers of the node to null
 */


Node::Node(string name): pos(name), visited(false),deg(0),corner(false){
    for(int i=0;i<8;i++)
        this->nextK[i]=NULL;
    if(this->pos=="a1"||this->pos=="a8"||this->pos=="h1"||this->pos=="h8") {
        this->corner = true;
    }
}
Node* Node::getLowestNext() {
    int min_deg=9;
    int min_deg_idx=-1;
    int start=rand()%8;
    for(int count = 0; count < 8; ++count){

        int i = (start + count)%8;
        if(this->nextK[i]==NULL)
            continue;
        if(this->nextK[i]->visited == false){
            if (this->nextK[i]->corner == true) {
                return this->nextK[i];
            }
            if (this->nextK[i]->deg < min_deg) {
                min_deg = this->nextK[i]->deg;
                min_deg_idx = i;
            }
        }
    }
    if(min_deg_idx==-1){
        return NULL;
    }
    return this->nextK[min_deg_idx];


}
void Node::visit() {
    this->visited=true;
    Node* tmp= this->nextK[0];
    int i;
    for(i=0;(tmp!= NULL)&&(i<8);i++){
        tmp->deg--;
        tmp=this->nextK[i+1];
    }
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

bool Node::isNeighbour(Node *n) {
    for(int i=0;i<8;i++){
        if(this->nextK[i]==NULL)
            break;
        if(n->pos==this->nextK[i]->pos)
            return true;
    }
    return false;
}


ostream & operator<< (ostream & out, const Node & aNode)
{
    aNode.display(out);
    return out;
}
