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
constexpr int NIL = -1;

template <typename T>
void print(vector<T> &v) {
  REP(i, v.size()) {
    if (i) cout << " ";
    cout << v[i];
  }
  cout << endl;
}

class Node {
 public:
  int location;
  int l, r;
  Node() : l(NIL), r(NIL) {}
};

class Point {
 public:
  int id, x, y;
  Point() {}
  Point(int id, int x, int y) : id(id), x(x), y(y) {}
  bool operator<(const Point &p) const { return id < p.id; }
  void print() { printf("%d\n", id); }
};

int make_KD_tree(vector<Point> &P, vector<Node> &T, int l, int r, int depth,
                 int &np) {
  if (!(l < r)) return NIL;
  auto mid = (l + r) / 2;
  auto t = np++;
  if (depth % 2 == 0) {
    sort(P.begin() + l, P.begin() + r,
         [](Point &p1, Point &p2) { return p1.x < p2.x; });
  } else {
    sort(P.begin() + l, P.begin() + r,
         [](Point &p1, Point &p2) { return p1.y < p2.y; });
  }
  T[t].location = mid;
  T[t].l = make_KD_tree(P, T, l, mid, depth + 1, np);
  T[t].r = make_KD_tree(P, T, mid + 1, r, depth + 1, np);
  return t;
}

void find(vector<Point> &P, vector<Node> &T, int v, int sx, int tx, int sy,
          int ty, int depth, vector<Point> &ans) {
  auto x = P[T[v].location].x;
  auto y = P[T[v].location].y;
  if (sx <= x && x <= tx && sy <= y && y <= ty) {
    ans.push_back(P[T[v].location]);
  }
  if (depth % 2 == 0) {
    if (T[v].l != NIL && sx <= x) {
      find(P, T, T[v].l, sx, tx, sy, ty, depth + 1, ans);
    }
    if (T[v].r != NIL && x <= tx) {
      find(P, T, T[v].r, sx, tx, sy, ty, depth + 1, ans);
    }
  } else {
    if (T[v].l != NIL && sy <= y) {
      find(P, T, T[v].l, sx, tx, sy, ty, depth + 1, ans);
    }
    if (T[v].r != NIL && y <= ty) {
      find(P, T, T[v].r, sx, tx, sy, ty, depth + 1, ans);
    }
  }
}

int main() {
  int n, x, y;
  scanf("%d", &n);
  vector<Node> T(n);
  vector<Point> P;
  REP(i, n) {
    scanf("%d %d", &x, &y);
    P.emplace_back(i, x, y);
  }
  auto np = 0;
  auto root = make_KD_tree(P, T, 0, n, 0, np);
  int q, sx, tx, sy, ty;
  cin >> q;
  vector<Point> ans;
  REP(i, q) {
    scanf("%d %d %d %d", &sx, &tx, &sy, &ty);
    ans.clear();
    find(P, T, root, sx, tx, sy, ty, 0, ans);
    sort(ALL(ans));
    for (auto &&a : ans) a.print();
    printf("\n");
  }
}
