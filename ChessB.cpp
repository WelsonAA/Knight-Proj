//
// Created by George Welson on 28-Nov-22.
//
#include "ChessB.h"


/*
 * 1- This is the constructor of the chess game which builds the 8 x 8 chess board with the nodes
 * 2- A node represent a square in the board e.g. : a1 , h8 , etc.
 * 3- A vector is used to insert all nodes into it thus implementing the idea of "Graph"
 *   which makes it easy to traverse through the board
 * */
ChessB::ChessB(){

}
ChessB::ChessB(string src)
{
    string temp="a1";
    for(int i= 0; i<8;i++){
        vector<Node>v;
        for(int j=0;j<8;j++){
            temp[1] = '1'+i;
            temp[0] = 'a'+j;
            Node k(temp);
            v.push_back(k);
        }
        cb.push_back(v);
    }
    this->src=&this->cb[src[1] - '1'][src[0] - 'a'];
    this->src->visited=true;
    this->current=this->src;
    this->pathK.push(this->current);
}

/*
 4-This function is implemented to avoid the chess pieces used (knight, pawn, bishop) to go
 out of the chess board (A chess piece can't go beyond A & H, and 1 & 8)
 */

bool ChessB::isValid(string str) {
    if(str[0]<'a'||str[0]>'h'||str[1]<'1'||str[1]>'8')
        return false;
    else
        return true;
}

/*
 5-This function is used to create the nodes available for the chess pieces used (knight, pawn, bishop)
 to move to, it also implements the isValid function to make sure that the pieces stays in board
*/

void ChessB::addNexts() {
    for (int i = 0; i < 8; i++) {//i=7
        for (int j = 0; j < 8; j++) {
            addKnight(i, j);
        }
    }
}


/*
 addKnight is a function used to create the nodes available for the knights to move to
  it's implemented using the xMovesK and yMovesK which is the positions the knight can move to
 */
void ChessB::addKnight(int i, int j) {
    int y = 0;
    for (int k = 0; k < 8; k++) {
        char temp[2];
        temp[0] = this->cb[i][j].pos[0] + xMovesK[k];
        temp[1] = this->cb[i][j].pos[1] + yMovesK[k];
        if (!(isValid(temp)))
            continue;
        else {
            this->cb[i][j].nextK[y] = &this->cb[temp[1] - '1'][temp[0] - 'a'];
            y++;
        }
    }
}
/*
 addPawn is a function used to create the nodes available for the pawn to move to
 it's implemented using the xMovesP and yMovesP which is the positions the pawn can move to
 */

/*
 addBishop is a function used to create the nodes available for the bishop to move to,
 it's implemented using the xMovesB and yMovesB which is the positions the bishop can move to
 */








//void ChessB::addPathK(Node *crt, int steps) {
//    if (steps > 6)
//        return;
//    else if ((crt->distanceToTargetK < steps) && (crt->distanceToTargetK != -1))
//        return;
//    else {
//        crt->distanceToTargetK = steps;
//        for (int i = 0; ((i < 8) && (crt->nextK[i] != nullptr)); i++) {
//            addPathK(crt->nextK[i], steps + 1);
//        }
//    }
//}

void ChessB::choosePathK() {
    Node* tmp= nullptr;
    for(int i=0;i<64;i++){
        for(int j=0;j<8;j++){
            tmp = this->current->nextK[j];
            if (tmp == nullptr)
                break;
            else if (tmp->visited == true)
                continue;
            else {
                this->current = tmp;
                this->current->visited = true;
                this->pathK.push(tmp);
                break;
            }
        }
    }
}