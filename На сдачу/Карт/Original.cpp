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
void Ogranich_Comp (CBall * b, double dt, double a, double bb);
double Dist (CBall b1, CBall b2);
void text (const char * text);
void Stolknovenie (CBall* b1, CBall* b2);
void snaryadi (CBall* sn, CBall b, double dt);
void Score (double Score, int x, int y);
void DrowSnar (CBall sn, int razmerX, int razmerY, HDC nazvan);
void DrawAll (const CBall bs[], int sz, HDC vrag);
void MoveAll (CBall bs[], int sz, double dt, double a, double b);
void ZadachaKord (CBall * Bs[], int sz);

int main ()
    {
    txCreateWindow (1500, 800);
    MoveShar ();
    }

void MoveShar ()
    {

    CBall Ball [5] = {{750, 400, 0, 0, 25, 3}};

    CBall sn1 = {0, 0, 5, 5, 8};
    CBall sn2 = {0, 400, 5, 5, 8};
    CBall sn3 = {1500, 400, 5, 5, 8};
    CBall sn4 = {1500, 0, 5, 5, 8};

    CBall snbig1 = {sn1.x, sn2.y, 5, 5, 16};
    CBall snbig2 = {sn3.x, sn4.y, 5, 5, 16};

    CBall snBIGG = {snbig1.x, snbig2.y, 5, 5, 32};

    //double t = 0;
    double dt = 1;

    int i = 1;
    int N = 5;

    HDC vrag = txLoadImage ("vrag.bmp");
    HDC igrok = txLoadImage ("igrok.bmp");
    HDC fon = txLoadImage ("fon1.bmp");
    HDC snaryad1 = txLoadImage ("������20.bmp");
    HDC snaryad2 = txLoadImage ("������40.bmp");
    HDC snaryad3 = txLoadImage ("������80.bmp");

    while (!GetAsyncKeyState(VK_ESCAPE))
        {

        txSetFillColor (TX_BLACK);
        txClear ();

        txBitBlt (txDC (), 0, 0, 1500, 800, fon, 0, 0);

        assert (0 < i && i <= N);

        while (i < N)
            {
            Ball[i].x = random (20, 1480);
            Ball[i].y = random (20, 780);
            Ball[i].vx = 2;
            Ball[i].vy = 2;
            Ball[i].rad = 30;
            i++;
            }
        DrawAll (Ball, N, vrag);
        MoveAll (Ball, N, dt, 1500, 800);

        txTransparentBlt (txDC (), Ball[0].x - Ball[0].rad, Ball[0].y - Ball[0].rad, 50, 50, igrok, 0, 0, TX_WHITE);
        Upravlenie (&Ball[0], dt);

        i = 1;

        assert (0 < i && i <= N);
        while (i < N)
            {
            if (Dist (Ball[i], Ball[0]) < Ball[i].rad + Ball[0].rad)
                {
                text ("�� �������");
                txMessageBox ("�� �������!!!", "���������", 0);
                break;
                }
            i++;
            }

        if (Ball[0].x + Ball[0].rad > 1500 ||
            Ball[0].x - Ball[0].rad < 0    ||
            Ball[0].y + Ball[0].rad > 800  ||
            Ball[0].y - Ball[0].rad < 0    )
            {
            text ("�� �����������");
            txMessageBox ("�� �����������!!!", "���������", 0);
            break;
            }

        Stolknovenie (&Ball[1], &Ball[2]);
        Stolknovenie (&Ball[1], &Ball[3]);                                          //
        Stolknovenie (&Ball[1], &Ball[4]);
        Stolknovenie (&Ball[1], &Ball[5]);
        Stolknovenie (&Ball[2], &Ball[3]);
        Stolknovenie (&Ball[2], &Ball[4]);
        Stolknovenie (&Ball[2], &Ball[5]);
        Stolknovenie (&Ball[3], &Ball[4]);
        Stolknovenie (&Ball[3], &Ball[5]);
        Stolknovenie (&Ball[4], &Ball[5]);


        snaryadi (&sn1, Ball[0], dt);
        snaryadi (&sn2, Ball[0], dt);
        snaryadi (&sn3, Ball[0], dt);
        snaryadi (&sn4, Ball[0], dt);
        snaryadi (&snbig1, Ball[0], dt);
        snaryadi (&snbig2, Ball[0], dt);
        snaryadi (&snBIGG, Ball[0], dt);

        if (Dist (snbig1, snbig2) <= snbig1.rad + snbig2.rad)
                {
                DrowSnar (snBIGG, 80, 80, snaryad3);
                }                                                                                                 //dddd
            else
                {
                if (Dist (sn1, sn2) <= sn1.rad + sn2.rad)
                    {
                    DrowSnar (snbig1, 40, 40, snaryad2);
                    }
                else
                    {
                    DrowSnar (sn1, 19, 20, snaryad1);
                    DrowSnar (sn2, 19, 20, snaryad1);
                    }
                if (Dist (sn3, sn4) <= sn3.rad + sn4.rad)
                    {
                    DrowSnar (snbig2, 40, 40, snaryad2);
                    }
                else
                    {
                    DrowSnar (sn3, 19, 20, snaryad1);
                    DrowSnar (sn4, 19, 20, snaryad1);
                    }
                }

        if (Dist (sn1, Ball[0]) <= sn1.rad + Ball[0].rad ||
            Dist (sn2, Ball[0]) <= sn2.rad + Ball[0].rad ||
            Dist (sn3, Ball[0]) <= sn3.rad + Ball[0].rad ||
            Dist (sn4, Ball[0]) <= sn4.rad + Ball[0].rad ||
            Dist (snbig1, Ball[0]) <= snbig1.rad + Ball[0].rad ||
            Dist (snbig2, Ball[0]) <= snbig2.rad + Ball[0].rad ||
            Dist (snBIGG, Ball[0]) <= snBIGG.rad + Ball[0].rad )
                {
                text ("�� �������");
                txMessageBox ("�� �������!!!", "���������", 0);
                break;
                }

        /*if (GetAsyncKeyState('N' && 'K'))
            {
            t += 1;
            }
        t += 0.005;
        Score (t, 750, 20);

        if (t > 20)
            {
            texvoid DrawAQll (CBall* bs[], int size)t ("�� ��������!!!");
            txMessageBox ("������!!!", "������", 0);
            break;
            } */
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

void Ogranich_Comp (CBall * b, double dt, double a, double bb)
    {
    b->x += b->vx * dt;
    b->y += b->vy * dt;

    if (b->x - b->rad < 0)
        {
        b->x = 0 + b->rad;
        b->vx = -b->vx;
        }
    if (b->x + b->rad > a)
        {
        b->x = a - b->rad;
        b->vx = -b->vx;
        }
    if (b->y - b->rad < 0)
        {
        b->y = 0 + b->rad;
        b->vy = -b->vy;
        }
    if (b->y + b->rad > bb)
        {
        b->y = bb - b->rad;
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
    char text [100] = "You have";
    sprintf (text, "You have %lg", Score);
    txTextOut (x - 75, y- 10, text);
    }

void DrowSnar (CBall sn, int razmerX, int razmerY, HDC nazvan)
    {
    txTransparentBlt (txDC(), sn.x - sn.rad, sn.y - sn.rad, razmerX, razmerY, nazvan, 0, 0);
    }

void DrawAll (const CBall bs[], int sz, HDC vrag)
    {
    int i = 1;
    assert (0 < i && i <= sz);

    while (i < sz)
        {
        txTransparentBlt (txDC (), bs[i].x - bs[i].rad, bs[i].y - bs[i].rad, 68, 74, vrag, 0, 0, TX_WHITE);
        i++;
        }
    }

void MoveAll (CBall bs[], int sz, double dt, double a, double b)
    {
    int i = 1;
    assert (0 < i && i <= sz);

    while (i < sz)
        {
        Ogranich_Comp (&bs[i], dt, a, b);
        i++;
        }
    }

void ZadachaKord (CBall * Bs[], int sz)
    {
    int i = 1;
    assert (0 < i && i <= sz);

    while (i < sz)
        {
        Bs[i]->x = random (20, 1480);
        Bs[i]->y = random (20, 780);
        Bs[i]->vx = 2;
        Bs[i]->vy = 2;
        Bs[i]->rad = 30;
        i++;
        }
    }
