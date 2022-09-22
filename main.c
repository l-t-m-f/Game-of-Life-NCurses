#include "main.h"

static bool main_init(void);

int main(int argc, char ** argv)
{
    
    if (!main_init())
    {
        exit(EXIT_FAILURE);
    }

    init_board();
    draw_board();

    Sleep(500);

    while(1)
    {         
        do_cells();
        Sleep(10);
        apply_futures();
        refresh();
        Sleep(500);    
        draw_board(); 
    }

    endwin();

    return 0;
}

static bool main_init(void)
{
    app.window = initscr();
    if (!app.window)
    {
        printf("Error! Something went wrong while initializing the screen.\n");
        return false;
    }
    else
    {
        cbreak();
        raw();
        noecho();
        curs_set(0);
        srand((unsigned int)time(NULL));
        return true;
    }    
}
