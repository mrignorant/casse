#include<stdio.h>
#include <math.h>
#include<ncurses.h>
#include<stdlib.h>
#include<string.h>

void *mode (char *ch);
void *pb (char *ch);
void *bottles (char *ch);
void *preforms (char *ch);
void *otherrb (char *ch);

char choose_mode[50];

char produced_bottles[50];
int pr_bottles; 
char rb[50];
int int_rb;
char other_rb[50];
int int_orb;
char rp[50];
int int_rp;
int bl_counter;
double casse;


int main () {
	initscr();
	start_color();      // Enable color functionality
	noecho();
	cbreak();

	while(true){
  		init_pair(1, COLOR_GREEN, COLOR_BLACK); // Green text on yellow background
		attron(COLOR_PAIR(1)); 

		mvprintw(2,90,"j -> produced bottles"),
		mvprintw(3,90,"k -> rejected bottles"),
		mvprintw(4,90,"l -> other rb"),
		mvprintw(5,90,"m -> rejected preforms"),
 	
		attroff(COLOR_PAIR(1));  

		// Define color pair: pair 1 (red text on black background)
                init_pair(1, COLOR_RED, COLOR_BLACK);
		attron(COLOR_PAIR(1));         // Enable color pair 1	
		
		mvprintw(3,4,"produced bottles : %i",pr_bottles);
		mvprintw(4,4,"rejected bottles : %i",int_rb);
		mvprintw(5,4,"other rb         : %i",int_orb);
		mvprintw(6,4,"rejected preforms: %i",int_rp);
		bl_counter = pr_bottles + int_rb + int_orb + int_rp;
		mvprintw(7,4,"blower counter   : %i",bl_counter);
		casse = ( ( (double)int_rb + int_orb + int_rp ) / pr_bottles) * 100;
		mvprintw(8,4,"casse            : %.2f% ",casse);
		attroff(COLOR_PAIR(1));        // Disable color pair 1

		char ch = getch();
		noecho();

		mode(&ch);
		pb(&ch);
		bottles(&ch);
		preforms(&ch);
		otherrb(&ch);


		for(int j=3; j<10; j++){
			for(int i=0; i<100;i++){
				mvprintw(j,i," ");
			}
		}
	}

	getch();
	endwin();

	return 0;
}


void *mode (char *ch){
	if(*ch == 'y' ){
		for(int i=40; i<70;i++){
			mvprintw(4,i," ");
		}
		mvprintw(4,40,"choose mode: %s",choose_mode);
		move(4,53);
		echo();
		getstr(choose_mode);
	
	}	

}


void *pb (char *ch){
	
	if(*ch == 'j'){
		for(int i=0; i<100;i++){
			mvprintw(1,i," ");
		}
		mvprintw(1,18,"produced bottles (%i):    ",pr_bottles - pr_bottles);
		move(1,42);
		echo();
		getstr(produced_bottles);
		pr_bottles = atoi(produced_bottles);
		noecho();
	}
}

void *bottles (char *ch){
	if(*ch == 'k'){
		for(int i=0; i<100;i++){
			mvprintw(1,i," ");
		}
		mvprintw(1,18,"rejected bottles (%i):    ",int_rb - int_rb);
		move(1,42);
		echo();
		getstr(rb);
		int_rb = atoi(rb);                                                                                               
		noecho();
	}
}


void *otherrb (char *ch){

	if(*ch == 'l'){
		for(int i=0; i<100;i++){
			mvprintw(1,i," ");
		}
		mvprintw(1,18,"other rb (%i):    ",int_orb);
		move(1,42);
		echo();
		getstr(other_rb);
		int_orb = atoi(other_rb);
		noecho();
	}
}


void *preforms (char *ch){
	if(*ch == 'm'){
		for(int i=0; i<100;i++){
			mvprintw(1,i," ");
		}
		mvprintw(1,18,"rejected preforms (%i):    ",int_rp);
		move(1,42);
		echo();
		getstr(rp);
		int_rp = atoi(rp);
		noecho();
	}
}




