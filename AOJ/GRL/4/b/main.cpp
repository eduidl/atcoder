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

vector<vi> G;
list<int> out;
vector<bool> visited;
vi indeg;

template <typename T>
void print(vector<T> &v) {
  REP(i, v.size()) {
    if (i) cout << " ";
    cout << v[i];
  }
  cout << endl;
}

void bfs(int s) {
  queue<int> q;
  q.push(s);
  visited[s] = true;
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    out.push_back(u);
    for (auto &&v : G[u]) {
      indeg[v]--;
      if (indeg[v] == 0 && !visited[v]) {
        visited[v] = true;
        q.push(v);
      }
    }
  }
}

void tsort() {
  auto n = G.size();
  for (auto &&uv : G) {
    for (auto &&v : uv) indeg[v]++;
  }
  REP(u, n) if (indeg[u] == 0 && !visited[u]) bfs(u);
  for (auto it = out.begin(); it != out.end(); it++) {
    cout << *it << endl;
  }
}

int main() {
  int n, m, s, t;
  cin >> n >> m;
  G.resize(n);
  visited.resize(n, false);
  indeg.resize(n);
  REP(i, m) {
    cin >> s >> t;
    G[s].push_back(t);
  }
  tsort();
}
