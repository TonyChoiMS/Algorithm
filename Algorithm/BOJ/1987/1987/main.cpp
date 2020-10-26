//
//  main.cpp
//  1987
//  Alphabet
//  using DFS Algorithm
//
//  Created by 최민수 on 2018. 2. 20..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int r, c;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
char alphabet[20][22];
bool ch[26];

// Depth First Search
int dfs(int x, int y) {
    int ans = 1;
    for (int i = 0; i < 4; i++) {
        // nx, ny means next x, next y
        // d mean direction
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= r || ny >= c || ch[alphabet[nx][ny] - 'A']) continue;
        ch[alphabet[nx][ny] - 'A'] = 1;
        ans = max(ans, dfs(nx, ny) + 1);
        ch[alphabet[nx][ny] - 'A'] = 0;
    }
    return ans;
}

int main() {
    // Get Row and Column
    scanf("%d %d", &r, &c);
    // Get Alphabet row
    for (int i = 0; i < r; i++)
        scanf(" %s", &alphabet[i]);
    // Initialize
    ch[alphabet[0][0] - 'A'] = 1;
    // start dfs (0,0) and print
    printf("%d\n", dfs(0,0));
    return 0;
}
