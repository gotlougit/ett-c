#include "inputs.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gettime(void) {

	int secs = 0;
	
	secs += get_spec_int("Hours (0-24): ",0,24) * 3600;
	secs += get_spec_int("Minutes (0-60): ",0,60) * 60;
	secs += get_spec_int("Seconds (0-60): ",0,60);

	return secs;

}

void wait(int diff) {

	time_t start,end;
	start = time(NULL);
	
	int running = 1;
	while (running) {

		end = time(NULL);
		float x = difftime(end,start);
		if (x >= diff) {
			running = 0;
			break;
		}

	}
}

int main(void) {

	printf("Enter time for working now-->\n");
	int secs = gettime();
	printf("Enter time for cooldown now-->\n");
	int cooldown = gettime();

	while (1) {
		wait(secs);
		system("notify-send -t 5000 \"Time's Up!\" \"Locking screen in 10 seconds...\"");
		wait(5);
		printf("Timeup!\n");
		system("loginctl lock-session");
		wait(cooldown);
		system("loginctl unlock-session");
		system("notify-send -t 5000 \"Welcome Back!\" \"Keep working...\"");
		printf("Welcome back!\n");
	}
}
