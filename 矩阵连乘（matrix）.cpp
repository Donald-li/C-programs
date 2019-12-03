#include<stdio.h>

//用来储存数组的行列信息，第一层表示矩阵数，第二层表示此个矩阵的行列数 
int matrix[50];

 //计算两个矩阵相乘所需次数
int MatrixMultiply(int num1,int num2,int num3){
 	int num;
 	num = num1*num2*num3; 
	return num; 	
} 

//递归计算最小相乘次数
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
	printf("请输入准备输入的矩阵数：");
	scanf("%d",&n);
	printf("\n");
	printf("请输入每个矩阵的行列数：");
	printf("\n");
	for(int i=0;i<=n;i++){
		scanf("%d",&matrix[i]); 
	}
	int u = ReturnMatrixChain(0,n-1);
	printf("最小相乘次数为：%d",u);
	return 0; 
}
