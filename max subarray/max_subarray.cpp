#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
int maxSubArray(vector<int> &nums);
vector<int> subarray;
int main()
{
    vector<int> nums {
        -2, 
        1, 
        -3, 
        4, 
        -1, 
        2, 
        1, 
        5, 
        -4
    };
    maxSubArray(nums);
    return 0;
}

int maxSubArray(vector<int> &nums)
{
    //initialization
    //set max to itself
    int answer = 0;
    int max_all = nums[0];
    int max_so_far = nums[0];

    if (nums.size() == 1)
    {
        return nums[0]; //return itself as max
    }
    else
    {
        for (int i = 1; i < nums.size(); i++) {
            max_so_far = max(nums[i], max_so_far + nums[i]);
            //compare values, the max function is used to indicate the element of the starting indices, if max is updated, max_so_far == nums[i], 
            //then it means i is the first element of a subarray / the start of a new subarray
            if (max_so_far > max_all) {
                max_all = max_so_far;
            }
            cout << "Update Iteration " << i << ": \n";
            cout << "Max So Far: " << max_so_far << "\n";
            cout << "Overall Max: " << max_all << "\n";
        }
    }
    answer = max_all;
    return answer;
}