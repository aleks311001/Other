#include "TXLib.h"

struct CBall
    {
    double x  = 0, y  = 0, z  = 0;
    double vx = 0, vy = 0, vz = 0;
    double dt, rad;
    };

double XWindow = GetSystemMetrics (SM_CXSCREEN), YWindow = GetSystemMetrics (SM_CYSCREEN);
double xGlob = 0, yGlob = 0, zGlob = -70;
double ZoomX = 500, ZoomY = 500, ZoomZ = 5;
double A = 0, B = 0, C = 0;

void Line3D (double x1, double y1, double z1, double x2, double y2, double z2);
void Circle3D    (double x1, double y1, double z1, double r);
void Translete3D ();
void Skale3D ();
void Rotate ();
void Dvig (CBall *Ball, double x, double y, double z);
void Mass1 (CBall Mol[], int sz);

int main()
    {
     _txWindowStyle &= ~ WS_CAPTION;

    txCreateWindow (XWindow, YWindow);

    int sz = 15;

    CBall  Ball [15] = {};

    Mass1 (Ball, sz);
    //double x = 0, y = 0, z = 0;
    //double vx = 0.06, vy = 0.04, vz = 0.02, dt = 1;
    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        txSetFillColor (TX_WHITE);
        txBegin();
        txClear ();

        txSetColor (TX_BLUE, 5);
        Line3D ( 1,  1,  1, -1,  1,  1);
        Line3D (-1,  1, -1,  1,  1, -1);
        Line3D (-1,  1, -1, -1,  1,  1);
        Line3D ( 1,  1,  1,  1,  1, -1);

        txSetColor (TX_BROWN, 5);
        Line3D (-1, -1,  1, -1, -1, -1);
        Line3D ( 1, -1,  1, -1, -1,  1);
        Line3D ( 1, -1, -1,  1, -1,  1);
        Line3D ( 1, -1, -1, -1, -1, -1);

        txSetColor (TX_GREEN, 5);
        Line3D (-1,  1,  1, -1, -1,  1);
        Line3D (-1,  1, -1, -1, -1, -1);
        Line3D ( 1,  1, -1,  1, -1, -1);
        Line3D ( 1,  1,  1,  1, -1,  1);

        printf ("%lf, %lf,\n",ZoomZ, zGlob);

        /*txSetColor (TX_ORANGE, 5);
        Line3D (0, 3, 0,  1, 1, -1);
        Line3D (0, 3, 0, -1, 1,  1);
        Line3D (0, 3, 0, -1, 1, -1);
        Line3D (0, 3, 0,  1, 1,  1);*/
        /*
        for (int K = 0; K < sz; K++)
            {
            Dvig (&Ball [K], 1, 1, 1);
            txSetColor (RGB(random (50, 250), random (50, 250), random (50, 250))
            , 5);
            txSetFillColor (RGB(random (50, 250), random (50, 250), random (50, 250)));
            Circle3D (Ball[K].x, Ball[K].y, Ball[K].z, Ball[K].rad);
            }
        */
        /*Line3D (0, 0, 0, 10, 0, 0);
        Line3D (0, 0, 0, 0, 10, 0);
        Line3D (0, 0, 0, 0, 0, 10);*/

        Skale3D ();
        Translete3D ();
        Rotate ();
        txEnd ();
        }
    return 0;
    }

void Dvig (CBall *Ball, double x, double y, double z)
    {
    Ball->x += Ball->vx * Ball->dt;
    Ball->y += Ball->vy * Ball->dt;
    Ball->z += Ball->vz * Ball->dt;
    if (Ball->x > x)
        {
        Ball->vx = - Ball->vx;
        Ball->x = x;
        }
    if (Ball->x < -x)
        {
        Ball->vx = - Ball->vx;
        Ball->x = -x;
        }
    if (Ball->y > y)
        {
        Ball->vy = - Ball->vy;
        Ball->y = y;
        }
    if (Ball->y < -y)
        {
        Ball->vy = - Ball->vy;
        Ball->y = -y;
        }
    if (Ball->z > z)
        {
        Ball->vz = - Ball->vz;
        Ball->z = z;
        }
    if (Ball->z < -z)
        {
        Ball->vz = - Ball->vz;
        Ball->z = -z;
        }
    }

void Skale3D ()
    {
    if (GetAsyncKeyState ('F')) ZoomX-=0.5;
    if (GetAsyncKeyState ('H')) ZoomX+=0.5;
    if (GetAsyncKeyState ('T')) ZoomY+=0.5;
    if (GetAsyncKeyState ('G')) ZoomY-=0.5;
    if (GetAsyncKeyState ('V')) ZoomZ-=0.05;
    if (GetAsyncKeyState ('B')) ZoomZ+=0.05;
    }

