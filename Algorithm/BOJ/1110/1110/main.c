//
//  main.c
//  1110
//  더하기 사이클
//  Created by 최민수 on 2017. 4. 29..
//  Copyright © 2017년 최민수. All rights reserved.
//

#include <stdio.h>

int main() {
    int cycle=0, start, cycle_number;
    scanf("%d", &start);
    cycle_number = start;
    do {
        int left, right;
        left = cycle_number / 10;
        right = cycle_number % 10;
        cycle_number = (10*right)+((left+right)%10);
        cycle++;
    } while(start!=cycle_number);
    printf("%d", cycle);
    
    return 0;
}
