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

void dfs(vector<vi> &M, vi &d, int s) {
  queue<int> q;
  q.push(s);
  d[s] = 0;
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    REP(v, d.size()) {
      if (M[u][v] == 0) continue;
      if (d[v] != INF) continue;
      d[v] = d[u] + 1;
      q.push(v);
    }
  }
  REP(i, d.size()) cout << i + 1 << " " << ((d[i] == INF) ? -1 : d[i]) << endl;
}

int main() {
  int n, u, k, v;
  cin >> n;
  vector<vi> M(n, vi(n, 0));
  vi d(n, INF);
  REP(i, n) {
    cin >> u >> k;
    REP(j, k) {
      cin >> v;
      M[u - 1][v - 1] = 1;
    }
  }
  dfs(M, d, 0);
}
