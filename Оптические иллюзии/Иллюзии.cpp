#include "TXLib.h"

#define Key(param) GetAsyncKeyState(param)

const int X_DEST    =          696,
          Y_DEST    =          473,
          SX        = X_DEST + 100,
          SY        = Y_DEST +  50,
          ILLUSIONS =           21;


class Illusions
    {
    public:

    HDC skin;

    int x     ,
        y     ,
        x_dest,
        y_dest;

    bool show;

    Illusions() :
        x      (50),
        y      (25),
        x_dest(696),
        y_dest(473),
        skin (NULL),
        show(false)
        {}

    ~Illusions()
        {
        txDeleteDC(skin);
        }

    void SetSkin(HDC n_skin)
        {
        skin = n_skin;
        }
    };

int main()
    {
    txCreateWindow(SX * 2, SY * 2);
    txTextCursor(false);
    SetWindowText(txWindow(), "Illusions");


    Illusions illus[ILLUSIONS] = {};

    HDC skins[ILLUSIONS] = {txLoadImage("WTF.bmp"),
                            txLoadImage("Cat.bmp"),
                            txLoadImage("Packman.bmp"),
                            txLoadImage("Spiral.bmp"),
                            txLoadImage("Sphere.bmp"),
                            txLoadImage("Figure.bmp"),
                            txLoadImage("DINOSOWER.bmp"),
                            txLoadImage("Packman2.bmp"),
                            txLoadImage("Cab.bmp"),
                            txLoadImage("Cab2.bmp"),
                            txLoadImage("Head.bmp"),
                            txLoadImage("6terna.bmp"),
                            txLoadImage("6terna4.bmp"),
                            txLoadImage("bike.bmp"),
                            txLoadImage("�����.bmp"),
                            txLoadImage("fish.bmp"),
                            txLoadImage("kriper.bmp"),
                            txLoadImage("WTF2.bmp"),
                            txLoadImage("kub.bmp"),
                            txLoadImage("water.bmp"),
                            txLoadImage("serdce.bmp")};

    HDC transparent = txLoadImage("Transparent5.bmp");

    double x = -450, y = 25;

    for(int i = 0; i < ILLUSIONS; i++) illus[i].SetSkin(skins[i]);
    illus[0].show = true;

    while(!Key(27))
        {
        txBegin();
        txSetFillColor(TX_BLACK);
        txClear();

        for(int i = 0; i < ILLUSIONS; i++)
            {
            if(illus[i].show)
                {
                txBitBlt(txDC(), illus[i].x, illus[i].y, X_DEST * 2, Y_DEST * 2, illus[i].skin, 0, 0);
                if(Key('1'))
                    {
                    if(i > 0) illus[i].show = false, illus[i         - 1].show = true;
                    else      illus[i].show = false, illus[ILLUSIONS - 1].show = true;
                    }
                if(Key('2'))
                    {
                    if(i < ILLUSIONS - 1) illus[i].show = false, illus[i + 1].show = true;
                    else                  illus[i].show = false, illus[    0].show = true;
                    }

                while(Key('1') || Key('2')) txSleep (1);
                }
            }

        if(Key(VK_LEFT )) x -= 0.25;
        if(Key(VK_RIGHT)) x += 0.25;
        if(Key(VK_UP   )) y--;
        if(Key(VK_DOWN )) y++;

        txTransparentBlt(txDC(), x, y, X_DEST * 4, Y_DEST * 2, transparent, 0, 0, TX_WHITE);

        txEnd();
        }

    txDeleteDC(transparent);

    return 0;
    }

