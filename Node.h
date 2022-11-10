//
// Created by George Welson on 08-Nov-22.
//

#ifndef KNIGHT_PROJ_NODE_H
#define KNIGHT_PROJ_NODE_H
using namespace std;
#include <string>
class Node {
public:
    explicit Node(const string &data);

    void display();

    const string &getData() const;

    Node *const *getNext() const;
    Node* next[8];
private:
    string data;

};
ostream& operator<<(ostream& out, const Node& aNode);

Node *const *Node::getNext() const {
    return next;
}

typedef Node* NodePointer;
#endif //KNIGHT_PROJ_NODE_H
