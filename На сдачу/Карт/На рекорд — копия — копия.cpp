#include "TXLib.h"
struct CBall
    {
    double x, y;
    double vx, vy;
    double rad, v;
    COLORREF color;
    };
void MoveShar ();
void Upravlenie (CBall * b, double dt);
void Ogranich_Comp (CBall * b, double dt);
double Dist (CBall b1, CBall b2);
void text (const char * text);
void Stolknovenie (CBall* b1, CBall* b2);
void snaryadi (CBall* sn, CBall b, double dt);
void Score (double Score, int x, int y);

int main ()
    {
    txCreateWindow (1500, 800);
    MoveShar ();
    }

void MoveShar ()
    {
    CBall b_vrag1 = {100, 200, 4, 3, 35};
    CBall b_vrag2 = {1400, 600, 3, 3, 35};
    CBall b_vrag3 = {300, 400, 4, 4, 35};
    CBall b_vrag4 = {600, 500, 3, 4, 35};

    CBall b_igr = {750, 400, 5, 5, 25, 5};

    CBall sn1 = {b_vrag1.x, b_vrag1.y, 5, 5, 8};
    CBall sn2 = {b_vrag2.x, b_vrag2.y, 5, 5, 8};
    CBall sn3 = {b_vrag3.x, b_vrag3.y, 5, 5, 8};
    CBall sn4 = {b_vrag4.x, b_vrag4.y, 5, 5, 8};

    CBall snbig1 = {sn1.x, sn2.y, 5, 5, 16};
    CBall snbig2 = {b_vrag3.x, b_vrag4.y, 5, 5, 16};

    CBall snBIGG = {snbig1.x, snbig2.y, 5, 5, 32};

    double t = 0;
    double dt = 1;

    HDC vrag = txLoadImage ("vrag.bmp");
    HDC igrok = txLoadImage ("igrok.bmp");
    HDC fon = txLoadImage ("fon.bmp");
    HDC snaryad1 = txLoadImage ("снаряд20.bmp");
    HDC snaryad2 = txLoadImage ("снаряд40.bmp");
    HDC snaryad3 = txLoadImage ("снаряд80.bmp");

    while (!GetAsyncKeyState(VK_ESCAPE))
        {
        txSetFillColor (TX_BLACK);
        txClear ();

        txBitBlt (txDC (), 0, 0, 1500, 800, fon, 0, 0);

        txTransparentBlt (txDC (), b_igr.x - b_igr.rad, b_igr.y - b_igr.rad, 50, 50, igrok, 0, 0, TX_WHITE);
        Upravlenie (&b_igr, dt);

        txTransparentBlt (txDC (), b_vrag1.x - b_vrag1.rad, b_vrag1.y - b_vrag1.rad, 68, 74, vrag, 0, 0, TX_WHITE);
        txTransparentBlt (txDC (), b_vrag2.x - b_vrag2.rad, b_vrag2.y - b_vrag2.rad, 68, 74, vrag, 0, 0, TX_WHITE);
        txTransparentBlt (txDC (), b_vrag3.x - b_vrag3.rad, b_vrag3.y - b_vrag3.rad, 68, 74, vrag, 0, 0, TX_WHITE);
        txTransparentBlt (txDC (), b_vrag4.x - b_vrag4.rad, b_vrag4.y - b_vrag4.rad, 68, 74, vrag, 0, 0, TX_WHITE);
        Ogranich_Comp (&b_vrag1, dt);
        Ogranich_Comp (&b_vrag2, dt);
        Ogranich_Comp (&b_vrag3, dt);
        Ogranich_Comp (&b_vrag4, dt);

        if (Dist (b_vrag1, b_igr) < b_vrag1.rad + b_igr.rad ||
            Dist (b_vrag2, b_igr) < b_vrag2.rad + b_igr.rad ||
            Dist (b_vrag3, b_igr) < b_vrag3.rad + b_igr.rad ||
            Dist (b_vrag4, b_igr) < b_vrag4.rad + b_igr.rad )
            {
            text ("Вы съедены");
            break;
            }

        if (b_igr.x + b_igr.rad > 1500 ||
            b_igr.x - b_igr.rad < 0    ||
            b_igr.y + b_igr.rad > 800  ||
            b_igr.y - b_igr.rad < 0    )
            {
            text ("Буль-буль");
            break;
            }
        Stolknovenie (&b_vrag1, &b_vrag2);
        Stolknovenie (&b_vrag1, &b_vrag3);
        Stolknovenie (&b_vrag1, &b_vrag4);
        Stolknovenie (&b_vrag2, &b_vrag3);
        Stolknovenie (&b_vrag2, &b_vrag4);
        Stolknovenie (&b_vrag3, &b_vrag4);

        if (Dist (snbig1, snbig2) <= snbig1.rad + snbig2.rad)
            {
            txTransparentBlt (txDC (), snBIGG.x - snBIGG.rad, snBIGG.y - snBIGG.rad, 80, 80, snaryad3, 0, 0);
            snaryadi (&snBIGG, b_igr, dt);
            if (Dist (snBIGG, b_igr) <= snBIGG.rad + b_igr.rad )
                {
                text ("Вы сгорели");
                break;
                }
            }
        else
            {
            if (Dist (sn1, sn2) <= sn1.rad + sn2.rad)
                {
                txTransparentBlt (txDC (), snbig1.x - snbig1.rad, snbig1.y - snbig1.rad, 40, 40, snaryad2, 0, 0);
                snaryadi (&snbig1, b_igr, dt);
                if (Dist (snbig1, b_igr) <= snbig1.rad + b_igr.rad )
                    {
                    text ("Вы сгорели");
                    break;
                    }
                }
            else
                {
                txTransparentBlt (txDC (), sn1.x - sn1.rad, sn1.y - sn1.rad, 20, 20, snaryad1, 0, 0);
                txTransparentBlt (txDC (), sn2.x - sn2.rad, sn2.y - sn2.rad, 20, 20, snaryad1, 0, 0);
                snaryadi (&sn1, b_igr, dt);
                snaryadi (&sn2, b_igr, dt);
                if (Dist (sn1, b_igr) <= sn1.rad + b_igr.rad ||
                    Dist (sn2, b_igr) <= sn2.rad + b_igr.rad )
                    {
                    text ("Вы сгорели");
                    break;
                    }
                }
            if (Dist (sn3, sn4) <= sn3.rad + sn4.rad)
                {
                txTransparentBlt (txDC (), snbig2.x - snbig2.rad, snbig2.y - snbig2.rad, 40, 40, snaryad2, 0, 0);
                snaryadi (&snbig2, b_igr, dt);
                if (Dist (snbig2, b_igr) <= snbig2.rad + b_igr.rad )
                    {
                    text ("Вы сгорели");
                    break;
                    }
                }
            else
                {
            txTransparentBlt (txDC (), sn3.x - sn3.rad, sn3.y - sn3.rad, 20, 20, snaryad1, 0, 0);
            txTransparentBlt (txDC (), sn4.x - sn4.rad, sn4.y - sn4.rad, 20, 20, snaryad1, 0, 0);
            snaryadi (&sn3, b_igr, dt);
            snaryadi (&sn4, b_igr, dt);
            if (Dist (sn3, b_igr) < sn3.rad + b_igr.rad ||
                Dist (sn4, b_igr) < sn4.rad + b_igr.rad )
                    {
                    text ("Вы сгорели");
                    break;
                    }
                }
            }

        t += 0.005;
        Score (t, 750, 20);

        if (t >= 20)
            {
            text ("Вы победили!!!");
            }
        txSleep (5);
        }
    txDeleteDC (vrag);
    txDeleteDC (igrok);
    txDeleteDC (fon);
    txDeleteDC (snaryad1);
    txDeleteDC (snaryad2);
    txDeleteDC (snaryad3);
    }

