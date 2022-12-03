//
// Created by George Welson on 28-Nov-22.
//

#ifndef KNIGHT_PROJ_CHESSB_H
#define KNIGHT_PROJ_CHESSB_H
#include <vector>
#include "Node.h"
#define a 0
#define b 1
#define c 2
#define d 3
#define e 4
#define f 5
#define g 6
#define h 7
using namespace std;
class ChessB{
public:
    vector<vector<Node>> cb;
    string src;
    string dest;
    ChessB(string src,string dest);
    bool isValid(char str[],int s=2);
    void addNexts();
    bool BFS();
};
#endif