#include <iostream>
#include <stdexcept>
using namespace std;

int C(int n, int k){
    if(k == 0 || n == k && n > 0){
        return 1;
    }
    else if(n > k && k > 0){
        return C(n-1,k) + C(n-1, k-1);
    }
    else{
        exit(1);
    }
}

int main(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    cout << C(n,k);
    return 0;
}