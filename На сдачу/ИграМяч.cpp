#include "TXLib.h"

struct CBall
    {
    double x, y;
    double vx, vy;
    double rad;
    COLORREF color;
    double v;
    };

void Snaryad (CBall* b, CBall b2, double dt);
void next_level ();
void Move_shariki (int dt2);
void Drow_Shar (CBall b);
void Dvig_Shar_Comp (CBall* b, double* dt);
void Drow_Text (double x, double y, const char* text);
void Ogranich_Igrok (CBall* b, double* dt);
void Upravlenie (CBall* b);
//void Igrok (double* x, double* y, double* vx, double* vy, double* dt, double rad);
double Dist (double x1, double y1, double x2, double y2);
void Drow_Score (double x, double y, double score, const char* text2);
void Razmer (CBall * b);
void stolknov_comp (CBall* b, CBall* b2);

int main ()
    {
    txCreateWindow (1500, 800);
    Move_shariki (20);
//    if (Drow_Text = "Game Over!") break;
    }

void Move_shariki (int dt2)
    {
    CBall b_C1 = {50, 50, 4, 3, 43, TX_RED};

    CBall b_C2 = {300, 300, -3, -4, 43, TX_RED};

    CBall b_C3 = {500, 500, -3, 4, 43, TX_RED};

    CBall b_C4 = {1000, 700, 3, -4, 43, TX_RED};

    CBall b_Cnar1 = {b_C1.x, b_C1.y, 3, 3, 10};

    CBall b_Cnar2 = {b_C2.x, b_C2.y, 3, 3, 10};

    CBall b_Cnar3 = {b_C3.x, b_C3.y, 3, 3, 10};

    CBall b_Cnar4 = {b_C4.x, b_C4.y, 3, 3, 10};

    CBall b_Cnar_Bol1 = {b_C2.x, b_C1.y, 3, 3, 22};

    CBall b_Cnar_Bol2 = {b_C3.x, b_C4.y, 3, 3, 22};

    CBall b_Cnar_Bol_Bol1 = {b_Cnar_Bol1.x, b_Cnar_Bol2.y, 3, 3, 44};

    //CBall b_Cnar_Bol_Bol2 = {b_Cnar_Bol_Bol1.x, b_Cnar_Bol_Bol1.y, 3, 3, 66};

    CBall b_igr = {750, 400, 20, 20, 27, TX_WHITE, 5};

    double t = 0;

    double dt = 1;

    HDC fon = txLoadImage ("cosmos-119.bmp");
    HDC igrok = txLoadImage ("igrok4.bmp");
    HDC vrag = txLoadImage ("Vrag1.bmp");
    HDC snarayd = txLoadImage ("Снаряд3.bmp");
    HDC snarayd2 = txLoadImage ("Снаряд3.2.bmp");
    HDC snarayd3 = txLoadImage ("Снаряд3.3.bmp");

    while (!GetAsyncKeyState(VK_ESCAPE))
        {
        if (!GetAsyncKeyState (VK_SPACE))
            {
            txClear ();
            }

        txBitBlt (txDC(), 0, 0, 1500, 800, fon, 0, 0);

        Drow_Score (750, 20, t, "У тебя %lg очков");

        Snaryad (&b_Cnar1, b_igr, dt);
        Snaryad (&b_Cnar2, b_igr, dt);
        Snaryad (&b_Cnar3, b_igr, dt);
        Snaryad (&b_Cnar4, b_igr, dt);
        Snaryad (&b_Cnar_Bol1, b_igr, dt);
        Snaryad (&b_Cnar_Bol2, b_igr, dt);
        Snaryad (&b_Cnar_Bol_Bol1, b_igr, dt);
       // Drow_Shar (b_C1);
        Dvig_Shar_Comp (&b_C1, &dt);

       // Drow_Shar (b_C2);
        Dvig_Shar_Comp (&b_C2, &dt);

       // Drow_Shar (b_C3);
        Dvig_Shar_Comp (&b_C3, &dt);

       // Drow_Shar (b_C4);
        Dvig_Shar_Comp (&b_C4, &dt);

 //       Igrok (&x_igr, &y_igr, &vx_igr, &vy_igr, &dt, rad);

        if (Dist (b_Cnar1.x, b_Cnar1.y, b_igr.x, b_igr.y) <= b_Cnar1.rad + b_igr.rad ||
            Dist (b_Cnar2.x, b_Cnar2.y, b_igr.x, b_igr.y) <= b_Cnar2.rad + b_igr.rad ||
            Dist (b_Cnar3.x, b_Cnar3.y, b_igr.x, b_igr.y) <= b_Cnar3.rad + b_igr.rad ||
            Dist (b_Cnar4.x, b_Cnar4.y, b_igr.x, b_igr.y) <= b_Cnar4.rad + b_igr.rad ||
            Dist (b_Cnar_Bol1.x, b_Cnar_Bol1.y, b_igr.x, b_igr.y) <= b_Cnar_Bol1.rad + b_igr.rad ||
            Dist (b_Cnar_Bol2.x, b_Cnar_Bol2.y, b_igr.x, b_igr.y) <= b_Cnar_Bol2.rad + b_igr.rad )
            {
            Drow_Text (200, 350, "Ты сгорел!");
            break;
            }

        if (Dist (b_C1.x, b_C1.y, b_igr.x, b_igr.y) <= b_C1.rad + b_igr.rad ||
            Dist (b_C2.x, b_C2.y, b_igr.x, b_igr.y) <= b_C2.rad + b_igr.rad ||
            Dist (b_C3.x, b_C3.y, b_igr.x, b_igr.y) <= b_C3.rad + b_igr.rad ||
            Dist (b_C4.x, b_C4.y, b_igr.x, b_igr.y) <= b_C4.rad + b_igr.rad)               //
            {
            Drow_Text (200, 350, "Ты съеден!");
            break;
            }


            if (Dist (b_Cnar_Bol1.x, b_Cnar_Bol1.y, b_Cnar_Bol2.x, b_Cnar_Bol2.y) <= b_Cnar_Bol1.rad + b_Cnar_Bol2.rad)
                {
                txTransparentBlt (txDC(), b_Cnar_Bol1.x - b_Cnar_Bol1.rad, b_Cnar_Bol1.y - b_Cnar_Bol1.rad, 88, 88, snarayd3, 0, 0, TX_WHITE);
                }                                                                                                 //dddd
            else
                {
                if (Dist (b_Cnar1.x, b_Cnar1.y, b_Cnar2.x, b_Cnar2.y) <= b_Cnar1.rad + b_Cnar2.rad)
                    {
                    txTransparentBlt (txDC(), b_Cnar_Bol1.x - b_Cnar_Bol1.rad, b_Cnar_Bol1.y - b_Cnar_Bol1.rad, 41, 49, snarayd2, 0, 0, TX_WHITE);
                    }
                else
                    {
                    txTransparentBlt (txDC(), b_Cnar1.x - b_Cnar1.rad, b_Cnar1.y - b_Cnar1.rad, 19, 20, snarayd, 0, 0, TX_WHITE);
                    txTransparentBlt (txDC(), b_Cnar2.x - b_Cnar2.rad, b_Cnar2.y - b_Cnar2.rad, 19, 20, snarayd, 0, 0, TX_WHITE);
                    }
                if (Dist (b_Cnar3.x, b_Cnar3.y, b_Cnar4.x, b_Cnar4.y) <= b_Cnar3.rad + b_Cnar4.rad)
                    {
                    txTransparentBlt (txDC(), b_Cnar_Bol2.x - b_Cnar_Bol2.rad, b_Cnar_Bol2.y - b_Cnar_Bol2.rad, 41, 49, snarayd2, 0, 0, TX_WHITE);
                    }
                else
                    {
                    txTransparentBlt (txDC(), b_Cnar3.x - b_Cnar3.rad, b_Cnar3.y - b_Cnar3.rad, 19, 20, snarayd, 0, 0, TX_WHITE);
                    txTransparentBlt (txDC(), b_Cnar4.x - b_Cnar4.rad, b_Cnar4.y - b_Cnar4.rad, 19, 20, snarayd, 0, 0, TX_WHITE);
                    }
                }
           // }
                                                                //ddddddddd
        stolknov_comp (&b_C1, &b_C2);
        stolknov_comp (&b_C1, &b_C3);
        stolknov_comp (&b_C1, &b_C4);
        stolknov_comp (&b_C2, &b_C3);
        stolknov_comp (&b_C2, &b_C4);          //aaaaaaaa
        stolknov_comp (&b_C3, &b_C4);

        if (b_igr.x + b_igr.rad > 1500 || b_igr.x - b_igr.rad < 0 || b_igr.y + b_igr.rad > 800 || b_igr.y - b_igr.rad < 0)
            {
            Drow_Text (200, 350, "Ты упал!");
            break;
            }
        else
            {
            txTransparentBlt (txDC(), b_igr.x - b_igr.rad, b_igr.y - b_igr.rad, 53, 54, igrok, 0, 0, TX_WHITE);
            //Drow_Shar (b_igr);
            Upravlenie (&b_igr);
            Ogranich_Igrok (&b_igr, &dt);
            }
        txTransparentBlt (txDC(), b_C1.x - b_C1.rad, b_C1.y - b_C1.rad, 86, 96, vrag, 0, 0, TX_WHITE);
        txTransparentBlt (txDC(), b_C2.x - b_C2.rad, b_C2.y - b_C2.rad, 86, 96, vrag, 0, 0, TX_WHITE);
        txTransparentBlt (txDC(), b_C3.x - b_C3.rad, b_C3.y - b_C3.rad, 86, 96, vrag, 0, 0, TX_WHITE);
        txTransparentBlt (txDC(), b_C4.x - b_C4.rad, b_C4.y - b_C4.rad, 86, 96, vrag, 0, 0, TX_WHITE);

        t += 0.005;//wwwwwww

        if (t > dt2)
            {
            break;
            }

        txSetFillColor (TX_BLACK);
        txSleep (5);
        }

    txDeleteDC (fon);
    txDeleteDC (igrok);
    txDeleteDC (vrag);
    txDeleteDC (snarayd);
    txDeleteDC (snarayd2);
    txDeleteDC (snarayd3);
    }

