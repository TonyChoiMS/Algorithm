//
//  main.cpp
//  10989
//  수 정렬하기 3
//
//  Created by 최민수 on 2018. 2. 15..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>
using namespace std;


int main() {
    // 테스트 케이스 입력
    int T;
    cin >> T;
    // 수를 배열에 직접 저장하는 것이 아닌 인덱스화해서 그 인덱스의 수만큼 출력하도록 실행
    int index;
    // 정렬 할 값을 저장할 배열 선언 후, 입력값 저장.
    int *arr = new int[10001];
    for (int i = 0; i < T; i++) {
        cin >> index;
        arr[index]++;
    }
    for (int j = 1; j <= 10000; j++) {
        for (int k = 0; k < arr[j]; k++) {
            if (arr[j] > 0) {
                cout << j << "\n";
            }
        }
    }
    // 선언한 배열 메모리 해제
    delete []arr;
    return 0;
}
