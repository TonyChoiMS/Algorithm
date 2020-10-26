//
//  main.cpp
//  9461
//  파도반 수열
//  Dynamic Programming
//
//  Created by 최민수 on 2018. 3. 11..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 DP 문제
 점화식 : array[i] = array[i-1] + array[i-5];
 점화식에서  i-5까지 검사하므로, 배열에 5번째 배열까지 채워넣는다.
 입력받는 n의 값을 그대로 사용하기 위해서 배열의 0번째를 임의로 1로 채워넣음.
 */
int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    
    long long int array[101] = {1,1,1,1,2,2,};
    
    for (int i = 6; i <= 100; i++) {
        array[i] = array[i-1] + array[i-5];
    }
    for (int i = 0; i <T; i++) {
        int n;
        cin >> n;
        cout << array[n] << endl;
    }
    return 0;
}
