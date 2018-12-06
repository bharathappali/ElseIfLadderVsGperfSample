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
                if (0 == strncmp("powersave", powersave, strlen(powersave))) {
                } else if (0 == strncmp("powersave", performance, strlen(performance))) {
                } else if (0 == strncmp("powersave", userspace, strlen(userspace))) {
                } else if (0 == strncmp("powersave", ondemand, strlen(ondemand))) {
                } else if (0 == strncmp("powersave", conservative, strlen(conservative))) {
                } else if (0 == strncmp("powersave", schedutil, strlen(schedutil))) {
                }
                clock_gettime(CLOCK_REALTIME, &end);
		printf("Total time elapsed : %ld seconds, %ld nanoseconds\n" , end.tv_sec - start.tv_sec, end.tv_nsec - start.tv_nsec); 
        }
        return 0;
}

