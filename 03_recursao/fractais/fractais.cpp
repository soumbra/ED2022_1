#define XPAINT
#include "tk.h"

void draw_line(int size) {
    if (size < 6) {
        return;
    }
    x_pen_walk(size);
    x_pen_rotate(-100);
    draw_line(size - 8);
}

int main() {
    x_open(720, 480, "img");
    x_pen_set_thick(3);
    x_pen_set_angle(90);
    x_pen_set_pos(185, 450);
    draw_line(410);
    x_save();
    x_close();
}