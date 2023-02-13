#include <iostream>

using namespace std;

int main(void){
    int N;
    cin >> N;

    int cnt = 0;
    int iter = N;


    while(iter--){
        int num;
        cin >> num;

        if(num == 1){
            cnt ++;
            continue;
        }

        for(int i = 2; i*i <= num; i++){
            if(num % i == 0){
                cnt ++;
                break;
            }
        }
    }

    cout << N-cnt << endl;
    return 0;
}