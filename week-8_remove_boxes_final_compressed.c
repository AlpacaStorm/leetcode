#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
int clumpColor[100],clumpSize[100];
int count;
int ans[100][100][200];

int ff(int left,int right,int expected) {
	if(ans[left][right][expected])
		return ans[left][right][expected];
		
	int tail = clumpSize[right]+expected;
	
	if(left==right) {
		ans[left][right][expected] = tail*tail;
		return ans[left][right][expected];
	} 
	
	int max = ff(left,right-1,0) + tail*tail;
	int i=right-2;
	for(;i>=left;i--) {
		if(clumpColor[right]==clumpColor[i]) {
			int temp = ff(left,i,tail) + ff(i+1,right-1,0);
			if(temp>max)
				max = temp;
		}
	}
	ans[left][right][expected] = max;
	return max;
}

int removeBoxes(int* boxes, int boxesSize){
	count=0;
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
	memset(ans,0,sizeof(ans));
			
	int final = ff(0,count-1,0);
	
	return final;
}

int main() {
		int arr[100]={1,3,2,2,2,3};
	int ans = removeBoxes(arr,6);
	printf("Ans = %d\n",ans);
	return 0;
}
