#include<stdio.h>

//�������������������Ϣ����һ���ʾ���������ڶ����ʾ�˸������������ 
int matrix[50][2];
//���������Ѽ�����Ľ��
int used[50][50];

 //����������������������
int MatrixMultiply(int num1,int num2,int num3){
 	int num;
 	num = num1*num2*num3; 
	return num; 	
} 

//�ݹ������С��˴���
int ReturnMatrixChain(int i,int j){
	if(used[i][j]!=-1) return used[i][j];
	else if(i==j){
		used[i][j] = 0;
		return 0;
	}
	int u = ReturnMatrixChain(i,i)+ReturnMatrixChain(i+1,j)+MatrixMultiply(matrix[i][0],matrix[i][1],matrix[j][1]);
	for(int k=i+1;k<j;k++){
		int t = ReturnMatrixChain(i,k)+ReturnMatrixChain(k+1,j)+MatrixMultiply(matrix[i][0],matrix[k+1][0],matrix[j][1]);
		if(t<u){
			u=t;
		}
	}
	used[i][j] = u;
	return u;	
}

int main(){
	
	//��ʼ����¼�����飬δ������ļ�Ϊ-1 
	for(int i=0;i<50;i++){
		for(int j=0;j<50;j++){
			used[i][j] = -1;
		}
	}
	
	int n;
	printf("������׼������ľ�������");
	scanf("%d",&n);
	printf("\n");
	for(int i=0;i<n;i++){
		printf("�������%d�������������",i+1);
		scanf("%d",&matrix[i][0]); 
		printf("�������%d�������������",i+1);
		scanf("%d",&matrix[i][1]);
	}
	int u = ReturnMatrixChain(0,n-1);
	printf("��С��˴���Ϊ��%d",u);
	return 0; 
}
