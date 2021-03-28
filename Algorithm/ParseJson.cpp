#include "ParseJson.h"

char * ParseJson::ReadFile(const char * fileName, int * readSize)
{
	
	FILE* fp = fopen(fileName, "rb");
	if (fp == nullptr)
		return nullptr;

	int size;
	char* buffer;

	// ���� ũ�� ���ϱ�
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	// ���� ũ�� + null������ŭ �޸𸮸� �Ҵ��ϰ� 0���� �ʱ�ȭ
	buffer = new char[size + 1];
	memset(buffer, 0, size + 1);

	// ���� ���� �б�
	if (fread(buffer, size, 1, fp) < 1)
	{
		*readSize = 0;
		free(buffer);
		fclose(fp);
		return nullptr;
	}

	// ���� ũ�� �Ѱ���
	*readSize = size;

	// ���� ������ �ݱ�
	fclose(fp);

	return buffer;
}

void ParseJson::Parse(char * doc, int size, JSON * json)
{
	int tokenIndex = 0;		// ��ū �ε���
	int pos = 0;			// ���� �˻� ��ġ�� �����ϴ� ����

	if (doc[pos] != '{')		// ������ ������ {���� �˻�
		return;

	pos++;

	while (pos < size)
	{
		switch (doc[pos])
		{
			case '"':
			{
				// ���ڿ��� ���� ��ġ�� ����. �� ���� "�� �����ϱ� ���� +1
				char *begin = doc + pos + 1;

				// ���ڿ��� �� ��ġ�� ����. ���� "�� ��ġ
				char *end = strchr(begin, '"');
				if (end == nullptr)
					break;

				// ���ڿ��� ���� ���̴� �� ��ġ - ���� ��ġ
				int stringLength = end - begin;

				// ��ū �迭�� ������ ����
				// ��ū ������ ���ڿ�
				json->tokens[tokenIndex].type = TOKEN_STRING;
				// ���ڿ� ���� + null ������ŭ �޸� �Ҵ�
				json->tokens[tokenIndex].string = new char[stringLength + 1];
				// �Ҵ��� �޸𸮸� 0���� �ʱ�ȭ
				memset(json->tokens[tokenIndex].string, 0, stringLength + 1);

				// �������� ���ڿ��� ��ū�� ����
				// ���ڿ� ���� ��ġ���� ���ڿ� ���̸�ŭ�� ����
				memcpy(json->tokens[tokenIndex].string, begin, stringLength);

				tokenIndex++;

				pos = pos + stringLength + 1;		// ���� ��ġ + ���ڿ� ���� + "(+ 1)

				break;
			}
			
			case '[':
			{
				pos++;
				// ���ڿ� �迭�� ����ɶ����� �ݺ�
				while (doc[pos] != ']')
				{
					// ���⼭�� ���ڿ� �迭�� ó��
					if (doc[pos] == '"')
					{
						// ���ڿ��� ���� ��ġ�� ����. �� ���� "�� �����ϱ� ���� + 1
						char *begin = doc + pos + 1;

						// ���ڿ��� �� ��ġ�� ����. ���� "�� ��ġ
						char *end = strchr(begin, '"');
						if (end == nullptr)
							break;

						int stringLength = end - begin;

						// ��ū �迭�� ���ڿ� ����
						// ��ū ������ ���ڿ�
						json->tokens[tokenIndex].type = TOKEN_STRING;
						// ���ڿ� ���� + null ������ŭ �޸� �Ҵ�
						json->tokens[tokenIndex].string = new char[stringLength + 1];
						// ���� ���ڿ��� �迭�� ���
						json->tokens[tokenIndex].isArray = true;
						// �Ҵ��� �޸𸮸� 0���� �ʱ�ȭ
						memset(json->tokens[tokenIndex].string, 0, stringLength + 1);

						// �������� ���ڿ��� ��ū�� ����
						// ���ڿ� ���� ��ġ���� ���ڿ� ���̸�ŭ�� ����
						memcpy(json->tokens[tokenIndex].string, begin, stringLength);

						tokenIndex++; // ��ū �ε��� ����

						pos = pos + stringLength + 1;//  ���� ��ġ + ���ڿ� ���� + "(+1)
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

				// ���ڿ��� �� ��ġ�� ����. ,�� �����ų�
				end = strchr(doc + pos, ',');
				
				if (end == nullptr)
				{
					// }�� ������ ���ڿ��� ����
					end = strchr(doc + pos, '}');
					if (end == nullptr)
						break;
				}

				int stringLength = end - begin;	// ���ڿ��� ���� ���̴� �� ��ġ - ���� ��ġ

				// ���ڿ� ���� + nullptr ������ŭ �޸� �Ҵ�
				buffer = new char[stringLength + 1];
				memset(buffer, 0, stringLength + 1);

				// ���������� ���ڿ��� ���ۿ� ����
				// ���ڿ� ���� ��ġ���� ���ڿ� ���̸�ŭ�� ����
				memcpy(buffer, begin, stringLength);

				// ��ū�� ������ ����
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
		// ��ū ������ ���ڿ��̸鼭 ��ū�� ���ڿ��� Ű�� ��ġ�ϸ�
		if (json->tokens[i].type == TOKEN_STRING &&
			strcmp(json->tokens[i].string, key) == 0)
		{
			// �ٷ� ���� ��ū(i + 1)�� ���ڿ��̸�
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
		// ��ū ������ ���ڿ��̸鼭 ��ū�� ���ڿ��� Ű�� ��ġ�ϸ�
		if (json->tokens[i].type == TOKEN_STRING &&
			strcmp(json->tokens[i].string, key) == 0)
		{
			// �ٷ� ���� ��ū (i + 1)���� �迭�� ���
			// �ε����� ������ ��ū�� ���ڿ��̸鼭 �迭�̸�
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
		// ��ū ������ ���ڿ��̸鼭 ��ū�� ���ڿ��� Ű�� ��ġ�Ѵٸ�
		if (json->tokens[i].type == TOKEN_STRING &&
			strcmp(json->tokens[i].string, key) == 0)
		{
			// �ٷ� ���� ��ū(i + 1)���� isArray�� true�� ��ū�� ������ ��� ��ȯ
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
		// ��ū ������ �����̸鼭 ��ū�� ���ڿ��� Ű�� ��ġ�Ѵٸ�
		if (json->tokens[i].type == TOKEN_STRING &&
			strcmp(json->tokens[i].string, key) == 0)
		{
			// �ٷ� ���� ��ū(i + 1)�� ���ڸ�
			if (json->tokens[i + 1].type == TOKEN_NUMBER)
				return json->tokens[i + 1].number;
		}
	}
	return 0.0;
}
