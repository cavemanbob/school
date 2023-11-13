#include <stdio.h>
int a=1234567;

int main(){
	while(a!=0){
	printf("%d",a%10);
	a=a/10;
	}
	return 0;
}
