#include <iostream>
using namespace std;

int D[1010101], P[1010101];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    D[1] = 0;
    P[1] = -1;
    for(int i = 2; i <= n; i++){
        D[i] = D[i-1] + 1;
        P[i] = i-1;
        if(i%2 == 0 && D[i] > D[i/2] +1){
            D[i] = D[i/2] + 1;
            P[i] = i/2;
        }
        if(i%3 == 0&& D[i] > D[i/3] +1){
            D[i] = D[i/3] +1;
            P[i] = i/3;
        }
    }

    cout << D[n] << endl;
    for(int i = n; i != -1; i = P[i]){
        cout << i << ' ';
    }
}