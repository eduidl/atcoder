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
  int a, min_abs = INF, minus_cnt = 0;
  i64 ans = 0;
  REP(i, n) {
    cin >> a;
    min_abs = min(min_abs, abs(a));
    ans += abs(a);
    if (a < 0) minus_cnt++;
  }
  if (minus_cnt % 2 != 0) {
    ans -= 2 * min_abs;
  }

  cout << ans << endl;
}
