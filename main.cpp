#include <iostream>
#include "ChessB.h"
#include <time.h>
using namespace std;
int main() {
    srand(time(NULL));
    while(true){
        ChessB x("f2");
        x.addNexts();
        x.choosePathK();
        cout << x.cnt << endl;
        if (x.cnt == 64  && x.pathK[0]->isNeighbour(x.pathK[63]) == true) {
            for(int i=0;i<64;i++){
                cout<<x.pathK[i]->pos<<endl;
            }
            break;
        }
    }
}
