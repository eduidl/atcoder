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
vi prenum, parent, lowest;
vector<bool> visited;
int timer = 1;

template <typename T>
void print(vector<T> &v) {
  REP(i, v.size()) {
    if (i) cout << " ";
    cout << v[i];
  }
  cout << endl;
}

void dfs(int current, int prev) {
  prenum[current] = lowest[current] = timer++;
  visited[current] = true;
  for (auto &&next : G[current]) {
    if (!visited[next]) {
      parent[next] = current;
      dfs(next, current);
      lowest[current] = min(lowest[current], lowest[next]);
    } else if (next != prev) {
      lowest[current] = min(lowest[current], prenum[next]);
    }
  }
}

void art_points() {
  auto n = G.size();
  dfs(0, -1);

  set<int> ap;
  int np = 0;
  FOR(i, 1, n) {
    auto p = parent[i];
    if (p == 0)
      np++;
    else if (prenum[p] <= lowest[i])
      ap.insert(p);
  }
  if (np > 1) ap.insert(0);
  for (auto it = ap.begin(); it != ap.end(); it++) cout << *it << endl;
}

int main() {
  int n, m, s, t;
  cin >> n >> m;
  G.resize(n);
  prenum.resize(n);
  parent.resize(n);
  lowest.resize(n);
  visited.resize(n, false);
  REP(i, m) {
    cin >> s >> t;
    G[s].push_back(t);
    G[t].push_back(s);
  }
  art_points();
}
