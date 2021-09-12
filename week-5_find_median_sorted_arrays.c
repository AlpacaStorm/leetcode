#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int t = nums1Size + nums2Size;
	int h = t/2;
	
	if(t%2) {
		if(nums2Size && nums1Size<=h) {
			if(!nums1Size || nums1[nums1Size-1]<=nums2[h-nums1Size]) {
				return nums2[h-nums1Size];
			}
			if(nums1[0]>=nums2[h]) {
				return nums2[h];
			}
		}
		if(nums2Size<=h) {
			if(!nums2Size || nums2[nums2Size-1]<=nums1[h-nums2Size]) {
				return nums1[h-nums2Size];
			}
			if(nums2[0]>=nums1[h]) {
				return nums1[h];
			}
		}
	}
	else {
		if(nums2Size && nums1Size<=h) {
			if(!nums1Size || nums1[nums1Size-1]<=nums2[h-nums1Size]) {
				if(nums1Size && (h-nums1Size==0 || nums2[h-nums1Size-1]<nums1[nums1Size-1])) {
					return (double)(nums2[h-nums1Size]+nums1[nums1Size-1])/2;
				}
				else {
					return (double)(nums2[h-nums1Size]+nums2[h-nums1Size-1])/2;
				}
			}
			if(nums2Size>h && nums1[0]>=nums2[h]) {
				return (double)(nums2[h]+nums2[h-1])/2;
			}
		}
		if(nums2Size<=h) {
			if(!nums2Size || nums2[nums2Size-1]<=nums1[h-nums2Size]) {
				if(nums2Size && (h-nums2Size==0 || nums1[h-nums2Size-1]<nums2[nums2Size-1])) {
					return (double)(nums1[h-nums2Size]+nums2[nums2Size-1])/2;
				}
				else {
					return (double)(nums1[h-nums2Size]+nums1[h-nums2Size-1])/2;
				}
			}
			if(nums1Size>h && nums2[0]>=nums1[h]) {
				return (double)(nums1[h]+nums1[h-1])/2;
			}
		}
		h--;
	}
	int c1=0,c2=0;
	for(int i=0;i<h;i++) {
		nums1[c1] < nums2[c2] ? c1++ : c2++;
	}
	if(t%2) {
		return nums1[c1]<nums2[c2] ? nums1[c1] : nums2[c2];
	}
	else {
		int n1 = nums1[c1] < nums2[c2] ? nums1[c1++] : nums2[c2++];
		int n2 = nums1[c1] < nums2[c2] ? nums1[c1] : nums2[c2];
		return (double)(n1+n2)/2;
	}
}

int main() {
	int arr1[10] = {};
	int arr2[10] = {2,3};
	int a = 10;
	double b = findMedianSortedArrays(arr1,0,arr2,2);
	printf("%lf",b);
}
