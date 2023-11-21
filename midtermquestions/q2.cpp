#include <stdio.h>
#include <math.h>

double a,b,tol,fa,fb,fm,m,k;
int main(){
	printf("Enter a and b: ");
	scanf("%lf%lf",&a,&b);
	printf("\n");
	printf("Enter tolerance: ");
	scanf("%lf",&tol);
	do{
		fa=pow(a,3)-a-2;
		fb=pow(b,3)-b-2;
		printf("f(a)=%lf ",fa);
		printf("f(b)=%lf \n",fb);
		if(fa * fb < 0){
			m= (a + b)/ 2;
			fm=pow(m,3)-m-2;
		}
		if(fa * fm < 0){
			b=m;
		}
		else {
			a=m;
		}
		printf("%lf",fm);
		printf("\nNew interval[%lf,%lf]",a,b);
	}
	while(fabs(fm) > tol);

	return 0;
}
