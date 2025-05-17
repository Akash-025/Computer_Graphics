
#include <graphics.h>
#include <conio.h>
#include <math.h>

void drawSquare(int x, int y, int size, int color, const char* label) {
    setcolor(color);
    rectangle(x, y, x + size, y + size);
    outtextxy(x, y + size + 10, (char*)label);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Original square (top-left)
    int x = 100, y = 100;
    int size = 50;
    drawSquare(x, y, size, WHITE, "Original");

    // Translated square (top-right)
    int tx = 300;
    int ty = 0;
    drawSquare(x + tx, y + ty, size, GREEN, "Translated");

    // Scaled square (middle-left)
    float sx = 2.0, sy = 2.0;
    int scaledX = 100;
    int scaledY = 250;
    drawSquare(scaledX, scaledY, size * sx, CYAN, "Scaled");

    // Rotated square (middle-right)
    float angle = 45.0 * M_PI / 180.0;
    int rx = 400, ry = 250; // rotation center
    int x1 = rx, y1 = ry;
    int x2 = rx + size * cos(angle), y2 = ry + size * sin(angle);
    int x3 = x2 - size * sin(angle), y3 = y2 + size * cos(angle);
    int x4 = x1 - size * sin(angle), y4 = y1 + size * cos(angle);
    setcolor(YELLOW);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x1, y1);
    outtextxy(x1, y1 + 60, (char*)"Rotated");

    // Reflected square (bottom-left)
    int refY = 400;
    drawSquare(x, refY - y, size, MAGENTA, "Reflected");

    // Sheared square (bottom-right, X-shear)
    float shx = 1.0;
    int shearX = 350, shearY = 400;
    int sx1 = shearX + shx * 0;
    int sy1 = shearY + 0;
    int sx2 = shearX + shx * size;
    int sy2 = shearY + 0;
    int sx3 = shearX + size + shx * size;
    int sy3 = shearY + size;
    int sx4 = shearX + shx * 0 + size;
    int sy4 = shearY + size;
    setcolor(RED);
    line(sx1, sy1, sx2, sy2);
    line(sx2, sy2, sx3, sy3);
    line(sx3, sy3, sx4, sy4);
    line(sx4, sy4, sx1, sy1);
    outtextxy(sx1, sy3 + 10, (char*)"Sheared");

    getch();
    closegraph();
    return 0;
}
