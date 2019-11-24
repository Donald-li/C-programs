
#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
/*
** 字符串翻转
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
** 这里假设str1和str2表示的数为非负数,并且str1表示的数大于等于str2的数
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
 
	Reverse(str1, len1);			// 将str1翻转
	Reverse(str2, len2);			// 将str2翻转
 
	memset(result, '0', N);
 
	int i, j;
 
	int multiFlag;					// 乘积进位
	int addFlag;					// 加法进位
 
	for (i = 0; i < len2; i++)		// str2的每一位
	{
		multiFlag = 0;
		addFlag = 0;
		for (j = 0; j < len1; j++) // str1的每一位
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
	
	Reverse(result, strlen(result));	// 对result进行翻转，得到最终的结果
}


int main(){

	//用来暂时将要存储输入数组的数字 
	int num=0;
	int n=0;
	
	printf("请输入您准备输入数字的个数：");
	scanf("%d",&n);  
	//为数组动态分配内存p 
	char*p=(char*)malloc(n*sizeof(char));
	//循环输入数组 
	for(int i=0;i<n;i++){
		printf("请输入第%s个数字：",i+1);
		scanf("%s",&num);
		*(p+i)=num;
		num=0;
	}

}
