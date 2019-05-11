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
  int r, g, b, n;
  cin >> r >> g >> b >> n;
  vector<i64> rv(n + 1, 0), gv(n + 1, 0), bv(n + 1, 0);
  REP(i, n + 1) {
    if (i % r == 0) rv[i] = 1;
  }
  REP(i, n + 1) {
    auto j = 0;
    while (true) {
      if (i + j > n) break;
      gv[i + j] += rv[i];
      j += g;
    }
  }
  REP(i, n + 1) {
    auto j = 0;
    while (true) {
      if (i + j > n) break;
      bv[i + j] += gv[i];
      j += b;
    }
  }

  cout << bv[n] << endl;
}
