//
//  main.c
//  1003
//  피보나치 함수
//  피보나치 함수 결과에서 0과 1이 출력되는 횟수 검색하기
//  기본 피보나치 함수에서 0과 1로 들어왔을 때 카운트하는 방법으로 해결
//
//  기존의 백준 문제에서 시간초과 제한 조건이 추가되어 수정
//
//  C++
//  Created by 최민수 on 2017. 12. 3..
//  Copyright © 2017년 최민수. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
//int zero, one;
//int memo[41] = {0, 1};

//int fibonacci(int n) {
//    if (n==0) {
//        zero++;
//        return memo[0];
//    } else if (n==1) {
//       one++;
//        return memo[1];
//    } else {
//        if (memo[n] == 0) {
//            memo[n] = fibonacci(n-1) + fibonacci(n-2);
//        }
//        return memo[n];
//    }
//}
/*
 재귀함수로 문제를 풀 경우, 새롭게 추가된 시간초과 조건으로 인해 오답으로 나온다.
 그래서 반복문을 통해 피보나치 수를 구하는 방법을 구현했다.
 또한 피보나치의 수를 재귀방식일 때 함수가 호출되는 것을 확인해보면
 n번째 피보나치의 수를 구할 떄 fibonacci(0)의 호출 횟수는 fibonacci(n-1)의 수와 같고,
 fibonacci(1)의 호출 횟수는 fibonacci(n)의 수와 같은 것을 확인할 수 있다.
 이것을 점화식으로 두고 값을 구한다.
 */
int fibonacci(int n) {
    int last = 0;
    int current = 1;
    int result = 0;
    for (int i = 0; i < n; i++) {
        last = current;
        current = result;
        result = last + current;
    }
    return result;
}

int main() {
    int testCase = 0;
    
    scanf("%d", &testCase);
    
    
    for (int i = 0; i < testCase; i++) {
        //zero = 0;
        //one = 0;
        int temp;
        
        scanf("%d", &temp);
        //fibonacci(temp);
        //printf("%d %d\n", zero, one);
        // 일반적인 피보나치의 수를 구할 때와 똑같이 0번째와 1번째는 예외로 처리해두고 실행한다.
        if (temp == 0) {
            printf("%d %d\n", 1, 0);
        } else if (temp == 1) {
            printf("%d %d\n", 0, 1);
        } else {
            printf("%d %d\n", fibonacci(temp-1), fibonacci(temp));
        }
    }
    return 0;
}
