#include <iostream>

using namespace std;

int N, P;

int main(){
    cin >> N >> P;

    long long factorialN = 1;

    N++;
    int iter = 0;

    while(--N){
        factorialN *= N;
        if (factorialN > P){
            factorialN %= P;
        }
    }

    cout << factorialN%P;

    return 0;
}
