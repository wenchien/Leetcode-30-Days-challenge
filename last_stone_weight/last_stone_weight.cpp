#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
int getStoneWeight();
int lastStoneWeight(vector<int> &stones);
priority_queue<int> check_queue;
int main()
{
    vector<int> stones = {
        2, 2
    };
    int value = lastStoneWeight(stones);
    cout << "Last Stone Weight: " << value << endl;
    return 0;
}

int lastStoneWeight(vector<int> &stones) {
    for (int i = 0; i < stones.size(); i++) {
        check_queue.push(stones[i]);//works similiar to max_heap
    }
    return getStoneWeight();
}


//there are 2 base cases;
int getStoneWeight() {
    if (check_queue.empty()) { //or just do check_queue.empty()
        return 0;//don't forget if remainder stone is 2 (even), both stones
        //are destroyed and should return 0;
    }
    //work directly on check_queue
    if (check_queue.size() == 1) {
        return check_queue.top();
    }
    int y = check_queue.top();
    check_queue.pop();
    int x = check_queue.top();
    check_queue.pop();
    //now given the condition, do checking
    if (x == y) {
        cout << "Both stones are destroyed" << endl;
        
    }
    else if (x != y) {
        cout << "Stones have different values" << endl;
        int value = y - x;//x is destroyed 
        //now we should add value variable back to check_queue
        check_queue.push(value);
    }
    return getStoneWeight();
}