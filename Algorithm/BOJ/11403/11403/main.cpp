//
//  main.cpp
//  11403
//  경로 찾기
//  BFS
//
//  Created by 최민수 on 2018. 1. 29..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>
using namespace std;

#define MAX 100
int N;
int G[MAX+1][MAX+1];
int CAN_GO[MAX+1][MAX+1];
int visited[MAX+1];

void bfs(int n) {
    for (int i=1; i<=N; i++) {
        if (G[n][i] && !visited[i]) {
            visited[i] = 1;
            bfs(i);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> N;
    for (int i =1; i <=N; i++) {
        for (int j = 1; j<=N; j++) {
            cin >> G[i][j];
            CAN_GO[i][j] = 0;
        }
    }
    
    for (int i = 1; i<= N; i++) {
        for ( int j = 1; j <= N; j++) {
            visited[j] = 0;
        }
        bfs(i);
        for (int j=1; j<=N; j++) {
            CAN_GO[i][j] = visited[j];
        }
    }
    for (int i = 1; i <=N; i++) {
        for (int j =1; j <= N; j++) {
            cout << CAN_GO[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
