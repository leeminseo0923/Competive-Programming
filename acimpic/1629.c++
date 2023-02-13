#include <iostream>

using namespace std;

long long multiply(long long a, long long b, long long c){

    if(c>=a){
        a %= c;
        if(a == 0){
            return a;
        }
    }

    if (b <= 1){
        return a;
    }

    else if(b % 2 == 0){
        long long temp = multiply(a, b/2, c);
        temp *= temp;
        temp %= c;

        return temp;
    }

    else{
        long long temp = multiply(a, b/2, c);

        temp *= temp;

        temp %= c;

        temp *= a;

        temp %= c;

        return temp;
    }

}

int main(void){
    long long A, B, C;

    long long result = 1;

    cin >> A >> B >> C;

    result = multiply(A, B, C);

    cout << result % C << endl;

    return 0;
}