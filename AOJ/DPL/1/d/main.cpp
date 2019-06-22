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
void print(T &v) {
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) cout << " ";
    cout << *it;
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  vi A(n), L(n);
  REP(i, n) cin >> A[i];
  L[0] = A[0];
  int length = 1;

  REP(i, n) {
    if (L[length - 1] < A[i]) {
      L[length++] = A[i];
    } else {
      *lower_bound(L.begin(), L.begin() + length, A[i]) = A[i];
    }
  }

  cout << length << endl;
}
