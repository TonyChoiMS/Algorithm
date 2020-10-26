//
//  main.cpp
//  7576
//
//  Created by 최민수 on 2018. 1. 28..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};

int find(int m, int n) {
    int boxArray[1001][1001];
    int visited[1001][1001];
    queue<pair<int, int>> box;
    
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> boxArray[i][j];
            visited[i][j] = -1;
            if (boxArray[i][j] == 1) {
                visited[i][j] = 0;
                box.push({i, j});
            }
         }
    }
    
    while(!box.empty()) {
        int x = box.front().first;
        int y = box.front().second;
        box.pop();
        
        for (i=0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (boxArray[nx][ny] == 0 && visited[nx][ny] == -1) {
                box.push({nx, ny});
                visited[nx][ny] = visited[x][y]+1;
                boxArray[nx][ny] = boxArray[x][y]+1;
            }
        }
    }
    int tomato = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j <m; j++) {
            if (tomato < visited[i][j])
                tomato = visited[i][j];
        }
    }
    
    for (i=0; i<n; i++) {
        for (int j=0; j < m; j++) {
            if (boxArray[i][j] == 0 && visited[i][j] == -1)
                tomato = -1;
        }
    }
    return tomato;
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << find(m, n);
    return 0;
}
