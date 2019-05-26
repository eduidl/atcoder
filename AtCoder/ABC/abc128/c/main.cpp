#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), i##_max = (b); i < i##_max; ++i)
#define RFOR(i, a, b) for (int i = (b)-1, i##_min = (a); i >= i##_min; --i)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define RREP(i, n) for (int i = (n)-1; i >= 0; --i)
#define ALL(obj) (obj).begin(), (obj).end()

using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using vi = vector<int>;
using vl = vector<i64>;
using vd = vector<double>;
using pi = pair<int, int>;
using pl = pair<i64, i64>;
using pd = pair<double, double>;

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
  int n, m;
  cin >> n >> m;
  vector<uint16_t> s(m);
  REP(i, n) {
    int k;
    cin >> k;
    REP(j, k) {
      int ss;
      cin >> ss;
      s[i] += ((uint16_t)1 << (ss - 1));
    }
  }
  vi p(m);
  REP(i, n) cin >> p[i];
  int ans = 0;
  for (uint16_t i = 0; i < (uint16_t)1 << n; ++i) {
    bool flag = true;
    REP(j, m) {
      if (__builtin_popcount(i & s[j]) % 2 != p[j]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      ans++;
    }
  }
  cout << ans << endl;
}
