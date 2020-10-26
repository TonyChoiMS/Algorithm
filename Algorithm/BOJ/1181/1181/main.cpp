//
//  main.cpp
//  1181
//  단어 정렬
//  Using Bubble Sort
//
//  Created by 최민수 on 2018. 2. 17..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Word {
    int len;
    char arr[51];
};

bool comp(const Word &s1, const Word &s2) {
    // 사이즈가 같으면, 사전순 앞으로
    if (s1.len == s2.len) {
        // 글자의 처음부터 끝까지 체크하며 알파벳 순서가 더 먼저인 것 찾기(O(n))
        for (int i = 0; i < s1.len; i++) {
            if (s1.arr[i] == s2.arr[i]) continue;
            else if (s1.arr[i] < s2.arr[i]) return true;
            else return false;
        }
    }
    return s1.len < s2.len;
}

int main() {
    // cout cin 속도 개선
    ios_base::sync_with_stdio(false);
    // 테스트 케이스
    int n;
    cin >> n;
    // Word 구조체 생성
    Word *word = new Word[n];
    
    // 테스트케이스만큼 단어와 단어의 길이 입력
    for (int i = 0; i < n; i++) {
        cin >> word[i].arr;
        word[i].len = strlen(word[i].arr);
    }
    
    sort(word, word+n, comp);
    
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            // 단어가 중복될 경우 출력하지 않고 다음 인덱스로 넘어감
            if (!strcmp(word[i].arr, word[i-1].arr)) {
                continue;
            }
        }
        // 단어 출력
        cout << word[i].arr << "\n";
    }
    // 생성한 Word를 메모리에서 삭제
    delete []word;
    return 0;
}
