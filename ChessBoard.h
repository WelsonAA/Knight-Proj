//
// Created by George Welson on 08-Nov-22.
//

#ifndef KNIGHT_PROJ_CHESSBOARD_H
#define KNIGHT_PROJ_CHESSBOARD_H
#include <iostream>
#include <math.h>
#include "Node.h"
#include <vector>
#include <map>
#define a 0
#define b 1
#define c 2
#define d 3
#define e 4
#define f 5
#define g 6
#define h 7
using namespace std;
class ChessBoard{

public:
    ChessBoard(string data);
    NodePointer Original;
    vector<vector<int>>cb;
    pair<char,char>src;
    pair<char,char>target;
    bool boardVisited[8][8]= {0};
    int distance[8][8]={0};
    constexpr static const int xMoves[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    constexpr static const int yMoves[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    void addNodes(Node parent);
    void addNodes();
private:
    int size;
    int level;

};
ostream& operator<<(ostream& out, const ChessBoard& aTree);
#endif //KNIGHT_PROJ_CHESSBOARD_H
