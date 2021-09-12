#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct boxList box;
struct boxList {
	box *next;
	int color,length;
};
typedef struct boxQueue queue;
struct boxQueue {
	int* total;
	box *boxes;
	int min,max;
	queue *next;
}*head,*end;

void pb(box*);
void enq(box*,int,int);

int removeBoxes(int* boxes, int boxesSize){
	int total[100],segment[100],min,max,count,last_num;
	min = 0;
	for(int i=0;i<100;i++) {
		total[i]=0;
		segment[i]=0;
	}
	total[boxes[0]]++;
	segment[boxes[0]]++;
	count=1;
	last_num=boxes[0];
	box *init = (box*)malloc(sizeof(box));
	box *tail = init;
	for(int i=1;i<boxesSize;i++){
		if(boxes[i-1]!=boxes[i]) {
			tail->color=boxes[i-1];
			tail->length=count;
			tail->next=(box*)malloc(sizeof(box));
			tail=tail->next;
			segment[boxes[i]]++;
			min+=count*count;
			count=0;
			if(boxes[i]>last_num) {
				last_num = boxes[i];
			}
		}
		count++;
		total[boxes[i]]++;
	}
	tail->color=boxes[boxesSize-1];
	tail->length=count;
	tail->next=NULL;
	min+=count*count;
	max=0;
	for(int i=0;i<=last_num;i++) {
		max+=total[i]*total[i];
	}
	
	pb(init);
	printf("max = %d,min = %d",max,min);
	head=end=NULL;
	enq(init,min,max);
	while(head) {
		box *previous = head->boxes;
		box *current = previous->next;
		
		while(current) {
			int newMin = head->min ,newMax = head->max;
			int* newTotal = (int*)malloc(sizeof(int*last_num));
			for(int i=0;i<last_num;i++) {
				newTotal[i] = head->total[i];
			}
			newTotal[i];
			newMax -= newTotal
			if(!current->next && previous->color == current->next->color) {
				
				previous->length += current->next->length;
			}
		}
	}
	
	
	return 0;
}

void enq(box* box,int min,int max,int* total) {
	
}

void pb(box* b) {
	while(b) {
		for(int i=0;i<b->length;i++) {
			printf("%d ",b->color);
		}
		//puts("");
		b=b->next;
	}
	puts("");
}
int main() {
	int arr[10]={1,3,2,2,2,3,4,3,1};
	removeBoxes(arr,9);
	return 0;
}
