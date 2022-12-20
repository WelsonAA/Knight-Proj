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
    Node* dest;
    queue<Node*> path;
    ChessB(string src,string dest);
    bool isValid(char str[],int s=2);//Makes sure position of pieces is valid
    void addNexts();//creates pieces Nodes
    void printNode(string str);
    void addKnight(int i, int j);//creates Knight nodes
    void addBishop(int i, int j);//creates Bishop nodes
    void addPawn(int i, int j);//creates Pawn nodes
    void addPath(Node* crt,int steps);
    void choosePath();
    //void setDistance(Node& req):
    bool BFS();
};
#endif