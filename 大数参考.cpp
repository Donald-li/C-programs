
#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
/*
** �ַ�����ת
*/
void Reverse(char *str, int n)
{
	int i;
 
	for (i = 0; i < n / 2; i++)
	{
		char tmp;
		tmp = str[i];
		str[i] = str[n-i-1];
		str[n-i-1] = tmp;
	}
}



/*
** �������str1��str2��ʾ����Ϊ�Ǹ���,����str1��ʾ�������ڵ���str2����
*/
void BigNumMulti(char *str1, char *str2, char *result)
{
	if (str1 == NULL || str2 == NULL || result == NULL)
	{
		return;
	}
 
	if (strcmp(str1, "0") == 0 || strcmp(str2, "0") == 0)
	{
		strcpy(result, "0");
		return;
	}
 
	int len1, len2;
 
	len1 = strlen(str1);
	len2 = strlen(str2);
 
	Reverse(str1, len1);			// ��str1��ת
	Reverse(str2, len2);			// ��str2��ת
 
	memset(result, '0', N);
 
	int i, j;
 
	int multiFlag;					// �˻���λ
	int addFlag;					// �ӷ���λ
 
	for (i = 0; i < len2; i++)		// str2��ÿһλ
	{
		multiFlag = 0;
		addFlag = 0;
		for (j = 0; j < len1; j++) // str1��ÿһλ
		{			
			int temp1 = (str2[i] - '0') * (str1[j] - '0') + multiFlag;
			multiFlag = temp1 / 10;
			temp1 = temp1 % 10;
			int temp2 = (result[i+j] - '0') + temp1 + addFlag;
			addFlag = temp2 / 10;
			result[i+j] = temp2 % 10 + '0'; 
		}
		result[i + len1] += multiFlag + addFlag;
	}
 
	if (result[len1+len2-1] == '0')
	{
		result[len1+len2-1] = '\0';
	}
	else
	{
		result[len1+len2] = '\0';
	}
	
	Reverse(result, strlen(result));	// ��result���з�ת���õ����յĽ��
}


int main(){

	//������ʱ��Ҫ�洢������������� 
	int num=0;
	int n=0;
	
	printf("��������׼���������ֵĸ�����");
	scanf("%d",&n);  
	//Ϊ���鶯̬�����ڴ�p 
	char*p=(char*)malloc(n*sizeof(char));
	//ѭ���������� 
	for(int i=0;i<n;i++){
		printf("�������%s�����֣�",i+1);
		scanf("%s",&num);
		*(p+i)=num;
		num=0;
	}

}
