#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/**
 * Given an array nums of n integers where n > 1,  return an array output such that 
 * output[i] is equal to the product of all the elements of nums except nums[i].
 * Example:
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * Constraint: It's guaranteed that the product of the elements of any prefix or suffix 
 * of the array (including the whole array) fits in a 32 bit integer.
 * Note: Please solve it without division and in O(n).
 */

vector<int> productExceptSelf(vector<int> &nums);
int main()
{
    vector<int> test = {
        1, 2, 3, 4};
    vector<int> rest = productExceptSelf(test);
    for (auto &i : rest)
    {
        cout << i << endl;
    }
    return 0;
}

vector<int> productExceptSelf(vector<int> &nums)
{
    int ar_size = nums.size();
    vector<int> forward_product(ar_size, 1), backward_product(ar_size, 1), answer(ar_size);

    //get all foorward product and store it at + 1 position in forward_product (cumulative product)
    for (int i = 0; i < ar_size - 1; i++)
    {
        forward_product[i + 1] = forward_product[i] * nums[i];
    }

    for (int j = ar_size - 1; j > 0; j--)
    {
        backward_product[j - 1] = backward_product[j] * nums[j];
    }

    for (int k = 0; k < ar_size; k++)
    {
        answer[k] = (forward_product[k] * backward_product[k]);
    }

    return answer;
}