#include <iostream>

using namespace std;

int recursion(int a) {
  if (a == 0) {
    return 1;
  }

  return a * recursion(a - 1);
}

int main() {
  cout << recursion(4) << "\n";
  return 0;
}