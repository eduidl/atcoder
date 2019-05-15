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

class Edge {
 public:
  int t, w;
  Edge() {}
  Edge(int t, int w) : t(t), w(w) {}
};

vector<vector<Edge>> G;
vi d;

void bfs(int s) {
  queue<int> q;
  q.push(s);
  d[s] = 0;
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    for (auto &&e : G[u]) {
      if (d[e.t] == INF) {
        d[e.t] = d[u] + e.w;
        q.push(e.t);
      }
    }
  }
}

void solve() {
  auto n = G.size();
  bfs(0);
  int maxv = 0;
  int tgt = 0;
  REP(i, n) {
    if (d[i] == INF) continue;
    if (maxv < d[i]) {
      maxv = d[i];
      tgt = i;
    }
  }

  fill(ALL(d), INF);
  bfs(tgt);
  maxv = 0;
  REP(i, n) {
    if (d[i] == INF) continue;
    maxv = max(maxv, d[i]);
  }
  cout << maxv << endl;
}

int main() {
  int n, s, t, w;
  cin >> n;
  G.resize(n);
  d.resize(n, INF);
  REP(i, n - 1) {
    cin >> s >> t >> w;
    G[s].emplace_back(t, w);
    G[t].emplace_back(s, w);
  }
  solve();
}
