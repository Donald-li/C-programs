#include<stdio.h>
#include<stdlib.h>

//�������潫Ҫ�洢�����ֵĸ��� 
int n=0;

//��ѯ����λ��
int judge(int*p){
	
		int before = 0;
		int after = n-1; 
		while(1){
		
		//��ǰ�����������жϺ�һ���Ƿ����ǰһ�� 
		if(*(p+before+1)>*(p+before)&&before<after){
			before++;
			continue;
		}
		//�����һ�����ǰһ��ԱȽϺ󸡱�
		else if(*(p+after)<*(p+after-1)&&after>before){
				after--;
				continue;
			}
		else if((p+before)==(p+after)){
				printf("%d",before+1);
				return before+1;
				break;
			}
		else{
				printf("0");
				return 0;
				break;
			}
		
		
	} 
	
} 

int Find(int*p,int before,int after){
	
	int mid = (before+after)/2;
	if(mid==n-1||mid==0) return mid+1;
	else if(*(p+mid-1)<*(p+mid)&&*(p+mid)>*(p+mid+1)) return mid+1;
	else if(*(p+mid-1)<*(p+mid)&&*(p+mid)<*(p+mid+1)) Find(p,mid,n);
	else if(*(p+mid-1)>*(p+mid)&&*(p+mid)>*(p+mid+1)) Find(p,0,mid);
	else return 0;
	
}


int main(){

	//������ʱ��Ҫ�洢������������� 
	int num=0;
	
	printf("��������׼���������ֵĸ�����");
	scanf("%d",&n);  
	//Ϊ���鶯̬�����ڴ�p 
	int*p=(int*)malloc(n*sizeof(int));
	//ѭ���������� 
	for(int i=0;i<n;i++){
		printf("�������%d�����֣�",i+1);
		scanf("%d",&num);
		*(p+i)=num;
		num=0;
	}
	
	judge(p);
	printf("\n%d",Find(p,0,n));
		
	//�ͷ��ڴ� 
	free(p);
	return 0;
}
