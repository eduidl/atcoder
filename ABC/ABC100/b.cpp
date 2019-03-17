#include <bits/stdc++.h>
 
using namespace std;
  
int main() {
    int d, n;
    
    cin >> d >> n;
    
    int ret;
    if (d == 0) {
        ret = 1;
    } else if (d == 1) {
        ret = 100;
    } else {
        ret = 10000;
    }
    
    if (n == 100) {
        cout << 101 * ret<< endl; 
    } else {
        cout << n * ret << endl;
    }
}
