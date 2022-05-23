#ifndef NODE_H
#define NODE_H
class Node{
    private:
        int data;
        Node* next;
    public:
        Node(int pData,Node* pNext);
        int getData();
        void setData(int pData);
        Node* getNext();
        void setNext(Node* pNext);
};
#endif