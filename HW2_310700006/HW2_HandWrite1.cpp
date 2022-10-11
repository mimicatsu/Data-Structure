#include <iostream>
using namespace std;

int fun(int x, int y){
    if(x > y){
        return -1;
    }
    else if(x == y){
        return 1;
    }
    else{
        return x*fun(x + 1, y);
    }
}

int main(){
    cout << fun(10,4);

    return 0;
}