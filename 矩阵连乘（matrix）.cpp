#include<stdiio.h>

//�������������������Ϣ����һ���ʾ���������ڶ����ʾ�˸������������ 
int matrix[50][2];

 //����������������������
int MatrixMultiply(int num1.int num2,int num3){
 	int num;
 	num = num1*num2*num3; 
	return num; 	
} 

//�ݹ������С��˴���
int ReturnMatrixChain(int i,int j){
	if(i==j) return 0;
	int u = ReturnMatrixChain(i,i)+ReturnMatrixChain(i+1,j)+MatrixMultiply(matrix[i][1],matrix[i][2],matrix[j][2]);
	for(int k=i+1;k<j;k++){
		int t = ReturnMatrixChain(i,k)+ReturnMatrixChain(k+1,j)+MatrixMultiply(matrix[i][1],matrix[k][2],matrix[j][2]);
		if(t<u){
			u=t;
		}
	}
	return u;	
}

int main(){
	
	return 0; 
}
