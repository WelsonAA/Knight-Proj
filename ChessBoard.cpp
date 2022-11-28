//
// Created by George Welson on 08-Nov-22.
//
#include "ChessBoard.h"
using namespace std;
ChessBoard::ChessBoard(string data) {
    this->Original=new(nothrow) Node(data);
    this->src.first=data[0];
    this->src.second=data[1];
    size=1;
    level=0;
    cb.at(0).at(0);
}
void ChessBoard::addNodes() {//if level =b create level b+1
    ++level;
    size+=pow(8,level);
    for(int i=0;i<8;i++){//b3 NULL c2
        char temp[2];
        temp[0]=this->Original->data[0]+this->xMoves[i];
        temp[1]=this->Original->data[1]+this->yMoves[i];
        if(temp[0]<'a'||temp[0]>'h'||temp[1]<'1'||temp[1]>'8')
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
    for(int i=1;i<8;i++){
        if(this->Original->next[i]==this->Original->next[i-1]){
            for(int j=i;j<8;j++) {
                this->Original->next[j] = NULL;
            }
            break;
        }
    }
}

ostream &operator<<(ostream &out, const ChessBoard &aTree) {
    out<<"Starting Position: "<<aTree.Original<<endl;
    out<<"Level 1 Nodes: "<<endl;
    for(int i=0;i<8;i++){
        out<<"Node "<<i+1<<"is "<<aTree.Original->next[i]<<endl;
    }
}
