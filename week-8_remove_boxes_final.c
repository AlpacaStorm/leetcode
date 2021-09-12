#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
int ans[100][100][100];
int* box;
int ff(int left,int right,int expected) {
	if(ans[left][right][expected])
		return ans[left][right][expected];
	
	int i=right,j;
	for(;i>left;i--) {
		if(box[i]==box[right])
			expected++;
		else
			break;
	}
	int max = expected*expected + ff(left,i,0);
	
	for(j=i;j>=left;j--) {
		if(box[j]==box[right] && box[j+1]!=box[right]) {
			int temp = ff(left,j,expected) + ff(j+1,right-expected,0);
			if(temp>max)
				max = temp;
		}
	}
	ans[left][right][expected] = max;
	return max;
}

int removeBoxes(int* boxes, int boxesSize){
	box = boxes;
	memset(ans,0,sizeof(ans));
	
	for(int i=0;i<boxesSize;i++)
		for(int k=0;k<boxesSize;k++)
			ans[i][i][k]=(1+k) * (1+k);
	int final = ff(0,boxesSize-1,0);
	
	return final;
}

int main() {
		int arr[100]={1,3,2,2,2,3,4,3,1};
	int ans = removeBoxes(arr,9);
	printf("Ans = %d\n",ans);
	return 0;
}
