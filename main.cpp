#include <iostream>
#include "ChessB.h"
using namespace std;
int main() {
    ChessB x("f6","f2");
    x.addNexts();
    x.addPath(x.dest,0);
    cout<<"Enter a position on the chess board\n";
    string str;
    cin>>str;
    x.printNode(str);
}
