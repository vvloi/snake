#define _CRT_SECURE_NO_WARNINGS
#include "frontend.h"
#include "backend.h"
#include "stats.h"
#include "types.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define LOGO_HEIGHT 5
#define LOGO_LENGTH 35
#define MAX_LENGTH 100
#define MIN_COLS 80
#define MIN_ROWS 25

#define WINDOW_SIZE_MSG1 "Minimum window size: " STR(MIN_COLS) " cols and " STR(MIN_ROWS) " rows."
#define WINDOW_SIZE_MSG2 "Please resize the console window and restart the game."
#define STR(X) STR2(X)
#define STR2(X) #X

int enable_vt_mode(void);
int min_window_size(void);
void draw_borders(void);
void draw_horizontal_border(Border, int);
void draw_vertical_border(Border, int);

void set_up_console()
{
    if (!enable_vt_mode() || !min_window_size())
        exit(EXIT_FAILURE);

    draw_borders();
    display_stats();
}

// enable ANSI escape sequences
int enable_vt_mode(void)
{
    DWORD mode;

    HANDLE hstdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hstdOut == INVALID_HANDLE_VALUE)
    {
        printf("Error getting output handle.");
        return 0;
    }
    if (!GetConsoleMode(hstdOut, &mode))
    {
        printf("Error getting console mode.");
        return 0;
    }

    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hstdOut, mode))
    {
        printf("Error setting console mode.");
        return 0;
    }

    return 1;
}

// check minimum window size
int min_window_size(void)
{
    Window window = get_window_size();

    if (window.cols < MIN_COLS || window.rows < MIN_ROWS)
    {
        enable_alt_screen();
        clear_screen();
        clear_scrollback();
        hide_cursor();

        // warn if the size of the console window is too small
        move_cursor(window.cols /2 - (int) strlen(WINDOW_SIZE_MSG1) /2, window.rows /2);
        printf("%s\n", WINDOW_SIZE_MSG1);
        move_cursor(window.cols /2 - (int) strlen(WINDOW_SIZE_MSG2) /2, window.rows /2 + 1);
        printf("%s", WINDOW_SIZE_MSG2);
        Sleep(5000);

        disable_alt_screen();
        clear_screen();
        clear_scrollback();
        show_cursor();

        return 0;
    }
    return 1;
}

// create rectangular borders
void draw_borders(void)
{     
    clear_screen();
    clear_scrollback();

    Border border = get_border_coordinates();

    // top border
    move_cursor(border.left, border.top);
    draw_horizontal_border(border, 1);

    // bottom border
    move_cursor(border.left, border.bottom);
    draw_horizontal_border(border, 0);

    // left border
    move_cursor(border.left, border.top + 1);
    draw_vertical_border(border, 1);

    // right border
    move_cursor(border.right, border.top + 1);
    draw_vertical_border(border, 0);
}

void draw_horizontal_border(Border border, int isTop)
{
    enable_line_drawing_mode();
    set_color(WHITE);

    // draw corners
    putchar(isTop ? TOP_LEFT_CORNER : BOTTOM_LEFT_CORNER);

    // draw horizontal lines
    for (int i = 0; i < border.right - 2; i++)
        printf("%c", HORIZONTAL_BAR);

    putchar(isTop ? TOP_RIGHT_CORNER : BOTTOM_RIGHT_CORNER);

    reset_color();
    disable_line_drawing_mode();
}

void draw_vertical_border(Border border, int isLeft)
{
    enable_line_drawing_mode();
    set_color(WHITE);

    // draw vertical lines
    for (int i = 0; i < border.bottom - TOP_BORDER_OFFSET - 2; i++)
    {
        save_cursor_position();
        printf("%c", VERTICAL_BAR);
        restore_cursor_position();
        move_cursor_down(1);
    }

    reset_color();
    disable_line_drawing_mode();
}

// get the size of the console window
Window get_window_size(void)
{
    Window window;
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    HANDLE hstdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hstdOut == INVALID_HANDLE_VALUE)
        printf("Error getting output handle.");

    if (!GetConsoleScreenBufferInfo(hstdOut, &csbi))
        printf("Error getting console screen buffer info.");

    window.cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    window.rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    return window;
}

// get coordinates of the borders
Border get_border_coordinates(void)
{
    Border border;

    Window window = get_window_size();

    /* If the number of columns is odd,
    adjust position of the vertical border */
    int adjustCols = window.cols % 2 == 0 ? 0 : 1;

    border.left = 1;
    border.right = window.cols - adjustCols;
    border.top = 1 + TOP_BORDER_OFFSET;
    border.bottom = window.rows;

    return border;
}
