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
void moveSnake() // Function to move the snake and handle related actions
{
	int i, j;
	for (i = 0; i < HEIGHT; i++) // Iterate through rows
		for (j = 0; j < WIDTH; j++) // Iterate through columns
			if (Blocks[i][j] > 0) // Values greater than 0 are snake elements
				Blocks[i][j]++; // Increment by 1
	int oldTail_i, oldTail_j, oldHead_i, oldHead_j; // Variables to store coordinates of the old tail and old head
	int max = 0; // Variable to record the maximum value
	for (i = 0; i < HEIGHT; i++) // Iterate through rows and columns
	{
		for (j = 0; j < WIDTH; j++)
		{
			if (max < Blocks[i][j]) // If the current element is greater than max
			{
				max = Blocks[i][j]; // Update max value
				oldTail_i = i; // Record coordinates of max, which is the old tail
				oldTail_j = j; // 
			}
			if (Blocks[i][j] == 2) // Find the element with a value of 2
			{
				oldHead_i = i; // Element with value 2 is the old head
				oldHead_j = j; // 
			}
		}
	}
	int newHead_i = oldHead_i; // Variable to store new head position
	int newHead_j = oldHead_j;

	// Set the new head position based on user input
	if (moveDirection == 'w') // Move up
		newHead_i = oldHead_i - 1;
	else if (moveDirection == 's') // Move down
		newHead_i = oldHead_i + 1;
	else if (moveDirection == 'a') // Move left
		newHead_j = oldHead_j - 1;
	else if (moveDirection == 'd') // Move right
		newHead_j = oldHead_j + 1;

	// If the head goes out of bounds or hits the body, the game fails
	if (newHead_i >= HEIGHT || newHead_i < 0 || newHead_j >= WIDTH || newHead_j < 0
		|| Blocks[newHead_i][newHead_j] > 0)
	{
		isFailure = 1; // Game over
		return; // Return from the function
	}

	Blocks[newHead_i][newHead_j] = 1;  // Set the new head position value to 1	
	if (newHead_i == food_i && newHead_j == food_j) // If the new head collides with food
	{
		food_i = rand() % (HEIGHT - 5) + 2; // Randomly reposition the food
		food_j = rand() % (WIDTH - 5) + 2; // 
		// No action on the old tail, effectively increasing the snake length by 1
	}
	else // New head does not collide with food
		Blocks[oldTail_i][oldTail_j] = 0; // Old tail becomes empty, maintaining snake length without eating food
}void startup()
{
    int i; //Draw a snake head in the middle of the picture, and the number is 1
    Blocks[HEIGHT/2][WIDTH/2] = 1;
    for (i = 1;i <= 4;i++)  //4 snake bodies, the values are 2, 3, 4, 5
        Blocks[HEIGHT/2][WIDTH/2-i] = i+1;
    moveDirection = 'd'; //move to the right at the beginning.
    food_i = rand()%(HEIGHT-5)+2; //Initialize random food positions
    food_j = rand()%(WIDTH-5)+2;
    initgraph(WIDTH*BLOCK_SIZE, HEIGHT*BLOCK_SIZE);
    setlinecolor(RGB(221,160,221));
    BeginBatchDraw();
}

void show()
{
    cleardevice();
    int i,j;
    for (i = 0;i < HEIGHT;i++) //Traverse all elements of a two-dimensional array
    {
        for (j = 0;j < WIDTH;j++)
        {
            if (Blocks[i][j] > 0) //Elements greater than 0 indicate a snake. Here, the snake's body color is gradually changed.
                setfillcolor(HSVtoRGB(Blocks[i][j]*10,0.9,1));
            else
                setfillcolor(RGB(150,150,150));//The element is 0, which means it is empty and the color is gray.
            fillrectangle(j*BLOCK_SIZE,i*BLOCK_SIZE,
                          (j+1)*BLOCK_SIZE,(i+1)*BLOCK_SIZE);
        }
    }
    setfillcolor(RGB(0,255,0));
    fillrectangle(food_j*BLOCK_SIZE,food_i*BLOCK_SIZE,
                  (food_j+1)*BLOCK_SIZE,(food_i+1)*BLOCK_SIZE);
    if (isFailure) // If game failure
    {
        setbkmode(TRANSPARENT);
        settextcolor(RGB(255,0,0));
        settextstyle(80,0,_T("宋体")); //Set text size and style
        outtextxy(240,220,_T("Game over"));
    }
    FlushBatchDraw();
}void updateWithoutInput() // Update function not related to input
{
	if (isFailure) // If the game fails, return from function
		return;
	static int waitIndex = 1; // Static local variable, initialized to 1
	waitIndex++; // Increment by 1 for each frame
	if (waitIndex == 10) // Execute when equal to 10, so the snake moves every 10 frames
	{
		moveSnake(); // Call snake movement function
		waitIndex = 1; // Reset to 1
	}
}

void updateWithInput()  // Update function related to input
{
	if (_kbhit() && isFailure == 0)  // If there's input and no failure
	{
		char input = _getch(); // Get input
		if (input == 'a' || input == 's' || input == 'd' || input == 'w') // Check for asdw input
		{
			moveDirection = input;  // Set movement direction
			moveSnake(); // Call snake movement function
		}
	}
}int main() // Main function
{
	startup();  // Initialize once
	while (1)   // Infinite loop
	{
		show();  // Perform drawing
		updateWithoutInput(); // Update unrelated to input
		updateWithInput();    // Update related to input
	}
	return 0;
}