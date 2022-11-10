//
// Created by George Welson on 08-Nov-22.
//
#include "KnightTree.h"
using namespace std;
KnightTree::KnightTree(string data) {
    this->Original=new(nothrow) Node(data);
    size=1;
    level=0;
}
void KnightTree::addNodes() {
    ++level;
    size+=pow(8,level);
    for(int i=0;i<8;i++){
        char temp[2];
        temp[0]=this->Original->data[0]+this->xMoves[i];
        temp[1]=this->Original->data[1]+this->yMoves[i];
        string str(temp);
        this->Original->next[i]=new Node(temp);  //b4 --> d5
    }
}

ostream &operator<<(ostream &out, const KnightTree &aTree) {
    out<<"Starting Position: "<<aTree.Original<<endl;
    out<<"Level 1 Nodes: "<<endl;
    for(int i=0;i<8;i++){
        out<<"Node "<<i+1<<"is "<<aTree.Original->next[i]<<endl;
    }
}
