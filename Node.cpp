//
// Created by George Welson on 28-Nov-22.
//
#include "Node.h"

#include <cstdlib>
/*
 this function initialize the nexts pointers of the node to null
 */
int check_substring(string str1, string str2)
{   int i,j;
    int len1 = str1.length();
    int len2 = str2.length();

    for (i = 0; i <= len2 - len1; i++) {
        for (j = 0; j < len1; j++)
            if (str2[i + j] != str1[j])
                break;

        if (j == len1)
            return i;
    }

    return -1;
}
int min(int a,int b,int c,int d){
    return min(min(min(a,b),c),d);
}
Node::Node(string name): pos(name), visited(false),deg(0),corner(false),edge(false),distToEdge(100){
    for(int i=0;i<8;i++)
        this->nextK[i]=NULL;
    if(this->pos=="a1"||this->pos=="a8"||this->pos=="h1"||this->pos=="h8") {
        this->corner = true;
        this->distToEdge=0;
    }
    if(check_substring("a",(this->pos))!=-1||check_substring("h",(this->pos))!=-1||check_substring("1",(this->pos))!=-1||check_substring("8",(this->pos))!=-1) {
        this->edge = true;
        this->distToEdge=0;
    }
    if(this->distToEdge==100){
        this->distToEdge= min(abs(((char)this->pos[0])-'a'),abs(((char)this->pos[0])-'h'),abs(((char)this->pos[1])-'1'),abs(((char)this->pos[1])-'8'));
    }
}
Node* Node::getLowestNext() {
    int min_deg=9;
    int min_deg_idx=-1;
    int start=rand()%8;
    for(int count = 0; count < 8; ++count){

        int i = (start + count)%8;
        if(this->nextK[i]==NULL)
            continue;
        if(this->nextK[i]->visited == false){
            if (this->nextK[i]->corner == true) {
                return this->nextK[i];
            }
            if (this->nextK[i]->deg < min_deg) {
                min_deg = this->nextK[i]->deg;
                min_deg_idx = i;
            }
        }
    }
    if(min_deg_idx==-1){
        return NULL;
    }
    return this->nextK[min_deg_idx];

    /*int min =10;
    Node* lowestNext=NULL;
    Node* tmp= NULL;
    int i;
    for(i=0;i<8;i++){
        tmp=this->nextK[i];
        if(tmp == NULL)
            break;
        else if((tmp->corner==true)&& (tmp->visited != true)){
            return tmp;
        }
        if(tmp->visited != true) {
            if (tmp->deg < min|| tmp->edge == true) {
                min = tmp->deg;
                lowestNext = tmp;
            }
        }
    }

    return lowestNext;*/
}
void Node::visit() {
    this->visited=true;
    Node* tmp= this->nextK[0];
    int i;
    for(i=0;(tmp!= NULL)&&(i<8);i++){
        tmp->deg--;
        tmp=this->nextK[i+1];
    }
}


Node::Node(){

}
/*
This function formats the printing of the nodes
 */
void Node::display(ostream &out) const {
    out<<"Node Position: "<<this->pos<<endl;
    out<<"Next Nodes for Knight:\n";
    for(int i=0;i<8;i++){
        if(this->nextK[i] == NULL)
            continue;
        else
            out << this->nextK[i]->pos << endl;
    }
}

bool Node::isNeighbour(Node *n) {
    for(int i=0;i<8;i++){
        if(this->nextK[i]==NULL)
            break;
        if(n->pos==this->nextK[i]->pos)
            return true;
    }
    return false;
}


ostream & operator<< (ostream & out, const Node & aNode)
{
    aNode.display(out);
    return out;
}
