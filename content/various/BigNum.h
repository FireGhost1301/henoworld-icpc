/**
 * Author: FireGhost
 * Date: 2022-11-08
 * Description: ez pz
 */

typedef vector<long long> BigNum;
const long long BASE = 1e8;
const int LOG = 8;
void fix(BigNum &a) {
  a.push_back(0);
  for (int i = 0; i < (int)a.size() - 1; ++i) {
    a[i + 1] += a[i] / BASE;
    a[i] %= BASE;
    if (a[i] < 0) a[i] += BASE, --a[i + 1];
  }
  while (a.size() > 1 && a.back() == 0) a.pop_back();
}
void operator += (BigNum &a, const BigNum &b) {
  a.resize(max(a.size(), b.size()));
  for (int i = 0; i < (int)b.size(); ++i) a[i] += b[i];
  return fix(a);
}
BigNum operator + (BigNum a, const BigNum &b) {a += b; return a;}
bool operator < (const BigNum &a, const BigNum &b) {
  if (a.size() != b.size()) return a.size() < b.size();
  for (int i = (int)a.size() - 1; i >= 0; --i) {
    if (a[i] != b[i]) return a[i] < b[i];
  }
  return false;
}
void operator -= (BigNum &a, const BigNum &b) {       // works only if a >= b
  for (int i = 0; i < (int)b.size(); ++i) a[i] -= b[i];
  return fix(a);
}
BigNum operator - (BigNum a, BigNum b) {
  if (a < b) {
    b -= a;
    b.back() = -b.back();
    return b;
  }
  else {
    a -= b; 
    return a;
  }
}
BigNum operator * (const BigNum &a, const BigNum &b) {
  BigNum c(a.size() + b.size());
  for (int i = 0; i < (int)a.size(); ++i)
    for (int j = 0; j < (int)b.size(); ++j)
      c[i + j] += a[i] * b[j];
  return fix(c), c;
}
istream& operator >> (istream& inp, BigNum &a) {
  string s; inp >> s;
  a.clear(); a.resize(s.size() / LOG + 1);
  for (int i = 0; i < (int)s.size(); ++i) {
    int x = (s.size() - i - 1) / LOG;
    a[x] = a[x] * 10 + s[i] - '0';
  }
  return fix(a), inp;
}
ostream& operator << (ostream& out, const BigNum &a) {
  cout << a.back();
  for (int i = (int) a.size() - 2; i >= 0; --i) 
    cout << setw(LOG) << setfill('0') << a[i];
  return out;
}
void Divide(BigNum a, int d, BigNum &q, int& r) {
  q.clear();
  for (int i = a.size() - 1; i >= 0; --i) {
    r = r * BASE + a[i];
    q.push_back(r / d); r %= d;
  }
  reverse(q.begin(), q.end());
  fix(q);
}
