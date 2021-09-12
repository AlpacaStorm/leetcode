#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct boxList box;
struct boxList {
	box *next,*prev;
	int color,length;
}*init;

void pb(box*);
int rb();

int removeBoxes(int* boxes, int boxesSize){
	int total[100],segment[100],max,count,last_num;
	for(int i=0;i<100;i++) {
		total[i]=0;
		segment[i]=0;
	}
	total[boxes[0]]++;
	segment[boxes[0]]++;
	count=1;
	last_num=boxes[0];
	init = (box*)malloc(sizeof(box));
	box *tail = init;
	init->prev = NULL;
	init->next = NULL;
	init->color = boxes[0];
	init->length = 1;
	for(int i=1;i<boxesSize;i++){
		if(boxes[i-1]!=boxes[i]) {
			tail->next = (box*)malloc(sizeof(box));
			tail->next->prev = tail;
			tail = tail->next;
			
			tail->color=boxes[i];
			tail->length=1;
			tail->next = NULL;
		}
		else {
			tail->length++;
		}
	}
	max=0;
	pb(init);
	//system("Pause");
	int ans = rb(init);
	
	return ans;
}

int rb() {
	//printf("hi\n");
	int max = 0;
	if(!(init->next&&init->next->next)) {
		max += init->length * init->length;
		if(init->next)
			max+= init->next->length * init->next->length;
		return max;
	}
	for(box* cur = init;cur;cur=cur->next) {
		pb(init);
		//system("Pause");
		if(cur->next && cur->prev) {
			if(cur->prev->color == cur->next->color) {
				cur->prev->length += cur->next->length;
				cur->prev->next = cur->next->next;
				if(cur->next->next)
					cur->next->next->prev = cur->prev;
				
				int ans = rb()+cur->length*cur->length;
				pb(init);
				if(ans>max) {
					max = ans;
				}
				
				cur->prev->length -= cur->next->length;
				cur->prev->next = cur;
				if(cur->next->next)
					cur->next->next->prev = cur->next;
				

			}
			else {
				
				cur->next->prev = cur->prev;
				cur->prev->next = cur->next;
				
				int ans = rb()+cur->length*cur->length;
				pb(init);
				
				if(ans>max) {
					max = ans;
				}
				cur->next->prev = cur;
				cur->prev->next = cur;
			}
		}
	}
	
	return max;
}

void pb(box* b) {
	//return;
	while(b) {
		for(int i=0;i<b->length;i++) {
			printf("%d ",b->color);
		}
		b=b->next;
	}
	puts("");
}
int main() {
	int arr[100]={1,2,2,1,1,1,2,1,1,2,1,2,1,1,2,2,1,1,2,2
				,1,1,1,2,2,2,2,1,2,1,1,2,2,1,2,1,2,2,2,2
				,2,1,2,1,2,2,1,1,1,2,2,1,2,1,2,2,1,2,1,1
				,1,2,2,2,2,2,1,2,2,2,2,2,1,1,1,1,1,2,2,2
				,2,2,1,1,1,1,2,2,1,1,1,1,1,1,1,2,1,2,2,1};
	int ans = removeBoxes(arr,100);
	printf("Ans = %d\n",ans);
	return 0;
}
