//����ת��
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAXSIZE 100

//����ջ�ṹ
typedef struct stack{
	int data[MAXSIZE];
	int top;
}Stack;

//��ʼ��ջ
void intstack(Stack &s){
	s.top = 0;
} 

//�ж�ջ��
int stackempty(Stack &s){
	if(s.top==0)
		return 1;
	else 
		return 0;
} 

//��ջ
void push(Stack &s,int i){
	if(s.top==MAXSIZE){
		printf("ջ����");
	}
	else{
		s.data[s.top]=i;
		s.top++;
	} 
}

//��ջ
int pop(Stack &s){
	int temp;
	temp = s.data[s.top-1];
	s.top--;
	return temp;
}

//����ת��
//ʮ��������X��N��Ϊ�β�
//��ʼ��ջ
//ֻҪ�ز�Ϊ���ظ������ж���
//      ���أ�N��ջ
//��������X=X/N
//ֻҪջ��Ϊ���ظ������ж���
//����ջ����ջ
//�������ջ��Ԫ��
void conversion(int x,int num){
	Stack *s;
	s = (Stack*)malloc(sizeof(Stack));
	intstack(*s);
	while(x){
		int a = x%num;
		push(*s,a);
		x=x/num;
	}
	while(!stackempty(*s)){
		printf("%d",pop(*s));
	}
} 

int main(){
	int num,x;
	printf("��������Ҫת�������֣�");
	scanf("%d",&x);
	printf("��������Ҫת���ɼ����ƣ�");
	scanf("%d",&num);
	conversion(x,num);
	return 0;
} 
