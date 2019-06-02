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
    if (it == v.begin()) cout << " ";
    cout << *it;
  }
  cout << endl;
}

bool dfs(vector<vector<pi>> &v, vb &visited, vi &x, int q) {
  visited[q] = true;
  for (auto &&u : v[q]) {
    if (visited[u.fst]) {
      if (x[u.fst] != x[q] + u.snd) return false;
      continue;
    } else {
      x[u.fst] = x[q] + u.snd;
      if (!dfs(v, visited, x, u.fst)) return false;
    }
  }
  return true;
}

bool solve(vector<vector<pi>> &v, vb &visited, vi &x) {
  REP(i, v.size()) {
    if (visited[i]) continue;
    if (!dfs(v, visited, x, i)) return false;
  }
  return true;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<pi>> v(n);
  vi x(n);
  vb visited(n);
  REP(i, m) {
    int l, r, d;
    cin >> l >> r >> d;
    l--;
    r--;
    v[l].pb(mp(r, d));
    v[r].pb(mp(l, -d));
  }

  cout << (solve(v, visited, x) ? "Yes" : "No") << endl;
}
