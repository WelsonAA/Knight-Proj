//
// Created by George Welson on 08-Nov-22.
//
#include "KnightTree.h"
using namespace std;
KnightTree::KnightTree(string data) {
    this->Original=new(nothrow) Node(data);
    size=1;
    level=1;
}
void KnightTree::addNodes(Node parent) {
    ++level;
    size+=8;
    for(int i=0;i<8;i++){
        parent.next[i]=(new Node(to_string(parent.data[0]+this->xMoves[i])));
        parent.next[i]=(new Node(to_string(parent.data[1]+this->yMoves[i])));
    }

}

ostream &operator<<(ostream &out, const KnightTree &aTree) {
    out<<"Starting Position: "<<aTree.Original<<endl;
    out<<"Level 1 Nodes: "<<endl;
    for(int i=0;i<8;i++){
        out<<"Node "<<i+1<<"is "<<aTree.Original->next[i]<<endl;
    }
}
