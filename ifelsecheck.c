#include <stdio.h>
#include <time.h>
#include <string.h>

int main(int count, int *words[]) {
	if (count != 2){
		return -1;
	}
        struct timespec start, end;
        char powersave[] = "powersave";
        char performance[] = "performance";
        char userspace[] = "userspace";
        char ondemand[] = "ondemand";
        char conservative[] = "conservative";
        char schedutil[] = "schedutil";
	char arr[20] = "";
	FILE *fp = fopen(words[1], "r");
	if(NULL == fp)
		return -1;
	while(NULL != fgets(arr, 20, fp)){
                clock_gettime(CLOCK_REALTIME, &start);
                if (0 == strncmp(arr, powersave, strlen(powersave))) {
                } else if (0 == strncmp(arr, performance, strlen(performance))) {
                } else if (0 == strncmp(arr, userspace, strlen(userspace))) {
                } else if (0 == strncmp(arr, ondemand, strlen(ondemand))) {
                } else if (0 == strncmp(arr, conservative, strlen(conservative))) {
                } else if (0 == strncmp(arr, schedutil, strlen(schedutil))) {
                }
                clock_gettime(CLOCK_REALTIME, &end);
		printf("Total time elapsed : %ld seconds, %ld nanoseconds\n" , end.tv_sec - start.tv_sec, end.tv_nsec - start.tv_nsec);
	}
        return 0;
}

