//
//  main.cpp
//  11727
//  2 * n 타일링 2
//  Dynamic Programming
//
//  Created by 최민수 on 2018. 3. 9..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int i, n, dp[1001] = {};
    dp[0] = 1;
    dp[1] = 1;
    cin >> n;
    // Dp 점화식 dp[n] = dp[n-1] + (dp[n-2] *2)
    // 2*n번째까지 타일을 채울 수 있는 경우의 수는
    // 제일 마지막의 타일을 2*1, 1*2, 2*2 타일 세가지의 경우를 들 수 있다.
    // 그렇기에 n번째의 값은 n-1번째까지의 합(마지막을 1*2 타일로 채울 떄)
    // + (n-2번째까지의 합 * 2)(마지막을 2*1 또는 2*2 타일로 채울 때)
    for (i = 2; i<= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]*2) % 10007;
    }
    cout << dp[n];
    return 0;
}
