//
// Created by George Welson on 28-Nov-22.
//
#include "ChessB.h"

#include <Queue>
/*
 * 1- This is the constructor of the chess game which builds the 8 x 8 chess board with the nodes
 * 2- A node represent a square in the board e.g. : a1 , h8 , etc.
 * 3- A vector is used to insert all nodes into it thus implementing the idea of "Graph"
 *    which makes it easy to traverse through the board
 * */

ChessB::ChessB(string src, string dest): src(src), dest(dest)
{
    string temp="a1";
    for(int i= 0; i<8;i++){
        vector<Node>v;
        for(int j=0;j<8;j++){
            temp[1] = '1'+i;
            temp[0] = 'a'+j;
            v.push_back(Node(temp));
        }
        cb.push_back(v);
    }
}
bool ChessB::BFS(){

}
/*
 4-This function is implemented to avoid the chess pieces used (knight, pawn, bishop) to go
 out of the chess board (A chess piece can't go beyond A & H, and 1 & 8)
 */

bool ChessB::isValid(char str[],int s) {
    if(str[0]<'a'||str[0]>'h'||str[1]<'1'||str[1]>'8')
        return false;
    else
        return true;
}

/*
 5-This function is used to create the nodes available for the knight to move to,
   it was also implemented using the isValid function to make sure that the knight
   stays in board
             */

void ChessB::addNexts() {
    for(int i= 0; i<8;i++){//i=7
        for(int j=0;j<8;j++){
            for (int k=0;k<8;k++){
                char temp[2];
                temp[0]= this->cb[i][j].pos[0] + xMovesK[k];
                temp[1]= this->cb[i][j].pos[1] + yMovesK[k];
                if(!(isValid(temp)))
                    continue;
                else {
                    this->cb[i][j].nextK[k] = &this->cb[temp[1] - '1'][temp[0] - 'a'];
                }
            }
            int y=0;
            for (int k=0;k<28;k++){
                char temp[2];
                temp[0]= this->cb[i][j].pos[0] + xMovesB[k];
                temp[1]= this->cb[i][j].pos[1] + yMovesB[k];
                if(!(isValid(temp))) {
                    continue;
                }
                else {
                    this->cb[i][j].nextB[y] = &this->cb[temp[1] - '1'][temp[0] - 'a'];
                    y++;
                }
                if(y>13)
                    break;
            }
            for(int k=0;k<3;k++){
                char temp[2];
                temp[0]= this->cb[i][j].pos[0] + xMovesP[k];
                temp[1]= this->cb[i][j].pos[1] + yMovesP[k];
                if(!(isValid(temp)))
                    continue;
                else {
                    this->cb[i][j].nextP[k] = &this->cb[temp[1] - '1'][temp[0] - 'a'];
                }
            }
        }
    }


}

/*
 * 1- Bfs Algo to traverse the graph
 * */

void ChessB::BFS()
{
    // Mark all the vertices as not visited
    vector<bool> visited;
    visited.resize(V,false);

    // Create a queue for BFS
    queue<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push()

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (auto adjecent: adj[s])
        {
            if (!visited[adjecent])
            {
                visited[adjecent] = true;
                queue.push_back(adjecent);
            }
        }
    }
}
