#include    <cstdlib>
#include    <conio.h>
#include    <windows.h>
#include     <iostream>
#include    <time.h>
using namespace std;
void gotoxy (int x, int y)
    {
         COORD coordinates;     // coordinates is declared as COORD
         coordinates.X = x;     // defining x-axis
         coordinates.Y = y;     //defining  y-axis
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
    }
int main()
{
    int i;
    int posx,posy,musuhx,musuhy,buahx,buahy,skorgue,skormusuh,boosterx,boostery,value;
    char ch;

    srand(time(NULL));

    for(i=0;i<=79;i++){
        gotoxy(i,0);    cout<<"#";
        gotoxy(i,20);    cout<<"#";

        if(i<20) (gotoxy(0,i)); cout<<"#";
        gotoxy(79,i); cout<<"#";

    }

    gotoxy(90,2); cout<<"HOTKEY GAME SNAKE";
    gotoxy(86,4); cout<<"Arah atas bawah kiri kanan ";
    gotoxy(86,6); cout<<"Dash = Spasi ";


    posx = rand()%40+ 20;
    posy = rand()%5+10 ;
    gotoxy(posx,posy); cout<<'\5';

    musuhx = rand()%40+ 20;
    musuhy = rand()%5+10 ;
    gotoxy(musuhx,musuhy); cout<<'\1';

    buahx = rand()%37+ 3;
    buahy = rand()%15+2 ;
    gotoxy(buahx,buahy); cout<<'@';

    boosterx = rand()%37+ 3;
    boostery = rand()%15+2 ;
    gotoxy(boosterx,boostery); cout<<'\6';
    int arah = 0;
    int delay = 0,limit=5000;
    skormusuh = 0;
    skorgue = 0;
    while(true)
    {
        delay++;

        if(delay>limit)
        {
            gotoxy(0,0); cout<<"Anda : "<< skorgue<<"  Musuhmu : "<<skormusuh<<"  ";
            delay=0;
                gotoxy(posx,posy);cout<<' ';
                gotoxy(musuhx,musuhy);cout<<' ';
                switch (arah)
                {
                    case 72 : posy--;break;
                    case 75 : posx--;break;
                    case 80 : posy++;break;
                    case 77 : posx++;break;
                }


            if(arah)
            {
                if(buahx==musuhx){

                if(buahy>musuhy) musuhy++;
                else if(buahy<musuhy) musuhy--;
                }
                if(buahx>musuhx) musuhx++;
                else if(buahx<musuhx) musuhx--;

            }

            gotoxy(musuhx,musuhy);cout<<'\1';
            gotoxy(posx,posy);cout<<'\5';
        if(musuhx==buahx&&musuhy==buahy)
        {
            buahx = rand()%37+ 3;
            buahy = rand()%15+2 ;
            gotoxy(buahx,buahy); cout<<'@';
            skormusuh+=100;
            limit-=10;
        }
        if(posx==buahx&&posy==buahy)
        {
            buahx = rand()%37+ 3;
            buahy = rand()%15+2 ;
            gotoxy(buahx,buahy); cout<<'@';
            skorgue+=100;
            limit-=100;
        }
         if(posx==boosterx&&posy==boostery)
        {
            boosterx = rand()%37+ 3;
            boostery = rand()%15+2 ;
            gotoxy(boosterx,boostery); cout<<'\6';
            limit-=500;
        }
        }

        if(skorgue== 1000 || skormusuh==1000){
            gotoxy(35,20); cout<<"Game Selesai : ";
            if(skorgue>skormusuh)
                cout<<"Selamat anda menang";
                else if (skorgue<skormusuh) cout<<" Anda kalah"; else cout<<"SERI";
            break;
        }

        if(posx>78||posx<1||posy>19||posy<1){

            gotoxy(35,20); cout<<"Game Selesai : ";
            if(skorgue>skormusuh)
                cout<<"Selamat anda menang";
                else if (skorgue<skormusuh) cout<<" Anda kalah"; else cout<<"SERI";
            break;


        }

        if(kbhit()){
            ch=getch();

        if(ch==32)
        {gotoxy(posx,posy);cout<<' ';
             switch(arah)
                {
                    case 72 : posy-=3;break;
                    case 75 : posx-=3;break;
                    case 80 : posy+=3;break;
                    case 77 : posx+=3;break;
                }

        }

        if(ch<0)
            {
             ch = getch();
            if (ch==72 || ch==80||ch==75||ch==77)
            {
                arah = ch;
            }
            }
        }
    }
    return EXIT_SUCCESS;
}
