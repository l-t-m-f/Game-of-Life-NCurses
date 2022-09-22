#include "logic.h"

static int count_neighbors(int y, int x);
static void do_live_cell(int y, int x, int neighbors);
static void do_dead_cell(int y, int x, int neighbors);

void init_board(void)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            app.board.cells[i][j] = rand() % 2;
        }
    }
    memset(app.board.futures, 0, ((m * n) * sizeof(int)));
}

void do_cells(void)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int count = count_neighbors(i, j);
            if(app.board.cells[i][j] == LIVE)
            {
                do_live_cell(i, j, count);
            }
            else
            {
                do_dead_cell(i, j, count);
            }
        }
    }
}

void apply_futures(void)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            app.board.cells[i][j] = app.board.futures[i][j];
        }
    }
    memset(app.board.futures, 0, ((m *n) * sizeof(int)));
}

static int count_neighbors(int y, int x)
{
    int count = 0;
    for(int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if(app.board.cells[y + i][x + j] == LIVE && !(i == 0 && j == 0))
            {
                count++;
            }
        }
    }
    return count;
}

static void do_live_cell(int y, int x, int neighbors)
{
    switch(neighbors)
    {
        case 0: case 1:
            app.board.futures[y][x] = DEAD;
            break;
        case 2: case 3:
            app.board.futures[y][x] = LIVE;
            break;
        default:
            app.board.futures[y][x] = DEAD;
            break;
    }
}

static void do_dead_cell(int y, int x, int neighbors)
{
    switch(neighbors)
    {
        case 3:
            app.board.futures[y][x] = LIVE;
            break;
        default:
            break;
    }
}