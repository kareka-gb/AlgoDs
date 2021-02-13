#include <iostream>
#include <cassert>
#include <vector>

using std::vector;
using std::cout;

int binary_search(const vector<int> &a, int left, int right, int x) {
  //write your code here
  int middle = (left + right)/2;
  if(a[middle]==x){
      return middle;
  } else if(left>=right){
      return -1;
  } else if(a[middle]<x){
      return binary_search(a, middle+1, right, x);
  } else {
      return binary_search(a, left, middle-1, x);
  }
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    int left = 0;
    std::cout << binary_search(a, left, (int)a.size()-1, b[i]) << ' ';
  }
}
