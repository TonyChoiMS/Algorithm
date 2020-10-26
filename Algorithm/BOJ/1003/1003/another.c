//
// another.c
// 1003
// 피보나치 함수
// 피보나치 함수 결과에서 0과 1이 출력되는 횟수 검색하기
// Memoization 기법을 통해 배열을 생성 한다.
// 각 배열의 index에 피보나치 결과값을 저장한 후,
// 원하는 결과값이 나올때까지 재귀함수를 돌린다.
// 원하는 결과값이 나왔을 때 멈춤.
//
// C
// Created by 최민수 on 2017.12.12..
// Copyright @ 2017년 최민수. All rights reserved.

#include <stdio.h>
#include <stdlib.h>

int memo[40] = {1,1,};

int fibonacci(int n){
	if ( n <= 1) return memo[n];
	else {
		if(memo[n] > 0) return memo[n];
	}
	return memo[n] = fibonacci(n-1) + fibonacci(n-2);
}

int main ()
{
	int T; //testCase
	scanf("%d",&T);

	for(int i = 0 ; i < T ;i++){
		int temp;
		scanf("%d", &temp);

		if (temp == 0) printf("1 0\n");
		else if(temp == 1) printf("0 1\n");
		else{
			fibonacci(temp);
			printf("%d %d\n",memo[temp-2],memo[temp-1]);
		}
	}

	return 0;
}