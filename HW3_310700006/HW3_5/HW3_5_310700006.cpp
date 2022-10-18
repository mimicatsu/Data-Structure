#include <iostream>
using namespace std;
#include <fstream>
#include <string>

struct stackNode{
    int x;
    int y;
    stackNode *next;
    stackNode(int a = 0, int b = 0, stackNode *n = nullptr);
};

stackNode::stackNode(int a, int b, stackNode *n)
    :x{a},y{b},next{nullptr}
    {}

struct stackList{
    stackNode *top;
    stackList( stackNode *t = nullptr);
    void push(int x, int y);
    void pop();
    bool isEmpty();
};

stackList::stackList(stackNode *t)
    :top{t}
    {}

void stackList::push(int x, int y){
    stackNode *newNode = new stackNode(x,y);
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
    else return false;
}




int main(){
    stackList First;
    stackList Second;

    string fileName = "input.txt";
    ifstream inputFile(fileName);

    if(!inputFile){
        cout << "file is not open";
        exit(1);
    }

    string line;
    getline(inputFile, line,' ');
    int maze_row = stoi(line);
    getline(inputFile, line,'\n');
    int maze_col = stoi(line);
    getline(inputFile, line,' ');
    int start_x = stoi(line);
    getline(inputFile, line,'\n');
    int start_y = stoi(line);
    getline(inputFile, line,' ');
    int end_x = stoi(line);
    getline(inputFile, line,'\n');
    int end_y = stoi(line);

    int maze[maze_row][maze_col];

    for( int i = 0; i < maze_row; i++){
        for ( int j = 0; j < maze_col; j ++){
            inputFile >> maze[i][j];
        }
    }

    inputFile.close();

    for( int i = 0; i < maze_row; i++){
        for ( int j = 0; j < maze_col; j ++){
            cout << maze[i][j] << " "; 
        }
        cout << "\n";
    }


    return 0;
}