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

int prim(vector<vi> &M) {
  auto n = M.size();
  vi d(n, INF), p(n, -1);
  vector<bool> visited(n, false);
  d[0] = 0;
  while (true) {
    auto minv = INF;
    auto u = -1;
    REP(i, n) {
      if (!visited[i] && d[i] < minv) {
        minv = d[i];
        u = i;
      }
    }
    if (u == -1) break;
    visited[u] = true;
    REP(i, n) {
      if (!visited[i] && M[u][i] < d[i]) {
        d[i] = M[u][i];
        p[i] = u;
      }
    }
  }
  int sum = 0;
  REP(i, n) if (p[i] != -1) sum += M[i][p[i]];
  return sum;
}

int main() {
  int n, e;
  cin >> n;
  vector<vi> M(n, vi(n, 0));
  REP(i, n) {
    REP(j, n) {
      cin >> e;
      M[i][j] = (e == -1) ? INF : e;
    }
  }

  auto ans = prim(M);
  cout << ans << endl;
}
