#include <iostream>
#include <vector>

using namespace std;

int Check[8080808];
vector<int> Primes;

void Sieve(int n){
    for(int i = 2; i <= n; i++){
        if(Check[i]) continue;
        Primes.push_back(i);
        for(int j = i+i; j <= n; j+= i) Check[j] = 1;
    }
}

int main(){
    Sieve(8000000);

    int K; cin >> K;
    cout << Primes[K-1];
}