//
//  main.cpp
//  11057
//  오르막 수
//  Dynamic Programming
//
//  Created by 최민수 on 2018. 3. 19..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    int number[1001][10] = {};
    int total = 0;
    cin >> n;
    
    for (int i = 0; i < 10; i++)
        number[1][i] = 1;
    
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = j; k < 10; k++) {
                number[i][j] = (number[i][j] + number[i-1][k]) % 10007;
            }
        }
    }
    
    for (int i = 0; i < 10; i++)
        total = (total + number[n][i]) % 10007;
    
    cout << total << endl;
    
    return 0;
}
