//
// Created by George Welson on 28-Nov-22.
//
#include "ChessB.h"

ChessB::ChessB() {
    for(int i= 0; i<8;i++){
        for(int j=0;j<8;j++){
            this->cb[i][j].pos[1] = '1'+i;
            this->cb[i][j].pos[0] = 'a'+j;
        }
    }
}

void ChessB::addNexts() {
    for(int i= 0; i<8;i++){
        for(int j=0;j<8;j++){
            for (int k=0;k<8;k++){
                this->cb[i][j].next[k] = &this->cb[(int)(cb[i][j].pos[1]-'1'+yMoves[k])][(int)(cb[i][j].pos[0]-'a'+xMoves[k])];
            }
        }
    }
    for(int i=0;i<8;i++) {//b3 NULL c2
        char temp[2];
        temp[0] = this->pos[0] + xMoves[i];
        temp[1] = this->pos[1] + yMoves[i];
        if (temp[0] < 'a' || temp[0] > 'h' || temp[1] < '1' || temp[1] > '8'
            continue;
        string str(temp);
        this->next[i] = new NNode(temp);  //b4 --> d5
    }
}