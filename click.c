#include<stdio.h>
#include <math.h>
#include <unistd.h>
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
	if (has_colors() == FALSE) {
                endwin();
   	 	printf("Your terminal does not support color\n");
    		return 1;
	}

	start_color();      // Enable color functionality
	noecho();
	cbreak();

    // Define color pairs (foreground, background)
	init_pair(1,6 , 0);      //6 cyan 
	init_pair(2,8 ,0);    //  94 brown like 
	init_pair(3,37, 0);   //  137 brow ,  
	init_pair(4, 137, 0);   // 37 light blue 


	attron(COLOR_PAIR(3));
	mvprintw(1,1,"#########################################\n");
	mvprintw(2,1,"## cccccc aaaaaa ssssss ssssss eeeeeee ##\n");
	mvprintw(3,1,"## cc     aa  aa ss     ss     ee      ##\n");
	mvprintw(4,1,"## cc     aaaaaa ssssss ssssss eeeeeee ##\n");
	mvprintw(5,1,"## cc   c aa  aa     ss     ss ee      ##\n");
	mvprintw(6,1,"## cccccc aa  aa ssssss ssssss eeeeeee ##\n");
	mvprintw(7,1,"#########################################\n");
	attroff(COLOR_PAIR(3));
	// napms(3000);

	while(true){
		
		attron(COLOR_PAIR(2));
		mvprintw(20,9,"keys");
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(2)); 
		mvprintw(21,2,"j -> produced bottles"),
		mvprintw(22,2,"k -> rejected bottles"),
		mvprintw(23,2,"l -> other rb"),
		mvprintw(24,2,"m -> rejected preforms"),
		attroff(COLOR_PAIR(2));  


		attron(COLOR_PAIR(1));         // Enable color pair 1	
		mvprintw(11,2,"produced bottles : %i",pr_bottles);
		mvprintw(12,2,"rejected bottles : %i",int_rb);
		mvprintw(13,2,"other rb         : %i",int_orb);
		mvprintw(14,2,"rejected preforms: %i",int_rp);
		bl_counter = pr_bottles + int_rb + int_orb + int_rp;
		mvprintw(15,2,"blower counter   : %i",bl_counter);
		casse = ( ( (double)int_rb + int_orb + int_rp ) / pr_bottles) * 100;
		mvprintw(16,2,"casse            : %.2f %% ",casse);
		attroff(COLOR_PAIR(1));        // Disable color pair 1

		char ch = getch();
		noecho();
		attron(COLOR_PAIR(4));
		mode(&ch);
		pb(&ch);
		bottles(&ch);
		preforms(&ch);
		otherrb(&ch);
		attroff(COLOR_PAIR(4));


		for(int j=9; j<10; j++){
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
	return NULL;

}


void *pb (char *ch){
	
	if(*ch == 'j'){
		for(int i=0; i<100;i++){
			mvprintw(9,i," ");
		}
		mvprintw(9,7,"produced bottles (%i):    ",pr_bottles - pr_bottles);
		move(9,29);
		echo();
		getstr(produced_bottles);
		pr_bottles = atoi(produced_bottles);
		noecho();
	}
	return NULL;
}

void *bottles (char *ch){
	if(*ch == 'k'){
		for(int i=0; i<100;i++){
			mvprintw(9,i," ");
		}
		mvprintw(9,7,"rejected bottles (%i):    ",int_rb - int_rb);
		move(9,29);
		echo();
		getstr(rb);
		int_rb = atoi(rb);                                                                                               
		noecho();
	}

	return NULL;
}


void *otherrb (char *ch){

	if(*ch == 'l'){
		for(int i=0; i<100;i++){
			mvprintw(9,i," ");
		}
		mvprintw(9,7,"other rb (%i):    ",int_orb);
		move(9,27);
		echo();
		getstr(other_rb);
		int_orb = atoi(other_rb);
		noecho();
	}

	return NULL;
}


void *preforms (char *ch){
	if(*ch == 'm'){
		for(int i=0; i<100;i++){
			mvprintw(9,i," ");
		}
		mvprintw(9,7,"rejected preforms (%i):    ",int_rp);
		move(9,29);
		echo();
		getstr(rp);
		int_rp = atoi(rp);
		noecho();
	}
	return NULL;
}




