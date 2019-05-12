#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), i##_max = (b); i < i##_max; ++i)
#define RFOR(i, a, b) for (int i = (b)-1, i##_min = (a); i >= i##_min; --i)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define RREP(i, n) for (int i = (n)-1; i >= 0; --i)
#define ALL(obj) (obj).begin(), (obj).end()

using namespace std;
using vi = vector<int>;
using vd = vector<double>;
using i64 = int64_t;

constexpr int INF = 1 << 30;
constexpr int MOD = 1000000007;

template <typename T>
void print(vector<T> &v) {
  REP(i, v.size()) {
    if (i) cout << " ";
    cout << v[i];
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  string x, y;
  REP(i, n) {
    cin >> x >> y;
    auto xs = x.size();
    auto ys = y.size();
    x = ' ' + x;
    y = ' ' + y;
    vector<vi> dp(xs + 1, vi(ys + 1, 0));
    FOR(xi, 1, xs + 1) {
      FOR(yi, 1, ys + 1) {
        if (x[xi] == y[yi])
          dp[xi][yi] = dp[xi - 1][yi - 1] + 1;
        else
          dp[xi][yi] = max(dp[xi - 1][yi], dp[xi][yi - 1]);
      }
    }
    cout << dp[xs][ys] << endl;
  }
}
