#include "TXLib.h"

void MoveShar ();
void Prepyatstvie (int x, int y);
void text (const char * text, int x, int y, COLORREF color);
void Score (double Score, int x, int y);
void Sharik (int* x, int* y, int* vx, int* vy, double* v, double dt, int r, const char* pob, COLORREF color, COLORREF vverh, COLORREF vlevo, COLORREF vniz, COLORREF vpravo);
void upravlenie (int* vx, int* vy, double* v, COLORREF vverh, COLORREF vlevo, COLORREF vniz, COLORREF vpravo);
void ogranich (int* x, int* y, int* vx, int*vy, const char* text1, COLORREF color, int r);
void Stolknov_s_Prep (COLORREF color, const char* text1, int x, int y, int* vx, int* vy, int Xpr, int Ypr, int r);
void DrawShar (int x, int y, int Diametr, COLORREF color);
double Dist (int x1, int y1, int x2, int y2);
void ogranich_COMP (int* x, int* y, int* vx, int*vy, const char* text1, COLORREF color, int r);
void Sharik_COMP (int* x, int* y, int* vx, int* vy, double* v, double dt, int r);
void Stolknov_s_Prep_COMP (int x, int y, int* vx, int* vy, int Xpr, int Ypr);
void Radiusi (int* r, COLORREF uvel, COLORREF umensh);

int main ()
    {
    txCreateWindow (1500, 800);
    MoveShar ();
    }