void Upravlenie (CBall * b, double dt)
    {
    b->x += b->vx * dt;
    b->y += b->vy * dt;
    if (!GetAsyncKeyState (VK_UP && VK_DOWN && VK_LEFT && VK_RIGHT))
        {
        b->vx = 0;
        b->vy = 0;
        }
    if (GetAsyncKeyState (VK_UP))
        {
        b->vy = -b->v;
        }
    if (GetAsyncKeyState (VK_DOWN))
        {
        b->vy = b->v;
        }
    if (GetAsyncKeyState (VK_LEFT))
        {
        b->vx = -b->v;
        }
    if (GetAsyncKeyState (VK_RIGHT))
        {
        b->vx = b->v;
        }
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

double Dist (CBall b1, CBall b2)
    {
    return sqrt ((b1.x - b2.x) * (b1.x - b2.x) + (b1.y - b2.y) * (b1.y - b2.y));
    }

void text (const char * text)
    {
    txSelectFont ("Comic Sans MS", 300, 100, 50, false, false, false, 0);
    txTextOut (100, 300, text);
    }

void Stolknovenie (CBall* b1, CBall* b2)
    {
    if (Dist (*b1, *b2) < b1->rad + b2->rad)
        {
        b1->vx = -b1->vx;
        b1->vy = -b1->vy;
        b2->vx = -b2->vx;
        b2->vy = -b2->vy;
        }
    }

void snaryadi (CBall* sn, CBall b, double dt)
    {
    sn->vx = ((b.x - sn->x)/20 + 0.1);
    sn->vy = ((b.y - sn->y)/20 + 0.1);
    sn->x += sn->vx * dt;
    sn->y += sn->vy * dt;
    }

void Score (double Score, int x, int y)
    {
    char text [100] = "You have";
    sprintf (text, "You have %lg", Score);
    txTextOut (x - 75, y- 10, text);
    }
