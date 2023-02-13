#include <iostream>

using namespace std;

int N, M, O;

int calCase(int n, int m){
    int SumCases[250];
    for(int i = 0; i < 250; i++) SumCases[i] = 0;
    SumCases[0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
        {
            if(j>0){
                SumCases[j+m*i] += SumCases[j-1 + m*i];
            }
            if(i>0){
                SumCases[j+m*i] += SumCases[j+m*(i-1)];
            }
        }
                
    }
    return SumCases[n*m-1];
}

int main(){
    cin >> N >> M >> O;
    int result = 0;

    if (O==0) result = calCase(N, M);
    else result = calCase((O-1)/M+1, O%M == 0 ? M : O%M) * calCase(N-((O-1)/M+1)+1, M-(O%M == 0 ? M : O%M)+1);

    cout << result;

    return 0;
}