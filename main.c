#include "inputs.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gettime(void) {

	int secs = 0;
	
	secs += get_spec_int("Hours to wait (0-24): ",0,24) * 3600;
	secs += get_spec_int("Minutes to wait (0-60): ",0,60) * 60;
	secs += get_spec_int("Seconds to wait (0-60): ",0,60);

	return secs;

}

int wait(int diff) {

	time_t start,end;
	start = time(NULL);
	
	int running = 1;
	while (running) {

		end = time(NULL);
		float x = difftime(end,start);
		if (x >= diff) {
			running = 0;
			return 0;
			break;
		}

	}
}

int main(void) {

	int secs = gettime();
	wait(secs);
	printf("Timeup!\n");

}
