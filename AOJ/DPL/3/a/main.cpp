#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), i##_max = (b); i < i##_max; ++i)
#define RFOR(i, a, b) for (int i = (b)-1, i##_min = (a); i >= i##_min; --i)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define RREP(i, n) for (int i = (n)-1; i >= 0; --i)
#define ALL(obj) (obj).begin(), (obj).end()

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<i64>;
using vd = vector<double>;
using pi = pair<int, int>;
using pl = pair<i64, i64>;
using pd = pair<double, double>;

constexpr int INF = 1 << 30;
constexpr int MOD = 1000000007;

template <typename T>
void print(T &v) {
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) cout << " ";
    cout << *it;
  }
  cout << endl;
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<vi> C(h, vi(w)), dp(h, vi(w));
  REP(y, h) { REP(x, w) cin >> C[y][x]; }

  int max_w = 0;
  REP(y, h) {
    REP(x, w) {
      dp[y][x] = (C[y][x] + 1) % 2;
      max_w |= dp[y][x];
    }
  }
  FOR(y, 1, h) {
    FOR(x, 1, w) {
      if (C[y][x]) continue;
      dp[y][x] = min(dp[y - 1][x - 1], min(dp[y - 1][x], dp[y][x - 1])) + 1;
      max_w = max(max_w, dp[y][x]);
    }
  }

  cout << max_w * max_w << endl;
}
