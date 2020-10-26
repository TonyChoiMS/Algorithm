//
//  main.cpp
//  2667
//  단지번호 붙이기
//  using BFS algorithm
//
//  Created by 최민수 on 2018. 2. 5..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int totalLayer;         // Get number 5<= totalLayer <= 25
int map[25][25];        // Map Array
int size[313];          // 각 번지에 존재하는 집의 갯수를 저장할 배열, n = totalLayer; (n*n/2 +1) several unit count
int cnt;                // unit count(numbering)
int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};       // Right, Left, Up, Down

/**
 * [a,b] 좌표가 map의 size 내에 존재하는지 확인
 */
bool IsInside(int a, int b) {
    return (a>=0 && a<totalLayer) && (b>=0 && b<totalLayer);
}

/**
 * [a, b] : Location
 * cnt : unit count(numbering)
 * BFS 알고리즘을 통해 map의 [a,b] 좌표를 시작점으로 탐색 시작
 */
void BFS(int a, int b, int mark) {
    // 입력받은 좌표를 Queue에 Pair를 통해 저장
    // Pair<x좌표, y좌표>
    queue<pair<int, int>> q;
    q.push(pair<int, int>(a, b));
    map[a][b] = mark;
    
    while(!q.empty()) {
        // 좌표의 x, y값을 변수에 저장한 후, queue에서 POP
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        // Check Up, Down, Left, Right
        for (int i = 0;  i < 4; i++) {
            // 탐색하는 좌표([a,b]의 위,아래,왼,오)가 map size 내에 존재하는지 확인
            if (!IsInside(y+ d[i][0], x+d[i][1])) continue;
            // 좌표값이 1일때,
            if (map[y+d[i][0]][x+d[i][1]] == 1) {
                // 해당 좌표에 마크값(단지표기값)을 입력해놓은 후, 좌표값을 Queue에 넣는다.
                map[y+d[i][0]][x+d[i][1]] = mark;
                q.push(pair<int, int>(y+d[i][0], x+d[i][1]));
            }
        }
    }
}

void Calc(int n) {
    for (int i = 0;  i < n; i++) {
        for (int j = 0;  j < n; j++) {
            // find 1
            if (map[i][j] == 1) {
                // if find 1, using BFS algorithm
                // Count + 1
                // 왜 cnt에 +2가 된 값을 파라메터로 전달할까?
                BFS(i, j, cnt+2);
                cnt++;
            }
        }
    }
    //
    for (int i = 0;  i < n; i++) {
        for (int j = 0;  j < n; j++) {
            if (map[i][j]==0) continue;
            
            size[map[i][j]-2]++;
        }
    }
}

/**
 * 구한 번지수의 총 갯수와, 각 번지당 존재하는 집의 갯수를 프린트
 */
void Print() {
    cout << cnt << "\n";
    for (int i = 0;  i < cnt; i++) {
        cout << size[i] << "\n";
    }
}

int main() {
    cin >> totalLayer;
    // 입력값 저장
    for (int i=0; i < totalLayer; i++) {
        for (int j=0; j < totalLayer; j++) {
             scanf("%1d", &map[i][j]);
        }
    }
    Calc(totalLayer);       // 입력된 값을 계산하는 함수 호출
    sort(size, size+cnt);   // 계산 결과를 숫자 순서대로 소팅
    Print();                // 계산과 소팅이 완료된 결과값을 프린트
    
    return 0;
}
