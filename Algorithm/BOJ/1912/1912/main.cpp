//
//  main.cpp
//  1912
//  연속합
//  Dynamic Programming
//
//  Created by 최민수 on 2018. 2. 27..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    // 테스트 케이스 입력
    int n;
    cin >> n;
    // number 배열은 입력받은 숫자를 저장할 배열
    // memo 배열은 더한 값들을 저장할 메모이제이션 배열
    int number[n];
    int memo[n];
    // 인덱스 0번은 쓰지 않을 것이므로 0으로 초기화시켜놓음.
    number[0] = 0;
    memo[0] = 0;
    // 숫자 입력받기
    for (int i = 1; i <= n; i++) {
        cin >> number[i];
    }
    // 1번쨰 인덱스부터 나머지 모든 수들과 차례대로 더해보며
    // 만약 두 수의 합이 두수를 합하지 않은 수보다 작은 경우엔,
    // 합하지 않은 수를 memo 배열에 저장한다.
    for (int i = 1; i <= n; i++) {
        if (memo[i-1] + number[i] > number[i]) {
            memo[i] = memo[i - 1] + number[i];
        } else {
            memo[i] = number[i];
        }
    }
    // memo에 저장한 모든 값들 중 가장 큰값을 비교하여 result 변수에 저장 후 출력
    int result = memo[1];
    for (int i = 2; i<= n; i++) {
        if (result < memo[i])
            result = memo[i];
    }
    cout << result << endl;
    return 0;
}
