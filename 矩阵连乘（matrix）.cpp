#include<stdio.h>

//�������������������Ϣ����һ���ʾ���������ڶ����ʾ�˸������������ 
int matrix[50];

 //����������������������
int MatrixMultiply(int num1,int num2,int num3){
 	int num;
 	num = num1*num2*num3; 
	return num; 	
} 

//�ݹ������С��˴���
int ReturnMatrixChain(int i,int j){
	if(i==j) return 0;
	int u = ReturnMatrixChain(i,i)+ReturnMatrixChain(i+1,j)+MatrixMultiply(matrix[i],matrix[i+1],matrix[j]);
	for(int k=i+1;k<j;k++){
		int t = ReturnMatrixChain(i,k)+ReturnMatrixChain(k+1,j)+MatrixMultiply(matrix[i],matrix[k],matrix[j]);
		if(t<u){
			u=t;
		}
	}
	return u;	
}

int main(){
	
	int n;
	printf("������׼������ľ�������");
	scanf("%d",&n);
	printf("\n");
	printf("������ÿ���������������");
	printf("\n");
	for(int i=0;i<=n;i++){
		scanf("%d",&matrix[i]); 
	}
	int u = ReturnMatrixChain(0,n-1);
	printf("��С��˴���Ϊ��%d",u);
	return 0; 
}
