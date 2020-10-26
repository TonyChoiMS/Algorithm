//
//  main.cpp
//  1427
//  소트인사이드
//  using bubble sort algorithm
//
//  Created by 최민수 on 2018. 2. 12..
//  Copyright © 2018년 최민수. All rights reserved.
//

#include <iostream>
//#include <algorithm>      //using sort function
#include <string>

using namespace std;

// call by reference
// swap array elements
void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// using buble sort
void BubbleSort(int *(&array), int length) {
    for (int i = 0; i < length-1; i++) {
        for (int j = 1; j < length-i; j++) {
            if (array[j] > array[j-1])      // Descending order
                swap(array[j], array[j-1]);
        }
    }
}

void solution(string arg) {
    int length = (int)arg.length();
    int *arr = new int[length];
    
    // insert string elements for each
    for (int i = 0; i < length; i++) {
        arr[i] = arg[i] - '0';
    }
    // Start Bubble sort function
    BubbleSort(arr, length);
    
    // output int array elements
    for (int j = 0; j < length; j++) {
        cout << arr[j];
    }
    // remove int array memeory
    delete []arr;
}

int main() {
    
    // using bubble sort algorithm
    string arg;
    cin >> arg;
    solution(arg);
    
    // using sort function
    //char testCase[10];
    //cin >> testCase;
    //sort(testCase, testCase+strlen(testCase), greater<int>());
    //for (int i = 0; i < strlen(testCase); i++) {
    //    cout << testCase[i];
    //}
    
    return 0;
}
