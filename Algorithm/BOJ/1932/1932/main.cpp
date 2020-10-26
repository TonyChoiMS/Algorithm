//
//  main.cpp
//  1932
//  숫자 삼각형
//  Dynamic Programming
//
//  Created by 최민수 on 2018. 4. 9..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;  // 테스트케이스 입력
    cin >> n;
    long long array[501][501] = {0};  // 숫자 삼각형을 저장할 배열
    long long dp[501][501] = {0};     // 숫자 삼각형에서 저장되는 순서를 저장하는 배열
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i+1; j++) {
            cin >> array[i][j]; // 숫자 삼각형 입력
        }
    }
    dp[0][0] = array[0][0];     // dp배열의 0번째 인덱스를 0번째 array로 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i+1; j++) {
            if (dp[i + 1][j] < dp[i][j] + array[i + 1][j])
                dp[i + 1][j] = dp[i][j] + array[i + 1][j];
            if (dp[i + 1][j + 1] < dp[i][j] + array[i + 1][j + 1])
                dp[i + 1][j + 1] = dp[i][j] + array[i + 1][j + 1];
        }
    }
    long long max = 0;
    for (int i = 0; i < n; i++) {
        if (dp[n-1][i] > max)
            max = dp[n-1][i];
    }
    cout << max;
    
    return 0;
}
