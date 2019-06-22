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
inline void chmin(T &a, T b) {
  a = min(a, b);
}
template <typename T>
inline void chmax(T &a, T b) {
  a = max(a, b);
}
template <typename T>
void print(T &v) {
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) cout << " ";
    cout << *it;
  }
  cout << endl;
}

i64 power(i64 x, i64 n) {
  i64 res = 1;
  if (n > 0) {
    res = power(x, n / 2);
    res = (res * res) % MOD;
    if (n % 2 == 1) res = (res * x) % MOD;
  }
  return res;
}

int main() {
  int m, n;
  cin >> m >> n;
  cout << power(m, n) << endl;
}
