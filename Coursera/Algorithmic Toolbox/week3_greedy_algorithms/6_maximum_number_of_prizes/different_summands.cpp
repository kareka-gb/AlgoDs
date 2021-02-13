#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int i;
  int j;
  for(i=(int)sqrt(n); i<n; i++){
      j = (i*i+i)/2;
      if(j>n){
          i--;
          break;
      }
  }
  int sum=0;
  for(j=1; j<i; j++){
      summands.push_back(j);
      sum+=j;
  }
  summands.push_back(n-sum);
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
  std::cout << "\n";
}
