#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int trap(int* height, int heightSize){
	int ans = 0;
	int temp = 0;
	int maxh = 0;
	int peek = 0;
	int i=0;
	while(i<heightSize) {
		
		if(height[i]<maxh) {
			temp += maxh - height[i];
		}
		else {
			maxh = height[i];
			ans += temp;
			temp = 0;
			peek = i;
		}
		i++;
		//printf("At %d , h = %d , total = %d , temp = %d\n",i,height[i],ans,temp);
	}
	i--;
	maxh = 0;
	if(!temp) {
		return ans;
	}
	while(i>peek) {
		if(height[i]>=maxh) {
			maxh = height[i];
		}
		else {
			ans += maxh - height[i];
		}
		i--;
	}
	return ans;
}
int main() {
	int input[20] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int ans = trap(input,12);
	printf("%d",ans);
}
