//
//  main.c
//  11721
//  열 개씩 끊어 출력하기
//  Created by TonyChoi on 2017. 4. 22..
//  Copyright © 2017년 TonyChoi. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main() {
    int i, j;
    char str[101] = "";
    
    scanf("%s", str);
    j=0;
    for (i=0;i<strlen(str);i++) {
        printf("%c", str[i]);
        j++;
        if (j==10 || j==20 || j==30 || j==40 || j==50 || j==60 || j==70 || j==80 || j==90) {
            printf("\n");
        }
    }
    
    return 0;
}
