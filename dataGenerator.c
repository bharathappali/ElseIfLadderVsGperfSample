#include <stdio.h>
#include <stdlib.h>

int main(int count, char *words[]) {
	if (count != 2) {
		printf("%s\n","Wrong arguments for code generation");
		return -1;
	}
	int i = 0;
	char *arr[6] = {"powersave", "performance", "userspace", "ondemand", "conservative", "schedutil"};
	if (0 == strncmp("random", words[1], 6)){
		for(i = 0; i < 2000; i++) { 
			printf("%s\n",arr[rand()%6]);
		}
	} else {
		for(i = 0; i < 2000; i++) {
			printf("%s\n", words[1]);
		}
	}
}
