#include <stdio.h>
#include <time.h>
int main() {
	time_t timer;
	struct tm* t;
	timer = time(NULL);
	t = localtime(&timer);
	printf("%d\n%d\n%d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
	return 0;
}