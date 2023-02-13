#include <stdio.h>

#define MAX 9
int n, m;
int list[MAX] = {0,};
int visited[MAX] = {0,};

void dfs(int count){
    if(count == m){
        for(int i = 0; i<m; i++){
            printf("%d ", list[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            visited[i] = 1;
            list[count] = i;
            dfs(count+1);
            visited[i] = 0;
        }
    }
}

int main(void){
    scanf("%d %d", &n, &m);

    dfs(0);
    return 0;
}


