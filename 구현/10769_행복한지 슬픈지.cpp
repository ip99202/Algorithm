#include <stdio.h>
#include <string.h>
int main()
{
	char em[256];
	int happy = 0, sad = 0, none = 0;
	gets(em);
	for (int i = 2; i <= strlen(em); i++) {
		if (em[i - 2] == ':' && em[i - 1] == '-' && em[i] == ')') {
			happy++;
		}
		if (em[i - 2] == ':' && em[i - 1] == '-' && em[i] == '(') {
			sad++;
		}
	}
	if (happy == 0 && sad == 0) {
		printf("none");
	}
	else if (happy == sad) {
		printf("unsure");
	}
	else if (happy > sad) {
		printf("happy");
	}
	else if (happy < sad) {
		printf("sad");
	}
	return 0;
}