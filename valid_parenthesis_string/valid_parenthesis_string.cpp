#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
#include <stack>
#include <string>

using namespace std;

bool checkValidString(string s);
bool checkValidStringGreedy(string s);
int main() {
    string test = "";
    bool answer = checkValidStringGreedy(test);
    cout << boolalpha << answer << endl;
    return 0;
}
bool checkValidStringGreedy(string s) {
    int smallest = 0, largest = 0;
    if (s.empty()) {
        return true;
    }
    for (auto& i : s) {
        smallest += i == '(' ? 1 : -1;//smallest possible open left bracket;
        largest += i != ')' ? 1 : -1;//largest possible open left bracket
        //if at smallest == 0, meaning we have a successful pair
        //if smallest < 0; meaning we need to look at largest, as there may be a excessive )
        if (largest < 0) break;
        smallest = max(smallest, 0);
    }
    return smallest == 0;
}
bool checkValidString(string s) {
    deque<char> char_q;
    stack<char> checker;
    bool answer = true;
    //filled
    for (int i = 0; i < s.size(); i++) {
        char_q.push_back(s[i]);
        cout << s[i] << endl;
    }

    while (!char_q.empty()) {
        char c = char_q.front();
        char q = char_q.back();
        char_q.pop_front();
        char_q.pop_back();
        checker.push(q);
    
        //now check
        if ((c == '(' && checker.top() == '*') || 
        (c == '(' && checker.top() == ')') || (c == '*' && checker.top() == ')')) {
            answer = true;
            cout << "setting to true" << endl;
        }
        else {
            answer = false;
            break;
        }
        checker.pop();
        cout << "is char_q empty? "<< boolalpha << char_q.empty() << endl;
    }
    return answer;
}