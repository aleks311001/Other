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
void Stena (CBall* b);
void All_Vrag(CBall Ball[], HDC vrag, int dt, int sz);
void Snaryad_polnost (CBall* sn1, CBall* sn2, CBall* sn3, CBall* sn4, CBall* snbig1, CBall* snbig2, CBall* snBIGG, HDC snaryad1, HDC snaryad2, HDC snaryad3, const CBall Ball[], int dt);

int main ()
    {
    txCreateWindow (1500, 800);
    MoveShar ();
    }

void MoveShar ()
    {
    CBall Ball [6] = {{750, 400, 0, 0, 25, 3}};

    CBall sn1 = {0,    0,   5, 5, 8};
    CBall sn2 = {1500, 0,   5, 5, 8};
    CBall sn3 = {1500, 800, 5, 5, 8};
    CBall sn4 = {0,    800, 5, 5, 8};

    CBall snbig1 = {sn1.x, sn2.y, 5, 5, 16};
    CBall snbig2 = {sn3.x, sn4.y, 5, 5, 16};

    CBall snBIGG = {snbig1.x, snbig2.y, 5, 5, 32};

    double t = 0;
    double dt = 1;

    int N = 6;
    int i = 1;

    HDC vrag = txLoadImage ("vrag.bmp");
    HDC igrok = txLoadImage ("igrok.bmp");
    HDC fon = txLoadImage ("fon1.bmp");
    HDC snaryad1 = txLoadImage ("снаряд20.bmp");
    HDC snaryad2 = txLoadImage ("снаряд40.bmp");
    HDC snaryad3 = txLoadImage ("снаряд80.bmp");

    while (!GetAsyncKeyState(VK_ESCAPE))
        {
        txSetFillColor (TX_BLACK);
        txClear ();

        txBitBlt (txDC (), 0, 0, 1500, 800, fon, 0, 0);

        txTransparentBlt (txDC (), Ball[0].x - Ball[0].rad, Ball[0].y - Ball[0].rad, 50, 50, igrok, 0, 0, TX_WHITE);
        Upravlenie (&Ball[0], dt);

        //----------------Mass------------------
        while (i < N)
            {
            Ball[i].x = random (20, 1480);
            Ball[i].y = random (20, 780);
            Ball[i].vx = random (1.5, 3.5);
            Ball[i].vy = random (1.5, 3.5);
            Ball[i].rad = 30;
            i++;
            }

        All_Vrag (Ball, vrag, dt, N);

        i = 1;

        while (i < N)
        {
            if (Dist (Ball[i], Ball[0]) <= Ball[i].rad + Ball[0].rad)
                {
                txMessageBox ("Вы съедены!!!", "Поражение", 0);
                break;
                }
            i++;
        }

        //--------------Chit------------------------
        if (GetAsyncKeyState ('L'))
        {
        Stena (&Ball[0]);
        }
        else
            {
            if (Ball[0].x + Ball[0].rad > 1500 ||
                Ball[0].x - Ball[0].rad < 0    ||
                Ball[0].y + Ball[0].rad > 800  ||
                Ball[0].y - Ball[0].rad < 0    )
                {
                txMessageBox ("Вы задохнулись!!!", "Поражение", 0);
                break;
                }
            }

        //-----------Snaryadi-----------------------
        Snaryad_polnost (&sn1, &sn2, &sn3, &sn4, &snbig1, &snbig2, &snBIGG, snaryad1, snaryad2, snaryad3, &Ball[0], dt);

        if (Dist (sn1, Ball[0]) <= sn1.rad + Ball[0].rad ||
            Dist (sn2, Ball[0]) <= sn2.rad + Ball[0].rad ||
            Dist (sn3, Ball[0]) <= sn3.rad + Ball[0].rad ||
            Dist (sn4, Ball[0]) <= sn4.rad + Ball[0].rad ||
            Dist (snbig1, Ball[0]) <= snbig1.rad + Ball[0].rad ||
            Dist (snbig2, Ball[0]) <= snbig2.rad + Ball[0].rad ||
            Dist (snBIGG, Ball[0]) <= snBIGG.rad + Ball[0].rad )
                {
                txMessageBox ("Вы сгорели!!!", "Поражение", 0);
                break;
                }

        //-------------Pobeda------------
        t += 0.005;
        Score (t, 750, 20);

        if (t > 20)
            {
            txMessageBox ("Победа!!!", "Победа", 0);
            break;
            }
        //-------------------------------
        txSleep (0);
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
    txSelectFont ("Comic Sans MS", 150, 50, 50, false, false, false, 0);
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
    sn->vx = ((b.x - sn->x)/40 + 0.1);
    sn->vy = ((b.y - sn->y)/40 + 0.1);
    sn->x += sn->vx * dt;
    sn->y += sn->vy * dt;
    }

void Score (double Score, int x, int y)
    {
    char tekst [100] = "You have";
    sprintf (tekst, "You have %lg", Score);
    txTextOut (x - 75, y- 10, tekst);
    }

void Stena (CBall* b)
    {
    if (b->x + b->rad > 1500)
        {
        b->x = 0 + b->rad;
        }
    if (b->x - b->rad < 0)
        {
        b->x = 1500 - b->rad;
        }
    if (b->y + b->rad > 800)
        {
        b->y = 0 + b->rad;
        }
    if (b->y - b->rad < 0)
        {
        b->y = 800 - b->rad;
        }
    }

void All_Vrag(CBall Ball[], HDC vrag, int dt, int sz)
    {
    int i = 1;

    while (i < sz)
        {
        txTransparentBlt (txDC (), Ball[i].x - Ball[i].rad, Ball[i].y - Ball[i].rad, 68, 74, vrag, 0, 0, TX_WHITE);
        i++;
        }

    i = 1;

    while (i < sz)
        {
        Ogranich_Comp (&Ball[i], dt);
        i++;
        }
    }
void Snaryad_polnost (CBall* sn1, CBall* sn2, CBall* sn3, CBall* sn4, CBall* snbig1, CBall* snbig2, CBall* snBIGG, HDC snaryad1, HDC snaryad2, HDC snaryad3, const CBall Ball[], int dt)
    {
    snaryadi (*&sn1, Ball[0], dt);
    snaryadi (*&sn2, Ball[0], dt);
    snaryadi (*&sn3, Ball[0], dt);
    snaryadi (*&sn4, Ball[0], dt);
    snaryadi (*&snbig1, Ball[0], dt);
    snaryadi (*&snbig2, Ball[0], dt);
    snaryadi (*&snBIGG, Ball[0], dt);

    if (Dist (*snbig1, *snbig2) <= snbig1->rad + snbig2->rad)
        {
        txTransparentBlt (txDC(), snBIGG->x - snBIGG->rad, snBIGG->y - snBIGG->rad, 80, 80, snaryad3, 0, 0);
        }                                                                                                 //dddd
    else
        {
        if (Dist (*sn1, *sn2) <= sn1->rad + sn2->rad)
            {
            txTransparentBlt (txDC(), snbig1->x - snbig1->rad, snbig1->y - snbig1->rad, 40, 40, snaryad2, 0, 0);
            }
        else
            {
            txTransparentBlt (txDC(), sn1->x - sn1->rad, sn1->y - sn1->rad, 19, 20, snaryad1, 0, 0);
            txTransparentBlt (txDC(), sn2->x - sn2->rad, sn2->y - sn2->rad, 19, 20, snaryad1, 0, 0);
            }
        if (Dist (*sn3, *sn4) <= sn3->rad + sn4->rad)
            {
            txTransparentBlt (txDC(), snbig2->x - snbig2->rad, snbig2->y - snbig2->rad, 40, 40, snaryad2, 0, 0);
            }
        else
            {
            txTransparentBlt (txDC(), sn3->x - sn3->rad, sn3->y - sn3->rad, 19, 20, snaryad1, 0, 0);
            txTransparentBlt (txDC(), sn4->x - sn4->rad, sn4->y - sn4->rad, 19, 20, snaryad1, 0, 0);
            }
        }
    }
