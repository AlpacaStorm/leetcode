#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//inside code
//2 = cat win
//1 = draw
//0 = mouse win
int cat(int,int);
int mouse(int,int);
int **g,g1,*g2;
int result[50][50][2];
int trace[50][50][2];
int deep = 0;
int catMouseGame(int** graph, int graphSize, int* graphColSize){
	g = graph;
	g1 = graphSize;
	g2 = graphColSize;
	for(int i=0;i<graphSize;i++) {
		for(int j=0;j<graphSize;j++) {
			trace[i][j][0]=trace[i][j][1]=0;
			result[i][j][0]=result[i][j][1]=-1;
		}
	}
	int ans = mouse(1,2);
	if(ans == 1) return 0;
    if(ans == 0) return 1;
    return 2;
}

int cat(int m,int c) {
	/*
	for(int i=0;i<deep;i++) {
		printf("  ");
	}
	*/
	//printf("%d %d ",m,c);
	
	if(c == 0 || m == 0) {
		//printf("out 0\n");
		return 0;
	}
	if (m == c) {
		//printf("catch 2\n");
		return 2;
	}
	if(trace[m][c][0] == 1) {
		//printf("loop 1\n");
		return 1;
	}
	if(result[m][c][0] != -1) {
		//printf("repeated %d\n",trace[m][c][0]);
		return result[m][c][0];
	}
	//puts("");
	trace[m][c][0] = 1;
	deep++;
	int ans = -1;
	for(int i=0;i<*(g2+c);i++) {
		if(result[m][*(*(g+c)+i)]==2)
		ans = 0;
	}
	for(int i=0;i<*(g2+c);i++) {
		if(ans == 2) break;
		int temp = mouse(m,*(*(g+c)+i));
		if(temp>ans) {
			ans = temp;
		}
	}
	deep--;
	trace[m][c][0] = 0;
	if(ans!=1) {
		result[m][c][0] = ans;
	}
	/*
	for(int i=0;i<deep;i++) {
		printf("  ");
	}
	*/
	//printf("%d %d final %d\n",m,c,ans);
	return ans;
}
int mouse(int m,int c) {
	/*
	for(int i=0;i<deep;i++) {
		printf("  ");
	}
	*/
	//printf("%d %d ",m,c);
	if(c == 0) {
		//printf("invalid 0\n");
		return 0;
	}
	if (m == c) {
		//printf("catch 2\n");
		return 2;
	}
	if(m == 0) {
		///printf("out 0\n");
		return 0;
	}
	if(trace[m][c][1] == 1) {
		//printf("loop 1\n");
		return 1;
	}
	if(result[m][c][1] != -1) {
		//printf("repeated %d\n",trace[m][c][1]);
		return result[m][c][1];
	}
	//puts("");
	trace[m][c][1] = 1;
	deep++;
	int ans = 3;
	for(int i=0;i<*(g2+m);i++) {
		if(result[*(*(g+m)+i)][c]==0)
		ans = 0;
	}
	for(int i=0;i<*(g2+m);i++) {
		if(ans == 0) break;
		int temp = cat(*(*(g+m)+i),c);
		if(ans>temp) {
			ans = temp;
		}
	}
	deep--;
	trace[m][c][1] = 0;
	if(ans!=1) {
		result[m][c][1] = ans;
	}
	/*
	for(int i=0;i<deep;i++) {
		printf("  ");
	}
	*/
	//printf("%d %d final %d\n",m,c,ans);
	return ans;
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
