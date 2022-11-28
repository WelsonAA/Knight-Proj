//
// Created by George Welson on 28-Nov-22.
//
#include "NNode.h"
NNode::NNode(string name):pos(name),visited(false){
    for(int i=0;i<8;i++)
        this->next[i]=NULL;
    //this->defNext();
}
NNode::NNode(){

}

void NNode::display(ostream &out) const {
    out<<"Node Position: "<<this->pos<<endl;
    out<<"Next Nodes:\n";
    for(int i=0;i<8;i++){
        if(this->next[i]==NULL)
            continue;
        else
            out<<this->next[i]->pos<<endl;
    }
}

ostream & operator<< (ostream & out, const NNode & aNode)
{
    aNode.display(out);
    return out;
}
/*void NNode::defNext(){
     for(int i=0;i<8;i++) {//b3 NULL c2
         char temp[2];
         temp[0] = this->pos[0] + xMoves[i];
         temp[1] = this->pos[1] + yMoves[i];
         if (temp[0] < 'a' || temp[0] > 'h' || temp[1] < '1' || temp[1] > '8')
             continue;
         string str(temp);
         this->next[i] = new NNode(temp);  //b4 --> d5
     }
}*/