#include <iostream>
#include "ChessB.h"
using namespace std;
int main() {

    ChessB x("d1","f2");
    x.addNexts();
    cout<<x.cb[1][1];

}
