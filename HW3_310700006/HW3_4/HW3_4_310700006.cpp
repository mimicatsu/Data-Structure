#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct stackNode{
    int data;
    stackNode *next;
    stackNode(int x = 0, stackNode *n = nullptr);
};

stackNode::stackNode(int x, stackNode *n)
    :data{x},next{nullptr}
    {}

struct stackList{
    stackNode *top;
    stackList(stackNode *t = nullptr);
    int getTop();
    void push(int x);
    void pop();
    bool isEmpty();
};

stackList::stackList(stackNode *t)
    :top{nullptr}
    {}

int stackList::getTop(){
    return top->data;
}

void stackList::push(int x){
    stackNode *newNode = new stackNode(x);
    newNode->next = top;
    top = newNode;
}

void stackList::pop(){
    stackNode *tmp = top->next;
    delete top;
    top = tmp;
}

bool stackList::isEmpty(){
    if(top == nullptr){
        return true;
    }
    else{
        return false;
    }

}

int main(){
    stackList stack;    
    string fileName = "input.txt";
    ifstream inputFile(fileName);

    if(!inputFile){
        cout << "not open";
        exit(1);
    }

    string line;
    while(getline(inputFile, line)){
        int val = stoi(line);
        if(val >= 0){
            stack.push(val);
        }
        else{
            cout << "The last 5 items are: ";
            for(int i = 0; i < 5; i++){
                cout << stack.getTop() << " ";
                stack.pop();
            }
            cout << "\n";
        }
    }

    while(!stack.isEmpty()){
        cout << stack.getTop() << " ";
        stack.pop();
    }




    inputFile.close();




    return 0;
}