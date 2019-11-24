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

//传入的m值表示多项式的项数，根据m使用尾插法创建多项式链表
void createPolyn(Polynomial &L,int m){
	L=(Polynomial)malloc(sizeof(LNode));
	L->next = NULL;
	Polynomial p;
	int e=1;
	for(int i=m;i>0;i--){
		p=(LinkList)malloc(sizeof(LNode));
		printf("请输入第%d个元素(指数为%d):",i,e);  
		scanf("%f",&p->coef);
		p->exp = e++;
		p->next = L->next;
		L->next = p;
	}
}
//la,lb分别表示多项式A和多项式B链表结构的头指针
//完成两个多项式的相加，返回得到的和
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

//输出多项式链表
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
////x表示一元多项式中的未知数x的值，根据x求多项式la的值
////有错。 
//double polynValue(Polynomial la, double x){
//	double rel;
//	Polynomial p;
//	p = (Polynomial)malloc(sizeof(LNode));
//    p=la->next;
//	while(p){
////		printf("系数\n");
////		printf("%lf\n",p->coef);
////		printf("指数\n");
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
	printf("请输入多项式la的项数：");
 	scanf("%d",&m);
	createPolyn(la,m);
	printf("请输入多项式lb的项数：");
 	scanf("%d",&n);
 	createPolyn(lb,n);
 	printf("多项式la为：");
 	printPolyn(la);
 	printf("多项式lb为：");
 	printPolyn(lb);
 	printf("两个多项式的和为：");
 	printPolyn(addPolyn(la,lb));
// 	printf("请输入未知数的值：");
// 	scanf("%lf",&x);
//	printf("多项式la的值为%2lf",polynValue(la,x));
	return 0;
}
