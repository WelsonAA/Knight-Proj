//
// Created by George Welson on 08-Nov-22.
//
#include "KnightTree.h"
using namespace std;
KnightTree::KnightTree(string data) {
    this->Original=new(nothrow) Node(data);
    size=1;
}
void KnightTree::addNodes(Node parent) {
    for(int i=0;i<8;i++){
        parent.next[i]+i=parent.getData()[0]+this->xMoves[i];
        parent.next[i]->data=parent.data[1]+this->yMoves[i];
    }
}
