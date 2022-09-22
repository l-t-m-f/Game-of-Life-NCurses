#include "draw.h"

void draw_board(void)
{
    for(int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(app.board.cells[i][j])
            {
                mvprintw(i, j, "o");
            }
            else
            {
                mvprintw(i, j, ".");
            }
        }
    }
}