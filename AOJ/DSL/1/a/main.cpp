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
using pd = pair<double, double>;
using i64 = int64_t;
using u64 = uint64_t;

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

class DisjointSet {
 public:
  vi rank, p;

  DisjointSet() {}
  DisjointSet(int size) : rank(size, 0), p(size, 0) {
    REP(i, size) make_set(i);
  }

  void make_set(int x) {
    p[x] = x;
    rank[x] = 0;
  }

  bool same(int x, int y) { return find_set(x) == find_set(y); }

  void unite(int x, int y) { link(find_set(x), find_set(y)); }

  void link(int x, int y) {
    if (rank[x] > rank[y]) {
      p[y] = x;
    } else {
      p[x] = y;
      if (rank[x] == rank[y]) rank[y]++;
    }
  }

  int find_set(int x) {
    if (x != p[x]) {
      p[x] = find_set(p[x]);
    }
    return p[x];
  }
};

int main() {
  int n, q, com, x, y;
  cin >> n >> q;
  DisjointSet ds(n);
  REP(i, q) {
    cin >> com >> x >> y;
    if (com == 0)
      ds.unite(x, y);
    else if (com == 1)
      cout << (ds.same(x, y) ? 1 : 0) << endl;
  }
}
