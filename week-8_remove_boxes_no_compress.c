#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int removeBoxes(int* boxes, int boxesSize){

	
	int ans[boxesSize][boxesSize][boxesSize];
	
	memset(ans,0,sizeof(ans));

	for(int i=0;i<boxesSize;i++)
		for(int k=0;k<boxesSize;k++)
			ans[i][i][k]=(1+k) * (1+k);
			
	
	
	for(int l=1;l<boxesSize;l++) {
		for(int i=0;i+l<boxesSize;i++) {
			int j = i+l;
			for(int k=0;k<boxesSize;k++) {
				ans[i][j][k]=ans[i][j-1][0]+(1+k)*(1+k);
			}
			for(int p=i;p<j;p++) {
				if(boxes[p]==boxes[j]) {
					for(int k=0;k+j<boxesSize;k++) {
						int temp = ans[i][p][k+1]+ans[p+1][j-1][0];
						if(temp > ans[i][j][k])
							ans[i][j][k]=temp;
					}
				}
			}
		}
	}	
	
	return ans[0][boxesSize-1][0];
}

int main() {
		int arr[100]={1,3,2,2,2,3,4,3,1};
	int ans = removeBoxes(arr,9);
	printf("Ans = %d\n",ans);
	return 0;
}
