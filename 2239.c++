#include <iostream>
#include <algorithm>

using namespace std;

int N, K, A[111], D[10101];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> K;
    for (int i = 1 ; i <= N; i++) cin >> A[i];

    D[0] = 1;

    for(int i = 1; i <= N; i++){
        for(int j = 0; j<=K; j++){
            if(j-A[i] >= 0) D[j]+= D[j-A[i]];
        }
    }

    cout << D[K];

}