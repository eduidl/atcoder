#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), i##_max = (b); i < i##_max; ++i)
#define RFOR(i, a, b) for (int i = (b)-1, i##_min = (a); i >= i##_min; --i)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define RREP(i, n) for (int i = (n)-1; i >= 0; --i)
#define ALL(obj) (obj).begin(), (obj).end()

using namespace std;
using vi = vector<int>;
using vl = vector<int64_t>;
using vd = vector<double>;
using pi = pair<int, int>;
using pd = pair<double, double>;
using i64 = int64_t;
using u64 = uint64_t;

constexpr i64 INF = 1LL << 32;
constexpr int MOD = 1000000007;

template <typename T>
void print(vector<T> &v) {
  REP(i, v.size()) {
    if (i) cout << " ";
    cout << v[i];
  }
  cout << endl;
}

void floyd(vector<vl> &d) {
  auto n = d.size();
  REP(k, n) {
    REP(i, n) {
      if (d[i][k] == INF) continue;
      REP(j, n) {
        if (d[k][j] == INF) continue;
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main() {
  int n, e, u, v, c;
  cin >> n >> e;
  vector<vl> d(n, vl(n, INF));
  REP(i, n) d[i][i] = 0;
  REP(i, e) {
    cin >> u >> v >> c;
    d[u][v] = c;
  }
  floyd(d);
  bool negative = false;
  REP(i, n) if (d[i][i] < 0) negative = true;

  if (negative) {
    cout << "NEGATIVE CYCLE" << endl;
  } else {
    REP(i, n) {
      REP(j, n) {
        auto item = d[i][j];
        if (j) cout << " ";
        if (item == INF)
          cout << "INF";
        else
          cout << item;
      }
      cout << endl;
    }
  }
}
