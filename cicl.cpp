#include <graphics.h>
#include <iostream>

using namespace std;

// Function to draw the eight symmetric points of the circle
void drawCirclePoints(int xc, int yc, int x, int y, int color) {
    putpixel(xc + x, yc + y, color);
    putpixel(xc - x, yc + y, color);
    putpixel(xc + x, yc - y, color);
    putpixel(xc - x, yc - y, color);
    putpixel(xc + y, yc + x, color);
    putpixel(xc - y, yc + x, color);
    putpixel(xc + y, yc - x, color);
    putpixel(xc - y, yc - x, color);
}

// Bresenham's Circle Drawing Algorithm
void drawCircle(int xc, int yc, int r, int color) {
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;

    drawCirclePoints(xc, yc, x, y, color);

    while (y >= x) {
        x++;

        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else {
            d = d + 4 * x + 6;
        }

        drawCirclePoints(xc, yc, x, y, color);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc = 250;  // Circle center x
    int yc = 250;  // Circle center y
    int r = 100;   // Radius

    drawCircle(xc, yc, r, WHITE);

    getch();      // Wait for key press
    closegraph(); // Close graphics window
    return 0;
}

