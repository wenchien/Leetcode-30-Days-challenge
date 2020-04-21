#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
/**Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n). */
int search(vector<int>& nums, int target);
int searchPivot(vector<int>& nums, int target);
int binarySearch(vector<int>& nums, int high, int low, int target);
int main () {
    //many ways of solving this
    vector<int> tester {
        4,5,6,7,0,1,2
    };
    //int answer = search(tester, 3);
    //cout << answer << endl;

    int answer = searchPivot(tester, 3);
    cout << answer << endl;
}

int search(vector<int>& nums, int target) {
    //if we use say a hash table, the loading of hash table is O(n), worst case and best case is always O(n)
    //we will use front and rear search, divide and conquer
    int front = 0;
    int rear = nums.size() - 1;
    while (rear >= front) {
        if (nums[front] == target) {
            return front;
        }
        else if (nums[rear] == target) {
            return rear;
        }
        else {
            front++;
            rear--;
        }
    }
    return -1;
}

//this method assumes sorted and rotated array
//we will need to get to the pivot point and then we can do binary search
int searchPivot(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int answer_int = 0;
    answer_int = binarySearch(nums, high, low, target);
    //now we need to compare values
    // find pivot

    return answer_int;
}

int binarySearch(vector<int>& nums, int high, int low, int target) {
   //we need to compare the ends of the subarrays 
   //low and mid / mid and high]
   int answer = -1;
   int mid = (low + high) / 2;
   if (low > high) {
       return -1;
   }
   if (nums[mid] == target) {
       cout << "Target Found: " << mid << endl;
       return mid;
   }

   if (nums[low] <= nums[mid]) {//then left side is sorted
       if (target >= nums[low] && target <= nums[mid]) {
           //recursive calls on this
           answer = binarySearch(nums, mid - 1, low, target);
       }
       else {//if left side doesn't seem to be sorted [4561] case
           answer = binarySearch(nums, high, mid + 1, target);
       }
   }
   else {//if right side is sorted
        if (target >= nums[mid] && target <= nums[high]) {
            answer = binarySearch(nums, high, mid + 1, target);//search right side
        }
        else {
            answer = binarySearch(nums, mid - 1, low, target); 
        }
   }
    return answer;
}