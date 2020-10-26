//
//  main.c
//  1546
//  평균
//
//  Created by 최민수 on 2017. 4. 29..
//  Copyright © 2017년 최민수. All rights reserved.
//

#include <stdio.h>

int main() {
    int i, j, subject;

    scanf("%d", &subject);
    float score[subject];
    float new_score[subject];
    float sum=0, max=0;
    
    for (i=0; i< subject; i++) {
        //get current score
        scanf("%f", &score[i]);
        //search max score value
        if (max<score[i]) {
            max = score[i];
        }
    }
    //convert new avg score
    for (j=0; j<subject; j++) {
        //get new_score and sum
        new_score[j] = score[j]/max*100;
        sum += new_score[j];
    }
    float avg = sum/subject;
    printf("%0.2f", avg);
    return 0;
}
