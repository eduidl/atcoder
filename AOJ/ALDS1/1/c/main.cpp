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

bool is_prime(int x) {
  if (x == 1)
    return false;
  else if (x == 2)
    return true;
  else if (x % 2 == 0)
    return false;
  for (int i = 3; i * i <= x; i += 2) {
    if (x % i == 0) return false;
  }
  return true;
}

int main() {
  int n, x, ans = 0;
  cin >> n;
  REP(i, n) {
    cin >> x;
    if (is_prime(x)) ans++;
  }
  cout << ans << endl;
}
