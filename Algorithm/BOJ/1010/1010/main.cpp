//
//  main.cpp
//  1010
//  다리 놓기
//  Dynamic Programming
//
//  Created by 최민수 on 2018. 3. 6..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>
#include <memory.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int arr[31][31];
    memset(arr, 0, sizeof(arr));
    int i, j, k;
    for (i = 0; i < 31; i++) {
        arr[1][i] = i;
    }
    for (i = 2; i < 31; i++) {
        for (j = i; j < 31; j++) {
            for (k = j-1; k >= i-1; k--) {
                arr[i][j] += arr[i-1][k];
            }
        }
    }
    int t, n, m;
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> n >> m;
        cout << arr[n][m] << endl;
    }
    return 0;
}
