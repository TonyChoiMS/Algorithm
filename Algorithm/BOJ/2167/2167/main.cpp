//
//  main.cpp
//  2167
//  2차원 배열의 합
//  Dynamic Programming
//
//  Created by 최민수 on 2018. 3. 13..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 다이나믹 프로그래밍
 dp배열에 입력값의 합들을 모두 저장해놓음.
 후에 원하는 원하는 (i,j) ~ (x,y)까지의 합을 구하는 공식은
 dp배열에서 (i,j)의 값에서 중복되는 값들을 제거 후, 남는 (x,y)까지의 합을 출력하면 되는 문제
 2차원 배열의 합을 구하는 공식은 2차원 배열을 손으로 그려보면서 확인하면 더 쉽게 이해할 수 있다.
 점화식 : dp[i][j] ~ dp[x][y] = dp[x][y] - dp[i-1][y] - dp[x][j-1] + dp[i-1][j-1]
 */
int main() {
    ios_base::sync_with_stdio(false);
    
    int n, m, K, i, j, x, y;
    cin >> n >> m;
    // BOJ에서는 동적 할당을 할 경우, 런타임 에러 발생
    int array[301][301];
    int dp[301][301] = {0};     // 0번째 인덱스를 사용하기 때문에 배열의 값을 0으로 초기화 시켜놓음
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // 각 배열의 값을 입력 받음
            cin >> array[i][j];
            // 입력받은 배열의 값을 바로 dp에 이전 배열들의 합들을 고려하며 저장
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + array[i][j];
        }
    }
    // 테스트 케이스 입력
    cin >> K;
    for (int p = 0; p < K; p++) {
        cin >> i >> j >> x >> y;
        // 결과값 출력
        cout << (dp[x][y] - dp[i-1][y] - dp[x][j-1] + dp[i-1][j-1]) << endl;
    }
    return 0;
}
