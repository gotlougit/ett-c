#include "inputs.h"
#include <stdio.h>
#include <time.h>

int main(void) {

	int secs = 0;

	secs += get_spec_int("Hours to wait (0-24): ",0,24) * 3600;
	secs += get_spec_int("Minutes to wait (0-60): ",0,60) * 60;
	secs += get_spec_int("Seconds to wait (0-60): ",0,60);

	time_t start,end;
	start = time(NULL);
	
	int running = 1;
	while (running) {

		end = time(NULL);
		float x = difftime(end,start);
		printf("%f\n",x);
		if (x >= secs) {
			running = 0;
			printf("TIMEUP!\n");
			break;
		}

	}

}
