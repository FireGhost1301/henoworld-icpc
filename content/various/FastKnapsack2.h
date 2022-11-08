/**
 * Author: FireGhost
 * Date: 2022-11-08
 * License: CC0
 * Source: Codeforces
 * Description: O(n * sqrt(sum) / 32)
 * Time: O(n * sqrt(sum) / 32)
 */

const int N = 1e6 + 1;
int n, cnt[N];
bitset<N> knapsack = 1;
void solve() {
  for (int i = 1; i <= n; ++i) {
    int x = (cnt[i] - 1) / 2;
    cnt[i] -= 2 * x, cnt[2 * i] += x;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < cnt[i]; ++j)
      knapsack |= knapsack << i;
    }
  knapsack.test(k);
}
