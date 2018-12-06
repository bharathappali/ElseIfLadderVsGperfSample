#include <stdio.h>
#include <time.h>
#include <string.h>

int main() {
	struct timespec start, end;
        char powersave[] = "powersave";
        char performance[] = "performance";
        char userspace[] = "userspace";
        char ondemand[] = "ondemand";
        char conservative[] = "conservative";
        char schedutil[] = "schedutil";
	int i = 0;
	for(i = 0; i < 2000; i++){
		clock_gettime(CLOCK_REALTIME, &start);
        	if (0 == strncmp("schedutil", powersave, strlen(powersave))) {
	        } else if (0 == strncmp("schedutil", performance, strlen(performance))) {
	        } else if (0 == strncmp("schedutil", userspace, strlen(userspace))) {
	        } else if (0 == strncmp("schedutil", ondemand, strlen(ondemand))) {
	        } else if (0 == strncmp("schedutil", conservative, strlen(conservative))) {
	        } else if (0 == strncmp("schedutil", schedutil, strlen(schedutil))) {
	        }
		clock_gettime(CLOCK_REALTIME, &end);
                printf("Total time elapsed : %ld seconds, %ld nanoseconds\n" , end.tv_sec - start.tv_sec, end.tv_nsec - start.tv_nsec);
	}
        return 0;
}

