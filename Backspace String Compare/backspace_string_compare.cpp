#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
bool backspaceCompare(string S, string T);
int main()
{
    bool answer = false;
    string S = "ad#c";
    string T = "ac";
    answer = backspaceCompare(S, T);
    cout << "The answer is " << boolalpha << answer << endl;
    return 0;
}

//O(m+n)
bool backspaceCompare(string S, string T)
{
    string processed_s = "";
    string processed_t = "";
    bool answer = false;

    //have two for loopsp here where we can simply just loop through both
    //worse case is either m or n, where m is S.size() and n is T.size()
    //in the problem constraint, no mention of m=n.
    for (int i = 0; i < S.size(); i++) {
        //start calculating
        cout << "Checking " << S[i] << endl;
         if (S[i] == '\0')
        {
            break;
        }
        else {
             if (S[i] != '\0' && S[i] != '#')
            {
                processed_s.push_back(S[i]);
            }
            else if (S[i] == '#' && !processed_s.empty()) // if processed string is not empty
            {//or else we may run into segmentation fault here
                processed_s.pop_back();
            }
        }

    }

    for (int j = 0; j < T.size(); j++) {
        cout << "Checking " << T[j] << endl;
         if (T[j] == '\0')
        {
            break;
        }
        else
        {
            if (T[j] != '\0' && T[j] != '#')
            {
                processed_t.push_back(T[j]);
            }
            else if (T[j] == '#' && !processed_t.empty())
            {
                processed_t.pop_back();
            }
        }
    }
    cout << "Final T string " << processed_t << endl;
    cout << "Final S string " << processed_s << endl;
    

    if (processed_t == processed_s) {
        answer = true;
    }
    return answer;
}