#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	 int val;
	 struct ListNode *next;
 };
 
struct ListNode* reverseKGroup(struct ListNode* head, int k);

void main (){
	struct ListNode* tester = (struct ListNode*) malloc(sizeof(struct ListNode));
	struct ListNode* next = NULL;
	tester->val = -1;
	tester->next = (struct ListNode*) malloc(sizeof(struct ListNode));
	tester->next->val = -2;
	next = tester->next;
	for(int i=0;i<10;i++) {
		next->next = (struct ListNode*) malloc(sizeof(struct ListNode));
		next = next->next;
		next->val = i;
		next->next = NULL;
		
	}
	for(struct ListNode* temp = tester;temp;temp = temp->next) {
		printf("%d\n",temp->val);
	}
	tester = reverseKGroup(tester,5);
	puts("\n\n");
	for(struct ListNode* temp = tester;temp;temp = temp->next) {
		printf("%d\n",temp->val);
	}
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
	struct ListNode* pioneer = head;
	struct ListNode* pioneer_backup = pioneer;
	struct ListNode* small_head; 
	struct ListNode* head_next = head;
	struct ListNode* tail;
	//struct ListNode* tail_next = tail->next;
	int flag = 1;
	for(int i=1;i<k;i++) {
		if(pioneer->next)
			pioneer = pioneer->next;
		else {
			flag = 0;
			break;
		}
	}
	
	if(flag) {
		pioneer_backup = pioneer->next;
		head = pioneer;
	}
		
	while(flag) {
		for(int i=0;i<k;i++) {
			if(pioneer->next)
				pioneer = pioneer->next;
			else
				flag = 0;
		}
		if(flag) {
			pioneer_backup = pioneer->next;
		}
		else {
			pioneer = pioneer_backup;
		}
		tail = pioneer;
		for(int i=0;i<k;i++) {
			small_head = head_next;
			head_next = small_head->next;
			small_head->next = tail;
			tail = small_head;	
		}
	}
	return head;
}
