#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class FirstUnique
{
public:
    int firstUnique = -1;
    map<int, int> number_list;
    vector<int> original_arr;
    FirstUnique(vector<int> &nums)
    {
        original_arr = nums;
        //populate
        for (auto &i : nums)
        {
            //because of a map, you can just add without if-else
            number_list[i]++;
        }

        //then a for loop to check
        for (auto &i : nums)
        {
            if (firstUnique == -1 && number_list[i] == 1)
            {
                firstUnique = i;
            }
        }
    }

    //well since update is done in another function, just return var here
    int showFirstUnique()
    {
        return firstUnique;
    }

    //add and update number_list and unique var accordingly
    void add(int value)
    {
        original_arr.push_back(value);
        number_list[value]++;
        if (number_list[value] == 1)
        {
            //unique but may not need to update unless firstUnique is -1
            cout << "Just added a new one i guess" << endl;
            if (firstUnique == -1)
            {
                firstUnique = value;
            }
        }
        else
        {
            //meaning the current value exists, for loop again to find, iterating through origina array
            for (int j = 0; j < number_list.size(); j++)
            {
                if (number_list[original_arr[j]] == 1)
                {
                    cout << "Found a unique" << endl;
                    firstUnique = original_arr[j]; //then it is unique
                    break;
                }
                else
                {
                    cout << "Not Unique" << endl;
                    firstUnique = -1;
                }
            }
        }
    }
};

int main()
{
    vector<int> tester = {7, 7, 7, 7, 7, 7};
    FirstUnique firstUnique(tester); //[689,11,12,689] should return something else tho

    int answer = firstUnique.showFirstUnique(); // return 2
    cout << "Answer: " << answer << endl;
    firstUnique.add(7);                     // the queue is now [2,3,5,5]
    answer = firstUnique.showFirstUnique(); // return 2
    cout << "Answer: " << answer << endl;
    firstUnique.add(3);                     // the queue is now [2,3,5,5,2]
    answer = firstUnique.showFirstUnique(); // return 3
    cout << "Answer: " << answer << endl;
    firstUnique.add(3);                     // the queue is now [2,3,5,5,2,3]
    answer = firstUnique.showFirstUnique(); // return -1
    cout << "Answer: " << answer << endl;
    firstUnique.add(7);                     // the queue is now [2,3,5,5]
    answer = firstUnique.showFirstUnique(); // return 2
    cout << "Answer: " << answer << endl;
    firstUnique.add(17);                    // the queue is now [2,3,5,5,2,3]
    answer = firstUnique.showFirstUnique(); // return -1
    cout << "Answer: " << answer << endl;
    return 0;
}