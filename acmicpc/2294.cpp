#include <iostream>
#include <algorithm>

using namespace std;

int N, K, Coin[111], MinCoin[10101];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> Coin[i];

    for(int i = 1; i <= K; i++) MinCoin[i] = -1;
    MinCoin[0] = 0;

    

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= K; j+=1){
            if(MinCoin[j] == -1){
                if(j-Coin[i] >= 0 && MinCoin[j-Coin[i]] != -1) MinCoin[j] = MinCoin[j-Coin[i]] + 1;
            }
            else{
                if(j-Coin[i] >= 0 && MinCoin[j-Coin[i]] != -1) MinCoin[j] = min(MinCoin[j], MinCoin[j-Coin[i]]+1);
            }
        }
    }

    cout << MinCoin[K];

}