void Drow_Shar (CBall b)
    {
    txSetFillColor (b.color);
    txCircle (b.x, b.y, b.rad);
    }

void Dvig_Shar_Comp (CBall* b, double* dt)
    {
    b->x += b->vx * *dt;
    b->y += b->vy * *dt;
    //*dt += 0.001;

    if (b->x + b->rad > 1500)
        {
        b->x = 1500 - b->rad;
        b->vx = -b->vx;
        }
    if (b->x - b->rad < 0)
        {
        b->x = 0 + b->rad;
        b->vx = -b->vx;
        }
    if (b->y + b->rad > 800)
        {
        b->y = 800 - b->rad;
        b->vy = -b->vy;
        }
    if (b->y - b->rad < 0)
        {
        b->y = 0 + b->rad;
        b->vy = -b->vy;
        }
    }

void Ogranich_Igrok (CBall* b, double* dt)
    {
    b->x += b->vx * *dt;
    b->y += b->vy * *dt;
    //*dt = *dt + 0.001;

    if (b->x + b->rad > 1500||
        b->x - b->rad < 0   ||
        b->y + b->rad > 800 ||
        b->y - b->rad < 0)
        {
        Drow_Text (200, 200, "Game Over!");
        b->vy = 0;
        b->vx = 0;
        }
    }

