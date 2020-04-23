#include <stdlib.h>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <map>
//Day 22
//Given an array of integers and an integer k,
//you need to find the total number of continuous subarrays whose sum equals to k.
using namespace std;
int subarraySum(vector<int> &nums, int k);
map<int, int> count_checker;
int main()
{
    vector<int> tester = {1, 1, 1};
    int answer = subarraySum(tester, 2);
    cout << "Final Answer : " << answer << endl;
    return 0;
}


//we can try two pointer approach
//If a key(sum - k) existed, meaning there was a subarray before where the sum
//of that subarray is equal to the key, therefore a count value existed for that key
int subarraySum(vector<int> &nums, int k)
{
    int count = 0;
    int cumulated_sum = 0;
    count_checker[0] = 1;//default value for 0
    for (int i = 0; i < nums.size(); i++) {
        cumulated_sum += nums[i];
        if (count_checker.count(cumulated_sum - k) > 0) {
            count += count_checker[cumulated_sum - k];
        }
        if(count_checker.count(cumulated_sum) > 0) {
            count_checker[cumulated_sum]++;
        }
        else {
            count_checker[cumulated_sum] = 1;
        }
        
    }
    return count;
}