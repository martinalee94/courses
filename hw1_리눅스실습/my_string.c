//-----------------------------------------------------------
// 
// SWE2007: Software Experiment II (2018 Fall)
//
// Skeleton code for PA #0
// September 12, 2018
//
// Somm Kim, Sooyun Lee
// Embedded Software Laboratory
// Sungkyunkwan University
//
// Student Name	: lee young suk(�̿���)
// Student ID	: 2014314433
//
//-----------------------------------------------------------

#include "my_string.h"
#include <stdlib.h>

#define isspace(ch) ((ch) == ' ' || (ch) == '\t' || (ch) == '\n' || \
					 (ch) == '\v' || (ch) == '\f' || (ch) == '\r')

/* Conversion of string to numeric format */
int my_atoi(const char *str) //���ڿ� str�� ������ int�� ��ȯ�Ͽ� ���
{
	//int ret = 0;
	//int sign = 0; // ��ȣ�� ���Դ�.
	//int minus = 0;	// minus�� �ƴϴ�
	//int base = 1;
	//int valid = 1;
	//int idx = 0;
	//

	//// isspace�� True�� �� ��ٸ���. null���� �ƴ� ��.(while)
	//char cur = str[idx];
	//while (isspace(str[idx]) && str[idx] != '\0') {
	//	idx++;
	//}
	//if (str[idx] == '\0') valid = 0; //��� �����̽��ִ°�... 

	//if (valid == 1) {
	//	// -, +, 0-9�� ������ �� ��ĭ�� ���鼭 ���ڸ� ret�� ����
	//	while (str[idx] != '\0') {
	//		// ��ȣ�� �ƴϰ� ���ڵ� �ƴϰ� �ȵǴ°�
	//		// invalid

	//		// ��ȣ�̰� ó�� ����
	//		// 
	//	}

	//	// ��ȿ���� ���� ���ڸ� invalid �� return
	//	// minus�� plus�� ������ sign=1;
	//	// minus�� minus�� 1��
	//	// plus�� �׳� �н�
	//	// ���� --> ret += ���� * base
	//	// base *= 10;
	//}

	//return ret;
}

long my_atol(const char *str) //���ڿ� str�� ������ long���� ��ȯ�Ͽ� ��� 
{
}

/* Conversion of numeric format to string */
char *int2str(char *dest, int num) {
	char buf[12];

	int cnt = -1, temp=1;
	while (num >= 1)
	{
		temp =num / 10;
		cnt++; //num�� �ڸ����� �˷��� ��!
	}

	for (int i = 0;i < cnt;i++)
	{
		
	}

	return dest;
}

/* String manipulation */
char *strcpy(char *dest, const char *src) {
	int i=0;
	while (src[i] != '\0') //src���� dest�� ��������, src�� ���ڿ� ���� ��Ÿ���� \0 ���� ������ ������ for�� ���� 
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0'; //dest ���� ���� ���� �־��ֱ�

	return dest;
}

char *strncpy(char *dest, const char *src, size_t n) {
	int i = 0;
	while (i < n && src[i] != '\0')//���̰� n���� ���� src�� n���� ���� �ʾ� ���Ṯ�� ������ ���� 
	{
		dest[i] = src[i];
		i++;
	}
	
	while (i < n)//n���� ���̰� ª�Ƽ� n����Ʈ ���簡 �Ұ����� ���� �� �ڿ� �� �ι���Ʈ ����!
	{
		dest[i] = '\0';
		i++;
	}

	return dest;
}

char *strcat(char *dest, const char *src) {
	int i = 0;

	while (dest[i] != '\0') //���� dest ��Ʈ�� �� �ε��� ã��
		i++;

	for (int j = 0;src[j] != '\0';j++)
	{
		dest[i] = src[j]; //���ε������� src�� �����ϱ�
		i++;
	}

	dest[i] = '\0';

	return dest; 
}
	


char *strncat(char *dest, const char *src, size_t n) {
	int j = 0, i = 0, dsize = 0, ssize=0;

	for (j = 0;dest[j] != '\0';j++) //dest ���� �ľ�
		dsize++;


	for (j = 0;j < n&&src[j] != '\0';j++) //���̰� n���� ���� src�� n���� ���� �ʾ� ���Ṯ�� ������ ���� 
	{
		dest[dsize] = src[j];
		dsize++;
	}
	
	dest[dsize] = '\0';
	return dest;

}

char *strdup(const char *str) {
	int size = 0; 

	for (int i = 0;str[i] != '\0';i++)
		size++; //str ������ ã�� 

	char *newbie = (char*)malloc(sizeof(char)*size); //������ ã�� str �����ŭ ���ο� new�� �����Ҵ�
	
	for (int i = 0;str[i] != '\0';i++)
		newbie[i] = str[i]; //new�� str ����

	newbie[size] = '\0';

	return newbie;
	
}

/* String examination */
size_t strlen(const char *str) {
	int i = 0;
	while (str[i] != '\0') //���� ���ϱ�
		i++;

	return i; //�ι��� �������� �ε��� ��½�Ű��
}

