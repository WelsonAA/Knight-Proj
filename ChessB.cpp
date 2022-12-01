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
            /*string temp="a1";
            cb.pu
            cb[i][j]=new NNode();
            */
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
            for (int k=0;k<8;k++){
                char temp[2];
                temp[0]= this->cb[i][j].pos[0] + xMovesK[k];
                temp[1]= this->cb[i][j].pos[1] + yMovesK[k];
                if(!(isValid(temp)))
                    continue;
                else
                    this->cb[i][j].nextK[k] = &this->cb[temp[1] - '1'][temp[0] - 'a'];

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
            /*for(int l=0;l<8;l++){
                bool escape=true;
                for(int m=l;m<8;m++){
                    if(this->cb[i][j].nextK[m]!=NULL) {
                        escape = false;
                        break;
                    }
                }
                if(escape==true)
                    break;
                while(this->cb[i][j].nextK[i]==NULL){
                    for(int m=l;m<7;m++){
                        this->cb[i][j].nextK[m] = this->cb[i][j].nextK[m + 1];
                    }
                }
            }*/
            /*for(int l=1;l<8;l++){
                if(this->cb[i][j].nextK[l]==this->cb[i][j].nextK[l-1]){
                    for(int m=l;m<8;m++) {
                        this->cb[i][j].nextK[m] = NULL;
                    }
                    break;
                }
            }*/
        }
    }


}