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

int solve(vi &A, int s) {
  int ans{0};
  vector<bool> V(A.size(), false);
  vi T(10001);
  auto B = A;
  sort(ALL(B));
  REP(i, A.size()) T[B[i]] = i;
  REP(i, A.size()) {
    if (V[i]) continue;
    int cur{i};
    int num{0}, sum{0}, min_{INF};
    while (!V[cur]) {
      V[cur] = true;
      auto w = A[cur];
      ++num;
      sum += w;
      min_ = min(min_, w);
      cur = T[w];
    }
    ans += min(sum + (num - 2) * min_, min_ + sum + (num + 1) * s);
  }
  return ans;
}

int main() {
  int n, s{INF};
  cin >> n;
  vi A(n);
  REP(i, n) {
    cin >> A[i];
    s = min(s, A[i]);
  }
  cout << solve(A, s) << endl;
}
