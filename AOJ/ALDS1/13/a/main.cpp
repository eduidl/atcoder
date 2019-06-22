#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), i##_max = (b); i < i##_max; ++i)
#define RFOR(i, a, b) for (int i = (b)-1, i##_min = (a); i >= i##_min; --i)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define RREP(i, n) for (int i = (n)-1; i >= 0; --i)
#define ALL(obj) (obj).begin(), (obj).end()

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<i64>;
using vd = vector<double>;
using pi = pair<int, int>;
using pl = pair<i64, i64>;
using pd = pair<double, double>;

constexpr int INF = 1 << 30;
constexpr int MOD = 1000000007;
constexpr int N = 8;

template <typename T>
inline void chmin(T &a, T b) {
  a = min(a, b);
}
template <typename T>
inline void chmax(T &a, T b) {
  a = max(a, b);
}
template <typename T>
void print(T &v) {
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) cout << " ";
    cout << *it;
  }
  cout << endl;
}

void print_board(vector<vb> &X, vi &row) {
  REP(y, N) {
    REP(x, N) {
      if (X[y][x] && row[y] != x) return;
    }
  }
  REP(y, N) {
    REP(x, N) cout << ((row[y] == x) ? "Q" : ".");
    cout << endl;
  }
}

void recursive(vector<vb> &X, vi &row, vb &col, vb &dpos, vb &dneg, int y) {
  if (y == N) {
    print_board(X, row);
    return;
  }
  REP(x, N) {
    if (col[x] || dpos[x + y] || dneg[y - x + N - 1]) continue;
    row[y] = x;
    col[x] = dpos[x + y] = dneg[y - x + N - 1] = true;
    recursive(X, row, col, dpos, dneg, y + 1);
    row[y] = -1;
    col[x] = dpos[x + y] = dneg[y - x + N - 1] = false;
  }
}

int main() {
  vi row(N, -1);
  vb col(N, false), dpos(2 * N - 1, false), dneg(2 * N - 1, false);
  vector<vb> X(N, vb(N, false));

  int k, x, y;
  cin >> k;
  REP(i, k) {
    cin >> y >> x;
    X[y][x] = true;
  }
  recursive(X, row, col, dpos, dneg, 0);
}
