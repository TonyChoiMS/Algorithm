//
//  main.cpp
//  10844
//  쉬운 계단 수
//  Dynamic Programming
//
//  Created by 최민수 on 2018. 3. 5..
//  Copyright © 2018년 최민수. All rights reserved.
//

/*
 계단수란 인접한 모든 자리수의 차이가 1이 나는 수
 이 때 자리수의 길이가 n인 계단 수가 몇개 있는지 알아보자
 이 때, 1 <= n <= 100
 */
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    
    int n;
    int dp[101][10];
    int sum = 0;
    int mod = 1000000000;
    cin >> n;
    
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;
    
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j ++) { 
            if (j == 0)
                dp[i][0] = dp[i-1][1] % mod;
            else if (j == 9)
                dp[i][9] = dp[i-1][8] % mod;
            else
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % mod;
        }
    }
    for (int i = 1; i < 10; i++)
        sum = (sum + dp[n][i]) % mod;
    
    cout << sum << endl;
    return 0;
}
