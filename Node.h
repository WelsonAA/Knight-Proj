//
// Created by George Welson on 28-Nov-22.
//

#ifndef KNIGHT_PROJ_NODE_H
#define KNIGHT_PROJ_NODE_H

#include <iostream>
#include <string>
#include <list>
using namespace std;
const int xMovesK[] = {2, 1,-1,-2,-2,-1, 1, 2};
const int yMovesK[] = {1, 2, 2, 1,-1,-2,-2,-1};


class Node{
public:
    typedef Node* NodePointer;
    bool visited;
    string pos;
    //int distanceToTargetK;
    NodePointer nextK[8];
    Node(string name);
    Node();
    void display(ostream & out) const;


};
ostream & operator<< (ostream & out, const Node & aNode);
#endif //KNIGHT_PROJ_NODE_H
