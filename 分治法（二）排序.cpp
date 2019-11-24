#include<stdio.h>

//int b[50];

//数组复制函数 
void Copy(int a[50],int b[50],int left,int right){
	for(int i = 0;i<=(right-left);i++){
		a[left+i] = b[left+i];
	}
}

//合并排序合并两个部分
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
	
//合并排序合并两个部分
void Merge_2(int arr[],int low,int mid,int high)
{
	int left_low=low;					//左边序列的左下标
	int left_high=mid;
	int right_low=mid+1;				//右边序列的左下标
	int right_high=high;
	int tmp[50],k=0,i;					//数组tmp用来存放序列元素
	while(left_low<=left_high&&right_low<=right_high)  //当左右序列都有元素时执行循环
	{
		if(arr[left_low]<arr[right_low])
			tmp[k++]=arr[left_low++];					//元素小的放进数组tmp
		else
			tmp[k++]=arr[right_low++];
	}
	if(left_low<=left_high){							//左边序列还有元素时
		for(i=left_low;i<=left_high;i++)
			tmp[k++]=arr[left_low++];
	}
	if(right_low<=right_high){							//右边序列还有元素时
		for(i=right_low;i<=right_high;i++)
			tmp[k++]=arr[right_low++];
	}
 
	for(i=0;i<high-low+1;i++){							//将数组tmp中的元素赋给数组arr，从而数组arr有序
		arr[low+i]=tmp[i];
	}
}


//合并排序，递归方案
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
	
	//储存将要输入的数组的个数 
	int n = 0;
	int a[50];
	
//	for(int i = 0;i<1;i++){
//		printf("%d ",i);
//	}
	
	printf("请输入待排序数组的数字个数（少于50个数字）：");
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		printf("请输入待排序数组的第%d数字（少于50个数字）：",i+1);
		scanf("%d",&a[i]);
	}
	MergeSort_1(a,0,n-1);
	printf("排序完成后的数组：");
	for(int i = 0;i<n;i++){
		printf("%d ",a[i]);
	}
//	printf("\n");
//	for(int i = 0;i<n;i++){
//		printf("%d ",b[i]);
//	}
	
	

	return 0;
}
