#include <stdio.h>
#include <math.h>

int f2(int bn, int dec=0, int rcx=0){
	return bn==0 ? dec : f2(bn/10, dec+ (int)pow(2,rcx) * (bn%10), rcx+1);
}

int main(){
  printf("%d",f2(1001001));
  return 0;
}
