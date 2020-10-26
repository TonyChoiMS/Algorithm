//
//  main.c
//  1924
//  2007년
//
//  Created by TonyChoi on 2017. 4. 1..
//  Copyright © 2017년 TonyChoi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define LEN 11
char str1[LEN];
char str2[LEN];

int main() {


    int month;
    int day;
    int sum_day = 0;

    scanf("%s", &str1);
    scanf("%s", &str2);

    month = atoi(str1);
    day = atoi(str2);

    printf("month : %d, day : %d\n", month, day);
    printf("sum %d", sum_day);

    if ((month>=1&&month<=12)&&(day>=1&&day<=31)) {
        printf("%d month", month);
        switch (month) {
            case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                printf("day 31");
                break;

            case 2:
                printf("day 28");
                break;

            case 4:case 6:case 9:case 11:
                printf("day 30");
                break;

            default:
                break;
        }
        printf("asdfasdf");
    } else {
        printf("else");
    }
    printf("if");
    return 0;
}
