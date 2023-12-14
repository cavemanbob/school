#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <assert.h>

#define space 32
#define esc 27

int screen[160*44] = {0};
int bomb[160] = {0};
int bombTimer=0;
int difficulity=5; //the grater difficulity, the easier game
int CharacterY=0;
int CharacterJmpId=-3;

void fillscreen(){
	for(int i=160*40; i<160 * 41; i++){
		screen[i]=1;
	}
}
void clearscreen(){
	memset(screen, 0, 160*44*sizeof(int));
}
void movebomb(){
	for(int i=0;i<159;i++){
		bomb[i]=bomb[i+1];
	}
	bomb[159]=0;	
}
void addbomb(){
	if(bombTimer!=0)
		bombTimer--;
	else{
		int g=rand()%difficulity;
		if(g==3){
			bomb[159]=1;
			bombTimer=3;
		}	
	}
}
void printscreen(){
	printf("\x1b[2J"); //magic
	for(int y=0; y<44; y++){
		for(int x=0; x<160; x++){
			if(y==39){
				if(CharacterY==0 && x==6) printf("$");
				else bomb[x]==0 ? printf(" ") : printf("*");
			}
			else{
				if(CharacterY!=0 && x==6 && y==39-CharacterY) printf("$"); 
				else screen[160*y + x]==0 ? printf(" ") : printf("*");
			}
		}
		printf("\n");
	}
	printf("%d - %d",CharacterY,CharacterJmpId);
	printf("\x1b[H"); //magic
}
int CheckPressing(){
 	if (kbhit()) {
		char ch = getch();
		if ((int)ch == esc) assert(0);
		if ((int)ch == space) return 1;
		return 0;	
	  }
}
void hook(){
	if(CheckPressing() && CharacterY==0 && CharacterJmpId==-3){
		CharacterJmpId=3;
		CharacterY+=CharacterJmpId;
	}
	else if(CharacterJmpId !=-3){
		CharacterJmpId--;
		CharacterY+=CharacterJmpId;
	}
}
void checkDied(){
	if(CharacterY==0 && bomb[6]==1){
		printf("YOU FUCKED UP !!\n");
		assert(0);
	}
}

int main(){
	srand(time(NULL));
	while(1){
		hook();
		addbomb();
		movebomb();
		fillscreen();
		printscreen();
		checkDied();
		clearscreen();
		usleep(1000 * 1000 * 1);
	}
}
