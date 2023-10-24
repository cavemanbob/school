#include <stdio.h>

int main() {
	int midterm= 0, final= 0, homework= 0, lab=0;
	printf("Midterm grade:%d\nFinal grade:%d\nHomework grade:%d\nlab grade:%d\n",midterm,final,homework,lab);
	(20*midterm+40*final+10*homework+30*lab)/100>60 ? printf("Pass") : printf("Fail");

	return 0;
}
