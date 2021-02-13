#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;
using std::pair;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<pair <int, int>> seg(segments.size());
  int n = segments.size();
  for(int i=0; i<n; i++)
      seg[i]=std::make_pair(segments[i].start, segments[i].end);
  sort(seg.begin(), seg.end());
  int j=1;
  vector<int> points;
  int common=seg[0].second;
  while(j<n){
      if(common<seg[j].first){
          points.push_back(common);
          common = seg[j].second;
      }
      if(common>seg[j].second) common=seg[j].second;
      if(j==n-1) points.push_back(common);
      j++;
  } 
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
  std::cout << "\n";
}
