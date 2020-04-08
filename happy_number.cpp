#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
bool calculateAndReturn(int n);
map<int, int> checkTable;

//if a give problem has infinite condition such as this, 
//should stop when no solution is found, means looping,
//and generally requires a some form of checking table
//to check if a certain number has appeared again.
//Therefore you can then use that as condition to stop
//the infinite loop.
int main()
{
    int number = 19;
    bool found = false;
    found = calculateAndReturn(number);
    return 0;
}

bool calculateAndReturn(int n)
{
    int answer = 0;
    bool found = false;

    do
    {
        if (n == 0)
        {
            answer += pow(n, 2);
            break;
        }
        int digit = n % 10;
        //putchar('0' + digit);
        answer += pow(digit, 2);
        n /= 10;
        cout << answer << "\n";

    } while (n >= 0);
    if (checkTable[answer] == 0)
    {
        cout << "NOt a repeated number, adding...\n"
             << "\n";
        checkTable[answer] = 1;
    }
    else if (checkTable[answer] == 1)
    {
        cout << "No solution due to redundancy"
             << "\n";
        return false;
    }

    if (answer != 1)
    {
        found = calculateAndReturn(answer);
    }
    else
    {
        found = true;
        cout << "Result: " << boolalpha << found;
    }
    return found;
}