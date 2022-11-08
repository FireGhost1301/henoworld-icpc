/**
 * Author: FireGhost
 * License: CC0
 * Source: cp-algo
 * Description: in code
 */

int dp_dac(int n, int k) {
  // dp[i, j] = min(dp[i - 1, k] + C[k + 1, j])
  vector<int> prv_dp(n + 1), cur_dp(n + 1);
  function<int(int, int)> C = [&](int l, int r) {
    // calc and return something
    // must satisfies: C(a, d) + C(b, c) >= C(a, c) + C(b, d)
    return 0;
  };
  function<void(int, int, int, int)> calc = [&](int l, int r, int pl, int pr) {
    if (l > r) return;
    int mid = (l + r) >> 1;
    pair<int, int> best = {INT_MAX, -1};
    for (int k = pl; k <= min(mid, pr); ++k)
      best = min(best, {prv_dp[k - 1] + C(k, mid), k});
    cur_dp[mid] = best.first;
    int p = best.second;
    calc(l, mid - 1, pl, p);
    calc(mid + 1, r, p, pr);
  };
  for (int i = 1; i <= n; ++i)
    prv_dp[i] = 0; // calc first layer of dp
  for (int i = 2; i <= k; ++i) {
    calc(1, n, 1, n);
    swap(prv_dp, cur_dp);
  }
  return prv_dp[n];
}
