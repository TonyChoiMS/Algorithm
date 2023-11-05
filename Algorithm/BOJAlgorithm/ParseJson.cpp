#include "ParseJson.h"

char * ParseJson::ReadFile(const char * fileName, int * readSize)
{
	
	FILE* fp = fopen(fileName, "rb");
	if (fp == nullptr)
		return nullptr;

	int size;
	char* buffer;

	// 파일 크기 구하기
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	// 파일 크기 + null공간만큼 메모리를 할당하고 0으로 초기화
	buffer = new char[size + 1];
	memset(buffer, 0, size + 1);

	// 파일 내용 읽기
	if (fread(buffer, size, 1, fp) < 1)
	{
		*readSize = 0;
		free(buffer);
		fclose(fp);
		return nullptr;
	}

	// 파일 크기 넘겨줌
	*readSize = size;

	// 파일 포인터 닫기
	fclose(fp);

	return buffer;
}

void ParseJson::Parse(char * doc, int size, JSON * json)
{
	int tokenIndex = 0;		// 토큰 인덱스
	int pos = 0;			// 문자 검색 위치를 저장하는 변수

	if (doc[pos] != '{')		// 문서의 시작이 {인지 검사
		return;

	pos++;

	while (pos < size)
	{
		switch (doc[pos])
		{
			case '"':
			{
				// 문자열의 시작 위치를 구함. 맨 앞의 "를 제외하기 위해 +1
				char *begin = doc + pos + 1;

				// 문자열의 끝 위치를 구함. 다음 "의 위치
				char *end = strchr(begin, '"');
				if (end == nullptr)
					break;

				// 문자열의 실제 길이는 끝 위치 - 시작 위치
				int stringLength = end - begin;

				// 토큰 배열에 무낮열 저장
				// 토큰 종류는 문자열
				json->tokens[tokenIndex].type = TOKEN_STRING;
				// 문자열 길이 + null 공간만큼 메모리 할당
				json->tokens[tokenIndex].string = new char[stringLength + 1];
				// 할당한 메모리를 0으로 초기화
				memset(json->tokens[tokenIndex].string, 0, stringLength + 1);

				// 문서에서 문자열을 토큰에 저장
				// 문자열 시작 위치에서 문자열 길이만큼만 복사
				memcpy(json->tokens[tokenIndex].string, begin, stringLength);

				tokenIndex++;

				pos = pos + stringLength + 1;		// 현재 위치 + 문자열 길이 + "(+ 1)

				break;
			}
			
			case '[':
			{
				pos++;
				// 문자열 배열이 종료될때까지 반복
				while (doc[pos] != ']')
				{
					// 여기서는 문자열 배열만 처리
					if (doc[pos] == '"')
					{
						// 문자열의 시작 위치를 구함. 맨 앞의 "를 제외하기 위해 + 1
						char *begin = doc + pos + 1;

						// 문자열의 끝 위치를 구함. 다음 "의 위치
						char *end = strchr(begin, '"');
						if (end == nullptr)
							break;

						int stringLength = end - begin;

						// 토큰 배열에 문자열 저장
						// 토큰 종류는 문자열
						json->tokens[tokenIndex].type = TOKEN_STRING;
						// 문자열 길이 + null 공간만큼 메모리 할당
						json->tokens[tokenIndex].string = new char[stringLength + 1];
						// 현재 문자열은 배열의 요소
						json->tokens[tokenIndex].isArray = true;
						// 할당한 메모리를 0으로 초기화
						memset(json->tokens[tokenIndex].string, 0, stringLength + 1);

						// 문서에서 문자열을 토큰에 저장
						// 문자열 시작 위치에서 문자열 길이만큼만 복사
						memcpy(json->tokens[tokenIndex].string, begin, stringLength);

						tokenIndex++; // 토큰 인덱스 증가

						pos = pos + stringLength + 1;//  현재 위치 + 문자열 길이 + "(+1)
					}

					pos++;
				}
				break;

			case '0' : case '1' : case '2': case '3': case '4': case '5':
			case '6': case '7': case '8': case '9': case '-':
			{
				char *begin = doc + pos;
				char *end;
				char *buffer;

				// 문자열의 끝 위치를 구함. ,가 나오거나
				end = strchr(doc + pos, ',');
				
				if (end == nullptr)
				{
					// }가 나오면 문자열이 끝남
					end = strchr(doc + pos, '}');
					if (end == nullptr)
						break;
				}

				int stringLength = end - begin;	// 문자열의 실제 길이는 끝 위치 - 시작 위치

				// 문자열 길이 + nullptr 공간만큼 메모리 할당
				buffer = new char[stringLength + 1];
				memset(buffer, 0, stringLength + 1);

				// ㅁ누서에서 문자열을 버퍼에 저장
				// 문자열 시작 위치에서 문자열 길이만큼만 복사
				memcpy(buffer, begin, stringLength);

				// 토큰의 종류는 숫자
				json->tokens[tokenIndex].type = TOKEN_NUMBER;
				json->tokens[tokenIndex].number = atof(buffer);

				free(buffer);
				tokenIndex++;

				pos = pos + stringLength + 1;
				break;
			}
			}
		}

		pos++;
	}
}

