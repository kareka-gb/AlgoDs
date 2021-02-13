#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;

int countmaj(vector<int> a, int left, int right, int maj){
    if(maj==-1) return 0;
    int cnt = 0;
    for(int i=left; i<right; i++){
        if(a[i]==maj) cnt++;
    }
    return cnt;
}

int get_majority_element(vector<int> &a, int left, int right) {
  if (left + 1 == right) return a[left];
  if(countmaj(a, left, right, get_majority_element(a, left, (left+right)/2))>(right-left)/2) return get_majority_element(a, left, (left+right)/2);
  else if(countmaj(a, left, right, get_majority_element(a, (left+right)/2, right))>(right-left)/2) return get_majority_element(a, (left+right)/2, right);
  return -1;
}

int findMajority(vector<int> &arr, int n)  
{  
    using namespace std;
    int maxCount = 0;  
    int index = -1; // sentinels  
    for(int i = 0; i < n; i++)  
    {  
        int count = 0;  
        for(int j = 0; j < n; j++)  
        {  
            if(arr[i] == arr[j])  
            count++;  
        }  
          
        // update maxCount if count of  
        // current element is greater  
        if(count > maxCount)  
        {  
            maxCount = count;  
            index = i;  
        }  
    }  
      
    // if maxCount is greater than n/2  
    // return the corresponding element  
    if (maxCount > n/2)  
        return arr[index];
    else
        return -1;
}

int main() {
    using namespace std;
    while(true){
        int n = rand()%100000 + 2;
        //cout << n << "\n";
        vector<int> a;
        for(int i=0; i<n; i++){
            a.push_back(rand()%1000000001);
        }
         //for(int i=0; i<n; i++){
          //   cout << a[i] << " ";
         //}
        //cout << "\n";
        //int res1 = findMajority(a, a.size());
        time_t start, end;
        time(&start);
        int res2 = get_majority_element(a, 0, a.size());
        time(&end);
        double time_taken=double(end-start);
        if(time_taken>1){
            cout << "Number of elements for which time greater than 1 : " << n << "\n";
            cout << "Time greater than 1 sec : " << time_taken << "\n";
            break;
        }
        /*if(res1!=res2){
            cout << "Wrong answer: " << res1 << ' ' << res2 << "\n";
            break;
        }
        else{
            cout << "OK\n";
        }*/
    }
}
