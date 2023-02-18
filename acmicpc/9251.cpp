#include <iostream>
#include <string>
using namespace std;

int N, M, D[1010][1010];
string A, B;

void print(int i, int j){
    if(D[i][j] == 0) return;
    if(A[i] == B[j]){
        print(i-1, j-1);
        cout << A[i];
    }
    else{
        D[i-1][j] > D[i][j-1] ? print(i-1,j):print(i,j-1);
    }

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> A >> B;
    N = A.size(); M = B.size();
    A = "#" + A; B= "#" + B;


    for(int i = 1; i<=N;i++){
        for(int j = 1; j <= M; j++){
            if(A[i] == B[j]) {
                D[i][j] = D[i-1][j-1] + 1;
            }
            else{
                D[i][j] = max(D[i-1][j], D[i][j-1]);
            }
        }
    }

    cout << D[N][M] << endl;
    print(N,M);
}