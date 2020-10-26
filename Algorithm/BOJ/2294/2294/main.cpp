//
//  main.cpp
//  2294
//  동전 2
//  Dynamic Programming
//
//  Created by 최민수 on 2018. 3. 19..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>
using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    int coin[101];          // 입력 받을 동전의 값어치(value)
    int dp[100001];         // 배열의 인덱스는 목표 금액을 나타내고, 값은 목표금액을 갖추기 위한 동전의 최소 개수
    // n : 동전의 종류 수
    // k : 테스트케이스에서 원하는 목표 금액
    cin >> n >> k;
    // 동전의 종류에 따른 값어치를 입력
    for (int i = 1; i <= n; i++)
        cin >> coin[i];
    
    dp[0] = 0;
    for (int i = 1; i <= k; i++) {
        dp[i] = 100001;
    }
    
    for ( int i = 1; i <=n; i++) {
        for (int j = coin[i]; j<= k; j++) {
            dp[j] = min(dp[j], dp[j-coin[i]]+1);
        }
    }
    
    if (dp[k] == 100001)
        dp[k] = -1;
    
    cout << dp[k];
    
    return 0;
}
