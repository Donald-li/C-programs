#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAXSIZE 100
//������ջ 
typedef struct intstack{
	int data[MAXSIZE];
	int top;
}IntStack;

//������ջ
typedef struct charstack{
	char data[MAXSIZE];
	int top;
}CharStack;

//��ʼ��ջ
void Intstack(IntStack &s){
	s.top = 0;
} 
void Charstack(CharStack &s){
	s.top = 0;
} 

//�ж�ջ��
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

//������ջȡջ��Ԫ��
int Intgettop(IntStack &s){
	int temp;
	temp = s.data[s.top-1];
	return temp;
} 

//������ջ��ջ
void Intpush(IntStack &s,int i){
	if(s.top==MAXSIZE){
		printf("ջ����");
	}
	else{
		s.data[s.top]=i;
		s.top++;
	} 
}

//������ջ��ջ
int Intpop(IntStack &s){
	int temp;
	temp = s.data[s.top-1];
	s.top--;
	return temp;
}


//������ջȡջ��Ԫ��
char Chargettop(CharStack &s){
	char temp;
	temp = s.data[s.top-1];
	return temp;
} 

//������ջ��ջ
void Charpush(CharStack &s,char i){
	if(s.top==MAXSIZE){
		printf("ջ����");
	}
	else{
		s.data[s.top]=i;
		s.top++;
	} 
}

//������ջ��ջ
char Charpop(CharStack &s){
	char temp;
	temp = s.data[s.top--];
	s.top--;
	return temp;
}

//�ж��Ƿ�Ϊ�����
int ifop(char c){
	char op[]={'+','-','*','/'};
	for(int i=0;i<5;i++){
		if(c==op[i])
			return 1;
		else if(i==5)
			return 0;
	}
} 

// �ж������ַ�s1��s2�����ȼ������s1���ȼ�����s2��
// �򷵻�>,�������ȼ���ȷ���=�����򷵻�<
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

//����a theta b��ֵ�����������
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


//���ʽ��ֵcompute
int compute(char exp[]){
   IntStack *int_stack;
   CharStack *char_stack;
   int_stack=(IntStack*)malloc(sizeof(IntStack));
   char_stack=(CharStack*)malloc(sizeof(CharStack));
   Charstack(*char_stack);
   Intstack(*int_stack);
   //��׺���ʽת��Ϊ��׺���ʽ
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
//�����׺���ʽ 
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
   printf("�������ǣ�%d",Intgettop(*int_stack));
   
}

int main(){
	int p=0,i=0;
	char str[100];
	printf("��������#��Ϊ�����ı��ʽ(ֻ����+,-,*,/,(,))��");//�������ı��ʽ��#��Ϊ������־
	scanf("%c",&str[p]);
	while(str[p]!='#')//�������ַ������ж�ֱ������#
	{
		p++;
		scanf("%c",&str[p]);
	}
	printf("\n");
	printf("������ʽΪ��");
	for(i=0;i<p;i++)
		printf("%c",str[i]);
	printf("\n");
	compute(str);
	return 0;
}
