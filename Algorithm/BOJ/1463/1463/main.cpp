//
//  main.cpp
//  1463
//  1로 만들기
//. 재귀함수를 통한 Top-down 방식의 문제풀이
//
//  Created by 최민수 on 2017. 12. 3..
//  Copyright © 2017년 최민수. All rights reserved.
//

#include <iostream>

using namespace std;
int d[1000001];
int go(int n) {
    if (n == 1) return 0;
    if (d[n] >0 ) return d[n];
    d[n] = go(n-1) + 1;
    if (n%2 == 0) {
        int temp = go(n/2) + 1;
        if (d[n] > temp) d[n] = temp;
    }
    if (n%3 == 0) {
        int temp = go(n/3) + 1;
        if (d[n] > temp) d[n] = temp;
    }
    return d[n];
}

int main() {
    int n;
    cin >> n;
    cout << go(n) << '\n';
    return 0;
}
