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
  vi a(n);
  REP(i, n) { cin >> a[i]; }

  vi gcdl(n, 0), gcdr(n, 0);
  gcdl[0] = a[0];
  gcdr[n - 1] = a[n - 1];
  FOR(i, 1, n - 1) {
    gcdl[i] = __gcd(gcdl[i - 1], a[i]);
    gcdr[n - 1 - i] = __gcd(gcdr[n - i], a[n - 1 - i]);
  }
  int ans = max(gcdl[n - 2], gcdr[1]);
  FOR(i, 1, n - 1) { ans = max(ans, __gcd(gcdl[i - 1], gcdr[i + 1])); }

  cout << ans << endl;
}
