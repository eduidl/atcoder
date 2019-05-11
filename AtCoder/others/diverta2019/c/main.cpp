#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), i##_max = (b); i < i##_max; ++i)
#define RFOR(i, a, b) for (int i = (b)-1, i##_min = (a); i >= i##_min; --i)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define RREP(i, n) for (int i = (n)-1; i >= 0; --i)
#define ALL(obj) (obj).begin(), (obj).end()

using namespace std;
using vi = vector<int>;
using vd = vector<double>;
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

int main() {
  int n;
  cin >> n;
  string s;
  int cnt_b = 0, cnt_e = 0, cnt_both = 0, ans = 0;
  REP(i, n) {
    cin >> s;
    if (s[0] == 'B' && s[s.size() - 1] == 'A') {
      cnt_both++;
    } else {
      if (s[0] == 'B') cnt_b++;
      if (s[s.size() - 1] == 'A') cnt_e++;
    }
    REP(j, s.size() - 1) {
      if (s[j] == 'A' && s[j + 1] == 'B') ans++;
    }
  }
  if (cnt_both > 0) {
    ans += cnt_both - 1;
    if (cnt_e > 0) {
      ans++;
      cnt_e--;
    }
    if (cnt_b > 0) {
      ans++;
      cnt_b--;
    }
  }

  ans += min(cnt_e, cnt_b);
  cout << ans << endl;
}
