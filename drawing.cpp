#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Set background and drawing color
    setbkcolor(BLACK);
    cleardevice();
    setcolor(WHITE);

    // Draw Triangle using lines
    line(100, 100, 150, 50);   // top-left to top point
    line(150, 50, 200, 100);   // top point to top-right
    line(100, 100, 200, 100);  // base of triangle

    // Draw Square using rectangle (equal sides)
    rectangle(250, 50, 300, 100);  // top-left (x1, y1), bottom-right (x2, y2)

    // Draw Rectangle (wider than tall)
    rectangle(350, 50, 450, 100);  // top-left (x1, y1), bottom-right (x2, y2)

    getch();
    closegraph();
    return 0;
}

