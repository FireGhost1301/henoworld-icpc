/**
 * Author: FireGhost
 * License: CC0
 * Source: cp-algo
 * Description: When doing DP on intervals: $a[i][j] = \min_{i < k < j}(a[i][k] + a[k][j]) + f(i, j)$, where the (minimal) optimal $k$ increases with both $i$ and $j$,
 *  one can solve intervals in increasing order of length, and search $k = p[i][j]$ for $a[i][j]$ only between $p[i][j-1]$ and $p[i+1][j]$.
 *  This is known as Knuth DP. Sufficient criteria for this are if $f(b,c) \le f(a,d)$ and $f(a,c) + f(b,d) \le f(a,d) + f(b,c)$ for all $a \le b \le c \le d$.
 *  Consider also: LineContainer (ch. Data structures), monotone queues, ternary search.
 * Time: O(N^2)
 */
int solve() {
  int N;
  int dp[N][N], opt[N][N];
  auto C = [&](int i, int j) {
    ... // Implement cost function C.
  };
  for (int i = 0; i < N; i++) {
    opt[i][i] = i;
    ... // Initialize dp[i][i] according to the problem
  }
  for (int i = N-2; i >= 0; i--) {
    for (int j = i+1; j < N; j++) {
      int mn = INT_MAX;
      int cost = C(i, j);
      for (int k = opt[i][j-1]; k <= min(j-1, opt[i+1][j]); k++) {
        if (mn >= dp[i][k] + dp[k+1][j] + cost) {
          opt[i][j] = k; 
          mn = dp[i][k] + dp[k+1][j] + cost; 
        }
      }
      dp[i][j] = mn; 
    }
  }
  cout << dp[0][N-1] << endl;
}
