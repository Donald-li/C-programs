#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void mergeAdd1(int arr[], int left, int mid, int right, int *temp){
	int i = left;
	int j = mid + 1;
	int k = left;//��ʱ�±�
	while (i <= mid&&j <= right){
		if (arr[i] < arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
		}
	}
	while (i <= mid){
		temp[k++] = arr[i++];
	}
	while (j <= right){
		temp[k++] = arr[j++];
	}
	//��temp�е����ݿ���arr������
	//���й鲢��ʱ�򣬴����������arr[left,right),��Ӧ�Ļ��
	//�ⲿ������������tmp[left,right)������
	memcpy(arr + left, temp + left, sizeof(int)*(right - left + 1));
}
void mergeSort2(int arr[],int len,int* tmp){
	if (len <= 1){
		return;
	}
	//����һ������gap����ʼֵΪ1���൱��ÿ��ֻ�ϲ���������Ϊ1��Ԫ��
	int gap = 1;
	for (; gap <= len; gap *= 2){
		int i = 0;
		for (; i <= len; i += 2 * gap){
			int beg = i;
			int mid = (gap - 1) + i;
			if (mid >= len){
				mid = len;
			}
			int end = mid + gap;
			if (end >= len){
				end = len;
			}
			mergeAdd1(arr, beg, mid, end, tmp);
		}
	}
}


int main(){
	
	int arr[50];
	int n = 0;
	printf("�������������������ָ���������50�����֣���");
	scanf("%d",&n);
	for (int i = 0; i < n; i++){
		printf("���������������ĵ�%d���֣�����50�����֣���",i+1);
		scanf("%d",&arr[i]);
	}
	
	int *temp = (int*)malloc(sizeof(int)*n);
 
	mergeSort2(arr, (n - 1), temp);
	free(temp);
	for (int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	return 0;
}


