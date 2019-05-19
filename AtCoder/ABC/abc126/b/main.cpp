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
void print(vector<T> &v) {
  REP(i, v.size()) {
    if (i) cout << " ";
    cout << v[i];
  }
  cout << endl;
}

int main() {
  string s;
  cin >> s;
  auto i = stoi(s);
  auto y = i / 100;
  auto m = i % 100;
  if (1 <= y && y <= 12 && 1 <= m && m <= 12) {
    cout << "AMBIGUOUS";
  } else if (1 <= y && y <= 12) {
    cout << "MMYY";
  } else if (1 <= m && m <= 12) {
    cout << "YYMM";
  } else {
    cout << "NA";
  }
  cout << endl;
}
