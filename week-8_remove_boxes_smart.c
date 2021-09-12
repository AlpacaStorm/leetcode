#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
int removeBoxes(int* boxes, int boxesSize){
	int clumpColor[100],clumpSize[100];
	int count=0;
	clumpColor[0]=boxes[0];
	clumpSize[0]=1;
	for(int i=1;i<boxesSize;i++) {
		if(boxes[i-1]!=boxes[i]) {
			count++;
			clumpColor[count]=boxes[i];
			clumpSize[count]=1;
		}
		else {
			clumpSize[count]++;
		}
	}
	count++;
	
	int ans[count][count][boxesSize*2];
	memset(ans,0,sizeof(ans));

	for(int i=0;i<count;i++)
		for(int k=0;k<boxesSize;k++)
			ans[i][i][k]=(clumpSize[i]+k) * (clumpSize[i]+k);
			
	
	
	for(int l=1;l<count;l++) {
		for(int i=0;i<count;i++) {
			int j = i+l<count-1 ? i+l : count-1;
			for(int k=0;k<boxesSize;k++) {
				ans[i][j][k]=ans[i][j-1][0]+(clumpSize[j]+k)*(clumpSize[j]+k);
			}
			for(int p=i;p<j;p++) {
				if(clumpColor[p]==clumpColor[j]) {
					for(int k=0;k<boxesSize;k++) {
						int temp = ans[i][p][k+clumpSize[j]]+ans[p+1][j-1][0];
						if(temp > ans[i][j][k])
							ans[i][j][k]=temp;
					}
				}
			}
		}
	}
	for(int i=0;i<count;i++) {
		for(int j=0;j<count;j++) {
			printf("%3d",ans[i][j][0]);
		}
		puts("");
	}
	
	
	return ans[0][count-1][0];
}

int main() {
		int arr[100]={1,3,2,2,2,3,4,3,1};
	int ans = removeBoxes(arr,9);
	printf("Ans = %d\n",ans);
	return 0;
}
