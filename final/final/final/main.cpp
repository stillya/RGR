#include <curses.h>
#include <unistd.h>

int main(void) {
    initscr();
    WINDOW* win = newwin(10, 40, 5, 10);
    wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);
    curs_set(0);
    int start_x = 4;
    int start_y = 4;
    int shaftlength = 20;

    mvwaddch(win, start_x, start_y, (char)56);
    for (int j = 1; j < shaftlength; j++) {
        mvwaddch(win, start_y, start_x + j, (char)61);
        wrefresh(win);
    }
    mvwaddch(win, start_y, start_x + shaftlength, (char)68);
    wrefresh(win);

    for (int k = 0; k < 5; k++)
    {
        for (int j = start_x + 3; j < (start_x + shaftlength - 3); j++)
        {
            mvwaddch(win, start_y, j - 1, (char)61);
            mvwaddch(win, start_y, j, (char)111);
            wrefresh(win);
            usleep(200000 - (k * 30000));
        }
        for (int j = (start_x + shaftlength - 3); j > start_x + 3; j--)
        {
            mvwaddch(win, start_y, j + 1, (char)61);
            mvwaddch(win, start_y, j, (char)111);
            wrefresh(win);
            usleep(200000 - (k * 30000));
        }
    }
    for (int k = 0; k < 3; k++) {
        mvwaddch(win, start_y + k, start_x + shaftlength + 1 + k, (char)92);
        mvwaddch(win, start_y - k, start_x + shaftlength + 1 + k, (char)47);
        mvwaddch(win, start_y, start_x + shaftlength + 2 + k, (char)45);
    }
    wmove(win, 0, 0);
    wrefresh(win);
    usleep(5000000);
    endwin();
    return 0;
}