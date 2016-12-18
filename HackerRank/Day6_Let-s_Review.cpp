//ref: https://www.hackerrank.com/challenges/30-review-loop?h_r=email&unlock_token=0f0379914b5d377b6ab84534231f338b5ca08da2&utm_campaign=30_days_of_code_continuous&utm_medium=email&utm_source=daily_reminder

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    string line,strAns1,strAns2;
    int count = -1;
    cin >> count;
    while((cin >> line)){
        int i=0;
        //if(count == -1) {count == atoi(line); continue;}
        while(line[i] != '\0'){
            //cout << line[i] << " ";
            if(i%2 == 0) strAns1 += line[i];
            else         strAns2 += line[i];  // i%2 == 1
            ++i;
        }
        cout << strAns1 << " " << strAns2 << endl;
        strAns1.clear();
        strAns2.clear();
    }
     return 0;
}

