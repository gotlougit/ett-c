//A header file for getting safe inputs from user
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <math.h>

#define MAX_LEN 30

typedef struct {
	char value[MAX_LEN];
	int length;
} string;

/* This is the fundamental function to get
 * input from the user
 * Using this one function we can then typecast
 * to other types of input
 */ 

string get_string(char *msg) {

	string out;

	printf("%s",msg);

	fgets(out.value, MAX_LEN, stdin);
	out.length = strlen(out.value);
	out.value[out.length-1] = '\0';
	out.length-=1;

	return out;

}

/* Gets all integers safely (within memory limits) 
 * If invalid characters are found it return 0
 */

int get_int(char *msg) {

	string out = get_string(msg);
	int negative = 0;	
	int n = 0;
	for (int i = 1, l = out.length; i <= l; i++) {
		char c = out.value[i-1];
		if (c >= 48 && c <= 57) {
			c -= 48;
			n += pow(10,l-i) * c;	
		} 
		else if (i == 1 && c == 45) { //negative number case
			negative = 1;	
		} else {
			n = 0;
			break;
		}
	}
	if (negative) {
		n = -n;
	}
	return n;

}

int get_positive_int(char *msg) {
	int n = get_int(msg);
	if (n>=0) {
		return n;
	} else {
		return 0;
	}
}

/*Like get_int, but you can easily restrict what types of numbers you want
* If proper number isn't obtained, it returns lower range value
*/

int get_spec_int(char *msg, int lower, int higher) {
	int n = get_int(msg);
	if (n >= lower && n <= higher) {
		return n;
	} else {
		return lower;
	}
}
