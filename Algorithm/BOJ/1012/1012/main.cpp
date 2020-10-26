//
//  main.cpp
//  1012
//  유기농 배추
//  Using DFS Algorithm
//
//  Created by 최민수 on 2018. 2. 6..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>
#include <memory.h>

using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

bool farm[52][52];

/**
 * 재귀함수를 통한 DFS 방식
 */
void DFS(int x, int y) {
    farm[x][y] = 0;             // 방문한 곳은 0으로 표시해서 다시 방문 안하게 설정
    for (int i = 0; i < 4; i++) {
        // 맵에서 검색하는 값이 0이 아니면 계속 탐색
        if (farm[x +dx[i]][y + dy[i]]) {
            DFS(x + dx[i], y + dy[i]);
        }
    }
}

int main() {
    int T;          // Test Case
    cin >> T;
    
    int answer;         // 출력할 결과값
    int M, N, K;        // M : 밭의 가로길이, N : 밭의 세로길이, K : 밭에 있는 배추의 수
    int x, y;           // x, y좌표
    
    while (T--) {
        answer = 0;
        // Farm 배열의 값을 0으로 초기화
        memset(farm, 0, sizeof(farm));
        cin >> M >> N >> K;
        // 배추가 있는 위치를 배열에 1을 넣어서 표시
        while (K--) {
            cin >> x >> y;
            farm[++x][++y] = 1;
        }
        // 1~맵의 길이까지 탐색을 시작
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                // 1인 지점을 찾으면 정답 카운트를 1증가
                if (farm[i][j]) {
                    answer++;
                    // 1인 지점 및 탐색하며 찾은 인접부분 중 1인부분을 모두 0으로 만드는 재귀함수 호출
                    DFS(i,j);
                }
            }
        }
        cout << answer << "\n";
    }
    return 0;
}
