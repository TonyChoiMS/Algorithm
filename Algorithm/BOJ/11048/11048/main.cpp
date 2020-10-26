//
//  main.cpp
//  11048
//  이동하기
//  Dynamic Programming
//
//  Created by 최민수 on 2018. 4. 6..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>
using namespace std;

// 인트형 두 정수 중, 큰 값을 리턴하는 함수
int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    ios_base::sync_with_stdio();
    int n,m;        // 맵의 크기. n : 행, m : 열
    int array[1001][1001] = {0};        // 맵의 사탕이 놓인 수를 저장할 배열
    int dp[1001][1001] = {0};           // 맵을 [1][1]부터 이동하면서 획득하는 사탕의 수를 저장할 배열
    cin >> n >> m;      // 맵의 크기 입력
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> array[i][j]; // 맵에 있는 사탕의 수를 입력
        }
    }
    // array 맵의 이동은 [i+1][j],[i][j+1], [i+1][j+1] 로 가능하다.
    // 그러므로 세가지 방향 중, 가장 큰 값만 선택하면 된다.
    // 선택됬으면 다음 칸으로 진행
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int result = 0;
            result = max(dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1]));
            dp[i][j] = result + array[i][j];
        }
    }
    
    cout << dp[n][m] << endl;       // 최종 결과 출력
    return 0;
}
