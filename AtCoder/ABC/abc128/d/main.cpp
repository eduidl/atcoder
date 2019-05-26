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
void print(T &v) {
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) cout << " ";
    cout << *it;
  }
  cout << endl;
}

int main() {
  int N, K;
  cin >> N >> K;
  vi v(N);
  REP(i, N) cin >> v[i];
  int ans = 0;
  int s = min(N, K);
  vi left(s + 1), right(s + 1);
  FOR(i, 1, s + 1) {
    left[i] = left[i - 1] + v[i - 1];
    right[i] = right[i - 1] + v[N - i];
  }
  REP(i, s + 1) {
    REP(j, s + 1 - i) {
      priority_queue<int> q;
      int score = left[i] + right[j];
      REP(ii, i) q.push(-v[ii]);
      REP(jj, j) q.push(-v[N - 1 - jj]);
      REP(k, K - i - j) {
        if (q.empty()) break;
        auto f = q.top();
        if (f <= 0) break;
        q.pop();
        score += f;
      }
      ans = max(ans, score);
    }
  }
  cout << ans << endl;
}
