/*
 * lab1a.c
 *
 *  Created on:
 *      Author:
 */

/* include helper functions for game */
#include "lifegame.h"

/* add whatever other includes here */

/* number of generations to evolve the world */
#define NUM_GENERATIONS 50

/* functions to implement */

/* this function should set the state of all
   the cells in the next generation and call
   finalize_evolution() to update the current
   state of the world to the next generation */
void next_generation(void);

/* this function should return the state of the cell
   at (x,y) in the next generation, according to the
   rules of Conway's Game of Life (see handout) */
int get_next_state(int x, int y);

/* this function should calculate the number of alive
   neighbors of the cell at (x,y) */
int num_neighbors(int x, int y);

int main(void)
{
	int n;

	/* TODO: initialize the world */
	initialize_world();

	for (n = 0; n < NUM_GENERATIONS; n++)
		next_generation();

	/* TODO: output final world state */
	output_world();

	return 0;
}

void next_generation(void) {
	/* TODO: for every cell, set the state in the next
	   generation according to the Game of Life rules
	   Hint: use get_next_state(x,y) */
	int x, y;
	extern WORLDWIDTH, WORLDHEIGHT;

	for (x = 0; x < WORLDWIDTH; x++) {
		for (y = 0; y < WORLDHEIGHT; y++) {
			if(get_next_state(x, y) == 1){

			}
		}
	}


	finalize_evolution(); /* called at end to finalize */
}

int get_next_state(int x, int y) {
	/* TODO: for the specified cell, compute the state in
	   the next generation using the rules

	   Use num_neighbors(x,y) to compute the number of live
	   neighbors */
	//extern ALIVE, DEAD;

	if(get_cell_state(x, y) == ALIVE){
		if(num_neighbors(x, y) == 2){
			return ALIVE;
		}
	}
	else if(num_neighbors(x, y) == 3){
		return ALIVE;
	}
	else{
		return DEAD;
	}
}

int num_neighbors(int x, int y) {
	/* TODO: for the specified cell, return the number of
	   neighbors that are ALIVE
	   Use get_cell_state(x,y) */
	//int x, y;
	//extern WORLDWIDTH, WORLDHEIGHT;
	int num;
	int m, n;

	//for (x = 0; x < WORLDWIDTH; x++) {
		//for (y = 0; y < WORLDHEIGHT; y++) {
			for(m=-1; m <= 1; m++){
				for(n=-1; n <= 1; n++){
					if(get_cell_state((x+n), (y+m)) == ALIVE){
						num += 1;
					}
				}
			}
		//}
	//}
	if(get_cell_state(x, y) == ALIVE){
		num -= 1;
	}
	return num;
}
