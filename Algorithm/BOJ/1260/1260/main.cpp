//
//  main.cpp
//  1260
//  dfs and bfs
//
//  Created by 최민수 on 2018. 1. 27..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int n,m,v;              // n : 정점의 개수, m : 간선의 개수, v : 탐색을 시작할 정점의 번호
bool check[1001];       // 노드를 탐색한 적이 있는지 확인할 변수
bool graph[1001][1001]; // 그래프 2차 배열(MAP)

// DFS : Deep First Search
void dfs(int now) {
    check[now] = true;  // 방문한 곳 인덱스의 값을 true로 변경
    cout << now << " "; // 방문한 곳의 노드 인덱스를 출력
    // 탐색하지 않은 다음 노드를 발견하면 재귀형식으로 호출
    for (int i=1; i<=n; i++)
        if(!check[i] && graph[now][i])
            dfs(i);
}

// BFS : Breadth First Search
// 재귀함수를 사용하지 않고 Queue를 사용하여 반복문을 통해서 모든 노드를 탐색
void bfs(int now) {
    queue<int> value;
    value.push(now);        // 현재 노드를 queue에 push
    check[now] = true;      // 현재 노드를 탐색했다고 값 변경
    while(!value.empty()) {
        // Queue에서 노드를 꺼내서 해당 노드를 출력
        int f = value.front();
        value.pop();
        cout << f << " ";
        // 현재 노드에서 이어져있는 노드를 확인 후 queue에 넣고 check 배열에 해당 노드의 인덱스를 true로 변경
        for (int i=1; i <= n; i++) {
            if (!check[i] && graph[f][i]) {
                value.push(i);
                check[i] = true;
            }
        }
    }
}

int main() {
    // 문제에서 주어진 값을 입력
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        // 입력받은 값을 맵에 표현
        graph[a][b] = graph[b][a] = true;
    }
    
    dfs(v);
    cout << "\n";
    // dfs 방식으로 탐색 완료 후, check 배열의 값을 모두 false로 초기화
    memset(check, false, sizeof(check));
    bfs(v);
    
    return 0;
}