void MoveShar ()
    {
    int x = 100, y = 100;
    int x1 = 1000, y1 = 700;
    int x2 = 500, y2 = 300;
    int x3 = 800, y3 = 500;

    int vx = 3, vy = 0;
    int vx1 = -3, vy1 = 0;
    int vx2 = -3, vy2 = 3;
    int vx3 = 4, vy3 = 4;

    int Xpr = 600, Ypr = 400;
    int Xpr1 = 400, Ypr1 = 600;
    int Xpr2 = 1200, Ypr2 = 450;
    int Xpr3 = 100, Ypr3 = 600;
    int Xpr4 = 300, Ypr4 = 300;

    double dt = 1;
    double v = 3;
    int r1 = 20, r2 = 20;

    while (!GetAsyncKeyState(VK_ESCAPE))
        {
        if (!GetAsyncKeyState (VK_SPACE))
            {
            txSetFillColor (TX_BLACK);
            txFloodFill (1600, 100);
            txClear ();
            }

        dt = dt + 0.001;
        Score (dt, 750, 50);

        DrawShar (x, y, r1, TX_LIGHTBLUE);
        DrawShar (x1, y1, r2, TX_LIGHTGREEN);
        DrawShar (x2, y2, r2, TX_RED);
        DrawShar (x3, y3, r1, TX_RED);

        Prepyatstvie (Xpr, Ypr);
        Prepyatstvie (Xpr1, Ypr1);
        Prepyatstvie (Xpr2, Ypr2);
        Prepyatstvie (Xpr3, Ypr3);
        Prepyatstvie (Xpr4, Ypr4);

        Stolknov_s_Prep_COMP (x2, y2, &vx2, &vy2, Xpr, Ypr);
        Stolknov_s_Prep_COMP (x2, y2, &vx2, &vy2, Xpr1, Ypr1);
        Stolknov_s_Prep_COMP (x2, y2, &vx2, &vy2, Xpr2, Ypr2);
        Stolknov_s_Prep_COMP (x2, y2, &vx2, &vy2, Xpr3, Ypr3);
        Stolknov_s_Prep_COMP (x2, y2, &vx2, &vy2, Xpr4, Ypr4);

        Stolknov_s_Prep_COMP (x3, y3, &vx3, &vy3, Xpr, Ypr);
        Stolknov_s_Prep_COMP (x3, y3, &vx3, &vy3, Xpr1, Ypr1);
        Stolknov_s_Prep_COMP (x3, y3, &vx3, &vy3, Xpr2, Ypr2);
        Stolknov_s_Prep_COMP (x3, y3, &vx3, &vy3, Xpr3, Ypr3);
        Stolknov_s_Prep_COMP (x3, y3, &vx3, &vy3, Xpr4, Ypr4);

        Stolknov_s_Prep (TX_LIGHTGREEN, "Win 1!", x, y, &vx, &vy, Xpr, Ypr, r1);
        Stolknov_s_Prep (TX_LIGHTGREEN, "Win 1!", x, y, &vx, &vy, Xpr1, Ypr1, r1);
        Stolknov_s_Prep (TX_LIGHTGREEN, "Win 1!", x, y, &vx, &vy, Xpr2, Ypr2, r1);
        Stolknov_s_Prep (TX_LIGHTGREEN, "Win 1!", x, y, &vx, &vy, Xpr3, Ypr3, r1);
        Stolknov_s_Prep (TX_LIGHTGREEN, "Win 1!", x, y, &vx, &vy, Xpr4, Ypr4, r1);

        Stolknov_s_Prep (TX_LIGHTBLUE, "Win 2!", x1, y1, &vx1, &vy1, Xpr, Ypr, r2);
        Stolknov_s_Prep (TX_LIGHTBLUE, "Win 2!", x1, y1, &vx1, &vy1, Xpr1, Ypr1, r2);
        Stolknov_s_Prep (TX_LIGHTBLUE, "Win 2!", x1, y1, &vx1, &vy1, Xpr2, Ypr2, r2);
        Stolknov_s_Prep (TX_LIGHTBLUE, "Win 2!", x1, y1, &vx1, &vy1, Xpr3, Ypr3, r2);
        Stolknov_s_Prep (TX_LIGHTBLUE, "Win 2!", x1, y1, &vx1, &vy1, Xpr4, Ypr4, r2);

        Sharik (&x, &y, &vx, &vy, &v, dt, r1, "Win 1!", TX_LIGHTGREEN, VK_UP, VK_LEFT, VK_DOWN, VK_RIGHT);
        Sharik (&x1, &y1, &vx1, &vy1, &v, dt, r2, "Win 2!", TX_LIGHTBLUE, 'W', 'A', 'S', 'D');
        Sharik_COMP (&x2, &y2, &vx2, &vy2, &v, dt, r2);
        Sharik_COMP (&x3, &y3, &vx3, &vy3, &v, dt, r1);

        Radiusi (&r1, 'O', 'P');
        Radiusi (&r2, 'R', 'T');

        if (Dist (x1, y1, x2, y2) <= r2 + r2)
            {
            txSetFillColor (TX_BLACK);
            txFloodFill (1600, 100);
            txClear ();
            text ("Win 2!", 100, 200, TX_LIGHTBLUE);
            break;
            }
        if (Dist (x1, y1, x3, y3) <= r2 + r1)
            {
            txSetFillColor (TX_BLACK);
            txFloodFill (1600, 100);
            txClear ();
            text ("Win 2!", 100, 200, TX_LIGHTBLUE);
            break;
            }
        if (Dist (x, y, x2, y2) <= r1 + r2)
            {
            txSetFillColor (TX_BLACK);
            txFloodFill (1600, 100);
            txClear ();
            text ("Win 1!", 100, 200, TX_LIGHTGREEN);
            break;
            }
        if (Dist (x, y, x3, y3) <= r1 + r1)
            {
            txSetFillColor (TX_BLACK);
            txFloodFill (1600, 100);
            txClear ();
            text ("Win 1!", 100, 200, TX_LIGHTGREEN);
            break;
            }
        if (Dist (x, y, x1, y1) <= r2 + r1)
            {
            vx = -2 * vx;
            vy = -2 * vy;
            vx1 = -2 * vx1;
            vy1 = -2 * vy1;
            }

        txSleep (5);
        }
    }

void Prepyatstvie (int x, int y)
    {
    txSetFillColor (RGB(random (0, 255), random (0, 255), random (0, 255)));
    POINT Prepyatstvie [4] = {{x - 10, y - 40}, {x + 10, y - 40}, {x + 10, y + 40}, {x - 10, y + 40}};
    txPolygon (Prepyatstvie, 4);
    }

void text (const char * text, int x, int y, COLORREF color)
    {
    txSetColor (color);
    txSelectFont ("Comic Sans MS", 300, 100, 50, false, false, false, 0);
    txTextOut (x, y, text);
    }

void Score (double Score, int x, int y)
    {
    txSetColor (RGB(255, 215, 0));
    txSetFillColor (TX_BLACK);
    txRectangle (x - 100, y - 20, x + 100, y + 20);
    char text [100] = "You have";
    sprintf (text, "You have %lg", Score);
    txTextOut (x - 75, y- 10, text);
    }

