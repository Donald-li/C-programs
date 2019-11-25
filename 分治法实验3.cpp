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
		//将左下角的部分赋给右上角 
		for(int i=0;i<=(right-left)/2;i++){
			for(int j=0;j<=(right-left)/2;j++){
				a[i+left][(right-left+1)/2+j]=a[mid+1+i][j];
			}
		}
		//将左上角的部分赋给右下角
		for(int i=0;i<=(right-left)/2;i++){
			for(int j=0;j<=(right-left)/2;j++){
				a[mid+1+i][(right-left+1)/2+j]=a[left+i][j];
				
			}
		}
		
		
		
	}else{
//			printf("初始化第一天数据"); 
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
	

	printf("请输入球队规模（2的k次幂？k<7）：");
	scanf("%d",&k);
	
	//k为所有球员数量的幂，借此求出球员数量n。 

	for(int i = 1;i<=k;i++){
		n*=2;
	}
	
	//初始化b，代表队员编号
	for(int i = 1;i<=n;i++){
		b[i-1] = i;
	} 
	
	//初始化第一列，用第一列的序号代表球员序号 
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
