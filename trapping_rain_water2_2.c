#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int trapRainWater(int** heightMap, int heightMapSize, int* heightMapColSize){
	int c = heightMapColSize[0];
	bool ** maxed = (bool**) calloc(heightMapSize * c,sizeof(bool));
	for(int i=1;i<heightMapSize-1;i++) {
		for(int j=1;j<c-1;j++) {
			while(true) {
				
			}
		}
	}
	return 0;
}
int main() {
	int heightMapColSize[3] = {3,3,3};
	int heightMap[3][3] = {{3,3,3},{3,3,3},{3,3,3}};
	int ans = trapRainWater(heightMap,3,heightMapColSize);
}
