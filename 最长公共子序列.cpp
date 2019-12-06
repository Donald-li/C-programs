#include<stdio.h>
#include<string.h>
//储存输入的两个数组 
char x[1001];
char y[1001];
//储存xiyj的最长公共子序列
int c[101][1001][1001]; 

int LCSLength(int k,int n,int m){

	if(c[k][n][m]!=-1) return c[k][n][m];
//	else if(n!=0&&m!=0){
	else if(x[n]==y[m]){
		c[k][n][m] = LCSLength(k,n-1,m-1)+1;
		return LCSLength(k,n-1,m-1)+1;
	}
	else{
		c[k][n][m] = LCSLength(k,n,m-1);
		return LCSLength(k,n-1,m-1);
	}
//	}
		
}

int main(){
	//初始化c 
	 for(int i=1;i<101;i++){
		for(int j=1;j<1001;j++){
			for(int k=1;k<1001;k++){
				c[i][j][k] = -1;
			}
		}
	}
	
	
	int n=0;
	int num1,num2;
 	printf("请输入想要计算的组数:");
	scanf("%d",&n);
	//初始化计算，将所有与空序列计算的值设为0，作为递归出口 
	for(int k=1;k<=100;k++){
		for(int m = 1;m<=n;m++){
			for(int i=1;i<=m;i++)
				c[k][i][0] = 0;
			for(int j=1;j<=n;j++)
				c[k][0][j] = 0;
		}
	}
	
	for(int k=1;k<=n;k++){
	printf("请输入第%d组字符的第一个字符串x：",k); 
	scanf("%s",&x);
	num1=strlen(x);
	printf("\n");
	printf("请输入第%d组字符的第二个字符串y：",k);
	scanf("%s",&y);
	num2=strlen(y);
	printf("\n");
	LCSLength(k,num1,num2);
	printf("%d\n",c[k][num1][num2]);
	}
	
	return 0; 
}
