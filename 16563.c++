#include <iostream>

using namespace std;

int SP[5050505];

void Sieve(int n){
    for(int i = 2; i <=n ; i++){
        if(SP[i]) continue;
        SP[i] = i;
        for(int j = i + i; j <= n; j+= i) if(!SP[j]) SP[j] = i;
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    Sieve(5000000);
    int N; cin >> N;
    for(int i = 1; i<=N; i++){
        int X; cin>>X;
        while(X>1){
            cout << SP[X] << ' ';
            X/=SP[X];
        }
        cout << '\n';
    }
}