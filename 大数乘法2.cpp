#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char*np;
//获取两个大数位数
int Count(long num){
	
	int count = 0;
	
	while(num!=0){
		num=num/10.0;
		count++;
	}
	return count;
} 

//计算两个大数乘积 
double Multi(char number1[200],char number2[200]){
	
	int n = strlen(number1);
	
	if(n<18){
		
		long num1 = strtol(number1,&np,0);
		long num2 = strtol(number2,&np,0);
		
//		printf("%ld\n",n1);
//		printf("%ld",n2);
		int n1 = 0;
		int n2 = 0;
	
		n1 = Count(num1);
		n2 = Count(num2);
	
		long long a = num1/pow(10,n1);
		long long b = num1 - a;
	
		long long c = num2/pow(10,n2);
		long long d = num2 - c;
	
		long long result = a*c*pow(2,n1)+((a-b)*(d-c)+a*c+b*d)*pow(2,n1/2)+b*d;
	
		return result ;
	}else{
		
		char a[100];
		char b[100];
		char c[100];
		char d[100];
		
		for(int i =0;i<(n/2);i++){
			a[i]=number1[i];
			c[i]=number2[i];
		}
		for(int i =(n/2);i<n;i++){
			b[i]=number1[i];
			d[i]=number2[i];
		}
		
		long a_n = strtol(a,&np,0);
		long b_n = strtol(b,&np,0);
		long c_n = strtol(c,&np,0);
		long d_n = strtol(d,&np,0);
		
		double result = Multi(a,c)*pow(2,n)+((a_n-b_n)*(d_n-c_n)+Multi(a,c)+Multi(b,d))*pow(2,n/2)+Multi(b,d);
		
		return result;
		
	}
	
}

int main(){

	char num1[200];
	char num2[200];
	printf("请输入第一个数（不超过200位）：");
	gets(num1);
	printf("请输入第二个数（不超过200位）：");
	gets(num2);
	
	double result;

	result = Multi(num1,num2);
	printf("结果为：%lf",result);
	
	
	return 0;
} 
