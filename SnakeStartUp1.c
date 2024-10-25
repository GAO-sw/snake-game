void startup()
{
    int i;
    Blocks[HEIGHT/2][WIDTH/2] = 1;
    for (i = 1;i <= 4;i++)
        Blocks[HEIGHT/2][WIDTH/2-i] = i+1;
    moveDirection = 'd';
    food_i = rand()%(HEIGHT-5)+2;
    food_j = rand()%(WIDTH-5)+2;
    initgraph(WIDTH*BLOCK_SIZE, HEIGHT*BLOCK_SIZE);
    setlinecolor(RGB(221,160,221));
    BeginBatchDraw();
}

void show()
{
    cleardevice();
    int i,j;
    for (i = 0;i < HEIGHT;i++)
    {
        for (j = 0;j < WIDTH;j++)
        {
            if (Blocks[i][j] > 0)
                setfillcolor(HSVtoRGB(Blocks[i][j]*10,0.9,1));
            else
                setfillcolor(RGB(150,150,150));
            fillrectangle(j*BLOCK_SIZE,i*BLOCK_SIZE,
                          (j+1)*BLOCK_SIZE,(i+1)*BLOCK_SIZE);
        }
    }
    setfillcolor(RGB(0,255,0));
    fillrectangle(food_j*BLOCK_SIZE,food_i*BLOCK_SIZE,
                  (food_j+1)*BLOCK_SIZE,(food_i+1)*BLOCK_SIZE);
    if (isFailure)
    {
        setbkmode(TRANSPARENT);
        settextcolor(RGB(255,0,0));
        settextstyle(80,0,_T("宋体"));
        outtextxy(240,220,_T("Game over"));
    }
    FlushBatchDraw();
}