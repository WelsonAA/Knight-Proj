#include <iostream>
#include "KnightTree.h"
using namespace std;
int main() {
    Node n1("b4");
    Node n2("c5");
    NodePointer n3=&n2;
    n1.next[0]=n3;
    cout<<*(n1.next[0]);
    KnightTree k1(n1.data);
    k1.addNodes();
    cout<<*(k1.Original->next[0]);
}
