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
float casse;


// filling machine
char prH1 [50];
int int_rpH1;

char casse_in[50];
int int_casse_in;

char filling_level[50];
int int_filling_level;

char wasted_caps[50];
int int_wasted_caps;

char casse_bt[50];
int int_casse_bt;

int cumul_casse1;

char casse2[50];
int int_casse2 ;

int cumulcasse2 = 02;
int filling_cumul ;
float filling_casse; 


void *bottles2 (char *ch);
void *casse_iner_filling (char *ch);
void *bottle_filling_level (char *ch);
void *missed_caps (char *ch);
void *casse_betwen_machines (char *ch);
void *lab_casse (char *ch);

int main () {

	initscr();
	curs_set(0);   //0 hide the blinking cursor
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
	init_pair(5, 94, 0);   // 37 light blue 


	// napms(3000);

	//noecho();

	
	while(true){

		attron(COLOR_PAIR(3));

		mvprintw(0,1," _____________________________________________________");
		mvprintw(1,1,"/ bbbbbb ll    oooooo ww             ww eeeeee rrrrrr /");
		mvprintw(2,1,"/ bb  bb ll    oo  oo  ww           ww  ee     rr  rr /");
		mvprintw(3,1,"/ bbbbbb ll    oo  oo   ww   ww    ww   eeeeee rrrrrr /");
		mvprintw(4,1,"/ bb  bb ll    oo  oo    ww ww ww ww    ee     rr rr  /");
		mvprintw(5,1,"/ bbbbbb lllll oooooo     ww    ww      eeeeee rr  rr /");
		mvprintw(6,1,"/_____________________________________________________/");

		attroff(COLOR_PAIR(3));

		
		attron(COLOR_PAIR(2));
		mvprintw(20,9,"keys");
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(2)); 
		mvprintw(21,2,"j -> produced bottles"),
		mvprintw(22,2,"k -> rejected bottles"),
		mvprintw(23,2,"l -> other rb"),
		mvprintw(24,2,"m -> rejected preforms"),
		attroff(COLOR_PAIR(2));  



		attron(COLOR_PAIR(5));         // Enable color pair 1	
		mvprintw(12,2,"produced bottles : %i",pr_bottles);
		mvprintw(13,2,"rejected bottles : %i",int_rb);
		mvprintw(14,2,"other rb         : %i",int_orb);
		mvprintw(15,2,"rejected preforms: %i",int_rp);
		bl_counter = pr_bottles + int_rb + int_orb + int_rp;
		mvprintw(16,2,"blower counter   : %i",bl_counter);
		casse = (int_rb + int_orb + int_rp )  / (float)pr_bottles * 100;
		mvprintw(17,2,"casse            : %.2f %% ",casse);
		attroff(COLOR_PAIR(5));        // Disable color pair 1


		char ch = getch();

		// filler part
		if(ch == 'c'){
			echo();
			attron(COLOR_PAIR(3));
			mvprintw(8,5," _____________________");
			mvprintw(9,5,"/ choose mode:       /");     
			mvprintw(10,5,"/____________________/");
			move(9,20);
			getstr(choose_mode);
			attroff(COLOR_PAIR(3));
			clear();
			attron(COLOR_PAIR(3));
			mvprintw(0,1," _____________________________________");
			mvprintw(1,1,"/ fffff iii ll    ll    eeeee rrrrrr / ");
			mvprintw(2,1,"/ ff    iii ll    ll    ee    rr  rr /");
			mvprintw(3,1,"/ fffff iii ll    ll    eeeee rrrrrr /");
			mvprintw(4,1,"/ ff    iii ll    ll    ee    rr rr  /");
			mvprintw(5,1,"/ ff    iii lllll lllll eeeee rr  rr /");
			mvprintw(6,1,"/____________________________________/");

			
			attroff(COLOR_PAIR(3));
			while(true){

				if(strcmp(choose_mode,"filler")==0){
			/*		echo();
					for(int i=0;i<100000;i++ ){
						mvprintw(7,4,"|/_");
						mvprintw(7,4,"    ");
						mvprintw(7,4,"|/_");
						refresh();
					}*/

					noecho();
				
					attron(COLOR_PAIR(5));         // Enable color pair 1	
					mvprintw(12,2,"produced bottles        (j): %i",int_rpH1);
					mvprintw(13,2,"e.filler                   : %i ",int_rpH1);
					mvprintw(14,2,"casse inside filler     (n): %i",int_casse_in);
					mvprintw(15,2,"bottles filling level   (v): %i",int_filling_level);
					mvprintw(16,2,"bootles without caps    (b): %i",int_wasted_caps);
					mvprintw(17,2,"casse between machines  (h): %i",int_casse_bt);
					cumul_casse1= int_casse_in + int_filling_level + int_wasted_caps + int_casse_bt;
					mvprintw(18,2,"cumul 1                    : %i",cumul_casse1);

					mvprintw(19,2,"casse2                     : %i",cumulcasse2);
					mvprintw(20,2,"cumul casse2            (f): %i",int_casse2);
					filling_cumul = int_rpH1 - (cumul_casse1 + cumulcasse2 + int_casse2);
					mvprintw(21,2,"E.filler(cumul)            : %i",filling_cumul);

					filling_casse = ( (cumul_casse1 + int_casse2 + cumulcasse2) / (float)int_rpH1) *100 ;

					mvprintw(22,2,"casse                      : %.2f %%",filling_casse);
					attroff(COLOR_PAIR(5));        // Disable color pair 1


					ch = getch();
					curs_set(1); 
					attron(COLOR_PAIR(4));
					bottles2(&ch);
					casse_iner_filling(&ch);
					bottle_filling_level(&ch);
					missed_caps(&ch);
					casse_betwen_machines (&ch);
					lab_casse (&ch);
					attroff(COLOR_PAIR(4));
					curs_set(0); 
					refresh();
					if( ch == 'c'){
						
						echo();
						attron(COLOR_PAIR(3));
						mvprintw(8,5," _____________________");
						mvprintw(9,5,"/ choose mode:       /");     
						mvprintw(10,5,"/____________________/");
						move(9,20);
						getstr(choose_mode);
						attroff(COLOR_PAIR(3));

						if(strcmp(choose_mode,"blower")==0){
							clear();
							break;
						}
						clear();
						break;
					}
					
				}	
			}
		}
		
		noecho();
		curs_set(1);  // 1 show the blinking cursor
		attron(COLOR_PAIR(4));
		if(ch == 'q'){
			endwin();
			return 0;
		}
		
		mode(&ch);
		pb(&ch);
		bottles(&ch);
		preforms(&ch);
		otherrb(&ch);
		attroff(COLOR_PAIR(4));
		curs_set(0);

		for(int j=9; j<20; j++){
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
		mvprintw(9,5,"produced bottles(%i):    ",pr_bottles - pr_bottles);
		mvprintw(10,9,"//");
		move(10,12);
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
		mvprintw(9,5,"rejected bottles(%i):    ",int_rb - int_rb);
		mvprintw(10,9,"//");
		move(10,12);
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
		mvprintw(9,5,"other rb(%i):    ",int_orb);
		mvprintw(10,9,"//");
		move(10,12);
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
		mvprintw(9,5,"rejected preforms(%i):    ",int_rp);
		mvprintw(10,9,"//");
		move(10,12);
		echo();
		getstr(rp);
		int_rp = atoi(rp);
		noecho();
	}
	return NULL;
}


