#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

string greatest(vector<string> &a){
    string mx=a[0];
    int index=0;
    for(int i=1; i<a.size(); i++){

    }
}

string largest_number(vector<string> a) {
  //write your code here
  vector<string> ab;
  for(int i=0; i<ab.size(); i++){
      ab.push_back(greatest(a));
  }
  std::stringstream ret;
  for (size_t i = 0; i < ab.size(); i++) {
    ret << ab[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
