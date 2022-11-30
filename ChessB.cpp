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

void ChessB::addNexts() {
    for(int i= 0; i<8;i++){//i=7
        for(int j=0;j<8;j++){
            for (int k=0;k<8;k++){
                char temp[2];
                temp[0]=this->cb[i][j].pos[0]+xMoves[k];
                temp[1]=this->cb[i][j].pos[1]+yMoves[k];
                if(temp[0]<'a'||temp[0]>'h'||temp[1]<'1'||temp[1]>'8')
                    continue;
                else
                    this->cb[i][j].next[k] = &this->cb[temp[1]-'1'][temp[0]-'a'];
            }
            /*for(int l=0;l<8;l++){
                bool escape=true;
                for(int m=l;m<8;m++){
                    if(this->cb[i][j].next[m]!=NULL) {
                        escape = false;
                        break;
                    }
                }
                if(escape==true)
                    break;
                while(this->cb[i][j].next[i]==NULL){
                    for(int m=l;m<7;m++){
                        this->cb[i][j].next[m] = this->cb[i][j].next[m + 1];
                    }
                }
            }*/
            /*for(int l=1;l<8;l++){
                if(this->cb[i][j].next[l]==this->cb[i][j].next[l-1]){
                    for(int m=l;m<8;m++) {
                        this->cb[i][j].next[m] = NULL;
                    }
                    break;
                }
            }*/
        }
    }


}