//
//  main.cpp
//  2583
//  영역 구하기
//
//  Created by 최민수 on 2018. 2. 18..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// x, y좌표로 이동시킬 변수
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

// x, y좌표를 저장할 구조체
struct Location {
    int left_x;
    int left_y;
    int right_x;
    int right_y;
};
// 탐색했는지 확인하는 변수
bool isChecked[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    // K : 테스트 케이스, (N, M) : Map의 오른쪽 위 꼭짓점 좌표
    int M, N, K;
    cin >> M >> N >> K;
    // Location 객체 생성
    Location *location = new Location[K];
    // 좌표 입력 받기
    for (int i = 0; i < K; i++) {
        cin >> location[i].left_x >> location[i].left_y >> location[i].right_x >> location[i].right_y;
        // 입력받은 좌표를 기준으로 직사각형의 모형만큼 check 변수를 true로 저장
        // 해당 좌표를 탐색하지 않게 설정
        for (int j = location[i].left_y; j < location[i].right_y; j++) {
            for (int k = location[i].left_x; k < location[i].right_x; k++) {
                isChecked[j][k] = true;
            }
        }
    }
    // 결과값을 저장할 벡터 생성
    vector<int> ans;
    // 탐색 시 사용할 Queue 생성
    queue<pair<int, int>> que;
    // (0, 0)부터 (N, M)까지 탐색 시작
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            // 이미 탐색한 곳일 경우 continue;
            if (isChecked[i][j]) continue;
            int cnt = 0;
            // 탐색한 곳의 좌표를 bool값으로 표시 후, Queue에 값 입력
            isChecked[i][j] = true;
            que.push({i, j});
            while(!que.empty()) {
                // Queue에서 값 추출
                auto now = que.front();
                que.pop();
                // 
                cnt++;
                for (int i = 0; i < 4; i ++) {
                    int nx = now.first + dx[i];
                    int ny = now.second + dy[i];
                    if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
                    if (!isChecked[nx][ny]) {
                        isChecked[nx][ny] = true;
                        que.push({nx, ny});
                    }
                }
            }
            //
            ans.push_back(cnt);
        }
    }
    // 영역의 넓이를 저장한 배열을 오름차순으로 정렬
    sort(ans.begin(), ans.end());
    // 영역의 갯수 출력
    cout << ans.size() << "\n";
    // 각 영역의 넓이 출력
    for (auto size : ans) {
        cout << size << " ";
    }
    delete []location;
    return 0;
}
