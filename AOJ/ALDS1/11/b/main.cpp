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

constexpr int N = 100;
enum Color { White, Gray, Black };
vector<vi> M(N, vi(N, 0));
vi d(N), f(N), nt(N, 0);
vector<Color> color(N, White);

int next(int u) {
  FOR(v, nt[u], nt.size()) {
    nt[u] = v + 1;
    if (M[u][v]) return v;
  }
  return -1;
}

void dfs_visit(int r, int &tt) {
  fill(nt.begin(), nt.end(), 0);
  stack<int> S;
  S.push(r);
  color[r] = Gray;
  d[r] = ++tt;

  while (!S.empty()) {
    auto u = S.top();
    auto v = next(u);
    if (v != -1) {
      if (color[v] == White) {
        color[v] = Gray;
        d[v] = ++tt;
        S.push(v);
      }
    } else {
      S.pop();
      color[u] = Black;
      f[u] = ++tt;
    }
  }
}

void dfs(int n, int &tt) {
  REP(u, d.size()) {
    if (color[u] == White) dfs_visit(u, tt);
  }
  REP(i, d.size()) cout << i + 1 << " " << d[i] << " " << f[i] << endl;
}

int main() {
  int n, u, k, v;
  cin >> n;
  REP(i, n) {
    cin >> u >> k;
    REP(j, k) {
      cin >> v;
      M[u - 1][v - 1] = 1;
    }
  }
  int tt = 0;
  d.resize(n);
  f.resize(n);
  nt.resize(n);
  dfs(n, tt);
}
