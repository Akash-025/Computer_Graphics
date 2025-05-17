#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int x = x1;
    int y = y1;

    int sx = (x2 > x1) ? 1 : -1; // step direction for x
    int sy = (y2 > y1) ? 1 : -1; // step direction for y

    bool is_steep = dy > dx;

    if (is_steep) {
        swap(dx, dy);
    }

    int p = 2 * dy - dx;

    for (int i = 0; i <= dx; i++) {
        putpixel(x, y, WHITE); // draw pixel

        if (p >= 0) {
            if (is_steep)
                x += sx;
            else
                y += sy;
            p -= 2 * dx;
        }

        if (is_steep)
            y += sy;
        else
            x += sx;

        p += 2 * dy;

        delay(10); // slow for visualization
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    setbkcolor(BLACK);
    cleardevice();

    int x1, y1, x2, y2;
    cout << "Enter starting point (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter ending point (x2 y2): ";
    cin >> x2 >> y2;

    drawLineBresenham(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

