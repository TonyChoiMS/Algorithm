//
//  main.cpp
//  11053
//  가장 긴 증가하는 부분 수열
//  Dynamic Programming
//
//  Created by 최민수 on 2018. 3. 6..
//  Copyright © 2018년 최민수. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

int n, answer, len;
/*
 O(N^2)의 시간복잡도를 가진 해결법
 dp[i] = i번째 원소를 마지막으로 하는 LIS의 길이
 dp[i] = 1 ~ i-1까지의 원소들에서, i번째 원소보다 값이 작은것들 중, 가장 큰 dp값 +1
 */
int Max(int a, int b) {
    return a > b ? a : b;
}
int seq[1001], dp[1001];
void NpowerTwo() {
    cout << "N^2 algorithm" << endl;
    for (int i = 1; i <= n; i++) {
        cin >> seq[i];
        int here = 0;
        for (int j = 1; j < i; ++j) {
            if (seq[i] > seq[j])
                here = Max(here, dp[j]);
        }
        dp[i] = here+1;
        answer = Max(answer, dp[i]);
    }
    cout << answer;
}

/*
 Lower Bound
 어떠한 정렬된 배열 arr에서 어떠한 값 val의 Lower Bound란,
 arr을 정렬된 상태로 유지하면서 val이 삽입될 수 있는 위치들 중 가장 인덱스가 작은 것입니다.
 Lower Bound 인덱스는 이진 탐색을 통해 logN의 시간에 구할 수 있다.
 
 O(NlogN)의 시간 복잡도를 가진 해결법
 L[i] = 길이 i인 증가하는 부분 수열을 만들 수 있는 마지막 원소 중 가장 작은 값
 따라서 L의 크기가 곧 현재까지 만들 수 있는 LIS의 길이이며, 처음에 L[]은 빈 리스트로 시작한다.
 lower_bound를 이용하여 이진 탐색을 실행한다.
 */
int L[1001], P[1001];
void backTrace(int idx, int num) {
    if (idx ==0)
        return;
    if (P[idx] == num) {
        backTrace(idx -1 , num -1);
        cout << seq[idx] << " ";
    } else {
        backTrace(idx - 1, num);
    }
}

void NlogN() {
    for (int i = 1; i <= n; i++) {
        cin >> seq[i];
        auto pos = lower_bound(L + 1, L + len + 1, seq[i]);
        *pos = seq[i];
        P[i] = distance(L, pos);
        if (pos == L + len + 1)
            len++;
    }
    cout << len << endl;
    cout << "back trace array" << endl;
    backTrace(n, len);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin >> n;
    NpowerTwo();
    NlogN();
    return 0;
}
