/* Getting time
 * Michelle Bergin
 */

#include <unistd.h>
#include <stdio.h>
#include <time.h>

// 31540000
// 2628000
// 86400
// 3600
// 60
// 1

int main(){
	time_t t;
	time(&t);
	int start;
	start = t;
	int year = (start / 31540000) + 1970;
	start = (start % 31540000);
	int month = start / 2628000;
	start = (start % 2628000);
	int day = start / 86400;
	start = (start % 86400);
	int hour = start / 3600;
	start = (start % 3600);
	int minute = start / 60;
	start = (start % 60);
	int second = start;

	printf("test %d/%d/%d %d:%d %d seconds\n", year, month, day, hour, minute, second);
	return 0;
}
