#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//inside code
//2 = draw
//1 = cat win
//0 = mouse win
struct q {
	int data[3];
	struct q *next;
}*head;

void enq(int,int,int);
struct q* deq();

int **g,g1,*g2;
int result[50][50][2];
int chance[50][50][2];

int catMouseGame(int** graph, int graphSize, int* graphColSize){
	g = graph;
	g1 = graphSize;
	g2 = graphColSize;
	head = NULL;
	for(int i=0;i<graphSize;i++) {
		for(int j=0;j<graphSize;j++) {
			result[i][j][0]=result[i][j][1]=2;
			chance[i][j][0]=*(g2+i);
			chance[i][j][1]=*(g2+j);
		}
	}
	for(int i=1;i<g1;i++) {
		for(int j=0;j<2;j++) {
			result[0][i][j]=0;
			enq(0,i,j);
			result[i][i][j]=1;
			enq(i,i,j);
		}
	}
	while(head) {
		struct q* cur = deq();
		int *data = cur->data;
		if(data[2]) {
			//cat turn
			for(int i=0;i<*(g2 + data[0]);i++) {
				if(result[data[0]][data[1]][data[2]] != 2) {
					continue;
				}
				if(result[data[0]][data[1]][data[2]] != data[2]) {
					result[]
				}
				else {
					
				}
			}
		}
		for(int i=0;i<*(g2 + data[!data[2]]);i++) {
			if(result[data[0]][data[1]][data[2]] != 2) {
				continue;
			}
			if(result[data[0]][data[1]][data[2]] != data[2]) {
				result[]
			}
			else {
				
			}
		}
		if(cur->t) {
			//cat turn
			if(result[cur->data[0]][cur->c][cur->t]==1) {
				//so last move is mouse
				for(int i=0;i<*(g2 + cur->m);i++) {
				
				}
			}
			
		}
		else {
			//mouse turn
		} 
	}
	int ans = 0;
	
    return ans;
}

void enq(int m,int c,int t) {
	
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
int main() {
	int a[10] = {2,5};
	int b[10] = {3};
	int c[10] = {0,4,5};
	int d[10] = {1,4,5};
	int e[10] = {2,3};
	int f[10] = {0,2,3};
	int *graph[6] = {a,b,c,d,e,f};
	int graphSize = 6;
	int graphColSize[6] = {2,1,3,3,2,3};
	
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
