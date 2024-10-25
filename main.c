int main() // Main function
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