int strcmp(const char *str1, const char *str2) {
	/*-1 s2�� ŭ
		0 ����
		1 s1�� ŭ*/
	int i = 0, ret=0;
	while (str1[i] != '\0'||str2[i] != '\0')
	{
		if (str1[i] > str2[i]) //str1�� Ŭ��
			return 1;
		else if (str1[i] < str2[i]) //str2�� Ŭ�� 
			return -1;

		i++;
	}

	if (str1[i] == '\0'&&str2[i] == '\0') //�� ��Ʈ�� ��� null�̸� ���� ����
		return 0;
	else if (str1[i] == '\0') //str2�� �� �� ����
		return -1;
	else //str1�� �� �� ����
		return 1;
}

int strncmp(const char *str1, const char *str2, size_t n) {
	/*-1 s2�� ŭ
	0 ����
	1 s1�� ŭ*/

	int i = 0;
	while ((str1[i] != '\0' || str2[i] != '\0')&&(i<n)) //i<n�� �߰����ְ�Ϳ���..
	{
		if (str1[i] > str2[i]) //str1�� Ŭ��
			return 1;
		else if (str1[i] < str2[i]) //str2�� Ŭ�� 
			return -1;

		i++;
	}

	if (i < n) //str�߿� ������ �� ª��
	{
		if (str2[i] == '\0')//str1�� �� �� ����
			return 1;
		else if (str1[i] == '\0') //str2�� �� �� ����
			return -1;
	}
	else //str �� ���� ����, n���� ä������!!!
		return 0;
	
}

char *strchr(const char *str, int c) {
	int i = 0;

	if (c == '\0')
	{
		while (str[i] != '\0')
			i++;

		return  str + i;
	}
		
	else
	{
			while (str[i] != '\0')
			{
				if (str[i] == 'c')
					break; //while ����������
				else
					i++;
			}

			if (str[i] != '\0')
				return NULL; //c�� ������ \0 �� ���� ������ �����
			else
				return str + i;
	}
}

char *strrchr(const char *str, int c) {
	int i = 0, last=-1; //last -1�� �� ������ �ε��� 0���� c�� ���ü��������ϱ�

	while (str[i] != '\0')
	{
		if (str[i] == 'c')
		{
			last = i; //last�� c ������ �ε��� ����
			i++;
		}	
		else
			i++;
	}

	if (last = -1)
		return NULL; //null ��ȯ
	else
		return str+last; //last ��ġ ������ ��ȯ
}

char *strpbrk(const char *str1, const char *str2) {
	//str1���� str2�߿� � ���ڵ� str1�� ��Ÿ���� �� ù��° �� v������ ��ȯ

	int s1 = 0, s2 = 0,i=0,j=0;

	while (str1[s1] != '\0') //str1 ���̱��ϱ�
		s1++;

	while (str1[s2] != '\0') //str2 ���̱��ϱ�
		s2++;

	for (i = 0;i < s1;i++) //str1�̶� str2���ϱ� ->str1 �տ�������
	{
		for (j = 0;j < s2;j++) //->str2��ü�� ���Ѵ�
		{
			if (str1[i] == str2[j]) //str1�̶�  str2�� ������ str2 ��ġ break
				break;
		}

		if (j < s2) //str1�̶�  str2�� ������ str1 ��ġ break
			break;
	}

	if (i >= s1) //str1�� str2�� ���ڰ� ��� ������ �� ���� ���
		return NULL;
	else
		return str1 + i;
}

char *strstr(const char *haystack, const char *needle) {
	//haystack�� �κ� ���ڿ� needle�� �ִ� ù��° ������ �ּҸ� ��ȯ��

	int a=0,h = 0, n = 0,i=0,j=0, cnt=0, len=0;
	
	while (haystack[h] != '\0') //hay ���̱��ϱ�
		h++;
	while (needle[n] != '\0') //need ���̱��ϱ�
		n++;

	char *index = (char*)malloc(sizeof(char)*h); //hay���̸�ŭ�� new�����Ҵ�

		for (j = 0;j < h;j++) //haystack��ü���� needle ���� �� �� �ִ� ��ġ�� ����
		{
			if (haystack[j] == needle[0])
			{
				index[cnt] = j;
				cnt++;
			}
		}
		index[cnt] = '\0';
		j = 0;

	while (index[len] != '\0') //index�迭 ���̱��ϱ�
		len++;

	cnt = 0;
	if (len == 0) return NULL;
	
	else {
		for (a = 0;a < len;a++)
		{
			i = index[a];
			for (j = 0;j < n;j++) //ù���� ������ġ���� needle ���̸�ŭ�� ����
			{
				if (haystack[i + j] == '\0'&& needle[j] != '\0')
					return NULL;
				else if (haystack[i + j] == needle[j])
					cnt++;
				else if (haystack[i + j] != needle[j])
					break;
			}
			if (cnt >= n) //needle ������ �񱳰� �����߰� �� ������ �� ���Ҵٴ°�.
				break;
		}


		return haystack + index[a];
	}
}

char *strtok(char *str, const char *delim) {
	static char *tok = NULL;


}

char *strtok_r(char *str, const char *delim, char **save_ptr) {
}

/* Character array manipulation */
void *memcpy(void *dest, const void *src, size_t n) {
	(char*)dest;
	(char*)src;

	for(int i=0;i<n;i++)
	{
		*((char*)dest+i) = *((char*)src+i);
		//(char*)src[i]
		//src[i]
	}
	return dest;
}

void *memset(void *str, int c, size_t n) {
	for (int i = 0;i < n;i++)
	{
		*((char*)str+i)=c;
	}
	
	return str;
	
}
