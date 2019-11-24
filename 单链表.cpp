#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct LNode{
	int data;
	struct LNode *next;
}LNODE,*LinkList; 

//����Ľ���
//��������CreateList_L(LinkList &L, int n)
//������  L��ʾ�����ĵ�����n��ʾ�����ĵ�����ĳ���
//���ܣ����ݸ�������n����λ������n��Ԫ�ص�ֵ����������ͷ���ĵ�����L��
void CreateList(LinkList &L,int n){
	L=(LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	LinkList p;
	for(int i=n;i>0;i--){
		p=(LinkList)malloc(sizeof(LNode));
		printf("�������%d��Ԫ��:",i); 
		scanf("%d",&p->data);
		p->next = L->next;
		L->next = p;
	}
} 

//����Ĵ�ӡ
 //��������PrintList(LinkList L)
//������  L��ʾ�������ͷָ��
//���ܣ������ӡ������L�ĸ�������Ԫ�ص�ֵ
void PrintList(LinkList L){
	LinkList p;
	p = L;
	printf("���ڿ�ʼ��ӡ����...\n");
	while(p->next!=NULL){
		printf("%d->",p->next->data);
		p=p->next;
	}
	printf("----------�����ӡ��ϣ�\n");
}

//����ĳ���
//��������Listlength(LinkList L)
//������  L��ʾ�������ͷָ��
//���أ�int�ͣ���������ֵ����ʾ������ĳ���
//���ܣ�������L�ĳ���
int ListLength(LinkList L){
	int i=0;
	LNODE *p=L;
	while(p->next!=NULL){
		i++;
		p=p->next;
	}
	return i;
} 

//����Ĳ������
 //��������InsertList(LinkList &L,int i,int e)
//������  L��ʾ�������ͷָ�룬i��ʾ����λ�ã�e��ʾ���������Ԫ�ص�ֵ
//���أ�int�ͣ�����1����ʾ����ɹ���0��ʾ����ʧ��
//���ܣ�������Ԫ��e���뵽������L�ĵ�i��λ����
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

//�����ɾ��
 //��������DeleteList(LinkList &L,int i)
//������  L��ʾ�������ͷָ�룬i��ʾɾ��Ԫ�ص�λ��
//���أ�int�ͣ�����ɾ��Ԫ�ص�ֵ
//���ܣ���������L�ĵ�i�����ɾ����������ɾ��Ԫ�ص�ֵ
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
   printf("����ĳ���Ϊ�� %d\n",length);
   printf("��������Ҫɾ����Ԫ�ص�λ�ã� ");
   scanf("%d",&i);
   printf("\n");
   int k=DeleteList(L,i);
   printf("ɾ����Ԫ��Ϊ��%d\n",k);
   PrintList(L);
   printf("������������ݵ�λ��i:");
   scanf("%d",&i);
   printf("\n"); 
   printf("������������������ݵ�ֵe:");
   scanf("%d",&e);
   printf("\n"); 
   InsertList(L,i,e);
   PrintList(L);
   return 0;
}
