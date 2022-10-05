#include <iostream>
using namespace std;
#include <fstream>
#include <string>

struct listNode{
    long int id;
    int score;
    listNode *next;
    listNode(int x = 0,int y = 0, listNode *n = nullptr);
};

listNode::listNode(int x, int y, listNode *n)
    :id{x},score{y},next{n}
    {}



int main(){

// build the linkedlist
    listNode *first = nullptr;
    listNode *current;

    string fileName = "input.txt";
    ifstream inputFile(fileName);

    if(!inputFile){
        cout << "not open";
        exit(1);
    }

    string line;
    while(getline(inputFile, line, ' ')){
        string one = line;
        getline(inputFile, line, '\n');
        string two = line;

        listNode *newdata = new listNode;
        newdata->id = stoi(one);
        newdata->score = stoi(two);
        newdata->next = nullptr; 

        if(first == nullptr){
            first = newdata;
        } 
        else{
            current->next = newdata;
        }
        current = newdata;
    }

    inputFile.close();

//find the max score student

    current = first;
    int maxScore = -1;
    int maxId;
    while(current != nullptr){
        if(current->score > maxScore){
            maxScore = current->score;
            maxId = current->id;
        }
        else if(current->score == maxScore){
            if(current->id < maxId){
                maxId = current->id;
            }
        }
        current = current->next;
    }

    cout << "Maximum ID: " << maxId <<", Maximum socre: " << maxScore;


    return 0;
}