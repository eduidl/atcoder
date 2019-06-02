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

void can_move(vector<bool> &v, int s, string &str) {
  v[s] = true;
  for (int i = s; i < str.size(); ++i) {
    if (!v[i]) continue;
    if (str[i + 1] == '.') v[i + 1] = true;
    if (str[i + 2] == '.') v[i + 2] = true;
  }
}

bool can_swap(vector<bool> &sv, vector<bool> &fv, int c, int d) {
  FOR(i, 1, sv.size() - 1) {
    if (sv[i - 1] && fv[i] && sv[i + 1] && i + 1 <= c && i <= d) return true;
    if (fv[i - 1] && sv[i] && fv[i + 1] && i <= c && i + 1 <= d) return true;
  }
  return false;
}

bool solve(vector<bool> &sv, vector<bool> &fv, int c, int d) {
  if (!sv[c] || !fv[d]) return false;
  if (c < d) return true;
  return can_swap(sv, fv, c, d);
}

int main() {
  int n, a, b, c, d;
  string s;
  cin >> n >> a >> b >> c >> d >> s;
  a--;
  b--;
  c--;
  d--;
  vector<bool> sv(n, false), fv(n, false);
  can_move(sv, a, s);
  can_move(fv, b, s);
  cout << (solve(sv, fv, c, d) ? "Yes" : "No") << endl;
}
