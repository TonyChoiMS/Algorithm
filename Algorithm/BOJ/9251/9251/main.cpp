//
//  main.cpp
//  9251
//  Dynamic Programming
//  LCS(Longest Common Subsequence)
//
//  Created by 최민수 on 2018. 5. 21..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    char a[1111], b[1111];
    int dp[1111][1111];
    int i, j;
    
    scanf("%s\n%s", a+1, b+1);
    
    for (i = 1; a[i]; i++) {
        for (j = 1; b[j]; j++) {
            dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1] + (a[i] == b[j])});
        }
    }
    cout << dp[i-1][j-1];
    return 0;
}
