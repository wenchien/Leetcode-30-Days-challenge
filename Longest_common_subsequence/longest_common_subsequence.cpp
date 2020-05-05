#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <string.h>

using namespace std;
int longestCommonSubsequence(string text1, string text2);
int longestHelper(int i, int j, string text1, string text2);
int main()
{
    string test_1 = "ylqpejqbalahwr";
    string test_2 = "yrkzavgdmdgtqpg";
    int answer = longestCommonSubsequence(test_1, test_2);
    cout << answer << endl;
}
/**
 * "ylqpejqbalahwr"
"yrkzavgdmdgtqpg"
 */
int longestCommonSubsequence(string text1, string text2)
{
    int m = text1.size();
    int n = text2.size();
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp[0][0]) * (m + 1) * (n + 1));
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (text1[i] == text2[j])
                dp[i][j] = 1 + dp[i + 1][j + 1];
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    return dp[0][0];
}
