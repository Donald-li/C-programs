#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void mergeAdd1(int arr[], int left, int mid, int right, int *temp){
	int i = left;
	int j = mid + 1;
	int k = left;//临时下标
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
	//把temp中的内容拷给arr数组中
	//进行归并的时候，处理的区间是arr[left,right),对应的会把
	//这部分区间的数组填到tmp[left,right)区间上
	memcpy(arr + left, temp + left, sizeof(int)*(right - left + 1));
}
void mergeSort2(int arr[],int len,int* tmp){
	if (len <= 1){
		return;
	}
	//定义一个步长gap，初始值为1，相当于每次只合并两个长度为1的元素
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
	printf("请输入待排序数组的数字个数（少于50个数字）：");
	scanf("%d",&n);
	for (int i = 0; i < n; i++){
		printf("请输入待排序数组的第%d数字（少于50个数字）：",i+1);
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


