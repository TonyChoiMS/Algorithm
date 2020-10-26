//
//  main.cpp
//  1697
//  숨바꼭질
//  BFS
//  Created by 최민수 on 2018. 1. 28..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int find(int from, int to) {
    queue<pair<int, int>> path;    // queue에 pair<현재위치, 이동한 횟수>를 저장
    bool visited[100001] = {false};    // 해당 번호를 방문했는지 확인하는 배열
    path.push({from, 0});    // 최초 시작지점과 카운트를 큐에 삽입 (최초 시작 지점에선 아직 움직이지 않았기 떄문에 카운트 0)
    // queue에 데이터가 다 pop 될 때까지 실행
    while (!path.empty()) {
        int current = path.front().first;
        int count = path.front().second;
        path.pop();    // 현재 정보를 읽어서 변수에 저장 후, queue에서 해당 값을 pop
        
        // 현재 위치가 문제에서 제시한 범위를 넘어서거나 이미 방문한 번호면 continue
        if (current < 0 || current > 100000) continue;
        if (visited[current]) continue;
        
        // 처음 방문한 번호일 경우, 번호에 방문했음을 true로 변경
        visited[current] = true;
        
        // 방문한 번호가 내가 원하는 목표 번호라면 현재까지 쌓인 카운트를 리턴
        if (current == to) {
            return count;
        }
        // 큐에 문제에서 제시한 이동 가능한 3가지 방법에 대해서 저장하면서 진행
        // 3가지 방법으로 계속적으로 이동하다보면 current가 목적지에 도착한 큐가 발생
        // 가장 먼저 도착한 큐의 정보에 담긴 카운트를 리턴하면 최단거리를 알 수 있다.
        path.push({current * 2, count + 1});
        path.push({current +1, count +1});
        path.push({current -1, count +1});
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    int n, k;               // n : 시작점, k : 도착점
    cin >> n >> k;
    cout << find(n, k);
    return 0;
}
