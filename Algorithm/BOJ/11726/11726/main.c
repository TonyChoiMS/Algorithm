//
//  main.c
//  11726
//  2xn 타일링
//. memoization
//
//  Created by 최민수 on 2017. 12. 3..
//  Copyright © 2017년 최민수. All rights reserved.
//

#include <stdio.h>

int main() {
    int m[1001];
    m[0] = 1;
    m[1] = 1;
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        m[i] = m[i-1] + m[i-2];
        m[i] %= 10007;
    }
    printf("%d\n", m[n]);
    return 0;
}
