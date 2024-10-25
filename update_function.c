void updateWithoutInput() // Update function not related to input
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
}