void Translete3D ()
    {
    if (GetAsyncKeyState ('A')) xGlob-=2;
    if (GetAsyncKeyState ('D')) xGlob+=2;
    if (GetAsyncKeyState ('W')) yGlob+=2;
    if (GetAsyncKeyState ('S')) yGlob-=2;
    if (GetAsyncKeyState ('Z')) zGlob-=0.2;
    if (GetAsyncKeyState ('X')) zGlob+=0.2;
    }

void Rotate ()
    {
    if (GetAsyncKeyState (VK_LEFT))  C -= 0.05;
    if (GetAsyncKeyState (VK_RIGHT)) C += 0.05;
    if (GetAsyncKeyState ('M'))      B -= 0.05;
    if (GetAsyncKeyState ('N'))      B += 0.05;
    if (GetAsyncKeyState (VK_UP))    A -= 0.05;
    if (GetAsyncKeyState (VK_DOWN))  A += 0.05;
    }

void Line3D (double x1, double y1, double z1, double x2, double y2, double z2)
    {
    double x1_old = x1, y1_old = y1, z1_old = z1;
    double x2_old = x2, y2_old = y2, z2_old = z2;

    y1 = z1_old * sin (A) + y1_old * cos (A);
    y2 = z2_old * sin (A) + y2_old * cos (A);
    z1 = z1_old * cos (A) - y1_old * sin (A);
    z2 = z2_old * cos (A) - y2_old * sin (A);

    y1_old = y1;
    y2_old = y2;
    z1_old = z1;
    z2_old = z2;

    y1 = x1_old * sin (B) + y1_old * cos (B);
    y2 = x2_old * sin (B) + y2_old * cos (B);
    x1 = x1_old * cos (B) - y1_old * sin (B);
    x2 = x2_old * cos (B) - y2_old * sin (B);

    x1_old = x1;
    x2_old = x2;

    z1 = x1_old * sin (C) + z1_old * cos (C);
    z2 = x2_old * sin (C) + z2_old * cos (C);
    x1 = x1_old * cos (C) - z1_old * sin (C);
    x2 = x2_old * cos (C) - z2_old * sin (C);

    x1 *= ZoomX;
    y1 *= ZoomY;
    z1 *= ZoomZ;

    x2 *= ZoomX;
    y2 *= ZoomY;
    z2 *= ZoomZ;

    x1 += xGlob;
    y1 += yGlob;
    z1 += zGlob;

    x2 += xGlob;
    y2 += yGlob;
    z2 += zGlob;
    double zmin = -100;
    txLine ((x1)/(z1 - zmin) + XWindow / 2, YWindow / 2  - (y1)/(z1 - zmin), XWindow / 2 + (x2)/(z2 - zmin), YWindow / 2 - (y2)/(z2 - zmin));

    x1_old = x1;
    y1_old = y1;
    z1_old = z1;
    x2_old = x2;
    y2_old = y2;
    z2_old = z2;
    }

void Circle3D (double x1, double y1, double z1, double r)
    {
    double x1_old = x1, y1_old = y1, z1_old = z1;

    y1 = z1_old * sin (A) + y1_old * cos (A);
    z1 = z1_old * cos (A) - y1_old * sin (A);

    y1_old = y1;
    z1_old = z1;

    y1 = x1_old * sin (B) + y1_old * cos (B);
    x1 = x1_old * cos (B) - y1_old * sin (B);

    x1_old = x1;

    z1 = x1_old * sin (C) + z1_old * cos (C);
    x1 = x1_old * cos (C) - z1_old * sin (C);

    x1 *= ZoomX;
    y1 *= ZoomY;
    z1 *= ZoomZ;

    x1 += xGlob;
    y1 += yGlob;
    z1 += zGlob;

    double zmin = -100;

    txCircle (x1/(z1 - zmin) + XWindow / 2, YWindow / 2 - y1/(z1 - zmin), r/(z1 - zmin));

    x1_old = x1;
    y1_old = y1;
    z1_old = z1;
    }

void Mass1 (CBall Mol[], int sz)
    {
    for (int N = 0; N < sz; N++)
        {
        Mol [N].x = 0;
        Mol [N].y = 0;
        Mol [N].z = 0;
        Mol [N].vx = random (1, 7) / 100;
        Mol [N].vy = random (1, 7) / 100;
        Mol [N].vz = random (1, 7) / 100;
        Mol [N].dt = 1;
        Mol [N].rad = 25;
        }
    }
