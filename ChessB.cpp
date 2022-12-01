//
// Created by George Welson on 28-Nov-22.
//
#include "ChessB.h"

ChessB::ChessB() {
    string temp="a1";
    for(int i= 0; i<8;i++){
        vector<NNode>v;
        for(int j=0;j<8;j++){
            temp[1] = '1'+i;
            temp[0] = 'a'+j;
            v.push_back(NNode(temp));
        }
        cb.push_back(v);
    }
}
bool ChessB::isValid(char str[],int s) {
    if(str[0]<'a'||str[0]>'h'||str[1]<'1'||str[1]>'8')
        return false;
    else
        return true;
}
void ChessB::addNexts() {
    for(int i= 0; i<8;i++){//i=7
        for(int j=0;j<8;j++){
            int x=0;
            for (int k=0;k<8;k++){
                char temp[2];
                temp[0]= this->cb[i][j].pos[0] + xMovesK[k];
                temp[1]= this->cb[i][j].pos[1] + yMovesK[k];
                if(!(isValid(temp)))
                    continue;
                else {
                    this->cb[i][j].nextK[k] = &this->cb[temp[1] - '1'][temp[0] - 'a'];
                    x++;
                }
                if(x>8)
                    break;

            }
            int y=0;
            for (int k=0;k<28;k++){
                char temp[2];
                temp[0]= this->cb[i][j].pos[0] + xMovesB[k];
                temp[1]= this->cb[i][j].pos[1] + yMovesB[k];
                if(!(isValid(temp))) {
                    continue;
                }
                else {
                    this->cb[i][j].nextB[y] = &this->cb[temp[1] - '1'][temp[0] - 'a'];
                    y++;
                }
                if(y>13)
                    break;
            }

        }
    }


}