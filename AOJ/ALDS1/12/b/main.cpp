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

void dijkstra(vector<vi> &M) {
  auto n = M.size();
  vi d(n, INF);
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
      if (!visited[i]) {
        d[i] = min(d[i], d[u] + M[u][i]);
      }
    }
  }
  REP(i, n) cout << i << " " << (d[i] == INF ? -1 : d[i]) << endl;
}

int main() {
  int n;
  cin >> n;
  vector<vi> M(n, vi(n, INF));
  int k, c, u, v;
  REP(i, n) {
    cin >> u >> k;
    REP(j, k) {
      cin >> v >> c;
      M[u][v] = c;
    }
  }
  dijkstra(M);
}
