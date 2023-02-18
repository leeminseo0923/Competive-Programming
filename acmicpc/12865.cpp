#include <iostream>

using namespace std;

int N, K, W[101010], V[101010];
double VperW[101010];

int main(){
    cin >> N >> K;

    for(int i = 0; i < N; i++){
        cin >> W[i] >> V[i];
        VperW[i] = (double)V[i]/W[i];
    }
    int curWeight = 0;
    int sumValue = 0;
    for(int i = 0; i < N; i++){
        double maxVperW = VperW[0];
        int maxId = 0;
        for(int j = 1; i < N; i++){
            if(maxVperW < VperW[i] || (maxVperW == VperW[i] && W[i] < W[maxId])){
                maxVperW = VperW[i];
                maxId = i;
            }
        }
        if(!(curWeight + W[maxId] > K)){
            curWeight += W[maxId];
            sumValue += V[maxId];
        }
    }
    cout << sumValue << endl;
}