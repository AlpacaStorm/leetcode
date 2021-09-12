#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define DRAW 2
#define CAT 1
#define MOUSE 0

typedef struct q queue;
struct q {
	int m,c,t;
	queue *next;
}*head,*tail;

void enq(int,int,int);

int catMouseGame(int** graph, int graphSize, int* graphColSize){
	head = NULL;
	int result[graphSize][graphSize][2];
	int chance[graphSize][graphSize][2];
	for(int i=0;i<graphSize;i++) {
		for(int j=0;j<graphSize;j++) {
			result[i][j][MOUSE]=result[i][j][CAT]=DRAW;
			chance[i][j][MOUSE]=graphColSize[i];
			chance[i][j][CAT]=graphColSize[j];
		}
	}
	result[0][0][MOUSE]=result[0][0][CAT]=MOUSE;
	for(int i=1;i<graphSize;i++) {
		for(int j=0;j<2;j++) {
			result[0][i][j]=MOUSE;
			enq(0,i,j);
			result[i][0][j]=MOUSE;
			enq(i,0,j);
			result[i][i][j]=CAT;
			enq(i,i,j);
		}
	}
	while(head) {
		struct q* cur = head;
		//printf("pops %d %d %d\n",cur->m,cur->c,cur->t);
		if(cur->t) {
			//cat turn
			for(int i=0;i<graphColSize[cur->m];i++) {
				//undetermined?
				if(result[graph[cur->m][i]][cur->c][MOUSE]==DRAW) {
					//printf("something happen at %d %d %d\n",*(*(g+cur->m)+i),cur->c,0);
					if(!result[cur->m][cur->c][CAT]) {
						//if cat loses any way
						//mouse should try to get this
						result[graph[cur->m][i]][cur->c][MOUSE] = MOUSE;
						enq(graph[cur->m][i],cur->c,MOUSE);
					}
					else {
						//if cat will win
						//mouse should avoid this
						chance[graph[cur->m][i]][cur->c][MOUSE]--;
						if(!chance[graph[cur->m][i]][cur->c][MOUSE]) {
							//if there's no chance for mouse
							//cat win
							result[graph[cur->m][i]][cur->c][MOUSE] = CAT;
							enq(graph[cur->m][i],cur->c,MOUSE);
						}
					}
				}
			}	
		}
		else {
			//mouse turn
			for(int i=0;i<graphColSize[cur->c];i++) {
				//same as above
				if(result[cur->m][graph[cur->c][i]][CAT]==DRAW) {
					if(result[cur->m][cur->c][MOUSE]) {
						result[cur->m][graph[cur->c][i]][CAT] = CAT;
						enq(cur->m,graph[cur->c][i],CAT);
					}
					else {
						chance[cur->m][graph[cur->c][i]][CAT]--;
						if(!chance[cur->m][graph[cur->c][i]][CAT]) {
							result[cur->m][graph[cur->c][i]][CAT] = MOUSE;
							enq(cur->m,graph[cur->c][i],CAT);
						}
					}
				}
			}
		}
		head = head->next;
		free(cur);
	}
    return result[1][2][0]==2 ? 0 : result[1][2][0]+1;
}

void enq(int m,int c,int t) {
	struct q* temp = (struct q*)malloc(sizeof(struct q));
	temp->m = m;
	temp->c = c;
	temp->t = t;
	temp->next = NULL;
	if(!head) {
		head = tail = temp;
	}
	else {
		tail->next = temp;
		tail = temp;
	}
}

//[[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]
/*
int a[10] = {2,5};
	int b[10] = {3};
	int c[10] = {0,4,5};
	int d[10] = {1,4,5};
	int e[10] = {2,3};
	int f[10] = {0,2,3};
	int *graph[6] = {a,b,c,d,e,f};
	int graphSize = 6;
	int graphColSize[6] = {2,1,3,3,2,3};
*/
/*
int a[10] = {4};
	int b[10] = {2,3,5};
	int c[10] = {1,5,3};
	int d[10] = {1,2};
	int e[10] = {0};
	int f[10] = {1,2};
	int *graph[6] = {a,b,c,d,e,f};
	int graphSize = 6;
	int graphColSize[6] = {1,3,3,2,1,2};
*/
/*
int a[10] = {5,6};
	int b[10] = {3,4};
	int c[10] = {6};
	int d[10] = {1,4,5};
	int e[10] = {1,3,5};
	int f[10] = {0,3,4,6};
	int g[10] = {0,2,5};
	int *graph[7] = {a,b,c,d,e,f,g};
	int graphSize = 7;
	int graphColSize[7] = {2,2,1,3,3,4,3};
*/
/*
int a[10] = {6};
int b[10] = {4};
int c[10] = {9};
int d[10] = {5};
int e[10] = {1,5};
int f[10] = {3,4,6};
int g[10] = {0,5,10};
int h[10] = {8,9,10};
int i[10] = {7};
int k[10] = {2,7};
int l[10] = {6,7};
int *graph[11] = {a,b,c,d,e,f,g,h,i,k,l};
int graphSize = 11;
int graphColSize[11] = {1,1,1,1,2,3,3,3,1,2,2};
*/
//[[2,3],[3,4],[0,4],[0,1],[1,2]]
int main() {
	int a[10] = {2,3};
	int b[10] = {3,4};
	int c[10] = {0,4};
	int d[10] = {0,1};
	int e[10] = {1,2};
	int *graph[5] = {a,b,c,d,e};
	int graphSize = 5;
	int graphColSize[5] = {2,2,2,2,2};
	
	/*
	for(int i=0;i<6;i++) {
		for(int j=0;j<graphColSize[i];j++) {
			printf("%d ",*(graph[i]+j));
		}
		puts("");
	}
	*/
	int ans = catMouseGame(graph,graphSize,graphColSize);
	printf("Ans = %d",ans);
}
