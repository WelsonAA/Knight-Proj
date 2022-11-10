#include <iostream>
#include "KnightTree.h"
using namespace std;
int main() {
    KnightTree k1("d5");
    k1.addNodes(*(k1.Original));
    for(int i=0;i<8;i++){
        cout<<k1.Original->getNext()+i<<endl;
    }
}
