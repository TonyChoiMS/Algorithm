//
//  main.cpp
//  1149
//  RGB거리
//  Dynamic Programming
//
//  Created by 최민수 on 2018. 3. 2..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>
using namespace std;

int Min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    ios_base::sync_with_stdio(false);
    // 테스트 케이스 갯수 입력
    int N;
    cin >> N;
    // house : 테스트 케이스에서 페인트를 칠하는 비용 배열
    // answer : 페인트를 칠하는 비용을 합산해서 답변으로 채택할 값 저장
    // 집의 인덱스를 1부터 시작하기 위해 테스트케이스 갯수 N에 +1을 더한 배열로 생성 후, 0번째 인덱스는 0으로 초기화
    int house[N+1][3];
    int answer[N+1][3];
    house[0][0] = house[0][1] = house[0][2] = answer[0][0] = answer[0][1] = answer[0][2]
    = 0;
    // 페인트를 칠하는 비용을 house 배열에 입력
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> house[i][j];
        }
    }
    // answer 배열 0, 1, 2번째 인덱스에 각각 다른 색상을 선택했을 때 드는 비용을 저장
    // Loop를 돌면서 확인해야될 경우의 수는 총 세가지이다.
    // 1. 첫번째를 R로 칠한 경우(0번째 인덱스)
    // 2. 첫번째를 G로 칠한 경우(1번째 인덱스)
    // 3. 첫번째를 B로 칠한 경우(2번째 인덱스)
    // answer 배열에 i번째 집에 0,1,2 번쨰 인덱스에 위에 해당 경우의 수는
    // i-1번째 answer에 저장했던 값 중 더 작은수 + 현재 인덱스의 페인트 칠하는 비용을 더한다.
    for (int i = 1;  i <= N; i++) {
        answer[i][0] = Min(answer[i-1][1], answer[i-1][2]) + house[i][0];
        answer[i][1] = Min(answer[i-1][2], answer[i-1][0]) + house[i][1];
        answer[i][2] = Min(answer[i-1][0], answer[i-1][1]) + house[i][2];
    }
    // Loop를 다돌고 나면 answer 배열의 N번째 인덱스에 저장되있는 0,1,2번째 값 중 가장 작은 값을 해답으로 출력
    cout << Min(Min(answer[N][0], answer[N][1]), answer[N][2]);
    return 0;
}
