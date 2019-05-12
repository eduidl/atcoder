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
  vector<vi> dp(n + 1, vi(n, 0));
  vi p(n + 1);
  REP(i, n) cin >> p[i] >> p[i + 1];
  FOR(s, 2, n + 1) {     // 掛ける個数
    REP(l, n - s + 1) {  // 掛け始めるidx
      dp[s][l] = INF;
      FOR(ls, 1, s) {  // 分割
        auto r = l + ls;
        auto rs = s - ls;
        dp[s][l] =
            min(dp[s][l], dp[ls][l] + dp[rs][r] + p[l] * p[r] * p[l + s]);
      }
    }
  }
  cout << dp[n][0] << endl;
}
