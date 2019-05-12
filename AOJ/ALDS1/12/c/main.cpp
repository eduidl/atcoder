#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), i##_max = (b); i < i##_max; ++i)
#define RFOR(i, a, b) for (int i = (b)-1, i##_min = (a); i >= i##_min; --i)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define RREP(i, n) for (int i = (n)-1; i >= 0; --i)
#define ALL(obj) (obj).begin(), (obj).end()

using namespace std;
using vi = vector<int>;
using vd = vector<double>;
using pi = pair<int, int>;
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

void dijkstra(vector<vector<pi>> &adj) {
  auto n = adj.size();
  priority_queue<pi> PQ;
  vi d(n, INF);
  vector<bool> visited(n, false);
  d[0] = 0;
  PQ.push(make_pair(0, 0));
  while (!PQ.empty()) {
    auto f = PQ.top();
    PQ.pop();
    auto u = f.second;
    visited[u] = true;
    if (d[u] < -f.first) continue;
    REP(i, adj[u].size()) {
      auto v = adj[u][i].first;
      auto new_cost = d[u] + adj[u][i].second;
      if (!visited[v] && new_cost < d[v]) {
        d[v] = new_cost;
        PQ.push(make_pair(-d[v], v));
      }
    }
  }
  REP(i, n) cout << i << " " << (d[i] == INF ? -1 : d[i]) << endl;
}

int main() {
  int n;
  cin >> n;
  vector<vector<pi>> adj(n);
  int k, c, u, v;
  REP(i, n) {
    cin >> u >> k;
    REP(j, k) {
      cin >> v >> c;
      adj[u].push_back(make_pair(v, c));
    }
  }
  dijkstra(adj);
}
