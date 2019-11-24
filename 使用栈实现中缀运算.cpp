#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAXSIZE 100
//操作数栈 
typedef struct intstack{
	int data[MAXSIZE];
	int top;
}IntStack;

//操作符栈
typedef struct charstack{
	char data[MAXSIZE];
	int top;
}CharStack;

//初始化栈
void Intstack(IntStack &s){
	s.top = 0;
} 
void Charstack(CharStack &s){
	s.top = 0;
} 

//判断栈空
int Intstackempty(IntStack &s){
	if(s.top==0)
		return 1;
	else 
		return 0;
} 

int Charstackempty(CharStack &s){
	if(s.top==0)
		return 1;
	else 
		return 0;
} 

//操作数栈取栈顶元素
int Intgettop(IntStack &s){
	int temp;
	temp = s.data[s.top-1];
	return temp;
} 

//操作数栈入栈
void Intpush(IntStack &s,int i){
	if(s.top==MAXSIZE){
		printf("栈满！");
	}
	else{
		s.data[s.top]=i;
		s.top++;
	} 
}

//操作数栈出栈
int Intpop(IntStack &s){
	int temp;
	temp = s.data[s.top-1];
	s.top--;
	return temp;
}


//操作符栈取栈顶元素
char Chargettop(CharStack &s){
	char temp;
	temp = s.data[s.top-1];
	return temp;
} 

//操作符栈入栈
void Charpush(CharStack &s,char i){
	if(s.top==MAXSIZE){
		printf("栈满！");
	}
	else{
		s.data[s.top]=i;
		s.top++;
	} 
}

//操作符栈出栈
char Charpop(CharStack &s){
	char temp;
	temp = s.data[s.top--];
	s.top--;
	return temp;
}

//判断是否为运算符
int ifop(char c){
	char op[]={'+','-','*','/'};
	for(int i=0;i<5;i++){
		if(c==op[i])
			return 1;
		else if(i==5)
			return 0;
	}
} 

// 判断两个字符s1和s2的优先级，如果s1优先级高于s2，
// 则返回>,两者优先级相等返回=，否则返回<
char precede(char s1,char s2){
	
	if(s1=='('&&s2!='(')
		return '>';
	else if(s1=='('&&s2=='(')
		return '=';
	else if(s1==')'&&s2!=')')
		return '<';
	else if(s1==')'&&s2==')')
		return '=';
	else if(s1=='*'||s1=='/'){
		if(s2=='+'||s2=='-'){
			return '>';
		}
		else if(s2=='*'||s2=='/'){
			return '=';
		}
	}
	else if(s1=='+'||s1=='-'){
		if(s2=='+'||s2=='-'){
			return '=';
		}
		else if(s2=='*'||s2=='/'){
			return '<';
		}
	}
//	else if(s1=='#'&&s2=='#')
//		return '=';
//	else if(s1=='#'&&s2!='#')
//		return '<';
//	else if(s1!='#'&&s2=='#')
//		return '>';
}

//计算a theta b的值，将结果返回
int Operate(int a,char theta,int b){
	int temp;
	if(theta=='+')
		temp=a+b;
	else if(theta=='-')
		temp=a-b;
	else if(theta=='*')
		temp=a*b;
	else if(theta=='/')
		temp=a/b;
	return temp;
}


//表达式求值compute
int compute(char exp[]){
   IntStack *int_stack;
   CharStack *char_stack;
   int_stack=(IntStack*)malloc(sizeof(IntStack));
   char_stack=(CharStack*)malloc(sizeof(CharStack));
   Charstack(*char_stack);
   Intstack(*int_stack);
   //中缀表达式转化为后缀表达式
   char back[MAXSIZE];
   int num=0;
   for(int i=0;exp[i]!='#';i++){ 
   		if(!ifop(exp[i])&&exp[i]!='('&&exp[i]!=')'&&exp[i]!='#'){
   			back[num]=exp[i];
   			num++;
   		}
   		else if(exp[i]=='('||exp[i]==')')
   		{	char temp='0';
   			if(exp[i]=='(')
   				Charpush(*char_stack,exp[i]);
   			else{
   				while(temp!='('){
   					temp = Charpop(*char_stack);
   					back[num]=temp;
   					num++;
   				}
   				back[num]=temp;
   				num++;
			   }
		   }
		else if(ifop(exp[i])){
			if(Charstackempty(*char_stack))
				Charpush(*char_stack,exp[i]);
			else{
				if(precede(exp[i],Chargettop(*char_stack))=='<'){
					back[num]=Charpop(*char_stack);
					num++;
				}
				else if(precede(exp[i],Chargettop(*char_stack))!='<'||Charstackempty(*char_stack))
					Charpush(*char_stack,exp[i]);
			}
		}
	}	
	if(!Charstackempty(*char_stack)){
		char temp2;
		while(!Charstackempty(*char_stack)){
			temp2=Charpop(*char_stack);
			back[num]=temp2;
			num++;
		}
	}
//计算后缀表达式 
   for(int i=0;exp[i]!='#';i++){
   		if(ifop(exp[i])){
			char op;
			int num1,num2,temp;
			op=Charpop(*char_stack);
			num1=Intpop(*int_stack);
			num2=Intpop(*int_stack);
			temp=Operate(num1,op,num2);
			Intpush(*int_stack,temp);
		}
   		else
   			Intpush(*int_stack,exp[i]);
   }
   printf("计算结果是：%d",Intgettop(*int_stack));
   
}

int main(){
	int p=0,i=0;
	char str[100];
	printf("请输入以#号为结束的表达式(只包含+,-,*,/,(,))：");//输入计算的表达式以#作为结束标志
	scanf("%c",&str[p]);
	while(str[p]!='#')//对输入字符进行判断直至输入#
	{
		p++;
		scanf("%c",&str[p]);
	}
	printf("\n");
	printf("输入表达式为：");
	for(i=0;i<p;i++)
		printf("%c",str[i]);
	printf("\n");
	compute(str);
	return 0;
}
