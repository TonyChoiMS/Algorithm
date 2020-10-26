//
//  main.c
//  9095
//. 1,2,3 더하기
//  Dynamic Programming
//
//  Created by 최민수 on 2017. 12. 4..
//  Copyright © 2017년 최민수. All rights reserved.
//

#include <stdio.h>

int d[11];

int main() {
    // d[0] ~ d[11] 까지 경우의 수를 모두 집어넣어놓음.
    d[0] = 1;
    // d[i] = d[i-1] + d[i-2] + d[i-3] 의 공식이 성립
    // d[0]은 초기화 했으니 d[1]부터 d[11]까지
    // for문을 돌며 위 점화식을 대입
    // if문의 경우, 1,2,3의 경우를 예외처리하기 위한 분기문
    for (int i=1; i <= 10; i++) {
        if (i-1 >= 0) {
            d[i] += d[i-1];
        }
        if (i-2 >= 0) {
            d[i] += d[i-2];
        }
        if (i-3 >= 0) {
            d[i] += d[i-3];
        }
    }
    int T;
    scanf("%d", &T);
    // 테스트 케이스만큼 루프를 돌며 원하는 n값에 대한 결과값을 print
    while (T--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", d[n]);
    }
    return 0;
}
