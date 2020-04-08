#include <stdlib.h>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

//bit operation on integers, still O(n) but less possible overflowing shit....
//and takes less space complexity O(1)
int main () {
    //using bit operation
     vector<int> nums {
            4,
            1,
            2,
            1,
            2
        };
    int a = 0;
    for (auto &i : nums) {
        a ^= i;
    }
    
    cout << a << " \n";
    return a;
}