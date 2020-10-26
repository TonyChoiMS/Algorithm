//
//  main.cpp
//  1699
//  Dynamic Programming
//  제곱수의 합
//
//  Created by 최민수 on 2018. 5. 21..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int count[100001] = {};
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j*j <= i; j++) {
            if (count[i] > count[i - j*j] + 1 || count[i] == 0)
                count[i] = count[i - j*j]+1;
        }
    }
    cout << count[N] << endl;
    return 0;
}
