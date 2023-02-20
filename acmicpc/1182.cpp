#include <stdio.h>

int N, S, A[20];

int main(){
    scanf("%d %d", &N, &S);
    for(int i = 0; i<N; i++) scanf("%d", &A[i]);

    int cnt = 0;
    for(int bit = 1; bit < (1<<N); bit++){
        int sum = 0;
        for(int i = 0; i<N; i++){
            if(bit & (1 << i)) sum += A[i];
        }

        if(sum==S) cnt++;
    }

    printf("%d", cnt);
}