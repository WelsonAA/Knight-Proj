//
// Created by George Welson on 28-Nov-22.
//
#include "Node.h"
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
Node::Node(string name): pos(name), visited(false),deg(0),corner(false),edge(false){
    for(int i=0;i<8;i++)
        this->nextK[i]=NULL;
    if(this->pos=="a1"||this->pos=="a8"||this->pos=="h1"||this->pos=="h8")
        this->corner=true;
    if(check_substring("a",(this->pos))!=-1||check_substring("h",(this->pos))!=-1||check_substring("1",(this->pos))!=-1||check_substring("8",(this->pos))!=-1)
        this->edge=true;
}
Node* Node::getLowestNext() {
    int min =10;
    Node* lowestNext=NULL;
    Node* tmp= NULL;
    int i;
    for(i=0;i<8;i++){
        tmp=this->nextK[i];
        if(tmp == NULL)
            continue;
        else if((tmp->corner==true)&& (tmp->visited != true)){
            return tmp;
        }
        else if((tmp->edge==true)&& (tmp->visited != true))
            return tmp;
        if ((tmp->deg < min) && (tmp->visited != true)) {
            min = tmp->deg;
            lowestNext = tmp;
        }
    }

    return lowestNext;
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


ostream & operator<< (ostream & out, const Node & aNode)
{
    aNode.display(out);
    return out;
}
