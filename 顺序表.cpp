#include<stdio.h>
#include<malloc.h>
#include<iostream>
#define ListSize 50
//定义结构 
typedef struct{
	int* elem;
	int length;
	int listsie;
}SeqList;

//顺序表的建立
//函数名:CreateList(SeqList &L,int n)
//参数:L表示创建的顺序表，n表示创建的顺序表的长度
//功能:根据给定长度n和用户输入的n个数据创建顺序表L
void CreateList(SeqList &L,int n){
	L.elem = (int*)malloc(ListSize*sizeof(int));
	if(!L.elem)exit(0);
	L.listsie = ListSize;
	for(int i=1;i<=n;i++){
		printf("请输入第%d个数:",i);
		scanf("%d",&L.elem[i]);
		L.length=n; 
	}
} 

//顺序表的打印
//函数名：PrintList(SeqList  L)
//参数：  L表示要打印的顺序表
//功能： 依次打印顺序表L中的各个数据元素的值
void PrintList(SeqList L){
	printf("这个顺序表是:\n");
	for(int i=1;i<=L.length;i++){
		printf("%d,",L.elem[i]);
	}
} 
//顺序表的查找
//函数名：LocateList(SeqList  L,int  x)
//参数：  L表示要查找的顺序表，x表示要查找的数据元素
//返回： int型，如果找到，返回数据元素所在的下标，找不到返回0
//功能：在顺序表中进行查找,并返回查找的元素的位置
int  LocateList(SeqList &L,int x){
	int i;
	for(i=1;i<=L.length;i++){
		if(L.elem[i]==x)
			return i;
		if(i==L.length) return 0;
	}
}

//顺序表的插入
 //函数名：InsertList(SeqList &L,int  i,int e) 
//参数：  L表示要操作的顺序表，i表示插入元素的位置，e表示要插入的数据元素
//功能：在顺序表中将e插入到第i个数据元素的位置
void InsertList(SeqList &L,int i,int e){
	L.length++;
	for(int j=L.length;j>i;j--)
		L.elem[j]=L.elem[j-1];
	L.elem[i]=e;
}

////函数名：DeleteList(SeqList &L,int i)
//参数：  L表示要操作的顺序表，i表示删除元素的位置
//功能：在顺序表中删除第i个数据元素，删除之前将其打印出来
void DeleteList(SeqList &L,int i){
//	char r;
	printf("%d\n",L.elem[i]);
//	printf("您确定要删除它吗？(确定：y；不：n)\n");
	for(int j=i;j<L.length;j++)
		L.elem[j]=L.elem[j+1];
	L.length--;
				
}
int main(){
	SeqList L;
	int i,x;
	int n=10;				/*顺序表大小*/
	L.length=0;
	CreateList(L,n);		/*创建顺序表*/
	PrintList(L);			/*打印顺序表*/
	printf("\n请输入想要查找的数值：");
	scanf("%d",&x);
	i=LocateList(L,x);
	printf("您想查找的值得位置为%d \n",i);
	printf("请输入想要插入的位置：");
	scanf("%d",&i);
	printf("\n请输入想要插入的数值：");
	scanf("%d",&x);
	InsertList(L, i, x);		/*顺序表插入*/
	PrintList(L);			/*打印顺序表*/
	printf("\n请输入想要删除的数的位置：");
	scanf("%d",&i);
	printf("\n");
	DeleteList(L,i);		/*顺序表删除*/
	PrintList(L);         /*打印顺序表*/
	return 0 ;
}
