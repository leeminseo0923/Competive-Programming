#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;

    string bulb[N];

    int innerSwitch = 0;

    for(int i = 0; i < N; i++){
        cin >> bulb[i];
        int j = 0;
        while(bulb[i][j+1] != '\0'){
            if (bulb[i][j] != bulb[i][j+1]){
                innerSwitch++;
            }
            j++;
        }
    }
    int min = 1000;
    sort(bulb, bulb+N);
    do{
        int current = innerSwitch;
        for(int i = 0; i < N-1 ; i++){
            int j = 0;
            int bulbSize = bulb[i].size()-1;
            if(bulb[i][bulbSize] != bulb[i+1][0]){
                current++;
            }
        }
        if(current<min){
            min = current;
        }
    }while(next_permutation(bulb, bulb+N));

    cout << min <<endl;

    return 0;
}