#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>

using namespace std;

class FirstUnique
{
public:
    int firstUnique = -1;
    unordered_set<int> checking_table;
    queue<int> queue_table;
    FirstUnique(vector<int> &nums)
    {
        //populate
        for (auto &i : nums)
        {
            if (checking_table.count(i) == 1)
            {
                queue_table.pop(); //stores only unique and have head point to unique
                continue;
            }
            checking_table.insert(i);
            queue_table.push(i);
        }
        if (queue_table.empty())
        {
            queue_table.push(-1);
        }
    }

    //well since update is done in another function, just return var here
    int showFirstUnique()
    {
        return queue_table.front();
    }

    //add and update number_list and unique var accordingly
    void add(int value)
    {

        if (value == queue_table.front())
        {
            //meaning head no longer unique

            while (queue_table.front() == value) //== 1 already existed
            {
                //cout << "popping " << queue_table.front() << endl;
                queue_table.pop();
            }
            if (queue_table.empty())
            {
                queue_table.push(-1);
            }
        }
        //unique
        if (checking_table.count(value) == 0)
        {
            if (queue_table.front() == -1)
            {
                //cout << "front is -1 " << endl;
                checking_table.insert(value);
                //cout << queue_table.front() << endl;
                queue_table.pop();

                queue_table.push(value);
                //cout << queue_table.front() << endl;
            }
            //if unique
            else
            {
                checking_table.insert(value);
                queue_table.push(value);
            }
        }
    }
};

int main()
{
    vector<int> tester = {689};
    FirstUnique firstUnique(tester); //[689,11,12,689] should return something else tho

    int answer = firstUnique.showFirstUnique(); // return 2
    cout << "Answer: " << answer << endl;
    firstUnique.add(689);                     // the queue is now [2,3,5,5]
    answer = firstUnique.showFirstUnique(); // return 2
    cout << "Answer: " << answer << endl;
    firstUnique.add(11); // the queue is now [2,3,5,5,2]
    answer = firstUnique.showFirstUnique();
    cout << "Answer: " << answer << endl;
    firstUnique.add(5); // the queue is now [2,3,5,5,2]
    answer = firstUnique.showFirstUnique();
    cout << "Answer: " << answer << endl;
    firstUnique.add(5); // the queue is now [2,3,5,5,2]
    answer = firstUnique.showFirstUnique();
    cout << "Answer: " << answer << endl;

    return 0;
}