#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int Partition(int *array,int low,int high){
 
	int k=low+rand()%(high-low+1);
	int tmp;
	tmp=array[k];array[k]=array[low];array[low]=tmp;//���ѡ��һ���㣬Ȼ�������low���㻥����
	int key=array[low];
	while(low<high){
		while(low<high&&array[high]>key) high--;
			array[low]=array[high];
		while(low<high&&array[low]<key) low++;
			array[high]=array[low];
	}
	array[low]=key;
	return low;
}
void qsort(int *array,int low,int high){
	if(low<high){
		int po=Partition(array,low,high);
		qsort(array,low,po-1);
		qsort(array,po+1,high);
	}
}
int main(){
	int q[50]; 
	
	int n;
	printf("�������������������ָ���������50�����֣���");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("���������������ĵ�%d���֣�����50�����֣���",i+1);
		scanf("%d",&q[i]);	
	}	
	 
    qsort(q,0,n-1);  
    for(int i=0;i<n;i++)  
        printf("%d ",q[i]);  
}

