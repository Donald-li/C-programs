#include<stdio.h>
int a[128][128];

void Table(int k){
	//kΪ������Ա�������ݣ���������Ա����n�� 
	int n = 1;
	for(int i = 1;i<=k;i++){
		n*=2;
	}
	//��ʼ����һ�У��õ�һ�е���Ŵ�����Ա��� 
	for(int i=1;i<=n;i++){
		a[1][i] = i;
	}
	//������Ա��ģ�������̱� 
	int m = 1;
	for(int s = 1;s<=k;s++){
		n/=2;
		for(int t=1;t<=n;t++){
			for(int i=m+1;i<=2*m;i++){
				for(int j = m+1;j<=2*m;j++){
					a[i][j+(t-1)*m*2]=a[i-m][j+(t-1)*m*2-m];
					a[i][j+(t-1)*m*2-m]=a[i-m][j+(t-1)*m*2];
				}
				m*=2;
			}
		}
	}

	for(int i = 0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d",a[i][j]);
			printf("\n");
		}
	}	
} 


int main(){
	
	int k=0;
	printf("��������ӹ�ģ��2��k���ݣ�k<7����");
	scanf("%d",&k);
	Table(k);
	
	return 0;
}
