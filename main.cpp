#include <iostream>
#include "ChessB.h"
#include <iostream>
#include <set>
#include <climits>
using namespace std;
int main() {
    ChessB x("a1", "c7");
    x.addNexts();
    x.putPawn("h4");
    x.addPathB(x.dest, 0);
    x.choosePathK();
    x.choosePathB();
    while(!x.pathK.empty()){
        cout<<x.pathK.front()->pos;
        x.pathK.pop();
    }
}
