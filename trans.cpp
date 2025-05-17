#include <graphics.h>
#include <conio.h>
#include <math.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color, const char* label) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x1, y1 + 15, (char*)label);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // --- Original Triangle (Top-Left) ---
    int x1 = 100, y1 = 100;
    int x2 = 150, y2 = 50;
    int x3 = 200, y3 = 100;
    drawTriangle(x1, y1, x2, y2, x3, y3, WHITE, "Original");

    // --- Translated Triangle (Top-Right) ---
    int tx = 300; // X offset
    drawTriangle(x1 + tx, y1, x2 + tx, y2, x3 + tx, y3, GREEN, "Translated");

    // --- Scaled Triangle (Middle-Left) ---
    float sx = 1.5, sy = 1.5;
    int baseX = 100, baseY = 250;
    int sx1 = baseX;
    int sy1 = baseY;
    int sx2 = baseX + (x2 - x1) * sx;
    int sy2 = baseY + (y2 - y1) * sy;
    int sx3 = baseX + (x3 - x1) * sx;
    int sy3 = baseY + (y3 - y1) * sy;
    drawTriangle(sx1, sy1, sx2, sy2, sx3, sy3, CYAN, "Scaled");

    // --- Rotated Triangle (Middle-Right) ---
    float angle = 45.0 * M_PI / 180.0;
    baseX = 400; baseY = 250;
    int rx1 = baseX;
    int ry1 = baseY;
    int rx2 = baseX + (x2 - x1) * cos(angle) - (y2 - y1) * sin(angle);
    int ry2 = baseY + (x2 - x1) * sin(angle) + (y2 - y1) * cos(angle);
    int rx3 = baseX + (x3 - x1) * cos(angle) - (y3 - y1) * sin(angle);
    int ry3 = baseY + (x3 - x1) * sin(angle) + (y3 - y1) * cos(angle);
    drawTriangle(rx1, ry1, rx2, ry2, rx3, ry3, YELLOW, "Rotated");

    // --- Reflected Triangle (Bottom-Left) ---
    int baseYRef = 400;
    drawTriangle(x1, baseYRef + (y1 - y1), x2, baseYRef + (y1 - y2), x3, baseYRef + (y1 - y3), MAGENTA, "Reflected");

    // --- Sheared Triangle (Bottom-Right) ---
    float shx = 0.5;
    baseX = 300; baseY = 400;
    int sh1x = baseX + shx * y1;
    int sh2x = baseX + (x2 - x1) + shx * y2;
    int sh3x = baseX + (x3 - x1) + shx * y3;
    drawTriangle(sh1x, baseY + y1, sh2x, baseY + y2, sh3x, baseY + y3, RED, "Sheared");

    getch();
    closegraph();
    return 0;
}
