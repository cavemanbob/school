#include <stdio.h>
int i=1, sum=0, num=0;

int main(){
	scanf("%d",&num);
	while(i<=num){
		sum=sum+1;
		if(sum == num){
			printf("X number");
			break;
		}
		else if(sum>num){
			printf("Not X number");
		}
		i++;
	}

	return 0;
}
