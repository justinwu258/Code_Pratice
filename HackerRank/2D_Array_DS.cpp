// ref: https://www.hackerrank.com/challenges/2d-array?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    vector< vector<int> > arr(6,vector<int>(6));
    vector<int> sumAns;
    int max = INT_MIN;
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            sumAns.push_back(arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]
                            +arr[i+2][j+1]+arr[i+2][j+2]);
        }
    }
    vector<int>::iterator sumList;
    for(sumList = sumAns.begin(); sumList != sumAns.end(); sumList++){
        if(*sumList > max)  max = *sumList;
    }
    cout << max << endl;
    return max;
}

