#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//
//2 3
//t = 2
//h = 1
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int t = nums1Size + nums2Size;
	int h = (t-1)/2;
	int c1=0,c2=0;
	int n1,n2;
	bool flag1,flag2;
	for(int i=0;i<h;i++) {
		flag1 = c1 == nums1Size;
		flag2 = c2 == nums2Size;
		if(flag1) {
			c2+=h-i;
			n1=nums2[c2++];
			break;
		}
		if(flag2) {
			c1+=h-i;
			n1=nums1[c1++];
			break;
		}
		nums1[c1] < nums2[c2] ? c1++ : c2++;
	}
	
	
	if(!(flag1||flag2)) {
		flag1 = c1 == nums1Size;
		flag2 = c2 == nums2Size;
		if(flag1) {
			n1 = nums2[c2++];
		}
		else if(flag2) {
			n1 = nums1[c1++];
		}
		else {
			n1 = nums1[c1] < nums2[c2] ? nums1[c1++] : nums2[c2++];
		}
	}
	//printf("%d\n",n1);
	if(t%2) {
		return n1;
	}
	flag1 = c1 == nums1Size;
	flag2 = c2 == nums2Size;
	//printf("flags %d %d\n",flag1,flag2);
	if(flag1) {
		n2 = nums2[c2];
		return (n1+n2)*0.5;
	}
	if(flag2) {
		n2 = nums1[c1];
		return (n1+n2)*0.5;
	}
	n2 = nums1[c1] < nums2[c2] ? nums1[c1] : nums2[c2];
	return (n1+n2)*0.5;
}

int main() {
	int arr1[10] = {};
	int arr2[10] = {1,2,3,4};
	int a = 10;
	double b = findMedianSortedArrays(arr1,0,arr2,4);
	printf("%lf",b);
}
