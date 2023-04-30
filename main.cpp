#include <iostream>
#include "ChessB.h"
using namespace std;
int main() {
    ChessB x("b4");
    x.addNexts();
    x.choosePathK();
    cout<<x.pathK.size();
    while(!x.pathK.empty()){
        cout<<x.pathK.front()->pos<<endl;
        x.pathK.pop();
    }
}