//filling
 
/*char prH1 [50];
char casse_in[50];
char filling_level;
char wasted_caps[50];
char cass_bt[50];
int cumul_casse1;
char casse2;
int cumulcasse2;
int filling_cumul;
int casse;
*/

/*
// filling machine
char prH1 [50];
int int_rpH1;

char casse_in[50];
int int_casse_in;

char filling_level[50];
int int_filling_level;

char wasted_caps[50];
int int_wasted_caps;

char casse_bt[50];
int int_casse_bt;

int cumul_casse1;

char casse2[50];
int int_casse2;

int cumulcasse2;
int filling_cumul;
int filling_casse;

*/
void *bottles2 (char *ch){
	if(*ch == 'j'){

		mvprintw(9,5,"produced bottles: ");
		mvprintw(10,7,"//");
		move(10,10);
		echo();
		getstr(prH1);
		int_rpH1 = atoi(prH1);
		noecho();
		for(int i=9; i<=10;i++){
			for(int j=5; j<30;j++){
				mvprintw(i,j," ");
			}
			printw("\n");
		}
	}


	return NULL;
}

void *casse_iner_filling (char *ch){
	if(*ch == 'n'){

		mvprintw(9,5,"casse inside filler: ");
		mvprintw(10,7,"//");
		move(10,10);
		echo();
		getstr(casse_in);
		int_casse_in = atoi(casse_in);
		noecho();
		for(int i=9; i<=10;i++){
			for(int j=5; j<30;j++){
				mvprintw(i,j," ");
			}
			printw("\n");
		}
	}

	return NULL;
}


void *bottle_filling_level (char *ch){
	if(*ch == 'b'){
	
		mvprintw(9,5,"filling level: ");
		mvprintw(10,7,"//");
		move(10,10);
		echo();
		getstr(filling_level);
		int_filling_level = atoi(filling_level);
		noecho();
		for(int i=9; i<=10;i++){
			for(int j=5; j<30;j++){
				mvprintw(i,j," ");
			}
			printw("\n");
		}
	}

	return NULL;
}

void *missed_caps (char *ch){
	if(*ch == 'v'){

		mvprintw(9,5,"bottles wihout caps: ");
		mvprintw(10,7,"//");
		move(10,10);
		echo();
		getstr(wasted_caps);
		int_wasted_caps= atoi(wasted_caps);
		noecho();
		for(int i=9; i<=10;i++){
			for(int j=5; j<30;j++){
				mvprintw(i,j," ");
			}
			printw("\n");
		}
	}

	return NULL;
}

void *casse_betwen_machines (char *ch){
	if(*ch == 'h'){
		 
		mvprintw(9,5,"casse between machines: ");
		mvprintw(10,7,"//");
		move(10,10);
		echo();
		getstr(casse_bt);
		int_casse_bt = atoi(casse_bt);
		noecho();
		for(int i=9; i<=10;i++){
			for(int j=5; j<30;j++){
				mvprintw(i,j," ");
			}

			printw("\n");
		}
	}

	return NULL;
}

	
void *lab_casse (char *ch){
	if(*ch == 'f'){
		 
		mvprintw(9,5,"lab casse: ");
		mvprintw(10,7,"//");
		move(10,10);
		echo();
		getstr(casse2);
		int_casse2 = atoi(casse2);
		noecho();
		for(int i=9; i<=10;i++){
			for(int j=5; j<30;j++){
				mvprintw(i,j," ");
			}
			printw("\n");
		}
	}

	return NULL;
}

