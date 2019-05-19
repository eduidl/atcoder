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

void dfs(vector<vector<pl>> &edges, vi &color) {
  auto cnt = 0;
  queue<i64> q;
  q.push(0);
  while (!q.empty()) {
    auto i = q.front();
    q.pop();
    for (auto &&p : edges[i]) {
      auto v = p.first;
      auto w = p.second;
      if (color[v] != -1) continue;
      if (w == 0) {
        color[v] = color[i];
      } else {
        color[v] = 1 - color[i];
      }
      q.push(v);
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<vector<pl>> edges(n);
  vi color(n, -1);
  color[0] = 0;
  REP(i, n) {
    i64 ui, vi, wi;
    cin >> ui >> vi >> wi;
    edges[ui - 1].push_back(make_pair(vi - 1, wi % 2));
    edges[vi - 1].push_back(make_pair(ui - 1, wi % 2));
  }
  dfs(edges, color);

  REP(i, n) cout << color[i] << endl;
}
