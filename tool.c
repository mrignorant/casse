#include<stdio.h>
#include<ncurses.h>
#include<stdlib.h>

int main (void){
	char bottles_produced [50];
	char rejected_preforms[50];
	char rejected_bottles [50];
	int blower_counter [50]; 
	int decimal;
	int decimal2;
	int decimal3;
	int decimal4;
	double decimal5;
	
	char world[3][50] = {
			    "################################################",
			    "#                          		                 ##",
	                    "################################################"
			};

	initscr();
	
	for(int r = 0; r < 3; r++){
		for(int c = 0; c < 50; c++){
			mvprintw(r+1,c+4,"%c",world[r][c]);
		} 
		printw("\n");
	}

	for(int r = 0; r < 3; r++){
		for(int c = 0; c < 50; c++){
			mvprintw(r+5,c+4,"%c",world[r][c]);
		} 
		printw("\n");
	}

	for(int r = 0; r < 3; r++){
		for(int c = 0; c < 50; c++){
			mvprintw(r+9,c+4,"%c",world[r][c]);
		} 
		printw("\n");
	}

	for(int r = 0; r < 3; r++){
		for(int c = 0; c < 50; c++){
			mvprintw(r+13,c+4,"%c",world[r][c]);
		} 
		printw("\n");
	}

	for(int r = 0; r < 3; r++){
		for(int c = 0; c < 50; c++){
			mvprintw(r+17,c+4,"%c",world[r][c]);
		} 
		printw("\n");
	}
	

	// init display
	mvprintw(2,6,"bottles produced: ");	
	mvprintw(6,6,"rejected preforms: ");	
	mvprintw(10,6,"rejected bottles: ");	
	mvprintw(14,6,"blower_counter: ");	
	mvprintw(18,6,"casse:  ");	

	mvprintw(2,6,"bottles produced: ");	
	getstr(bottles_produced);	
	decimal = atoi(bottles_produced); //atoi is a function that converts srtring to integer in stdlib library

	mvprintw(6,6,"rejected preforms: ");	
	getstr(rejected_preforms);
	decimal2 = atoi(rejected_preforms);

	mvprintw(10,6,"rejected bottles: ");	
	getstr(rejected_bottles);
	decimal3 = atoi(rejected_bottles);
	
	mvprintw(14,22,"%i ",decimal+decimal2+decimal3);

	mvprintw(18,15,"%.2f ",((double)decimal2+decimal3) / (decimal+decimal2+decimal3) * 100);
	
//	blower_counter = decimal2 + decimal3;	
//	mvprintw(10,6,"%i",blower_counter); 

/*	
	mvprintw(10,6,"blower counter: ");	
	getstr(blower_counter);
	decimal4 = atoi(blower_counter);
		
	mvprintw(10,6,"casse: ");	
	getstr(casse);
	decimal5 = atoi(casse);	
*/	
		
	
	
	

	getch();
	endwin();
	return 0;
}
