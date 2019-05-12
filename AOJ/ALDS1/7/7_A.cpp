#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), i##_max = (b); i < i##_max; ++i)
#define RFOR(i, a, b) for (int i = (b)-1, i##_min = (a); i >= i##_min; --i)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define RREP(i, n) for (int i = (n)-1; i >= 0; --i)
#define ALL(obj) (obj).begin(), (obj).end()

using namespace std;
using vi = vector<int>;
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

// 二重連鎖木
// 左子右兄弟表現
struct Node {
  int p, l, r, d;
};

void print(vector<Node> &T, int u) {
  cout << "node " << u << ": ";
  cout << "parent = " << T[u].p << ", ";
  cout << "depth = " << T[u].d << ", ";

  if (T[u].p == -1)
    cout << "root, ";
  else if (T[u].l == -1)
    cout << "leaf, ";
  else
    cout << "internal node, ";

  cout << "[";
  for (int i = 0, c = T[u].l; c != -1; ++i, c = T[c].r) {
    if (i) cout << ", ";
    cout << c;
  }
  cout << "]" << endl;
}

void rec(vector<Node> &T, int u, int p) {
  T[u].d = p;
  if (T[u].r != -1) rec(T, T[u].r, p);
  if (T[u].l != -1) rec(T, T[u].l, p + 1);
}

int main() {
  int n, l;
  cin >> n;
  vector<Node> T(n);
  REP(i, n) T[i].p = T[i].l = T[i].r = T[i].d = -1;
  REP(i, n) {
    int id, k;
    cin >> id >> k;
    REP(j, k) {
      int c;
      cin >> c;
      if (j == 0)
        T[id].l = c;
      else
        T[l].r = c;
      l = c;
      T[c].p = id;
    }
  }
  int r;
  REP(i, n) {
    if (T[i].p == -1) r = i;
  }
  rec(T, r, 0);
  REP(i, n) print(T, i);
}
