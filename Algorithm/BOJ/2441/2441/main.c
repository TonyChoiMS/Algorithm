//
//  main.c
//  2441
//
//  Created by TonyChoi on 2017. 4. 1..
//  Copyright © 2017년 TonyChoi. All rights reserved.
//

#include <stdio.h>

int main() {
    
    int a = 0;
    int i;
    int j;
    int k;
    
    scanf("%d", &a);
    
    if (a >=1 && a <=100) {
        for (i=0; i<a; i++) {
            for (k=0; k<i; k++) {
                printf(" ");
            }
            for (j=a-i; j>0; j--) {
                printf("*");
            }
            printf("\n");
            
        }
    }
    
    return 0;
}
