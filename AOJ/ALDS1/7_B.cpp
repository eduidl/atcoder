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

struct Node {
  int p, l, r, d, h;
};

int get_sibling(vector<Node> &T, int u) {
  if (T[u].p == -1) return -1;
  auto p = T[u].p;
  return (T[p].l == u) ? T[p].r : T[p].l;
}

void print(vector<Node> &T, int u) {
  cout << "node " << u << ": ";
  cout << "parent = " << T[u].p << ", ";
  cout << "sibling = " << get_sibling(T, u) << ", ";
  cout << "degree = " << ((T[u].l != -1) + (T[u].r != -1)) << ", ";
  cout << "depth = " << T[u].d << ", ";
  cout << "height = " << T[u].h << ", ";

  if (T[u].p == -1)
    cout << "root";
  else if (T[u].l == -1 && T[u].r == -1)
    cout << "leaf";
  else
    cout << "internal node";
  cout << endl;
}

void set_depth(vector<Node> &T, int u, int d) {
  if (u == -1) return;
  T[u].d = d;
  set_depth(T, T[u].l, d + 1);
  set_depth(T, T[u].r, d + 1);
}

int set_height(vector<Node> &T, int u) {
  int h1 = (T[u].l != -1) ? set_height(T, T[u].l) + 1 : 0;
  int h2 = (T[u].r != -1) ? set_height(T, T[u].r) + 1 : 0;
  return T[u].h = max(h1, h2);
}

int main() {
  int n, root;
  cin >> n;
  vector<Node> T(n);
  REP(i, n) T[i].p = -1;
  REP(i, n) {
    int id, l, r;
    cin >> id >> l >> r;
    T[id].l = l;
    T[id].r = r;
    if (l != -1) T[l].p = id;
    if (r != -1) T[r].p = id;
  }
  REP(i, n) if (T[i].p == -1) root = i;

  set_depth(T, root, 0);
  set_height(T, root);
  REP(i, n) print(T, i);
}
