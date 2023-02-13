#include <iostream>
#include <algorithm>
using namespace std;

int N, A[8];

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    sort(A, A+N);

    int mx = 0;
    do{
        int now = 0;
        for(int i = 1; i<N;i++){
            if(A[i-1] > A[i]){
                now += A[i-1] - A[i];
            }
            else now += A[i] - A[i-1];
        }
        if(now > mx) mx = now;
    }while(next_permutation(A, A+N));
    printf("%d", mx);
}