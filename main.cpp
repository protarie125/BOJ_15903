#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;
using pq = priority_queue<ll, vl, greater<ll>>;

ll n, m;
pq Q;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n >> m;
  for (auto i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    Q.push(x);
  }

  for (auto i = 0; i < m; ++i) {
    auto x = Q.top();
    Q.pop();
    auto y = Q.top();
    Q.pop();

    Q.push(x + y);
    Q.push(x + y);
  }

  ll ans = 0;
  while (!Q.empty()) {
    ans += Q.top();
    Q.pop();
  }

  cout << ans;

  return 0;
}