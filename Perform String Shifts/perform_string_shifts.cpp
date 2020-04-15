#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

/** Problem Statement: 
 * You are given a string s containing lowercase English letters,
 *  and a matrix shift, where shift[i] = [direction, amount]:
 * 
 * direction can be 0 (for left shift) or 1 (for right shift). 
 * amount is the amount by which string s is to be shifted.
 * A left shift by 1 means remove the first character of s and append it to the end.
 * Similarly, a right shift by 1 means remove the last character of s and add 
 * it to the beginning.
*/
using namespace std;
string stringShift(string s, vector<vector<int>> &shift);
string stringRotation(string s, vector<vector<int>> &rotation);
long mod(long a, long b);
int main()
{
    string s = "xbjdxpgqrshm";
    vector<vector<int>> shift = {
        {1, 1},
        {1, 3}, 
        {0, 12}, 
        {1, 12}, 
        {1, 2},
        {0, 8}, 
        {0, 11}, 
        {1, 5}, 
        {0, 4}, 
        {1, 1}, 
        {0, 9}, 
        {1, 10}
    };
    string answer = "";
    answer = stringRotation(s, shift);
    cout << "Final Shift Result: " << answer << endl;
    return 0;
}

//remember to consider if shifting goes beyond s.size(), like by 2x or 3x...etc
//however this is a bit overengineering, and strings in c++ is mutable...lol
string stringShift(string s, vector<vector<int>> &shift)
{
    int shifts = 0; //0 = no shifts, negatives = shift left, positive = right shift
    string processed_string = "";
    for (auto& shifting : shift) {
        cout << shifting[0] << endl; 
        if (shifting[0] == 0) {
            shifts -= shifting[1];
        }
        else if (shifting[0] == 1) {
            shifts += shifting[1];
        }
    }

    int remainder_shifts = 0;
    if (abs(shifts) > s.size()) {
        remainder_shifts = mod(shifts, s.size());
    }
    else {
        remainder_shifts = shifts;
    }

    //perform final string manipulation
    //a total of three cases
    if (remainder_shifts == 0) {
        processed_string = s;
    }
    else if (remainder_shifts < 0) {
        cout << "Shifting Left" << endl;
        int abs_shift = abs(remainder_shifts);//we can't negavtives so yeah, doing abs
        //left shift meaning take the first shifts amount of add to back
        processed_string.append(s.substr(abs_shift));
        processed_string.append(s.substr(0, abs_shift));
        
    }
    else if (remainder_shifts > 0){
        cout << "Shift Right" << endl;
      //right shift meaning take the last shifts amount and add to front
      processed_string.append(s.substr(s.size() - remainder_shifts));
      processed_string.append(s.substr(0, s.size()-remainder_shifts));
    }
    return processed_string;
}

long mod(long a, long b)
{ return (a%b+b)%b; }

//a better solution is to use std::rotate
//good thing to know coming from Java
string stringRotation(string s, vector<vector<int>> &rotation) {
    int n = s.length();
    for (auto & i : rotation) {
        int d = i[0], count = i[1] % n;//this is to remove any possibility of i[n] > s.length();
        if (d == 0) {
            rotate(s.begin(), s.begin() + count, s.end());//left shift, take the first count characters
        }
        else {
            rotate(s.begin(), s.begin() + n - count, s.end());//right shift, taking last n-count characters
        }
    }
    return s;
}