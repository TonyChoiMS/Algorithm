//
//  main.c
//  11052
//  붕어빵 판매하기.
//
//  Created by 최민수 on 2017. 12. 4..
//  Copyright © 2017년 최민수. All rights reserved.
//

#include <stdio.h>
int a[1001];    //
int d[1001];    // 붕어빵 i개를 팔아서 얻을 수 있는 최대 수익
int main() {
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i=1; i<=n;i++) {
        for (int j=1; j<=i; j++) {
            if (d[i] < d[i-j] + a[j]) {
                d[i] = d[i-j] + a[j];
            }
        }
    }
    printf("%d\n", d[n]);
    return 0;
}
