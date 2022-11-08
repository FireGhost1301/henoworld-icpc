/**
 * Author: FireGhost
 * Date: 2022-11-08
 * Description: ez pz
 */

struct PersistentSegTree {
  struct node {
    int val = 0;
    node *left, *right;
  };
  node *new_node() {
    node *temp = new node;
    temp->val = 0;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
  }
  int sz = 1;
  node *version[N * 2];
  void init(int n) {
    while (sz < n) sz <<= 1;
  }
  void build(int b[], node *cur, int lx, int rx) {
    if (rx - lx == 1) {
      if (lx <= n) cur->val = b[lx];
      return;
    }
    int mid = (lx + rx) >> 1;
    cur->left = new_node();
    cur->right = new_node();
    build(b, cur->left, lx, mid);
    build(b, cur->right, mid, rx);
    cur->val = cur->left->val + cur->right->val;
  }
  void build(int b[]) {
    version[0] = new_node();
    build(b, version[0], 0, sz);
  }
  void update(int i, int v, node *prev, node *cur, int lx, int rx) {
    if (rx - lx == 1) {
      cur->val = v;
      return;
    }
    int mid = (lx + rx) >> 1;
    if (i < mid) {
      cur->right = prev->right;
      cur->left = new_node();
      update(i, v, prev->left, cur->left, lx, mid);
    }
    else {
      cur->left = prev->left;
      cur->right = new_node();
      update(i, v, prev->right, cur->right, mid, rx);
    }
    cur->val = cur->left->val + cur->right->val;
  }
  void update(int i, int v, int k) {
    version[k] = new_node();
    update(i, v, version[k - 1], version[k], 0, sz);
  }
  int get(int v, node *cur, int lx, int rx) {
    if (rx - lx == 1) return lx;
    int mid = (lx + rx) >> 1;
    if (cur->left->val >= v) return get(v, cur->left, lx, mid);
    return get(v - cur->left->val, cur->right, mid, rx);
  }
  int get(int v, int k) {
    return get(v, version[k], 0, sz);
  }
};