void ParseJson::FreeJson(JSON * json)
{
	for (int i = 0; i < TOKEN_COUNT; i++)
	{
		if (json->tokens[i].type == TOKEN_STRING)
			free(json->tokens[i].string);
	}
}

char * ParseJson::GetString(JSON * json, const char * key)
{
	for (int i = 0; i < TOKEN_COUNT; i++)
	{
		// 토큰 종류가 문자열이면서 토큰의 문자열이 키와 일치하면
		if (json->tokens[i].type == TOKEN_STRING &&
			strcmp(json->tokens[i].string, key) == 0)
		{
			// 바로 뒤의 토큰(i + 1)이 문자열이면
			if (json->tokens[i + 1].type == TOKEN_STRING)
				return json->tokens[i + 1].string;
		}
	}

	return nullptr;
}

char * ParseJson::GetArrayString(JSON * json, const char * key, int index)
{
	for (int i = 0; i < TOKEN_COUNT; i++)
	{
		// 토큰 종류가 문자열이면서 토큰의 문자열이 키와 일치하면
		if (json->tokens[i].type == TOKEN_STRING &&
			strcmp(json->tokens[i].string, key) == 0)
		{
			// 바로 뒤의 토큰 (i + 1)부터 배열의 요소
			// 인덱스를 지정한 토큰이 문자열이면서 배열이면
			if (json->tokens[i + 1 + index].type == TOKEN_STRING &&
				json->tokens[i + 1 + index].isArray == true)
				return json->tokens[i + 1 + index].string;
		}
	}

	return nullptr;
}

int ParseJson::GetArrayCount(JSON * json, const char * key)
{
	for (int i = 0; i < TOKEN_COUNT; i++)
	{
		// 토큰 종류가 문자열이면서 토큰의 문자열이 키와 일치한다면
		if (json->tokens[i].type == TOKEN_STRING &&
			strcmp(json->tokens[i].string, key) == 0)
		{
			// 바로 뒤의 토큰(i + 1)부터 isArray가 true인 토큰의 개수를 세어서 반환
			int j = 0;
			while (json->tokens[i + 1 + j].isArray == true)
				j++;

			return j;
		}
	}

	return 0;
}

double ParseJson::GetNumber(JSON * json, const char * key)
{
	for (int i = 0; i < TOKEN_COUNT; i++)
	{
		// 토큰 종류가 숫자이면서 토큰의 문자열이 키와 일치한다면
		if (json->tokens[i].type == TOKEN_STRING &&
			strcmp(json->tokens[i].string, key) == 0)
		{
			// 바로 뒤의 토큰(i + 1)이 숫자면
			if (json->tokens[i + 1].type == TOKEN_NUMBER)
				return json->tokens[i + 1].number;
		}
	}
	return 0.0;
}
