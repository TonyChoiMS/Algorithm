//
//  main.cpp
//  9465
//  스티커
//  Dynamic Programming
//
//  Created by 최민수 on 2018. 3. 11..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 DP 문제
 점화식 :
 dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + point[0][i];
 dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + point[1][i];
 */

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    ios_base::sync_with_stdio(false);
    // 테스트 케이스 입력
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        int point[2][n+1], dp[2][n+1];
        for (int j = 0; j < 2; j++) {
            for (int k = 1; k <= n; k++) {
                cin >> point[j][k];
                
            }
        } // 테스트 케이스 입력 끝
        // dp 배열의 초기값을 설정 (처음부터 n-2 번째 까지 검사하므로 배열의 2번째까지 초기화)
        dp[0][0] = dp[1][0] = 0;
        dp[0][1] = point[0][1];
        dp[1][1] = point[1][1];
        // 선택한 스티커의 전후좌우의 스티커는 사용하지 못하므로,
        // 2차원 배열로 생각할 때 현재 선택한 스티커에서 다음 스티커는 n+1번째의 대각선 또는 n+2번째의 스티커를 고르게 되어있다.
        // 고로 첫 시작점이 0번째 인덱스일 때와, 1번째 일 떄 두가지 경우의 수를 두고 탐색 시작
        // 2번째부터 n번째까지 검사하면서 더 높은 값을 dp 배열에 저장한다.
        for (int j = 2; j <= n; j++) {
            dp[0][j] = max(dp[1][j-1], dp[1][j-2]) + point[0][j];
            dp[1][j] = max(dp[0][j-1], dp[0][j-2]) + point[1][j];
        }
        // 최종적으로 시작점 인덱스가 0번째일 때와 1번째 일때 중 어느곳이 더 점수가 높은 값으로 출력
        cout << max(dp[0][n], dp[1][n]) << endl;
        
    }
    return 0;
}
