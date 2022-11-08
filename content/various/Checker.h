/**
 * Author: FireGhost
 * Date: 2022-11-08
 * Description: ez pz
 */

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) {
  return uniform_int_distribution<int>(l, r)(rng);
}
void gen_test() {
  const int NTEST = 100;
  srand(time(NULL));
  for (int iTest = 1; iTest <= NTEST; iTest++) {
    ofstream inp("name.inp");
    inp.close();
    system("name.exe");
    system("name_trau.exe");
    if (system("fc name.out name.ans") != 0) {
      cout << "Test " << iTest << ": WRONG!\n";
      return;
    }
    cout << "Test " << iTest << ": CORRECT!\n";
  }
}
