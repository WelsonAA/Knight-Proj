//
// Created by George Welson on 08-Nov-22.
//
#include <iostream>
#include "Node.h"

using namespace std;
void Node::display() {
    cout<<this;
}

const string &Node::getData() const {
    return data;
}

Node::Node(const string &data) : data(data) {}

void Node::setData(const string &data) {
    Node::data = data;
}


ostream &operator<<(ostream &out, const Node &aNode) {
    out<<aNode.getData()<<endl;
}
