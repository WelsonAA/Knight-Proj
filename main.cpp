#include <iostream>
#include "ChessB.h"
#include <iostream>
#include <set>
#include <climits>
using namespace std;
int main() {
    ChessB x("a1", "a8");
    x.addNexts();
    x.putPawn("h4");
    x.addPathK(x.dest, 0);
    x.choosePathK();
    while(!x.pathK.empty()){
        cout<<x.pathK.front()->pos;
        x.pathK.pop();
    }
}
