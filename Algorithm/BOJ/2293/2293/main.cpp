//
//  main.cpp
//  2293
//  동전 1
//  Dynamic Programming
//
//  Created by 최민수 on 2018. 3. 7..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>
using namespace std;
/*
 귀납적 접근법을 사용하여 풀이
 */
int main() {
    ios_base::sync_with_stdio(false);
    // dp에 사용될 배열의 값들을 0으로 초기화해줘야한다.
    int n, k, dp[10001] = {0,}, coin[100];
    cin >> n >> k;
    // 각 동전의 값을 입력받는다.
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    // 0번째 인덱스는 '아무런 동전을 선택하지 않는다' 이므로
    // 경우의 수를 1개 추가한다.
    // 동전이 1,2,5원이 있다면.
    // dp[n] = dp[n-1] + dp[n-2] + dp[n-5];
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {          // 1원부터 시작
            if (coin[i] <= j)
                dp[j] += dp[j-coin[i]];
        }
    }
    // 문제에서 요구하는 k 인덱스에 저장된 dp 배열의 값을 출력
    cout << dp[k] << endl;
    return 0;
}
