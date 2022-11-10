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
void KnightTree::addNodes() {//if level =b create level b+1
    ++level;
    size+=pow(8,level);
    NodePointer ptr=NULL;
    for(int i=0;i<8;i++){//b3 NULL c2
        char temp[2];
        temp[0]=this->Original->data[0]+this->xMoves[i];
        temp[1]=this->Original->data[1]+this->yMoves[i];
        if(temp[0]<'a'||temp[0]>'h'||temp[1]<'0'||temp[1]>'8')
            continue;
        string str(temp);
        this->Original->next[i]=new Node(temp);  //b4 --> d5
    }// b4 c6 NULL f7 NULL
    for(int i=0;i<8;i++){
        bool escape=true;
        for(int k=i;k<8;k++){
            if(this->Original->next[k]!=NULL) {
                escape = false;
                break;
            }
        }
        if(escape==true)break;
        while(this->Original->next[i]==NULL){
            for(int j=i;j<7;j++){
                this->Original->next[j] = this->Original->next[j + 1];
            }
        }
    }
}

ostream &operator<<(ostream &out, const KnightTree &aTree) {
    out<<"Starting Position: "<<aTree.Original<<endl;
    out<<"Level 1 Nodes: "<<endl;
    for(int i=0;i<8;i++){
        out<<"Node "<<i+1<<"is "<<aTree.Original->next[i]<<endl;
    }
}
