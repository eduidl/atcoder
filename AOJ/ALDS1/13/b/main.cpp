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

constexpr int N = 3;
constexpr int N2 = N * N;
constexpr array<int, 4> dx{-1, 0, 1, 0}, dy{0, -1, 0, 1};

struct Puzzle {
  array<int, N2> f;
  int space, path;

  bool operator<(const Puzzle &p) const {
    REP(i, N2) {
      if (f[i] == p.f[i]) continue;
      return f[i] > p.f[i];
    }
    return false;
  }
};

bool is_target(Puzzle &p) {
  REP(i, N2) {
    if (p.f[i] != i + 1) return false;
  }
  return true;
}

int bfs(Puzzle &s) {
  queue<Puzzle> Q;
  map<Puzzle, bool> V;
  s.path = 0;
  Q.push(s);
  V[s] = true;

  while (!Q.empty()) {
    auto u = Q.front();
    Q.pop();
    if (is_target(u)) return u.path;
    int sx = u.space / N;
    int sy = u.space % N;
    REP(r, 4) {
      int tx = sx + dx[r];
      int ty = sy + dy[r];
      if (tx < 0 || ty < 0 || tx >= N || ty >= N) continue;
      auto v = u;
      swap(v.f[u.space], v.f[tx * N + ty]);
      v.space = tx * N + ty;
      if (!V[v]) {
        V[v] = true;
        v.path++;
        Q.push(v);
      }
    }
  }
  return -1;
}

int main() {
  Puzzle in;
  REP(i, N2) {
    cin >> in.f[i];
    if (in.f[i] == 0) {
      in.f[i] = N2;
      in.space = i;
    }
  }
  cout << bfs(in) << endl;
}
