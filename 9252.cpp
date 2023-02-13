#include <iostream>
#include <string>
using namespace std;

int N, M, D[1010][1010];
string A, B, result[1010][1010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> A >> B;
    N = A.size(); M = B.size();
    A = "#" + A; B= "#" + B;


    for(int i = 1; i<=N;i++){
        for(int j = 1; j <= M; j++){
            if(A[i] == B[j]) {
                D[i][j] = D[i-1][j-1] + 1;
                result[i][j] = result[i-1][j-1] + A[i];
            }
            else{
                D[i][j] = max(D[i-1][j], D[i][j-1]);
                result[i][j] = D[i][j] == D[i-1][j] ? result[i-1][j] : result[i][j-1];
            }
        }
    }

    cout << D[N][M] << endl;
    if(D[N][M] > 0) cout << result[N][M];
}