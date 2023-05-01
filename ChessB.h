//
// Created by George Welson on 28-Nov-22.
//

#ifndef KNIGHT_PROJ_CHESSB_H
#define KNIGHT_PROJ_CHESSB_H
#include <vector>
#include "Node.h"
#include <queue>
using namespace std;
class ChessB{
public:
    vector<vector<Node>> cb;
    Node* src;
    Node* current;
    queue<Node*> pathK;
    ChessB(string src);
    bool isValid(string str);//Makes sure position of pieces is valid
    void addNexts();//creates pieces Nodes
    void addKnight(int i, int j);//creates Knight nodes
    void choosePathK();
};
#endif
