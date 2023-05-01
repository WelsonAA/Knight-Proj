#include <iostream>
#include "ChessB.h"
#include <time.h>
using namespace std;
int main() {
    srand(time(NULL));
    while(true){
        ChessB x("c5");
        x.addNexts();
        x.choosePathK();
        cout << x.pathK.size() << endl;
        if (x.pathK.size() == 64  && x.pathK.front()->isNeighbour(x.pathK.back()) == true) {
            while (!x.pathK.empty()) {
                cout << x.pathK.front()->pos << endl;
                x.pathK.pop();
            }
            break;
        }
    }
}
