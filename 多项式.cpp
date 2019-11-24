#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>

typedef struct LNode
{
    float coef;
    int exp;
    struct LNode* next;
}LNode,*LinkList;
typedef LinkList Polynomial;

//�����mֵ��ʾ����ʽ������������mʹ��β�巨��������ʽ����
void createPolyn(Polynomial &L,int m){
	L=(Polynomial)malloc(sizeof(LNode));
	L->next = NULL;
	Polynomial p;
	int e=1;
	for(int i=m;i>0;i--){
		p=(LinkList)malloc(sizeof(LNode));
		printf("�������%d��Ԫ��(ָ��Ϊ%d):",i,e);  
		scanf("%f",&p->coef);
		p->exp = e++;
		p->next = L->next;
		L->next = p;
	}
}
//la,lb�ֱ��ʾ����ʽA�Ͷ���ʽB����ṹ��ͷָ��
//�����������ʽ����ӣ����صõ��ĺ�
Polynomial addPolyn(Polynomial &la, Polynomial &lb){
	Polynomial p;
	p=(Polynomial)malloc(sizeof(LNode));
	p=la;
	while(p&&lb){
		if(lb->exp<p->exp){
			p->coef=p->coef;
			p=p->next;
			continue;
		}
		else if(lb->exp==p->exp){
			p->coef=p->coef+lb->coef;
			p=p->next;
			lb=lb->next;
			continue;
		}
		else if(lb->exp>p->exp){
			Polynomial e;
			e=(Polynomial)malloc(sizeof(LNode));
			e=p->next;
			p->next=lb;
			lb->next=e;
			continue;
		}
	} 
	return la;
}

//�������ʽ����
void printPolyn(Polynomial l){
  Polynomial p;
  p=(LinkList)malloc(sizeof(LNode));
  p=l->next;
  while(p)
  {
     printf("%.2f(x^%d) ",p->coef,p->exp);
     p=p->next;
  }
 printf("\n");
}
////x��ʾһԪ����ʽ�е�δ֪��x��ֵ������x�����ʽla��ֵ
////�д� 
//double polynValue(Polynomial la, double x){
//	double rel;
//	Polynomial p;
//	p = (Polynomial)malloc(sizeof(LNode));
//    p=la->next;
//	while(p){
////		printf("ϵ��\n");
////		printf("%lf\n",p->coef);
////		printf("ָ��\n");
////		printf("%lf\n",p->exp);
////		rel=rel+((double)p->coef)*(pow(x,(double)p->exp));
//		double q = p->coef;
//		double e = p->exp;
//		rel=rel+q*pow(x,e);
//		p=p->next;
//	}
//	return rel;
//}



int main(){
	int m,n;
 	float x;
 	Polynomial la,lb;
	printf("���������ʽla��������");
 	scanf("%d",&m);
	createPolyn(la,m);
	printf("���������ʽlb��������");
 	scanf("%d",&n);
 	createPolyn(lb,n);
 	printf("����ʽlaΪ��");
 	printPolyn(la);
 	printf("����ʽlbΪ��");
 	printPolyn(lb);
 	printf("��������ʽ�ĺ�Ϊ��");
 	printPolyn(addPolyn(la,lb));
// 	printf("������δ֪����ֵ��");
// 	scanf("%lf",&x);
//	printf("����ʽla��ֵΪ%2lf",polynValue(la,x));
	return 0;
}
