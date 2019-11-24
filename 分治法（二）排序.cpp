#include<stdio.h>

//int b[50];

//���鸴�ƺ��� 
void Copy(int a[50],int b[50],int left,int right){
	for(int i = 0;i<=(right-left);i++){
		a[left+i] = b[left+i];
	}
}

//�ϲ�����ϲ���������
void Merge_1(int a[50],int b[50],int left,int i,int right){
	int base = left;
	int mid = i;
	for(int j = 0;j<=(right-left);j++){
		if(a[left]<=a[i+1]){
			b[base+j] = a[left];
			if(left==mid&&i==(right-1)){
				b[right] = a[i+1];
			}
			left++;
	 }
		else if(a[left]>a[i+1]){
			b[base+j] = a[i+1];
			if(left==mid&&i==(right-1)){
				b[right] = a[left];
			}
			i++;
		}
	}
}
	
//�ϲ�����ϲ���������
void Merge_2(int arr[],int low,int mid,int high)
{
	int left_low=low;					//������е����±�
	int left_high=mid;
	int right_low=mid+1;				//�ұ����е����±�
	int right_high=high;
	int tmp[50],k=0,i;					//����tmp�����������Ԫ��
	while(left_low<=left_high&&right_low<=right_high)  //���������ж���Ԫ��ʱִ��ѭ��
	{
		if(arr[left_low]<arr[right_low])
			tmp[k++]=arr[left_low++];					//Ԫ��С�ķŽ�����tmp
		else
			tmp[k++]=arr[right_low++];
	}
	if(left_low<=left_high){							//������л���Ԫ��ʱ
		for(i=left_low;i<=left_high;i++)
			tmp[k++]=arr[left_low++];
	}
	if(right_low<=right_high){							//�ұ����л���Ԫ��ʱ
		for(i=right_low;i<=right_high;i++)
			tmp[k++]=arr[right_low++];
	}
 
	for(i=0;i<high-low+1;i++){							//������tmp�е�Ԫ�ظ�������arr���Ӷ�����arr����
		arr[low+i]=tmp[i];
	}
}


//�ϲ����򣬵ݹ鷽��
void MergeSort_1(int a[50],int left,int right){
	if(left<right){
		int i = (left+right)/2;
		MergeSort_1(a,left,i);
		MergeSort_1(a,i+1,right);
		Merge_2(a,left,i,right);
//		Copy(a,b,left,right);
	}
	
	
} 

int main(){
	
	//���潫Ҫ���������ĸ��� 
	int n = 0;
	int a[50];
	
//	for(int i = 0;i<1;i++){
//		printf("%d ",i);
//	}
	
	printf("�������������������ָ���������50�����֣���");
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		printf("���������������ĵ�%d���֣�����50�����֣���",i+1);
		scanf("%d",&a[i]);
	}
	MergeSort_1(a,0,n-1);
	printf("������ɺ�����飺");
	for(int i = 0;i<n;i++){
		printf("%d ",a[i]);
	}
//	printf("\n");
//	for(int i = 0;i<n;i++){
//		printf("%d ",b[i]);
//	}
	
	

	return 0;
}
