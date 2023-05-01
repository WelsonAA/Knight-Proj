#include <iostream>
#include "ChessB.h"
#include <time.h>
using namespace std;
int main() {
    srand(time(0));
    while(true){
        ChessB x("a5");
        x.addNexts();
        x.choosePathK();
        cout << x.pathK.size() << endl;
        if (x.pathK.size() == 64 && x.pathK.front()->isNeighbour(x.pathK.back()) == true) {
            while (!x.pathK.empty()) {
                cout << x.pathK.front()->pos << endl;
                x.pathK.pop();
            }
            break;
        }
    }
}

/*
const int cx[] = {2,2, 1,-1,-2,-2,-1, 1};
const int cy[] = {1,-1, 2, 2, 1,-1,-2,-2};
const int n=8;
bool range(int x, int y)
{
    return ((x >= 0 && y >= 0) && (x < n && y < n));
}

bool isempty(int a[], int x, int y)
{
    return (range(x, y)) && (a[y*n+x] < 0);
}
int degree(int a[], int x, int y)
{
    int count = 0;
    for (int i = 0; i < n; ++i)
        if (isempty(a, (x + cx[i]), (y + cy[i])))
            count++;

    return count;
}

void print(int a[])
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            printf("%d\t",a[j*n+i]);
        printf("\n");
    }
}

bool neighbour(int x, int y, int xx, int yy)
{
    for (int i = 0; i < n; ++i)
        if (((x+cx[i]) == xx)&&((y + cy[i]) == yy))
            return true;

    return false;
}

bool next(int a[], int *x, int *y)
{
    int min_degree_index = -1, c, min_degree = (n+1), nx, ny;
    int start = rand()%n;
    for (int count = 0; count < n; ++count)
    {
        int i = (start + count)%n;
        nx = *x + cx[i];
        ny = *y + cy[i];
        if ((isempty(a, nx, ny))&&(c = degree(a, nx, ny)) < min_degree)
        {
            min_degree_index = i;
            min_degree = c;
        }
    }
    if (min_degree_index == -1)
        return false;
    nx = *x + cx[min_degree_index];
    ny = *y + cy[min_degree_index];
    a[ny*n + nx] = a[(*y)*n + (*x)]+1;
    *x = nx;
    *y = ny;

    return true;
}


int main()
{
    int a[n*n]={-1};
    int x1 = 1;
    int y1 = 1;
    int x = x1, y = y1;
    a[y*n+x] = 1;
    for (int i = 0; i < n*n-1; ++i)
        if (next(a, &x, &y) == 0)
            return 0;
    if (!neighbour(x, y, x1, y1))
        return 0;
    print(a);
    return 1;
}*/