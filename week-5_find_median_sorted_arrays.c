#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
	if(nums1Size>nums2Size) {
		int temp = nums1Size;
		nums1Size = nums2Size;
		nums2Size = temp;
		int *temp_ = nums1;
		nums1 = nums2;
		nums2 = temp_;
	}
	int left1=0,left2=0,right1=nums1-1,right2=nums2-2,n1,n2;
	while(true) {
		n1=nums1[(left1+right1)/2];
		n2=nums2[(left2+right2)/2];
	}
}

int main() {
	int nums1[];
	int nums2[];
}
