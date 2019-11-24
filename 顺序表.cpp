#include<stdio.h>
#include<malloc.h>
#include<iostream>
#define ListSize 50
//����ṹ 
typedef struct{
	int* elem;
	int length;
	int listsie;
}SeqList;

//˳���Ľ���
//������:CreateList(SeqList &L,int n)
//����:L��ʾ������˳���n��ʾ������˳���ĳ���
//����:���ݸ�������n���û������n�����ݴ���˳���L
void CreateList(SeqList &L,int n){
	L.elem = (int*)malloc(ListSize*sizeof(int));
	if(!L.elem)exit(0);
	L.listsie = ListSize;
	for(int i=1;i<=n;i++){
		printf("�������%d����:",i);
		scanf("%d",&L.elem[i]);
		L.length=n; 
	}
} 

//˳���Ĵ�ӡ
//��������PrintList(SeqList  L)
//������  L��ʾҪ��ӡ��˳���
//���ܣ� ���δ�ӡ˳���L�еĸ�������Ԫ�ص�ֵ
void PrintList(SeqList L){
	printf("���˳�����:\n");
	for(int i=1;i<=L.length;i++){
		printf("%d,",L.elem[i]);
	}
} 
//˳���Ĳ���
//��������LocateList(SeqList  L,int  x)
//������  L��ʾҪ���ҵ�˳���x��ʾҪ���ҵ�����Ԫ��
//���أ� int�ͣ�����ҵ�����������Ԫ�����ڵ��±꣬�Ҳ�������0
//���ܣ���˳����н��в���,�����ز��ҵ�Ԫ�ص�λ��
int  LocateList(SeqList &L,int x){
	int i;
	for(i=1;i<=L.length;i++){
		if(L.elem[i]==x)
			return i;
		if(i==L.length) return 0;
	}
}

//˳���Ĳ���
 //��������InsertList(SeqList &L,int  i,int e) 
//������  L��ʾҪ������˳���i��ʾ����Ԫ�ص�λ�ã�e��ʾҪ���������Ԫ��
//���ܣ���˳����н�e���뵽��i������Ԫ�ص�λ��
void InsertList(SeqList &L,int i,int e){
	L.length++;
	for(int j=L.length;j>i;j--)
		L.elem[j]=L.elem[j-1];
	L.elem[i]=e;
}

////��������DeleteList(SeqList &L,int i)
//������  L��ʾҪ������˳���i��ʾɾ��Ԫ�ص�λ��
//���ܣ���˳�����ɾ����i������Ԫ�أ�ɾ��֮ǰ�����ӡ����
void DeleteList(SeqList &L,int i){
//	char r;
	printf("%d\n",L.elem[i]);
//	printf("��ȷ��Ҫɾ������(ȷ����y������n)\n");
	for(int j=i;j<L.length;j++)
		L.elem[j]=L.elem[j+1];
	L.length--;
				
}
int main(){
	SeqList L;
	int i,x;
	int n=10;				/*˳����С*/
	L.length=0;
	CreateList(L,n);		/*����˳���*/
	PrintList(L);			/*��ӡ˳���*/
	printf("\n��������Ҫ���ҵ���ֵ��");
	scanf("%d",&x);
	i=LocateList(L,x);
	printf("������ҵ�ֵ��λ��Ϊ%d \n",i);
	printf("��������Ҫ�����λ�ã�");
	scanf("%d",&i);
	printf("\n��������Ҫ�������ֵ��");
	scanf("%d",&x);
	InsertList(L, i, x);		/*˳������*/
	PrintList(L);			/*��ӡ˳���*/
	printf("\n��������Ҫɾ��������λ�ã�");
	scanf("%d",&i);
	printf("\n");
	DeleteList(L,i);		/*˳���ɾ��*/
	PrintList(L);         /*��ӡ˳���*/
	return 0 ;
}
