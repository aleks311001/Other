#include "TXLib.h"

void MoveShar();
void DrovSharik (int x, int y, COLORREF color, int* Radius);
void MoveShar (int* x, int* y, double* vx, double* vy, double dt, int Radius);
void Radiusi (int* r, COLORREF uvel, COLORREF umensh);
void scorost (double* dt, COLORREF uvel, COLORREF umen);
double Dist (int x1, int y1, int x2, int y2);
void Score (double Score, int x, int y, const char* text);
void Ottalkiv (int x1, int y1, int x2, int y2, int r1, int r2, double* vx1, double* vy1, double* vx2, double* vy2);

int main()
    {
    txCreateWindow (1500, 800);

    MoveShar();
    }

void MoveShar()
    {
    int Xmal = 0, Ymal = 0;
    double VXmal = 3, VYmal = 5;
    int Xsred = 0, Ysred = 100;
    double VXsred = 4, VYsred = 4;
    int Xbol = 0, Ybol = 200;
    double VXbol = 5, VYbol = 3;
    int r1 = 5, r2 = 10, r3 = 15;

    double dt = 1;

    while (!GetAsyncKeyState(VK_ESCAPE))
        {
        if(!GetAsyncKeyState(VK_SPACE))
            {
            txSetFillColor (TX_BLACK);
            txClear ();
            }

        DrovSharik (Xmal, Ymal, RGB(random(0, 255), random(0, 255), random(0, 255)), &r1);
        MoveShar (&Xmal, &Ymal, &VXmal, &VYmal, dt, r1);

        DrovSharik (Xsred, Ysred, RGB(random(0, 255), random(0, 255), random(0, 255)), &r2);
        MoveShar (&Xsred, &Ysred, &VXsred, &VYsred, dt, r2);

        DrovSharik (Xbol, Ybol, RGB(random(0, 255), random(0, 255), random(0, 255)), &r3);
        MoveShar (&Xbol, &Ybol, &VXbol, &VYbol, dt, r3);

        Radiusi (&r1, 'Q', 'A');
        Radiusi (&r2, 'W', 'S');
        Radiusi (&r3, 'E', 'D');

        scorost (&dt, 'Z', 'X');

        Ottalkiv (Xmal, Ymal, Xsred, Ysred, r1, r2, &VXmal, &VYmal, &VXsred, &VYsred);
        Ottalkiv (Xsred, Ysred, Xbol, Ybol, r3, r2, &VXbol, &VYbol, &VXsred, &VYsred);
        Ottalkiv (Xmal, Ymal, Xbol, Ybol, r3, r1, &VXbol, &VYbol, &VXmal, &VYmal);

        Score (r1, 80, 20, "Radius1 %lg");
        Score (r2, 80, 780, "Radius2 %lg");
        Score (r3, 1420, 20, "Radius3 %lg");
        Score (dt, 1420, 780, "Speed %lg");

        txSleep (5);
        }
    }

void DrovSharik (int x, int y, COLORREF color, int* Radius)
    {
    txSetFillColor (color);
    txCircle (x, y, *Radius);
    }

void MoveShar (int* x, int* y, double* vx, double* vy, double dt, int Radius)
    {
    *x = *x + *vx * dt;
    *y = *y + *vy * dt;

    if (*x + Radius > 1500)
        {
        *vx = -*vx;
        *x = 1500 - Radius;
        }

    if (*y + Radius > 800)
        {
        *vy = -*vy;
        *y = 800 - Radius;
        }

    if (*x - Radius < 0)
        {
        *vx = -*vx;
        *x = 0 + Radius;
        }

    if (*y - Radius < 0)
        {
        *vy = -*vy;
        *y = 0 + Radius;
        }

    }

void Radiusi (int* r, COLORREF uvel, COLORREF umensh)
    {
    if (GetAsyncKeyState (uvel))
        {
        *r = *r + 5;
        }
    if (GetAsyncKeyState (umensh))
        {
        *r = *r - 2;
        }
    if (*r <= 0)
        {
        *r = 0;
        }
    }

void scorost (double* dt, COLORREF uvel, COLORREF umen)
    {
    if (GetAsyncKeyState (uvel))
        {
        *dt = *dt + 0.1;
        }
    if (GetAsyncKeyState (umen))
        {
        *dt = *dt - 0.1;
        }
    if (*dt <= 0)
        {
        *dt = 0;
        }
    }

double Dist (int x1, int y1, int x2, int y2)
    {
    return sqrt ((x2- x1)*(x2- x1) + (y2 - y1)*(y2 - y1));
    }

void Score (double Score, int x, int y, const char* text)
    {
    txSetColor (RGB(255, 215, 0));
    txSetFillColor (TX_BLACK);
    txRectangle (x - 80, y - 20, x + 80, y + 20);
    char tekst [100] = "";
    sprintf (tekst, text, Score);
    txTextOut (x - 75, y- 10, tekst);
    }

void Ottalkiv (int x1, int y1, int x2, int y2, int r1, int r2, double* vx1, double* vy1, double* vx2, double* vy2)
    {
    if (Dist (x1, y1, x2, y2) <= r1 + r2)
        {
        *vx1 = -*vx1;
        *vy1 = -*vy1;
        *vx2 = -*vx2;
        *vy2 = -*vy2;
        }
    }
