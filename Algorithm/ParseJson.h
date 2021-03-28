#pragma once
//#include <iostream>
#define _CRT_SECURE_NO_WARNINGS    // fopen ���� ���� ���� ������ ���� ����
#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����
#include <stdbool.h>   // bool, true, false�� ���ǵ� ��� ����
#include <string.h>    // strchr, memset, memcpy �Լ��� ����� ��� ����

// ��ū ����
typedef enum _TOKEN_TYPE
{
	TOKEN_STRING,
	TOKEN_NUMBER,
} TOKEN_TYPE;

// ��ū ����ü
typedef struct _TOKEN
{
	TOKEN_TYPE type;
	union
	{
		// �� ���� �� �� ������ ������ ���̹Ƿ� ����ü�� ����
		char* string;		// ���ڿ� ������
		double number;		// �Ǽ��� ����
	};
	bool isArray;		// �迭���� �Ǻ�
} TOKEN;

#define TOKEN_COUNT 20		// ��ū �ִ� ����

// JSON ����ü
typedef struct _JSON
{
	TOKEN tokens[TOKEN_COUNT];		// ��ū �迭
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

