//
// Created by George Welson on 08-Nov-22.
//

#ifndef KNIGHT_PROJ_KNIGHTTREE_H
#define KNIGHT_PROJ_KNIGHTTREE_H
#include <iostream>
#include "Node.h"
using namespace std;
class KnightTree{

public:
    KnightTree(string data);
    NodePointer Original;
    void addNodes(Node parent);

    constexpr static const int xMoves[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    constexpr static const int yMoves[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
private:
    int size;
    int level;
};
ostream& operator<<(ostream& out, const KnightTree& aTree);
#endif //KNIGHT_PROJ_KNIGHTTREE_H
