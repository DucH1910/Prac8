#include "LinkedList.h"
#include <iostream>
#include <limits>
using namespace std;
LinkedList::LinkedList(){
    head=null;
}
LinkedList::LinkedList(int* array, int size){
    if(size>0)
        for(int i=0;i<size;i++)
            addEnd(array[i]);
    else
        head= null;
}
void LinkedList::addFront(int newItem){
    Node* nodePointer= new Node(newItem,head);
    head = nodePointer;
}
void LinkedList::addEnd(int newItem){
    Node* nodePointer= new Node(newItem,null);
    Node* iPointer=head;
    if(head==null)
        addFront(newItem);
    else{
        while (iPointer->getNext()!=null){
            iPointer=iPointer->getNext();
        }
        iPointer->setNext(nodePointer);
    }
}
void LinkedList::addAtPosition(int position, int newItem){
    if(position<=1)
        addFront(newItem);
    else if(head==null)
        addFront(newItem);
    else{
        Node* iPointer=head;
        for(int i=2;i<position;i++){
            iPointer=iPointer->getNext();
            if(iPointer->getNext()==null)
                break;
        }
        Node* nodePointer = new Node(newItem,iPointer->getNext());
        iPointer->setNext(nodePointer);
    }
}
int LinkedList::search(int item){
    if (head==null){
        cout<<"0"<<" ";
        return 0;
    }else {
        Node* iPointer=head;
        int position=1;
        while(iPointer!=null){
            if(iPointer->getData()==item){
                cout<<position<<" ";
                return position;
            }else{
                position++;
                iPointer=iPointer->getNext();
            }
        }
        cout<<"0"<<" ";
        return 0;
    }
}
void LinkedList::deleteFront(){
    if(head!=null){
        Node* iPointer=head;
        head=head->getNext();
        delete iPointer;
    }
}
void LinkedList::deleteEnd(){
    if(head!=null){
        if(head->getNext()==null)
            head=null;
        else{
            Node* iPointer=head->getNext();
            Node* jPointer=iPointer->getNext();
            if(jPointer==null)
                head->setNext(null);
            else{
                while(jPointer->getNext()!=null){
                    iPointer=jPointer;
                    jPointer=jPointer->getNext();
                }
                iPointer->setNext(null);
                delete jPointer;
            }
        }
    }
}
void LinkedList::deletePosition(int position){
    if(position<1||head==null){
        cout<<"outside range";
        return;
    }
    Node* iPointer=head;
    Node* jPointer=null;
    for(int i=1;i<position;i++){
        if(iPointer->getNext()!=null){
            jPointer=iPointer;
            iPointer=iPointer->getNext();
        }else{
            cout<<"outside range";
            return;
        }
    }
    if(iPointer==head)
        deleteFront();
    else{
        jPointer->setNext(iPointer->getNext());
        delete iPointer;
    }
}
int LinkedList::getItem(int position){
    if(position<1||head==null){
        cout<<numeric_limits<int>::max()<<" ";
        return numeric_limits<int>::max();
    }
    Node* iPointer=head;
    for(int i=1;i<position++){
        if(iPointer->getNext()!=null){
            iPointer=iPointer->getNext();
        }else{
            cout<<numeric_limits<int>::max()<<" ";
            return numeric_limits<int>::max();
        }
    }
    cout<<iPointer->getData()<<" ";
    return iPointer->getData();
}
void LinkedList::printItem(){
    if(head!=null){
        Node* iPointer=head;
        while(iPointer!=null){
            cout<<iPointer->getData()<<" ";
            iPointer=iPointer->getNext();
        }
    }
}
LinkedList::~LinkedList(){
    if(head!=null){
        Node* iPointer=head;
        while(iPointer!=null){
            head=iPointer;
            iPointer=iPointer->getNext();
            delete head;
        }
    }
}