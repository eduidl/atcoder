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

struct Rectangle {
  int height, pos;
};

int get_largest_rectangle(int w, vi &Tr) {
  stack<Rectangle> S;
  int max_v = 0;
  Tr[w] = 0;

  REP(i, w + 1) {
    Rectangle rect{Tr[i], i};
    if (S.empty()) {
      S.push(rect);
      continue;
    }
    if (S.top().height < rect.height) {
      S.push(rect);
    } else if (S.top().height > rect.height) {
      int target = i;
      while (!S.empty() && S.top().height >= rect.height) {
        const auto pre = S.top();
        S.pop();
        auto area = pre.height * (i - pre.pos);
        chmax(max_v, area);
        target = pre.pos;
      }
      rect.pos = target;
      S.push(rect);
    }
  }
  return max_v;
}

int solve(int w, int h, vector<vi> &C) {
  vector<vi> T(h, vi(w + 1, 0));
  REP(y, h) {
    REP(x, w) {
      if (C[y][x]) continue;
      T[y][x] = (y > 0) ? T[y - 1][x] + 1 : 1;
    }
  }

  int max_v = 0;
  REP(y, h) { chmax(max_v, get_largest_rectangle(w, T[y])); }
  return max_v;
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<vi> C(h, vi(w));
  REP(y, h) { REP(x, w) cin >> C[y][x]; }

  cout << solve(w, h, C) << endl;
}
