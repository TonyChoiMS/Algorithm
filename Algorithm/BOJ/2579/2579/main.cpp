//
//  main.cpp
//  2579
//  계단오르기
//
//  Created by 최민수 on 2018. 1. 15..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>
using namespace std;

int Max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    ios_base::sync_with_stdio(false);
    int count, i;
    cin >> count;
    // 계단의 점수를 저장할 배열
    int stair[305];
    // 여태까지 올라온 계단 점수의 총 합을 저장할 배열
    int dp[305];
    for (i=1; i <= count; i++) {
        cin >> stair[i];
    }
    // 첫번째부터 3번째 계단까지 합을 저장
    // 계단의 수가 3이하일 경우를 대비해서 범위를 1~3까지와 1~count까지 두가지 범위로 설정해서 저장
    for (i = 1; i <= 3 && i <= count; i++) {
        if (i != 3) {
            dp[i] = dp[i-1] + stair[i];
        } else {
            dp[i] = Max(dp[i-2] + stair[i], stair[i-1] + stair[i]);
        }
    }
    // 3번째 계단의 합을 가지고 4번째 계단부터 각 계단마다 두칸을 한번에 뛰는 것과 한칸 뛴 후 두칸을 올라가는 것 중 값이 더 큰쪽을 dp에 저장
    for (i = 4; i <= count; i++) {
        dp[i] = Max(dp[i-2] + stair[i], dp[i-3] + stair[i-1] + stair[i]);
    }
    cout << dp[count] << endl;
    return 0;
}
