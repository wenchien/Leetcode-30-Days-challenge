#include <stdlib.h>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <bitset>
using namespace std;
int rangeBitwiseAnd(int m, int n);
int rangeBinaryBitwiseAnd(int m, int n);
int binaryBitHelper(int m, int n, int res);
int rangeBitwiseAndBest(int m, int n);
bool first_time = true;
int main()
{
    int answer = rangeBitwiseAndBest(26,400);
    cout << "Final Answer : " << answer << endl;
}

//Need to review bitwise operations and common problems
int rangeBitwiseAndBest(int m, int n) {
    //best solution
    bitset<8> bit_1(m);
    int i = 0;
    while (m != n) {
        bitset<8> bit_1(m);
        bitset<8> bit_2(n);
        m >>= 1;
        n >>= 1;
        bitset<8> bit_1_after(m);
        bitset<8> bit_2_after(n);
        cout << bit_1 << " and " << bit_1_after << endl;
        cout << bit_2 << " and " << bit_2_after << endl;
        ++i;
    }
    bitset<8> bit_1_after(m << i);
    cout << bit_1_after << endl;
    return m << i;
}

//bruteforce
int rangeBitwiseAnd(int m, int n)
{
    int i = m;
    while (i <= n)
    {
        m = m & (m + 1);
        i++;
    }
    return m;
}

int rangeBinaryBitwiseAnd(int m, int n)
{
    int res = 0;
    if (n-m==1 || m==n) {
        return m&n;
    }
    int answer = binaryBitHelper(m, n, res);
    return answer;
}

int binaryBitHelper(int m, int n, int res)
{  
    if (first_time == true)
    {
        res = (m + n) / 2;
        first_time = false;
    }

    cout << "Other Time" << endl;
    int mid = (m + n) / 2;
    res &= mid;//if identical, then it will return itself
    cout << mid << endl;
    cout << res << endl;
    if (m > n)
    {
        cout << "Returned due to m >= n" << endl;
        return res;
    }
    return binaryBitHelper(m, mid - 1, res) & binaryBitHelper(mid + 1, n, res);
}