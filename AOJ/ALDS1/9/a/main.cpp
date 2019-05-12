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

int parent(int i) { return i / 2; }
int left(int i) { return 2 * i; }
int right(int i) { return 2 * i + 1; }

int main() {
  int n;
  cin >> n;
  vi a(n + 1, 0);
  FOR(i, 1, n + 1) cin >> a[i];
  FOR(i, 1, n + 1) {
    cout << "node " << i << ": key = " << a[i] << ", ";
    if (parent(i) >= 1) cout << "parent key = " << a[parent(i)] << ", ";
    if (left(i) <= n) cout << "left key = " << a[left(i)] << ", ";
    if (right(i) <= n) cout << "right key = " << a[right(i)] << ", ";
    cout << endl;
  }
}
