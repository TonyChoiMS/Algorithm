#pragma once
//#include <iostream>
#define _CRT_SECURE_NO_WARNINGS    // fopen 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <stdbool.h>   // bool, true, false가 정의된 헤더 파일
#include <string.h>    // strchr, memset, memcpy 함수가 선언된 헤더 파일

// 토큰 종류
typedef enum _TOKEN_TYPE
{
	TOKEN_STRING,
	TOKEN_NUMBER,
} TOKEN_TYPE;

// 토큰 구조체
typedef struct _TOKEN
{
	TOKEN_TYPE type;
	union
	{
		// 두 종류 중 한 종류만 저장할 것이므로 공용체로 선언
		char* string;		// 문자열 포인터
		double number;		// 실수형 숫자
	};
	bool isArray;		// 배열인지 판별
} TOKEN;

#define TOKEN_COUNT 20		// 토큰 최대 개수

// JSON 구조체
typedef struct _JSON
{
	TOKEN tokens[TOKEN_COUNT];		// 토큰 배열
} JSON;

class ParseJson
{
public:
	ParseJson() {};
	~ParseJson() {};

	char* ReadFile(const char *fileName, int *readSize);

	void Parse(char* doc, int size, JSON *json);
	void FreeJson(JSON* json);
	char* GetString(JSON* json, const char* key);
	char* GetArrayString(JSON* json, const char* key, int index);
	int GetArrayCount(JSON* json, const char* key);
	double GetNumber(JSON* json, const char* key);
};

