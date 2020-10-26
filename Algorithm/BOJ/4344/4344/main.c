//
//  main.c
//  4344
//  평균은 넘겠지
//  Created by 최민수 on 2017. 4. 29..
//  Copyright © 2017년 최민수. All rights reserved.
//

#include <stdio.h>

int main() {
    
    int i, j, k, c, m, student;
    
    scanf("%d", &c);
    float result[c];
    for (i=0;i<c;i++) {
        scanf("%d", &student);
        float score[student];
        float avg, sum = 0.0;
        
        //get student's total score
        for (j=0; j<student; j++){
            scanf("%f", &score[j]);
            sum += score[j];
        }
        //get average
        avg = sum/student;
        //find student's score higher than average
        //initialize overflow
        float overflow = 0.0, f_student = 0.0;
        for (m=0;m<student;m++){
            f_student++;
            if(score[m]>avg){
                overflow++;
            }
        }
        result[i] = overflow/f_student*100;
    }
    for (k=0;k<c;k++) {
        printf("%0.3f%%\n", result[k]);
    }
    
    return 0;
}
