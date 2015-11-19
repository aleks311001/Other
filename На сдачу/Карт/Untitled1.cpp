#include "TXLib.h"
struct CBall
    {
    double x, y, vx, vy, rad;
    COLORREF color;
    };
void Ogranich_Comp (CBall * b, double dt);
void MoveBall();

int main ()
    {
    txCreateWindow (1500, 800);
    MoveBall ();
    }

void MoveBall()
    {
    CBall ball [50] = {};
    CBall ball2 [50] = {};
    CBall ball3 [50] = {};
    CBall ball4 [50] = {};
    CBall ball5 [50] = {};
    CBall ball6 [50] = {};
    CBall ball7 [50] = {};
    CBall ball8 [50] = {};
    CBall ball9 [50] = {};
    CBall ball10 [50] = {};

    int i = 0;
    int dt = 1;

    HDC ris1 = txLoadImage ("vrag.bmp");
    HDC ris2 = txLoadImage ("vrag4.bmp");
    HDC ris3 = txLoadImage ("vrag4.bmp");
    HDC ris4 = txLoadImage ("vrag4.bmp");
    HDC ris5 = txLoadImage ("vrag4.bmp");
    HDC ris6 = txLoadImage ("vrag4.bmp");
    HDC ris7 = txLoadImage ("vrag.bmp");
    HDC ris8 = txLoadImage ("vrag.bmp");
    HDC ris9 = txLoadImage ("vrag.bmp");
    HDC ris10 = txLoadImage ("vrag.bmp");

    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        while (i < 100)
            {
            ball[i].x = random (20, 1480);
            ball[i].y = random (20, 780);
            ball[i].vx = 2;
            ball[i].vy = 2;
            ball[i].rad = 30;
            i++;
            }

        i = 0;

        while (i < 100)
            {
            txTransparentBlt (txDC (), ball[i].x - ball[i].rad, ball[i].y - ball[i].rad, 70, 70, ris1, 0, 0, TX_WHITE);
            i++;
            }

        i = 0;

        while (i < 100)
            {
            Ogranich_Comp (&ball[i], dt);
            i++;
            }
        //------------------------------------------------------------------------------
        while (i < 100)
            {
            ball2[i].x = random (20, 1480);
            ball2[i].y = random (20, 780);
            ball2[i].vx = 2;
            ball2[i].vy = 2;
            ball2[i].rad = 30;
            i++;
            }

        i = 0;

        while (i < 100)
            {
            txTransparentBlt (txDC (), ball2[i].x - ball2[i].rad, ball2[i].y - ball2[i].rad, 70, 70, ris2, 0, 0, TX_WHITE);
            i++;
            }

        i = 0;

        while (i < 100)
            {
            Ogranich_Comp (&ball2[i], dt);
            i++;
            }
        //------------------------------------------------------------------------------
        while (i < 100)
            {
            ball3[i].x = random (20, 1480);
            ball3[i].y = random (20, 780);
            ball3[i].vx = 2;
            ball3[i].vy = 2;
            ball3[i].rad = 30;
            i++;
            }

        i = 0;

        while (i < 100)
            {
            txTransparentBlt (txDC (), ball3[i].x - ball3[i].rad, ball3[i].y - ball3[i].rad, 70, 70, ris3, 0, 0, TX_WHITE);
            i++;
            }

        i = 0;

        while (i < 100)
            {
            Ogranich_Comp (&ball3[i], dt);
            i++;
            }
        //------------------------------------------------------------------------------
        while (i < 100)
            {
            ball4[i].x = random (20, 1480);
            ball4[i].y = random (20, 780);
            ball4[i].vx = 2;
            ball4[i].vy = 2;
            ball4[i].rad = 30;
            i++;
            }

        i = 0;

        while (i < 100)
            {
            txTransparentBlt (txDC (), ball4[i].x - ball4[i].rad, ball4[i].y - ball4[i].rad, 70, 70, ris4, 0, 0, TX_WHITE);
            i++;
            }

        i = 0;

        while (i < 100)
            {
            Ogranich_Comp (&ball4[i], dt);
            i++;
            }
        //------------------------------------------------------------------------------
        while (i < 100)
            {
            ball5[i].x = random (20, 1480);
            ball5[i].y = random (20, 780);
            ball5[i].vx = 2;
            ball5[i].vy = 2;
            ball5[i].rad = 30;
            i++;
            }

        i = 0;

        while (i < 100)
            {
            txTransparentBlt (txDC (), ball5[i].x - ball5[i].rad, ball5[i].y - ball5[i].rad, 70, 70, ris5, 0, 0, TX_WHITE);
            i++;
            }

        i = 0;

        while (i < 100)
            {
            Ogranich_Comp (&ball5[i], dt);
            i++;
            }
        //------------------------------------------------------------------------------
        while (i < 100)
            {
            ball6[i].x = random (20, 1480);
            ball6[i].y = random (20, 780);
            ball6[i].vx = 2;
            ball6[i].vy = 2;
            ball6[i].rad = 30;
            i++;
            }

        i = 0;

        while (i < 100)
            {
            txTransparentBlt (txDC (), ball6[i].x - ball6[i].rad, ball6[i].y - ball6[i].rad, 70, 70, ris6, 0, 0, TX_WHITE);
            i++;
            }

        i = 0;

        while (i < 100)
            {
            Ogranich_Comp (&ball6[i], dt);
            i++;
            }
        //------------------------------------------------------------------------------
        while (i < 100)
            {
            ball7[i].x = random (20, 1480);
            ball7[i].y = random (20, 780);
            ball7[i].vx = 2;
            ball7[i].vy = 2;
            ball7[i].rad = 30;
            i++;
            }

        i = 0;

        while (i < 100)
            {
            txTransparentBlt (txDC (), ball7[i].x - ball7[i].rad, ball7[i].y - ball7[i].rad, 70, 70, ris7, 0, 0, TX_WHITE);
            i++;
            }

        i = 0;

        while (i < 100)
            {
            Ogranich_Comp (&ball7[i], dt);
            i++;
            }
        //------------------------------------------------------------------------------
        while (i < 100)
            {
            ball8[i].x = random (20, 1480);
            ball8[i].y = random (20, 780);
            ball8[i].vx = 2;
            ball8[i].vy = 2;
            ball8[i].rad = 30;
            i++;
            }

        i = 0;

        while (i < 100)
            {
            txTransparentBlt (txDC (), ball8[i].x - ball8[i].rad, ball8[i].y - ball8[i].rad, 70, 70, ris8, 0, 0, TX_WHITE);
            i++;
            }

        i = 0;

        while (i < 100)
            {
            Ogranich_Comp (&ball8[i], dt);
            i++;
            }
        //------------------------------------------------------------------------------
        while (i < 100)
            {
            ball9[i].x = random (20, 1480);
            ball9[i].y = random (20, 780);
            ball9[i].vx = 2;
            ball9[i].vy = 2;
            ball9[i].rad = 30;
            i++;
            }

        i = 0;

        while (i < 100)
            {
            txTransparentBlt (txDC (), ball9[i].x - ball9[i].rad, ball9[i].y - ball9[i].rad, 70, 70, ris9, 0, 0, TX_WHITE);
            i++;
            }

        i = 0;

        while (i < 100)
            {
            Ogranich_Comp (&ball9[i], dt);
            i++;
            }
        //------------------------------------------------------------------------------
        while (i < 100)
            {
            ball10[i].x = random (20, 1480);
            ball10[i].y = random (20, 780);
            ball10[i].vx = 2;
            ball10[i].vy = 2;
            ball10[i].rad = 30;
            i++;
            }

        i = 0;

        while (i < 100)
            {
            txTransparentBlt (txDC (), ball10[i].x - ball10[i].rad, ball10[i].y - ball10[i].rad, 70, 70, ris10, 0, 0, TX_WHITE);
            i++;
            }

        i = 0;

        while (i < 100)
            {
            Ogranich_Comp (&ball10[i], dt);
            i++;
            }
        txSleep (10);
        }
    txDeleteDC (ris1);
    txDeleteDC (ris2);
    txDeleteDC (ris3);
    txDeleteDC (ris4);
    txDeleteDC (ris5);
    txDeleteDC (ris6);
    txDeleteDC (ris7);
    txDeleteDC (ris8);
    txDeleteDC (ris9);
    txDeleteDC (ris10);
    }

void Ogranich_Comp (CBall * b, double dt)
    {
    b->x += b->vx * dt;
    b->y += b->vy * dt;

    if (b->x - b->rad < 0)
        {
        b->x = 0 + b->rad;
        b->vx = -b->vx;
        }
    if (b->x + b->rad > 1500)
        {
        b->x = 1500 - b->rad;
        b->vx = -b->vx;
        }
    if (b->y - b->rad < 0)
        {
        b->y = 0 + b->rad;
        b->vy = -b->vy;
        }
    if (b->y + b->rad > 800)
        {
        b->y = 800 - b->rad;
        b->vy = -b->vy;
        }
    }
