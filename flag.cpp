
#include <graphics.h>
#include <math.h>
#include <dos.h>

#define PI 3.1416

// Draw the flag with waving effect
void drawFlag(int baseX, int baseY, int width, int height, int time) {
    int waveHeight = 10;       // Amplitude of wave
    int waveLength = 40;       // Wavelength

    // Draw green waving rectangle (flag)
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);

    for (int y = 0; y < height; y++) {
        int xOffset = waveHeight * sin((y + time) * 2 * PI / waveLength);
        bar(baseX + xOffset, baseY + y, baseX + width + xOffset, baseY + y + 1);
    }

    // Draw red circle (sun) in the middle of the flag
    int centerY = baseY + height / 2;
    int centerX = baseX + width / 2 + waveHeight * sin((height / 2 + time) * 2 * PI / waveLength);
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    fillellipse(centerX, centerY, 30, 30);  // Circle radius 30
}

// Draw the flag pole
void drawPole(int baseX, int baseY, int height) {
    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);
    bar(baseX - 5, baseY, baseX + 5, baseY + height);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int flagX = 150;
    int flagY = 100;
    int flagWidth = 200;
    int flagHeight = 100;
    int poleHeight = 300;

    int time = 0;

    while (!kbhit()) {  // Loop until a key is pressed
        cleardevice();

        setbkcolor(CYAN);  // Sky background

        drawPole(flagX, flagY, poleHeight);
        drawFlag(flagX + 10, flagY, flagWidth, flagHeight, time);

        time += 1;
        delay(30);
    }

    closegraph();
    return 0;
}
