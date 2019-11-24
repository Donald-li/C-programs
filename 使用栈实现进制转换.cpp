//进制转换
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAXSIZE 100

//定义栈结构
typedef struct stack{
	int data[MAXSIZE];
	int top;
}Stack;

//初始化栈
void intstack(Stack &s){
	s.top = 0;
} 

//判断栈空
int stackempty(Stack &s){
	if(s.top==0)
		return 1;
	else 
		return 0;
} 

//入栈
void push(Stack &s,int i){
	if(s.top==MAXSIZE){
		printf("栈满！");
	}
	else{
		s.data[s.top]=i;
		s.top++;
	} 
}

//出栈
int pop(Stack &s){
	int temp;
	temp = s.data[s.top-1];
	s.top--;
	return temp;
}

//进制转换
//十进制整数X和N作为形参
//初始化栈
//只要Ｘ不为０重复做下列动作
//      将Ｘ％N入栈
//　　　　X=X/N
//只要栈不为空重复做下列动作
//　　栈顶出栈
//　　输出栈顶元素
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
	printf("请输入想要转化的数字：");
	scanf("%d",&x);
	printf("请输入想要转化成几进制：");
	scanf("%d",&num);
	conversion(x,num);
	return 0;
} 
