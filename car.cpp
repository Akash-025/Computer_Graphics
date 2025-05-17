
#include <graphics.h>
//#include <conio.h>
//#include <dos.h>
#include<bits/stdc++.h>

void draw_road(int width, int height) {
    // Road background
    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(0, height / 2, width, height);

    // Lane line (dashed)
    setcolor(WHITE);
    int lane_y = height / 2 + height / 4;
    for (int x = 0; x < width; x += 80) {
        bar(x, lane_y, x + 40, lane_y + 5);
    }
}

void draw_car(int x, int y) {
    // Car body (red rectangle)
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    bar(x, y, x + 120, y + 40);

    // Car top (green rectangle)
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    bar(x + 20, y - 25, x + 100, y);

    // Windows (light blue)
    setcolor(LIGHTCYAN);
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    bar(x + 30, y - 20, x + 60, y - 5);
    bar(x + 65, y - 20, x + 90, y - 5);

    // Wheels (black circles)
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(x + 30, y + 40, 15, 15);
    fillellipse(x + 90, y + 40, 15, 15);

    // Hubcaps (white small circles)
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(x + 30, y + 40, 7, 7);
    fillellipse(x + 90, y + 40, 7, 7);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int width = getmaxx();
    int height = getmaxy();
    int x = -150;
    int y = height / 2 + 40;

    while (!kbhit()) {  // Loop until a key is pressed
        cleardevice(); // Clear screen

        setbkcolor(CYAN); // Sky background
        draw_road(width, height);
        draw_car(x, y);

        x += 5;
        if (x > width)
            x = -150;

        delay(50);  // Delay for animation
    }

    closegraph();
    return 0;
}
