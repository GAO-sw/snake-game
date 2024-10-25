#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#define BLOCK_SIZE 20 // Size of each block
#define HEIGHT 30 // 30 blocks in height
#define WIDTH 40 // 40 blocks in width

// Global variable definitions
int Blocks[HEIGHT][WIDTH] = { 0 }; // 2D array to record all game data
char moveDirection;  // Snake movement direction
int food_i, food_j; // Position of the food
int isFailure = 0; // Indicates if the game has failed
