#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops, int n) {
    vector<int> diff(n+1);
    for(int i=0; i<n+1; i++){
        if(i==0) diff[i]=stops[i];
        else if(i==n) diff[i]=dist-stops[i-1];
        else diff[i]=stops[i]-stops[i-1];
    }
    int i=0;
    int difference = 0;
    int refills = 0;
    while(i<=n){
        if(diff[i]>tank){
            return -1;
        }else{
           difference+=diff[i];
           if(difference>tank){
               refills++;
               difference = diff[i];
           }
       }
       i++; 
    }
    return refills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (int i = 0; i < n; ++i)
        cin >> stops[i];

    cout << compute_min_refills(d, m, stops, n) << "\n";

    return 0;
}
