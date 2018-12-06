#include <stdio.h>
#include <string.h>
#include <time.h>
#include "cpugovernorhash.h"
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
		struct GovernorType *attribType = (struct GovernorType *)lookupgovernor(schedutil, strlen(schedutil));
		clock_gettime(CLOCK_REALTIME, &end);
                printf("Total time elapsed : %ld seconds, %ld nanoseconds\n" , end.tv_sec - start.tv_sec, end.tv_nsec - start.tv_nsec);
	}	
}

