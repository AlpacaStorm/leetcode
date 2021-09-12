#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
void pts(int* st,int top) {
	for(int i=0;i<=top;i++) {
		printf("%d ",st[i]);
	} 
	puts("");
}

int largestRectangleArea(int* heights, int heightsSize){
	int hs[heightsSize],ps[heightsSize];
	int max=0,top=0,back;
	hs[0]=heights[0];
	ps[0]=0;
	for(int i=1;i<heightsSize;i++) {
		back = i;
		while(top&&heights[i]<hs[top]) {
			back=ps[top];
			int temp = hs[top]*(i-ps[top]);
			//printf("temp = %d\n",temp);
			if(temp>max)max = temp;
			top--;
		}
		if(heights[i]<hs[top]) {
			int temp = hs[top]*(i-ps[top]);
			//printf("temp = %d\n",temp);
			if(temp>max)max = temp;
			hs[0] = heights[i];
		}
		if(heights[i]>hs[top]) {
			top++;
			hs[top] = heights[i];
			ps[top] = back;
		}
		//printf("max = %d, hs[top] = %d, ps[top] = %d\n",max,hs[top],ps[top]);
		//pts(hs,top);
		//pts(ps,top);
	}
	while(top>=0) {
		int temp = hs[top]*(heightsSize-ps[top]);
		//printf("temp = %d\n",temp);
		if(temp>max)max = temp;
		top--;
	}
	return max;
}

int main() {
	int length = 6;
	int arr[] = {2,1,5,6,3,2};
	int ans = largestRectangleArea(arr,length);
	printf("ans = %d\n",ans);
}
