#include "Node.h"
using namespace std;
Node::Node(int pData,Node* pNext){
    data=pData;
    next=pNext;
}
int Node::getData(){
    return data;
}
void Node::setData(int pData){
    data=pData;
}
Node* Node::getNext(){
    return next;
}
void Node::setNext(Node* pNext){
    next=pNext;
}