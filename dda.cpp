
#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

// DDA line drawing function with bold line (3x3 pixels)
void drawLineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = max(abs(dx), abs(dy));

    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        int px = round(x);
        int py = round(y);

        // Draw 3x3 pixels block around (px, py) for thickness
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                putpixel(px + dx, py + dy, RED);
            }
        }

        x += xIncrement;
        y += yIncrement;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw a bold red line parallel to X-axis
    int x1 = 100, y1 = 200;
    int x2 = 300, y2 = 200;

    drawLineDDA(x1, y1, x2, y2);

    getch();    // Wait for a key press
    closegraph(); // Close graphics mode

    return 0;
}
