//
// Created by George Welson on 08-Nov-22.
//

#ifndef KNIGHT_PROJ_NODE_H
#define KNIGHT_PROJ_NODE_H
using namespace std;
#include <string>
class Node {
public:
    Node* next[8];
    string data;
public:
    explicit Node(const string &data);
    void display();
    const string &getData() const;
    void setData(const string &data);
};
ostream& operator<<(ostream& out, const Node& aNode);

typedef Node* NodePointer;
#endif //KNIGHT_PROJ_NODE_H
