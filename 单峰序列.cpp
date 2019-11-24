#include<stdio.h>
#include<stdlib.h>

//用来储存将要存储的数字的个数 
int n=0;

//查询单峰位置
int judge(int*p){
	
		int before = 0;
		int after = n-1; 
		while(1){
		
		//从前向后遍历数组判断后一项是否大于前一项 
		if(*(p+before+1)>*(p+before)&&before<after){
			before++;
			continue;
		}
		//如果后一项不大于前一项，试比较后浮标
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

	//用来暂时将要存储输入数组的数字 
	int num=0;
	
	printf("请输入您准备输入数字的个数：");
	scanf("%d",&n);  
	//为数组动态分配内存p 
	int*p=(int*)malloc(n*sizeof(int));
	//循环输入数组 
	for(int i=0;i<n;i++){
		printf("请输入第%d个数字：",i+1);
		scanf("%d",&num);
		*(p+i)=num;
		num=0;
	}
	
	judge(p);
	printf("\n%d",Find(p,0,n));
		
	//释放内存 
	free(p);
	return 0;
}
