#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values, int n) {
  double value = 0.0;

  // write your code here
    vector<std::pair <float,int> > valbyweight(n);
    for(int i=0; i<n; i++) 
        valbyweight[i]=std::make_pair(((float)values[i])/weights[i], i);
    std::sort(valbyweight.begin(), valbyweight.end());
    std::reverse(valbyweight.begin(), valbyweight.end());
    int i=0;
    while(capacity>0 && i<n){
        if(weights[valbyweight[i].second]<=capacity){
            capacity-=weights[valbyweight[i].second];
            value+=values[valbyweight[i].second];
        } else {
            value+=capacity*valbyweight[i].first;
            capacity=0;
        }
        i++;
    }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values, n);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