void Sharik (int* x, int* y, int* vx, int* vy, double* v, double dt, int r, const char* pob, COLORREF color, COLORREF vverh, COLORREF vlevo, COLORREF vniz, COLORREF vpravo)
    {
    *x = *x + *vx * dt;
    *y = *y + *vy * dt;

    ogranich (x, y, vx, vy, pob, color, r);

    upravlenie (vx, vy, v, vverh, vlevo, vniz, vpravo);
    }

void Sharik_COMP (int* x, int* y, int* vx, int* vy, double* v, double dt, int r)
    {
    *x = *x + *vx * dt;
    *y = *y + *vy * dt;

    ogranich_COMP  (x, y, vx, vy, "Win 2!", TX_LIGHTRED, r);
    }

void upravlenie (int* vx, int* vy, double* v, COLORREF vverh, COLORREF vlevo, COLORREF vniz, COLORREF vpravo)
    {
    if (GetAsyncKeyState(vverh))
        {
        *vx = 0;
        *vy = -*v;
        }
    if (GetAsyncKeyState(vlevo))
        {
        *vy = 0;
        *vx = -*v;
        }
    if (GetAsyncKeyState(vniz))
        {
        *vx = 0;
        *vy = *v;
        }
    if (GetAsyncKeyState(vpravo))
        {
        *vy = 0;
        *vx = *v;
        }
    }

void ogranich (int* x, int* y, int* vx, int*vy, const char* text1, COLORREF color, int r)
    {
    if (*x - r < 0)
        {
        *vy = -10000;
        *vx = -10000;
        txSetFillColor (TX_BLACK);
        txFloodFill (1600, 100);
        txClear ();
        text (text1, 100, 200, color);
        }
    if (*x + r > 1500)
        {
        *vy = 10000;
        *vx = 10000;
        txSetFillColor (TX_BLACK);
        txFloodFill (1600, 100);
        txClear ();
        text (text1, 100, 200, color);
        }
    if (*y + r > 800)
        {
        *vy = 10000;
        *vx = 10000;
        txSetFillColor (TX_BLACK);
        txFloodFill (1600, 100);
        txClear ();
        text (text1, 100, 200, color);
        }
    if (*y - r < 0)
        {
        *vy = -10000;
        *vx = -10000;
        txSetFillColor (TX_BLACK);
        txFloodFill (1600, 100);
        txClear ();
        text (text1, 100, 200, color);
        }
    }

void ogranich_COMP (int* x, int* y, int* vx, int*vy, const char* text1, COLORREF color, int r)
    {
    if (*x - r < 0)
        {
        *x = 0 + r;
        *vx = -*vx;
        }
    if (*x + r > 1500)
        {
        *x = 1500 - r;
        *vx = -*vx;
        }
    if (*y + r > 800)
        {
        *y = 800 - r;
        *vy = -*vy;
        }
    if (*y - r < 0)
        {
        *y = 0 + r;
        *vy = -*vy;
        }
    }

double Dist (int x1, int y1, int x2, int y2)
    {
    return sqrt ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }

void Stolknov_s_Prep (COLORREF color, const char* text1, int x, int y, int* vx, int* vy, int Xpr, int Ypr, int r)
    {
    if (-10 - r <= Xpr - x && Xpr - x <= 10 + r && 7 -40 - r <= Ypr - y && Ypr - y <= 40 + r)
        {
        *vx = 0;
        *vy = 0;
        txSetFillColor (TX_BLACK);
        txFloodFill (1600, 100);
        txClear ();
        text (text1, 100, 200, color);
        }
    }

void Stolknov_s_Prep_COMP (int x, int y, int* vx, int* vy, int Xpr, int Ypr)
    {
    if (-30 <= Xpr - x && Xpr - x <= 30 && -60 <= Ypr - y && Ypr - y <= 60)
        {
        *vx = -*vx;
        *vy = -*vy;
        }
    }

void DrawShar (int x, int y, int Diametr, COLORREF color)
    {
    txSetColor (color);
    txSetFillColor (color);
    txCircle (x, y, Diametr);
    }

void Radiusi (int* r, COLORREF uvel, COLORREF umensh)
    {
    if (GetAsyncKeyState (uvel))
        {
        *r = *r + 2;
        }
    if (GetAsyncKeyState (umensh))
        {
        *r = *r - 2;
        }
    if (*r <= 15)
        {
        *r = 1500000;
        }
    }
