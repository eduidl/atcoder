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

void rec(vi &pre, vi &in, vi &post, int l, int r, int &pos) {
  if (l >= r) return;
  auto root = pre[pos++];
  int m = distance(in.begin(), find(ALL(in), root));
  rec(pre, in, post, l, m, pos);
  rec(pre, in, post, m + 1, r, pos);
  post.push_back(root);
}

int main() {
  int n;
  cin >> n;
  vi pre(n), in(n), post(0);
  REP(i, n) cin >> pre[i];
  REP(i, n) cin >> in[i];
  int pos = 0;
  rec(pre, in, post, 0, pre.size(), pos);
  print(post);
}
