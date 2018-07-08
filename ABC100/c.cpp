#include <bits/stdc++.h>
 
using namespace std;
  
int main() {
    int n, a;
    int count = 0;
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        while (a % 2 == 0) {
            a /= 2;
            ++count;
        }
    }
    
    cout << count << endl;
}

