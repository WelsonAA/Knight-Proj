//
// Created by George Welson on 28-Nov-22.
//

#ifndef KNIGHT_PROJ_NNODE_H
#define KNIGHT_PROJ_NNODE_H

#include <iostream>
#include <string>

using namespace std;
const int xMovesK[] = {2, 1, -1, -2, -2, -1, 1, 2 };
const int yMovesK[] = {1, 2, 2, 1, -1, -2, -2, -1 };
const int xMovesB[] = {1,2,3,4,5,6,7,-1,-2,-3,-4,-5,-6,-7,1,2,3,4,5,6,7,-1,-2,-3,-4,-5,-6,-7};
const int yMovesB[] = {1,2,3,4,5,6,7,-1,-2,-3,-4,-5,-6,-7,-1,-2,-3,-4,-5,-6,-7,1,2,3,4,5,6,7};
class NNode{
    typedef NNode* NodePointer;
public:
   bool visited;
   string pos;
   NodePointer nextK[8];
   NodePointer nextB[13];
   //void defNext();
   NNode(string name);

   NNode();
   void display(ostream & out) const;
};
ostream & operator<< (ostream & out, const NNode & aQueue);
#endif //KNIGHT_PROJ_NNODE_H
