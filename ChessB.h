//
// Created by George Welson on 28-Nov-22.
//

#ifndef KNIGHT_PROJ_CHESSB_H
#define KNIGHT_PROJ_CHESSB_H
#include <vector>
#include "NNode.h"
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
    vector<vector<NNode>> cb;
    ChessB();
    bool isValid(char str[],int s=2);
    void addNexts();
};
#endif