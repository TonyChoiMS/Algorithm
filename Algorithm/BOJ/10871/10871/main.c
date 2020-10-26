/**
 *  10871
 *  X보다 작은 수
 *
 *  since : 2017-04-22
 *  author : Tony Choi
 */

#include <stdio.h>

int main(){
    
    int i, n, x;
    scanf("%d %d", &n, &x);
    
    int number[n];
    for (i=0; i<n; i++){
        scanf("%d", &number[i]);
    }
    
    for (i=0; i<n; i++){
        if (number[i] < x) {
            printf("%d ", number[i]);
        }
    }
    return 0;
}
