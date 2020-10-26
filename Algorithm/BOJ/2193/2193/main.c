//
//  main.c
//  2193
//  이친수 (pinary number)
//  다이나믹 프로그래밍
//  https://www.acmicpc.net/problem/2193
//
//  Created by 최민수 on 2017. 12. 25..
//  Copyright © 2017년 최민수. All rights reserved.
//

#include <stdio.h>

int main() {
    // insert code here...
    int n;
    scanf("%d", &n);
    long long d[91];
    d[0] = 0;
    d[1] = 1;
    for (int i = 2; i <= n; i++) {
        d[i] = d[i-1] + d[i-2];
    }
    printf("%lld", d[n]);
    
    return 0;
}
