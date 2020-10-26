//
//  main.cpp
//  2156
//  포도주 시식
//  Dynamic Programming
//
//  Created by 최민수 on 2018. 2. 27..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>
using namespace std;

// Parameter 두 수 중 더 높은 수를 리턴해주는 함수
int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    ios_base::sync_with_stdio(false);
    
    // 테스트 케이스 입력
    int n;
    cin >> n;
    
    // memo 배열은 이떄까지 마신 와인의 양을 합한 값을 저장하기 위한 메모이제이션
    // wine 배열은 각 와인잔에 담긴 와인의 양을 저장하는 배열
    // 두 배열을 테스트 케이스에 맞춰 동적 배열로 생성
    int wine[n];
    int memo[n];
    // 문제에서 1번째 잔부터 계산하므로 배열에서 0번째 인덱스를 제외함
    // 0번째 인덱스는 사용하지 않을 것이므로 0으로 초기화
    wine[0] = 0;
    memo[0] = 0;
    // 와인 잔에 따라지는 와인의 양 입력
    for (int i = 1; i <= n; i++) {
        cin >> wine[i];
    }
    // 와인을 마실 때, 연속해서 3잔을 마실 수 없다는 것을 염두에 두며
    // 마신 잔의 양을 memo 배열에 저장
    for (int i = 1; i < 3 &&  i <= n; i++) {
        if (i==1)
            memo[i] = wine[i];
        else
            memo[i] = wine[i] + wine[i-1];
    }
    // 내가 현재의 포도주를 먹지 않았을 경우와 ( memo[i-1] )
    // 현재의 포도주를 마시고 이전꺼를 안마신 경우 ( wine[i] + memo[i-2] )
    // 현재의 포도주와 이전의 포도주를 마신 경우 ( wine[i] + wine[i-1] + memo[i-3] )
    // 이 세가지 경우의 수 중 가장 높은 값을 출력
    for (int i = 3; i <= n; i++) {
        int result = 0;
        result = max(wine[i] + memo[i-2], memo[i-1]);
        result = max(result, wine[i] + wine[i-1] + memo[i-3]);
        memo[i] = result;
    }
    cout << memo[n];
    return 0;
}
