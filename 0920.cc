#include <iostream>
using namespace std;

struct listNode{
    void *dataPtr;
    listNode *next;
    listNode(void *dPtr, listNode *n = nullptr);
    // ~listNode();
};

listNode::listNode(void *dPtr, listNode *n)
    :dataPtr{dPtr},next{n}
    {}

// listNode::~listNode(){
//     if(dataPtr!=nullptr)
//     delete dataPtr;
// }//解構子
    
struct linkedList{
    listNode *first;
    LinkedList();
};

int main(){
    int *newData1 = new int(7);
    listNode node1(newData1);

    int *newData2 = new int(15);
    listNode node2(newData2);

    node1.next = &node2;

    cout << "The newdata1 :" << *newData1 << "\n";
    cout << "The newdata2 :" << *newData2;



    return 0;
}