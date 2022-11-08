/**
 * Author: FireGhost
 * Date: 2022-11-08
 * Description: ez pz
 */

int a[N];
struct Line {
  int a, b;
  Line(int a = 0, int b = 1e9) : a(a), b(b) {}
  int operator()(int x) { return a * x + b; }
} seg[maxn * 4];
void add(int u, int l, int r, Line line) {
  if (l == r) {
    if (seg[u](a[l]) > line(a[l])) seg[u] = line;
     return;
  }
  int mid = (l + r) >> 1;
  if (seg[u].a > line.a) swap(seg[u], line);
  if (seg[u](a[mid]) > line(a[mid])) {
    swap(seg[u], line);
    add(u << 1 | 1, mid + 1, r, line);
  }
  else add(u << 1, l, mid, line);
}
int get(int u, int l, int r, int p) {
  if (l == r) return seg[u](a[p]);
  int mid = (l + r) >> 1;
  if (p <= mid) return std::min(seg[u](a[p]), get(u << 1, l, mid, p));
  return min(seg[u](a[p]), get(u << 1 | 1, mid + 1, r, p));
}
