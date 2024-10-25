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
}