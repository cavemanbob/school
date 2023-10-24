#include <stdio.h>
#include <math.h>
int main() {
	double x,ans;
	printf("Promt a value for x:");
	scanf("%lf",&x);
	printf("\nVal1: %lf\nVal2: %lf\nVal3: %lf\nVal4: %lf\n", sqrt(25)+(pow(x,3)+4)/exp(2) , fabs(x*x + 3*x -10)/log(x) , (pow(sin(x),2) - 20) / cos(x) , log10(1000)/ (log10(x) + log(2)) );
	return 0;
}
