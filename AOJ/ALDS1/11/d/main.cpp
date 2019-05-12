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
constexpr int NIL = -1;

template <typename T>
void print(vector<T> &v) {
  REP(i, v.size()) {
    if (i) cout << " ";
    cout << v[i];
  }
  cout << endl;
}

void dfs(vector<vi> &G, vi &color, int r, int c) {
  stack<int> S;
  S.push(r);
  color[r] = c;
  while (!S.empty()) {
    auto u = S.top();
    S.pop();
    REP(i, G[u].size()) {
      auto v = G[u][i];
      if (color[v] == NIL) {
        color[v] = c;
        S.push(v);
      }
    }
  }
}

int main() {
  int n, m, s, t;
  cin >> n >> m;
  vector<vi> G(n, vi());
  vi color(n, NIL);
  REP(i, m) {
    cin >> s >> t;
    G[s].push_back(t);
    G[t].push_back(s);
  }
  int id = 1;
  REP(i, n) if (color[i] == NIL) dfs(G, color, i, id++);
  cin >> m;
  REP(i, m) {
    cin >> s >> t;
    cout << (color[s] == color[t] ? "yes" : "no") << endl;
  }
}
