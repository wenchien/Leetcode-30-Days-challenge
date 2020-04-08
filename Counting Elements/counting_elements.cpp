#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
// Problem Contraint
// 1 <= arr.length <= 1000
// 0 <= arr[i] <= 1000
// 
using namespace std;
int findCount(vector<int>& arr);
map<int, int> checker;
int main() {
    vector<int>array = {
        1, 3, 2, 3, 5, 0
    };
    
    findCount(array);
    return 0;
}

int findCount(vector<int>& arr) {
    //store everything
    int answer = 0;
    for (auto &i : arr) {
        checker[i];//add all values without repeating
        //so when we do lookups, it's O(1)
    }

    //now iterate through the original array and see if it needs to increment values
    for (int i = 0; i < arr.size(); i++) {
        if (checker.find((arr[i] + 1)) == checker.end()) {
            cout << "Key: " << arr[i] << " currently isn't in hashtable" << endl;
            continue;
        }
        else {
            answer++;
        }
    }
    
    cout << "Values Counted " << answer << " of times" << endl;
    return answer;
}