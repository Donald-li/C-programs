#include<stdio.h>
#include<math.h>
//��ȡ��������λ��
int Count(long num){
	
	int count = 0;
	
	while(num!=0){
		num=num/10.0;
		count++;
	}
	return count;
} 

//�������������˻� 
long long Multi(long long num1,long long num2){
	
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
}

int main(){

	long long num1 = 0;
	long long num2 = 0;
	printf("�������һ������������200λ����");
	scanf("%lld",&num1);
	printf("������ڶ�������������200λ����");
	scanf("%lld",&num2);
	
	long long result;
	
	result = Multi(num1,num2);
	printf("���Ϊ��%lld",result);
	
	
	return 0;
} 
