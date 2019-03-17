#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
  
int main() {
    int n, m;
    ll x, y, z;
    array<vector<ll>, 8> sum;
    
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> z;
        sum[0].push_back(x + y + z);
        sum[1].push_back(x - y + z);
        sum[2].push_back(x + y - z);
        sum[3].push_back(x - y - z);
    }
    
    std::sort(sum[0].begin(), sum[0].end(), greater<ll>());
    std::sort(sum[1].begin(), sum[1].end(), greater<ll>());
    std::sort(sum[2].begin(), sum[2].end(), greater<ll>());
    std::sort(sum[3].begin(), sum[3].end(), greater<ll>());
    
    array<ll, 8> ret{0};
    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < m; ++i) {
            ret[j * 2] += sum[j][i];
            ret[j * 2 + 1] -= sum[j][n - 1 - i];
        }
    }
    
    ll max_ = ret[0];
    for (int i = 1; i < 8; ++i) {
        if (ret[i] > max_) max_ = ret[i];
                            
    }
    cout << max_ << endl;
}
