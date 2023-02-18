#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

pair<int, int> bulk[55];

bool compare(const pair<int,int> &a, const pair<int,int> &b){
    if(a.second == b.second){
        return a.first < b.first;
    }

    return a.second < b.second;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        bulk[i] = make_pair(x, y);
    }

    sort(bulk, bulk+n, compare);
}