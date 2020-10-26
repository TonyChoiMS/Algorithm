//
//  main.cpp
//  11650
//  좌표 정렬하기
//
//  Created by 최민수 on 2018. 2. 18..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

// x와 y의 값을 저장하고 있을 구조체 생성
struct Data {
    int x;
    int y;
};

// using sort algorithm
bool comp(const Data &s1, const Data &s2) {
    // x의 값이 같을 경우, y의 값에 따라 오름차순으로 정렬하도록
    if (s1.x == s2.x) {
        if (s1.y < s2.y) return true;       // Ascending for y
        else return false;
    }
    return s1.x < s2.x;     // Acsending for x
}

// Print x,y in Data struct
void Print(Data *data, int length) {
    for (int i=0; i < length; i++) {
        printf("%d %d\n", data[i].x, data[i].y);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    // get Test Case number variable
    int T;
    cin >> T;
    
    Data *data = new Data[T];
    // get x, y test case data
    for (int i = 0; i <T; i++) {
        cin >> data[i].x >> data[i].y;
    }
    sort(data, data+T, comp);
    
    Print(data, T);
    
    // delete Data struct in memory
    delete []data;
    return 0;
}
