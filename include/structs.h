typedef struct _board
{
    int cells[m * n][m * n];
    int futures[m * n][m * n];
} Board;

typedef struct _app
{
    Board board;
    WINDOW *window;
} App;