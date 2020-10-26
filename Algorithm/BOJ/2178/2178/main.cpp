//
//  main.cpp
//  2178
//  미로탐색 (MAZE)
//  using BFS alrorithm
//  Created by 최민수 on 2018. 1. 27..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int n;  // row
int m;  // column

bool map[100][100]; // true
int check[100][100];
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}; // up, down, left, right

void input() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int b;
            scanf("%1d", &b);
            
            if (b==1) {
                map[i][j] = true;
            }
        }
    }
}

void output(int num) {
    cout << num << "\n";
}

bool isInside(int a, int b) {
    return (a >= 0 && a < n) && (b >= 0 && b < m);
}

int bfs() {
    int cur_y = 0;
    int cur_x = 0;
    
    queue<pair<int, int>> q;
    q.push(pair<int, int>(cur_y, cur_x));
    check[cur_y][cur_x] = 1;
    
    while(!q.empty()) {
        cur_y = q.front().first;
        cur_x = q.front().second;
        q.pop();
        
        if ((cur_y == n) && (cur_x == m)) break;        // 도착 시 종료
        
        for (int i = 0; i < 4; i++) {
            int next_y = cur_y + dir[i][0];
            int next_x = cur_x + dir[i][1];
            
            // next y, x가 배열 내부에 있고, check 2차원 배열에 기록된 적이 없으며, map이 true로 되어있으면,
            if (isInside(next_y, next_x) && check[next_y][next_x] == 0 && map[next_y][next_x]) {
                check[next_y][next_x] = check[cur_y][cur_x] + 1;    // 이전 방문값 +1 = 다음 방문
                q.push(pair<int, int>(next_y, next_x));
            }
        }
    }
    return check[n-1][m-1];
}

int main(int argc, const char * argv[]) {
    input();
    output(bfs());
    return 0;
}
