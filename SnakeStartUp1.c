void startup()
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
}