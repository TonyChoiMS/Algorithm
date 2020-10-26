//
//  main.c
//  10817
//  세 수
//  Created by TonyChoi on 2017. 4. 22..
//  Copyright © 2017년 TonyChoi. All rights reserved.
//

#include <stdio.h>

int main() {
    int a,b,c;
    scanf("%d %d %d", &a,&b,&c);
    if ((b>=a && a>=c) || (c>=a && a>=b)){
        printf("%d", a);
    }else if ((a>=b && b>=c) || (c>=b && b>=a)){
        printf("%d", b);
    }else{
        printf("%d", c);
    }
    return 0;
}

