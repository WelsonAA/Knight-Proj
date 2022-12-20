#include <iostream>
#include "ChessB.h"
using namespace std;
int main() {
    ChessB x("d1","f2");
    x.addNexts();
    x.addPath();
    cout<<"Enter a position on the chess board\n";
    string str;
    cin>>str;
    //cout<<x.cb[0][0];
    x.printNode(str);
}
