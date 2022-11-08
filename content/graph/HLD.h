/**
 * Author: Benjamin Qi, Oleksandr Kulkov, chilli
 * Date: 2022-11-08
 * License: CC0
 * Source: Codeforces
 * Description: ez pz
 * Time: O((\log N)^2)
 */

int n, a[N];
vector<int> g[N];
int cnt, sz[N], h[N], p[N], id[N], hld[N];
void dfs(int u) {
  sz[u] = 1;
  for (int v: g[u]) if (v != p[u]) {
    h[v] = h[u] + 1, p[v] = u;
    dfs(v);
    sz[u] += sz[v];
  }
}
void build_hld(int u, int top) {
  id[u] = ++cnt;
  hld[u] = top;
  int max_sz = -1, z = -1;
  for (int v: g[u]) if (v != p[u]) {
    if (sz[v] > max_sz)
      max_sz = sz[v], z = v;
  }
  if (z == -1) return;
  build_hld(z, top);
  for (int v: g[u]) if (v != p[u] && v != z)
    build_hld(v, v);
}
int path(int x, int y) {
  int ans = 0;
  while (hld[x] != hld[y]) {
    if (h[hld[x]] < h[hld[y]]) swap(x, y);
    ans += get_sum(id[hld[x]], id[x]);
    x = p[hld[x]];
  }
  if (h[x] > h[y]) swap(x, y);
  ans += get_sum(id[x], id[y]);
  return ans;
}