void Drow_Text (double x, double y, const char* text)
    {
    txSelectFont ("Arial", 75, 35, 10, false, false, false, 0);
    txTextOut (x, y, text);
    }

void Drow_Score (double x, double y, double score, const char* text2)
    {
    //txRectangle (x - 125, y - 20, x + 125, y + 20);
    char text1 [50] = "";
    sprintf (text1, text2, score);
    txTextOut (x - 100, y, text1);
    }

void Upravlenie (CBall* b)
    {
    if (!GetAsyncKeyState (VK_RIGHT && VK_LEFT && VK_DOWN && VK_UP))
        {
        b->vx = 0;
        b->vy = 0;
        }
    if (GetAsyncKeyState (VK_RIGHT))
        {
        b->vx = b->v;
        }
    if (GetAsyncKeyState (VK_LEFT))
        {
        b->vx = -b->v;
        }
    if (GetAsyncKeyState (VK_DOWN))
        {
        b->vy = b->v;
        }
    if (GetAsyncKeyState (VK_UP))
        {
        b->vy = -b->v;
        }
    }

/*void Igrok (double* x, double* y, double* vx, double* vy, double* dt, double rad)
    {
    if (*x + rad > 1500 || *x - rad < 0 || *y + rad > 800 || *y - rad < 0)
        {
        Drow_Text (200, 200, "Game Over!");
        *vx = 0;
        *vy = 0;
        }
    else
        {
        Drow_Shar (*x, *y, rad, TX_LIGHTGREEN);
        Upravlenie (*&vx, *&vy);
        Ogranich_Igrok (*&x, *&y, *&vx, *&vy, *&dt, rad);
        }
    }*/

double Dist (double x1, double y1, double x2, double y2)
    {
    return sqrt ((x2- x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }

void stolknov_comp (CBall* b, CBall* b2)
    {
    if (Dist (b->x, b->y, b2->x, b2->y) <= b->rad + b2->rad)
        {
        b->vx = -b->vx;
        b->vy = -b->vy;
        b2->vx = -b2->vx;
        b2->vy = -b2->vy;//
        }
    }

void Snaryad (CBall* b, CBall b2, double dt)
    {
    b->vx = ((b2.x - b->x)/60 + 0.1);
    b->vy = ((b2.y - b->y)/60 + 0.1);
    b->x += b->vx * dt;
    b->y += b->vy * dt;
    }
