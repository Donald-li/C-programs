#include<stdio.h>
int a[128][128];
int b[128];
int k=0;
int n = 1;
void Table(int left,int right){
	
	int mid = (right+left)/2;
	if((right-left+1)>2){
		
		Table(left,mid);
		Table(mid+1,right);
		//�����½ǵĲ��ָ������Ͻ� 
		for(int i=0;i<=(right-left)/2;i++){
			for(int j=0;j<=(right-left)/2;j++){
				a[i+left][(right-left+1)/2+j]=a[mid+1+i][j];
			}
		}
		//�����ϽǵĲ��ָ������½�
		for(int i=0;i<=(right-left)/2;i++){
			for(int j=0;j<=(right-left)/2;j++){
				a[mid+1+i][(right-left+1)/2+j]=a[left+i][j];
				
			}
		}
		
		
		
	}else{
//			printf("��ʼ����һ������"); 
//			printf("\n");
			for(int i = left;i<=right;i++){
				for(int j = left;j<=right;j++){
					if(i!=j){
						a[i][1] = b[j];
					}else{
						continue;
					}
				}
			}
	}
} 


int main(){
	

	printf("��������ӹ�ģ��2��k���ݣ�k<7����");
	scanf("%d",&k);
	
	//kΪ������Ա�������ݣ���������Ա����n�� 

	for(int i = 1;i<=k;i++){
		n*=2;
	}
	
	//��ʼ��b�������Ա���
	for(int i = 1;i<=n;i++){
		b[i-1] = i;
	} 
	
	//��ʼ����һ�У��õ�һ�е���Ŵ�����Ա��� 
	for(int i=0;i<n;i++){
		a[i][0] = i+1;
	}
	
	Table(0,n-1);
	
	for(int i = 0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d",a[i][j]);
			
		}
		printf("\n");
	}	
	
	return 0;
}
