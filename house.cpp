#include <graphics.h>
#include <conio.h>

void drawPentagonHouse() {
    // Draw pentagon shape (5-angle house)
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, LIGHTMAGENTA);

    // Points of pentagon: roof peak, left roof, left base, right base, right roof
    int house[] = {300, 120, 200, 200, 200, 350, 400, 350, 400, 200, 300, 120};
    drawpoly(6, house);  // 5 points + repeat first
    floodfill(300, 200, WHITE);

    // Roof (top triangle)
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    line(200, 200, 300, 120);
    line(400, 200, 300, 120);
    line(200, 200, 400, 200);
    floodfill(300, 150, RED);

    // Door - 2 panels (পাল্লা)
    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);
    rectangle(270, 270, 300, 350); // Left panel
    floodfill(271, 271, BROWN);
    rectangle(300, 270, 330, 350); // Right panel
    floodfill(301, 271, BROWN);

    // Door handles
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(295, 310, 3, 3); // Left
    fillellipse(305, 310, 3, 3); // Right

    // Left Window
    setcolor(WHITE);
    rectangle(220, 230, 250, 260);
    setfillstyle(SOLID_FILL, CYAN);
    floodfill(221, 231, WHITE);

    // Right Window
    rectangle(350, 230, 380, 260);
    floodfill(351, 231, WHITE);

    // Staircase (সিঁড়ি)
    setcolor(LIGHTGRAY);
    for (int i = 0; i < 3; i++) {
        rectangle(270 - i * 10, 350 + i * 10, 330 + i * 10, 360 + i * 10);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    setbkcolor(CYAN); // Sky background
    cleardevice();

    drawPentagonHouse();

    getch();
    closegraph();
    return 0;
}
