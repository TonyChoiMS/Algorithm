//
//  main.c
//  no. 6359
//  About Dynamic Programming
//  만취한 상범
//  Created by 최민수 on 2017. 5. 14..
//  Copyright © 2017년 최민수. All rights reserved.
//

#include <stdio.h>

int main() {
    
    typedef enum {false, true} boolean;
    
    int test_case;
    int i, j, round, room;       // for loop variable
    
    scanf("%d", &test_case);
    
    int n[test_case];          //n equals room count and round count
    for (i=0; i<test_case;i++) {
        scanf("%d", &n[i]);
    }
    
    for (j=0; j<test_case; j++) {
        //boolean initialize
        boolean isOpen[n[j]];
        int open_room_count = n[j];        //열려있는 방의 갯수
        //첫번째 라운드는 무조건 다 오픈이니 값을 true로 초기화
        for (i=0; i<n[j]; i++) {
            isOpen[i] = true;
        }
        //play game. round 1 = 0(skip)
        for (round=1; round<n[j];round++) {
            for (room=0; room<n[j];room++) {
                if ((room+1)%(round+1) == 0) {
                    if (isOpen[room] == true) {
                        isOpen[room] = false;
                        open_room_count--;
                    } else {
                        isOpen[room] = true;
                        open_room_count++;
                    }

                }
            }
        }
        printf("%d\n", open_room_count);
    }
    return 0;
}
