#include <iostream>
#include <iomanip>
using namespace std;

double squareRoot(double num, double ans, double tol){
    if(abs(ans*ans - num) <= tol){
        return ans;
    }
    else{
        return squareRoot(num,(ans*ans + num)/(2 * ans), tol);
    }
}

int main(){
    double num;
    cin >> num;
    cout << fixed << setprecision(2)<<squareRoot(num, 1, 0.01);
    return 0;
}