#include <stdio.h>

int a=54,b=24;
int main(){
	for(int c=a; c>0; c--){
		if(a%c==0 && b%c==0 ){
			printf("%d",c);
			break;
		}
	}
	return 0;
}
