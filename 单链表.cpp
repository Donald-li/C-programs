#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct LNode{
	int data;
	struct LNode *next;
}LNODE,*LinkList; 

//链表的建立
//函数名：CreateList_L(LinkList &L, int n)
//参数：  L表示创建的单链表，n表示创建的单链表的长度
//功能：根据给定长度n，逆位序输入n个元素的值，建立带表头结点的单链表L。
void CreateList(LinkList &L,int n){
	L=(LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	LinkList p;
	for(int i=n;i>0;i--){
		p=(LinkList)malloc(sizeof(LNode));
		printf("请输入第%d个元素:",i); 
		scanf("%d",&p->data);
		p->next = L->next;
		L->next = p;
	}
} 

//链表的打印
 //函数名：PrintList(LinkList L)
//参数：  L表示单链表的头指针
//功能：逐个打印单链表L的各个数据元素的值
void PrintList(LinkList L){
	LinkList p;
	p = L;
	printf("现在开始打印链表...\n");
	while(p->next!=NULL){
		printf("%d->",p->next->data);
		p=p->next;
	}
	printf("----------链表打印完毕！\n");
}

//链表的长度
//函数名：Listlength(LinkList L)
//参数：  L表示单链表的头指针
//返回：int型，返回整数值，表示单链表的长度
//功能：求单链表L的长度
int ListLength(LinkList L){
	int i=0;
	LNODE *p=L;
	while(p->next!=NULL){
		i++;
		p=p->next;
	}
	return i;
} 

//链表的插入操作
 //函数名：InsertList(LinkList &L,int i,int e)
//参数：  L表示单链表的头指针，i表示插入位置，e表示插入的数据元素的值
//返回：int型，返回1，表示插入成功，0表示插入失败
//功能：将数据元素e插入到单链表L的第i个位置上
int InsertList(LinkList &L,int i,int e){
	LNODE *p;
	p=L;
	int j=0;
	while(p!=NULL&&(j<i-1)){
		p=p->next;
		++j;
	}
	if(p||(j>i-1))
		return 0;
	else{
		LNODE *r;
		r=(LinkList)malloc(sizeof(LNode));
		r->data=e;
		r->next=p->next;
		p->next=r;
		return 1;
	}
}

//链表的删除
 //函数名：DeleteList(LinkList &L,int i)
//参数：  L表示单链表的头指针，i表示删除元素的位置
//返回：int型，返回删除元素的值
//功能：将单链表L的第i个结点删除，并返回删除元素的值
int DeleteList(LinkList &L,int i){
	int e;
	LinkList p = L;
	int j=0;
	if(i>ListLength(L)||i<0)
		return 00;
	while((j<i-1)&&p->next){
		p=p->next;
		j++;
	}
	LinkList q;
	q = p->next;
	p->next = q->next;
	return q->data;
} 
int main(){
   LinkList L;
   int length;
   int i,e;
   CreateList(L,10);
   PrintList(L);
   length=ListLength(L);
   printf("链表的长度为： %d\n",length);
   printf("请输入想要删除的元素的位置： ");
   scanf("%d",&i);
   printf("\n");
   int k=DeleteList(L,i);
   printf("删除的元素为：%d\n",k);
   PrintList(L);
   printf("请输入插入数据的位置i:");
   scanf("%d",&i);
   printf("\n"); 
   printf("请输入请输入插入数据的值e:");
   scanf("%d",&e);
   printf("\n"); 
   InsertList(L,i,e);
   PrintList(L);
   return 0;
}
