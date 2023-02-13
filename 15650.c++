#include <iostream>
#define MAX 9

using namespace std;

int n, m;
bool visited[MAX] = {0, };
int list[MAX] = {0, };

void dfs(int count, int num){
    if(count == m){
        for(int i = 0; i < m; i++){
            cout << list[i] << ' ';
        }
        cout << "\n";
        return;
    }
    for(int i = num; i <= n; i++){
        if(!visited[i]){
            visited[i] = true;
            list[count] = i;
            dfs(count+1, i+1);
            visited[i] = false;
        }
    }
}
int main(){
    cin >> n >> m;
    dfs(0,1);
}