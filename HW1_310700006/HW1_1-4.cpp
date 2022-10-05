#include <iostream>
#include <string>
using namespace std;

void *larger(
    void *dataPtr1,
    void *dataPtr2,
    int(*ptrToCmpFun)(void*, void*))
{
    if (ptrToCmpFun(dataPtr1,dataPtr2) > 0){
        return dataPtr1;
    }
    else{
        return dataPtr2;
    }
}

int compareStr(void *ptr1, void *ptr2){
    string str1 = *(string*)ptr1;
    string str2 = *(string*)ptr2;
    if(str1 >= str2){
        cout << 1;
        return 1;
    }
    else{
        return -1;
    }
}


int main(){
    string str1 = "abcde" ;
    string str2 = "abs";

    string lrg = *(string*)larger(&str1, &str2, compareStr);

    cout << lrg;

    return 0;
}