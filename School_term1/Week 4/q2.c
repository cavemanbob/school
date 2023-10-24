#include <stdio.h>
#include <math.h>
int main() {
	double x,ans;
	printf("Promt a value for x:");
	scanf("%lf",&x);
	if(x<-3.0){
		printf("\nThe result of piecewise function is => %lf",(pow(x,3)+4)/pow(x,2));
	}
	else if(-2.0<=x && x<0.0){
		printf("\nThe result of piecewise function is => %lf",fabs(pow(x,2)+3*x-10));
	}
	else{
		printf("\nThe result of piecewise function is => %lf",x*x-4*x);
	}

	return 0;
}
