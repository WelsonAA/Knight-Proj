//
// Created by George Welson on 28-Nov-22.
//

#ifndef KNIGHT_PROJ_NNODE_H
#define KNIGHT_PROJ_NNODE_H


#include <string>

using namespace std;
const int xMoves[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
const int yMoves[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
class NNode{
    typedef NNode* NodePointer;
public:
   bool visited;
   string pos;
   NodePointer next[8];
   //void defNext();
   NNode(string name);
};
#endif //KNIGHT_PROJ_NNODE_H
