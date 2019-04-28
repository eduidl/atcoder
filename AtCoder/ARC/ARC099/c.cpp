#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), i##_max = (b); i < i##_max; ++i)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end() 
 
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
 
const int INF = 1 << 25;
 
template<class T>
void chmin (T& a, const T& b) { a = min(a, b); }
 
template<class T>
void chmax (T& a, const T& b) { a = max(a, b); }
 
 
int main() {
    cin.tie();
 
    int n, k, min = INF;
    cin >> n >> k;
 
    vi a(n);
    int min_i;
    REP(i, n) {
      cin >> a[i];
      if (a[i] < min) {
        min = a[i];
        min_i = i;
      }
    }
 
    int ans = (n - 1 + k - 2) / (k - 1);
    cout << ans << endl;
}
