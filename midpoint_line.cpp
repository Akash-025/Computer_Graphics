#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <cmath>
using namespace std;

void drawLineMidPoint(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int x = x1;
    int y = y1;

    int dxAbs = abs(dx);
    int dyAbs = abs(dy);

    int twoDy = 2 * dyAbs;
    int twoDyMinusDx = 2 * (dyAbs - dxAbs);

    int p = 2 * dyAbs - dxAbs;

    // Determine which direction to step
    int xStep = (dx >= 0) ? 1 : -1;
    int yStep = (dy >= 0) ? 1 : -1;

    if (dxAbs > dyAbs) {
        // x is the independent variable
        for (int i = 0; i <= dxAbs; i++) {
            putpixel(x, y, WHITE);
            x += xStep;
            if (p < 0) {
                p += twoDy;
            } else {
                y += yStep;
                p += twoDyMinusDx;
            }
            delay(5);
        }
    } else {
        // y is the independent variable (steep slope)
        p = 2 * dxAbs - dyAbs;
        int twoDx = 2 * dxAbs;
        int twoDxMinusDy = 2 * (dxAbs - dyAbs);
        for (int i = 0; i <= dyAbs; i++) {
            putpixel(x, y, WHITE);
            y += yStep;
            if (p < 0) {
                p += twoDx;
            } else {
                x += xStep;
                p += twoDxMinusDy;
            }
            delay(5);
        }
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

    drawLineMidPoint(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

