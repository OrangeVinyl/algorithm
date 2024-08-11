#include <iostream>
#include <string>

using namespace std;

int a,b,res = 1;

int main() { 
    cin >> a >> b;

    while (true) {
        if (a == b) {
            break;
        } else if ( a > b) {
            res = -1;
            break;
        }

        if (b % 2 == 0) {
            b /= 2;
        } else if (b % 10 == 1) {
            b  = ( b - 1) / 10;
        } else {
            res = -1;
            break;
        }
        res++;
    }

    cout << res;
    return 0;
}
