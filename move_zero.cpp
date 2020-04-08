#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;
void moveZeroes(vector<int> &nums);
void moveZeroesBetter(vector<int> &nums);
void printVector(vector<int> &nums);
int main()
{
    vector<int> vec = {
        0,
        1,
        0,
        3,
        12};
    moveZeroes(vec);
    printVector(vec);
}

//without any additional arrays
//but apparently you can use a temp array for this problem.....lmao ok
void moveZeroes(vector<int> &nums)
{
    int zeroes = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            zeroes++;
        }
    }
    nums.erase( std::remove(nums.begin(), nums.end(), 0), nums.end());
    try
    {
        for (int j = zeroes; j > 0; j--)
        {
            nums.push_back(0);
            //zeroes--;
        }
    }
    catch (const std::bad_alloc &)
    {
        cout << "Error Bad Alloc" << endl;
    }
}


void printVector(vector<int> &nums)
{
    for (const auto &i : nums)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}