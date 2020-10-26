//
//  main.c
//  9498
//  시험성적
//  Created by TonyChoi on 2017. 4. 22..
//  Copyright © 2017년 TonyChoi. All rights reserved.
//

#include <stdio.h>

int main() {
    
    int score;
    
    scanf("%d", &score);
    if (score>89){
        printf("A");
    }else if (score>79 && score<90){
        printf("B");
    }else if (score>69 && score<80){
        printf("C");
    }else if (score>59 && score<70){
        printf("D");
    }else{
        printf("F");
    }
    
    return 0;
}
