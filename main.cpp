#include <iostream>
#include "ChessB.h"
#include <iostream>
#include <set>
#include <climits>
using namespace std;
int main() {
    ChessB x("a1");
    x.addNexts();
    x.choosePathK();
    cout<<x.pathK.size();
    while(!x.pathK.empty()){

        cout<<x.pathK.front()->pos;
        x.pathK.pop();
    }
}
