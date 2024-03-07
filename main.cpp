#include <iostream>
#include <cstring>
#include <graphics.h>

void draw_Tabla(int x);
void draw_Piesa();
void Menu();
void Play_4x4();
void Play_5x5();
void Play_6x6();
void Play_7x7();
void Play_8x8();
void initializareTabla(int x);
void alegePiesa(int x);
bool punerePiesa(int x);

int Tabla[10][10];
int n;
int jucator = 2;
int cursorX, cursorY;
int piesaAleasa = 4;
int marimeaAleasa;
bool ok;
using namespace std;

void Menu()
{
    initwindow(1200,700);

    setcolor(WHITE);
    settextstyle(10, HORIZ_DIR, 5);
    outtextxy(450,50, "COLTUL NEGRU");

    //for(int i=100;i<=1100;i+=50)
      //  line(i,0,i,700);

        setcolor(WHITE);
    for(int i=100;i<1100;i+=210)
    {
        rectangle(i,350,i+160,440);
    }

    setcolor(WHITE);
    settextstyle(10, HORIZ_DIR, 5);
    outtextxy(250,250, "ALEGE MARIMEA TABLEI DE JOC");

    int boardsize_text=140;
    outtextxy(boardsize_text,375, "4x4");
    outtextxy(boardsize_text+210,375, "5x5");
    outtextxy(boardsize_text+420,375, "6x6");
    outtextxy(boardsize_text+630,375, "7x7");
    outtextxy(boardsize_text+840,375, "8x8");

    while(true)
    {
        while(!ismouseclick(WM_LBUTTONDOWN));
    getmouseclick(WM_LBUTTONDOWN, cursorX, cursorY);
    if(cursorX>100 and cursorX<260 and cursorY>350 and cursorY<440)
    {
        closegraph();
        Play_4x4();
    }
    if(cursorX>310 and cursorX<470 and cursorY>350 and cursorY<440)
    {
        closegraph();
        Play_5x5();
    }
    if(cursorX>520 and cursorX<680 and cursorY>350 and cursorY<440)
    {
        closegraph();
        Play_6x6();
    }
    if(cursorX>730 and cursorX<890 and cursorY>350 and cursorY<440)
    {
        closegraph();
        Play_7x7();
    }
    if(cursorX>940 and cursorX<1100 and cursorY>350 and cursorY<440)
    {
        closegraph();
        Play_8x8();
    }
    }
}

void win(int player)
{
    closegraph();
    initwindow(1200,700);
    if(player == 1)
    outtextxy(250,100, "JUCATORUL 1 A CASTIGAT");
   else
    outtextxy(250,100, "JUCATORUL 2 A CASTIGAT");
    getch();
    closegraph();
}

void lose(int player)
{
    closegraph();
    initwindow(1200,700);
    if(player == 1)
    outtextxy(250,100, "JUCATORUL 1 A PIERDUT");
   else
    outtextxy(250,100, "JUCATORUL 2 A PIERDUT");
   getch();
   closegraph();
}

void Play_4x4()
{
    initwindow(1200,700);

       //for(int i = 0 ;i<=1200;i+=50)
       //line(0,i,1200,i);

       //for(int i = 0 ;i<=700;i+=50)
       //line(i,0,i,1200);

    piesaAleasa = 5;
    setcolor(WHITE);
    rectangle(20,20,150,70);
    settextstyle(10, HORIZ_DIR, 4);
    outtextxy(45,30, "BACK");

        marimeaAleasa=4;
        initializareTabla(marimeaAleasa);

    draw_Tabla(marimeaAleasa);
    readimagefile("0.jpg", 150 + 50 * 12, 150, 150 + 50 * 11, 200);
    readimagefile("1.jpg", 150 + 50 * 13 + 10, 150, 150 + 50 * 12 + 10, 200);
    readimagefile("2.jpg", 150 + 50 * 14 + 20, 150, 150 + 50 * 13 + 20, 200);
    readimagefile("3.jpg", 150 + 50 * 15 + 30, 150, 150 + 50 * 14 + 30, 200);

    while(true)
    {
        while(!ismouseclick(WM_LBUTTONDOWN));
    getmouseclick(WM_LBUTTONDOWN, cursorX, cursorY);

    if(cursorX>20 and cursorX<150 and cursorY>20 and cursorY<70)
    {
        closegraph();
        Menu();
    }
    do
    {
    if(cursorX>150+50*12 and cursorX<150+50*13 and cursorY>150 and cursorY<200)
    {
        piesaAleasa = 0;
        cout<<"piesa aleasa este 0 "<<"\n";
        setcolor(YELLOW);
        rectangle(150+50*12-3, 150-3, 150+50*13+3,203);
        setcolor(BLACK);
        rectangle(150+50*13+10-3, 150-3, 150+50*14+10+3,203);
        rectangle(150+50*14+20-3, 150-3, 150+50*15+20+3,203);
        rectangle(150+50*15+30-3, 150-3, 150+50*16+30+3,203);
    }
    if(cursorX>150+50*13+10 and cursorX<150+50*14+10 and cursorY>150 and cursorY<200)
    {
        piesaAleasa = 1;
        cout<<"piesa aleasa este 1"<<"\n";
        setcolor(YELLOW);
        rectangle(150+50*13+10-3, 150-3, 150+50*14+10+3,203);
        setcolor(BLACK);
        rectangle(150+50*12-3, 150-3, 150+50*13+3,203);
        rectangle(150+50*14+20-3, 150-3, 150+50*15+20+3,203);
        rectangle(150+50*15+30-3, 150-3, 150+50*16+30+3,203);
    }
    if(cursorX>150+50*14+20 and cursorX<150+50*15+20 and cursorY>150 and cursorY<200)
    {
        piesaAleasa = 2;
        cout<<"piesa aleasa este 2"<<"\n";
        setcolor(YELLOW);
        rectangle(150+50*14+20-3, 150-3, 150+50*15+20+3,203);
        setcolor(BLACK);
        rectangle(150+50*13+10-3, 150-3, 150+50*14+10+3,203);
        rectangle(150+50*12-3, 150-3, 150+50*13+3,203);
        rectangle(150+50*15+30-3, 150-3, 150+50*16+30+3,203);
    }
    if(cursorX>150+50*15+30 and cursorX<150+50*16+30 and cursorY>150 and cursorY<200)
    {
        piesaAleasa = 3;
        cout<<"piesa aleasa este 3"<<"\n";
        setcolor(YELLOW);
        rectangle(150+50*15+30-3, 150-3, 150+50*16+30+3,203);
        setcolor(BLACK);
        rectangle(150+50*12-3, 150-3, 150+50*13+3,203);
        rectangle(150+50*13+10-3, 150-3, 150+50*14+10+3,203);
        rectangle(150+50*14+20-3, 150-3, 150+50*15+20+3,203);
    }
    } while(piesaAleasa == 4);

        if(jucator == 2)
        {
            jucator = 1;
            setcolor(YELLOW);
            outtextxy(680, 250, "Randul jucatorului 1");
        }

        else if(jucator == 1)
        {
            jucator = 2;
            setcolor(YELLOW);
            outtextxy(680, 250, "Randul jucatorului 2");
        }

        do
        {
            ok=punerePiesa(marimeaAleasa);
        }
        while (!ok);

        int i,j;
        cout <<"\n\n";
        for (i=0; i<=marimeaAleasa+1; i++)
        {
            for (j=0; j<=marimeaAleasa+1; j++)
                cout << Tabla[i][j] << " ";
            cout << endl;
        }

    }

}
void Play_5x5()
{
    initwindow(1200,700);

        marimeaAleasa=5;
        initializareTabla(marimeaAleasa);

    setcolor(WHITE);
    rectangle(20,20,150,70);
    settextstyle(10, HORIZ_DIR, 4);
    outtextxy(45,30, "BACK");

    draw_Tabla(marimeaAleasa);
    readimagefile("0.jpg", 150 + 50 * 12, 150, 150 + 50 * 11, 200);
    readimagefile("1.jpg", 150 + 50 * 13 + 10, 150, 150 + 50 * 12 + 10, 200);
    readimagefile("2.jpg", 150 + 50 * 14 + 20, 150, 150 + 50 * 13 + 20, 200);
    readimagefile("3.jpg", 150 + 50 * 15 + 30, 150, 150 + 50 * 14 + 30, 200);

    while(true)
    {
        while(!ismouseclick(WM_LBUTTONDOWN));
    getmouseclick(WM_LBUTTONDOWN, cursorX, cursorY);

    if(cursorX>20 and cursorX<150 and cursorY>20 and cursorY<70)
    {
        closegraph();
        Menu();
    }
    do
    {
    if(cursorX>150+50*12 and cursorX<150+50*13 and cursorY>150 and cursorY<200)
    {
        piesaAleasa = 0;
        cout<<"piesa aleasa este 0 "<<"\n";
        setcolor(YELLOW);
        rectangle(150+50*12-3, 150-3, 150+50*13+3,203);
        setcolor(BLACK);
        rectangle(150+50*13+10-3, 150-3, 150+50*14+10+3,203);
        rectangle(150+50*14+20-3, 150-3, 150+50*15+20+3,203);
        rectangle(150+50*15+30-3, 150-3, 150+50*16+30+3,203);
    }
    if(cursorX>150+50*13+10 and cursorX<150+50*14+10 and cursorY>150 and cursorY<200)
    {
        piesaAleasa = 1;
        cout<<"piesa aleasa este 1"<<"\n";
        setcolor(YELLOW);
        rectangle(150+50*13+10-3, 150-3, 150+50*14+10+3,203);
        setcolor(BLACK);
        rectangle(150+50*12-3, 150-3, 150+50*13+3,203);
        rectangle(150+50*14+20-3, 150-3, 150+50*15+20+3,203);
        rectangle(150+50*15+30-3, 150-3, 150+50*16+30+3,203);
    }
    if(cursorX>150+50*14+20 and cursorX<150+50*15+20 and cursorY>150 and cursorY<200)
    {
        piesaAleasa = 2;
        cout<<"piesa aleasa este 2"<<"\n";
        setcolor(YELLOW);
        rectangle(150+50*14+20-3, 150-3, 150+50*15+20+3,203);
        setcolor(BLACK);
        rectangle(150+50*13+10-3, 150-3, 150+50*14+10+3,203);
        rectangle(150+50*12-3, 150-3, 150+50*13+3,203);
        rectangle(150+50*15+30-3, 150-3, 150+50*16+30+3,203);
    }
    if(cursorX>150+50*15+30 and cursorX<150+50*16+30 and cursorY>150 and cursorY<200)
    {
        piesaAleasa = 3;
        cout<<"piesa aleasa este 3"<<"\n";
        setcolor(YELLOW);
        rectangle(150+50*15+30-3, 150-3, 150+50*16+30+3,203);
        setcolor(BLACK);
        rectangle(150+50*12-3, 150-3, 150+50*13+3,203);
        rectangle(150+50*13+10-3, 150-3, 150+50*14+10+3,203);
        rectangle(150+50*14+20-3, 150-3, 150+50*15+20+3,203);
    }
    } while(piesaAleasa == 4);

        if(jucator == 2)
        {
            jucator = 1;
            setcolor(YELLOW);
            outtextxy(680, 250, "Randul jucatorului 1");
        }

        else if(jucator == 1)
        {
            jucator = 2;
            setcolor(YELLOW);
            outtextxy(680, 250, "Randul jucatorului 2");
        }

        do
        {
            ok=punerePiesa(marimeaAleasa);
        }
        while (!ok);

        int i,j;
        cout <<"\n\n";
        for (i=0; i<=marimeaAleasa+1; i++)
        {
            for (j=0; j<=marimeaAleasa+1; j++)
                cout << Tabla[i][j] << " ";
            cout << endl;
        }
    }
}
void Play_6x6()
{
    initwindow(1200,700);

    setcolor(WHITE);
    rectangle(20,20,150,70);
    settextstyle(10, HORIZ_DIR, 4);
    outtextxy(45,30, "BACK");

        marimeaAleasa=6;
        initializareTabla(marimeaAleasa);

    draw_Tabla(marimeaAleasa);
    readimagefile("0.jpg", 150 + 50 * 12, 150, 150 + 50 * 11, 200);
    readimagefile("1.jpg", 150 + 50 * 13 + 10, 150, 150 + 50 * 12 + 10, 200);
    readimagefile("2.jpg", 150 + 50 * 14 + 20, 150, 150 + 50 * 13 + 20, 200);
    readimagefile("3.jpg", 150 + 50 * 15 + 30, 150, 150 + 50 * 14 + 30, 200);

    while(true)
    {
        while(!ismouseclick(WM_LBUTTONDOWN));
    getmouseclick(WM_LBUTTONDOWN, cursorX, cursorY);

    if(cursorX>20 and cursorX<150 and cursorY>20 and cursorY<70)
    {
        closegraph();
        Menu();
    }do
    {
    if(cursorX>150+50*12 and cursorX<150+50*13 and cursorY>150 and cursorY<200)
    {
        piesaAleasa = 0;
        cout<<"piesa aleasa este 0 "<<"\n";
        setcolor(YELLOW);
        rectangle(150+50*12-3, 150-3, 150+50*13+3,203);
        setcolor(BLACK);
        rectangle(150+50*13+10-3, 150-3, 150+50*14+10+3,203);
        rectangle(150+50*14+20-3, 150-3, 150+50*15+20+3,203);
        rectangle(150+50*15+30-3, 150-3, 150+50*16+30+3,203);
    }
    if(cursorX>150+50*13+10 and cursorX<150+50*14+10 and cursorY>150 and cursorY<200)
    {
        piesaAleasa = 1;
        cout<<"piesa aleasa este 1"<<"\n";
        setcolor(YELLOW);
        rectangle(150+50*13+10-3, 150-3, 150+50*14+10+3,203);
        setcolor(BLACK);
        rectangle(150+50*12-3, 150-3, 150+50*13+3,203);
        rectangle(150+50*14+20-3, 150-3, 150+50*15+20+3,203);
        rectangle(150+50*15+30-3, 150-3, 150+50*16+30+3,203);
    }
    if(cursorX>150+50*14+20 and cursorX<150+50*15+20 and cursorY>150 and cursorY<200)
    {
        piesaAleasa = 2;
        cout<<"piesa aleasa este 2"<<"\n";
        setcolor(YELLOW);
        rectangle(150+50*14+20-3, 150-3, 150+50*15+20+3,203);
        setcolor(BLACK);
        rectangle(150+50*13+10-3, 150-3, 150+50*14+10+3,203);
        rectangle(150+50*12-3, 150-3, 150+50*13+3,203);
        rectangle(150+50*15+30-3, 150-3, 150+50*16+30+3,203);
    }
    if(cursorX>150+50*15+30 and cursorX<150+50*16+30 and cursorY>150 and cursorY<200)
    {
        piesaAleasa = 3;
        cout<<"piesa aleasa este 3"<<"\n";
        setcolor(YELLOW);
        rectangle(150+50*15+30-3, 150-3, 150+50*16+30+3,203);
        setcolor(BLACK);
        rectangle(150+50*12-3, 150-3, 150+50*13+3,203);
        rectangle(150+50*13+10-3, 150-3, 150+50*14+10+3,203);
        rectangle(150+50*14+20-3, 150-3, 150+50*15+20+3,203);
    }
    } while(piesaAleasa == 4);

        if(jucator == 2)
        {
            jucator = 1;
            setcolor(YELLOW);
            outtextxy(680, 250, "Randul jucatorului 1");
        }

        else if(jucator == 1)
        {
            jucator = 2;
            setcolor(YELLOW);
            outtextxy(680, 250, "Randul jucatorului 2");
        }

        do
        {
            ok=punerePiesa(marimeaAleasa);
        }
        while (!ok);

        int i,j;
        cout <<"\n\n";
        for (i=0; i<=marimeaAleasa+1; i++)
        {
            for (j=0; j<=marimeaAleasa+1; j++)
                cout << Tabla[i][j] << " ";
            cout << endl;
        }

    }
}
void Play_7x7()
{
    initwindow(1200,700);

    setcolor(WHITE);
    rectangle(20,20,150,70);
    settextstyle(10, HORIZ_DIR, 4);
    outtextxy(45,30, "BACK");

        marimeaAleasa=7;
        initializareTabla(marimeaAleasa);

    draw_Tabla(marimeaAleasa);
    readimagefile("0.jpg", 150 + 50 * 12, 150, 150 + 50 * 11, 200);
    readimagefile("1.jpg", 150 + 50 * 13 + 10, 150, 150 + 50 * 12 + 10, 200);
    readimagefile("2.jpg", 150 + 50 * 14 + 20, 150, 150 + 50 * 13 + 20, 200);
    readimagefile("3.jpg", 150 + 50 * 15 + 30, 150, 150 + 50 * 14 + 30, 200);

    while(true)
    {
        while(!ismouseclick(WM_LBUTTONDOWN));
    getmouseclick(WM_LBUTTONDOWN, cursorX, cursorY);

    if(cursorX>20 and cursorX<150 and cursorY>20 and cursorY<70)
    {
        closegraph();
        Menu();
    }
    do
    {
    if(cursorX>150+50*12 and cursorX<150+50*13 and cursorY>150 and cursorY<200)
    {
        piesaAleasa = 0;
        cout<<"piesa aleasa este 0 "<<"\n";
        setcolor(YELLOW);
        rectangle(150+50*12-3, 150-3, 150+50*13+3,203);
        setcolor(BLACK);
        rectangle(150+50*13+10-3, 150-3, 150+50*14+10+3,203);
        rectangle(150+50*14+20-3, 150-3, 150+50*15+20+3,203);
        rectangle(150+50*15+30-3, 150-3, 150+50*16+30+3,203);
    }
    if(cursorX>150+50*13+10 and cursorX<150+50*14+10 and cursorY>150 and cursorY<200)
    {
        piesaAleasa = 1;
        cout<<"piesa aleasa este 1"<<"\n";
        setcolor(YELLOW);
        rectangle(150+50*13+10-3, 150-3, 150+50*14+10+3,203);
        setcolor(BLACK);
        rectangle(150+50*12-3, 150-3, 150+50*13+3,203);
        rectangle(150+50*14+20-3, 150-3, 150+50*15+20+3,203);
        rectangle(150+50*15+30-3, 150-3, 150+50*16+30+3,203);
    }
    if(cursorX>150+50*14+20 and cursorX<150+50*15+20 and cursorY>150 and cursorY<200)
    {
        piesaAleasa = 2;
        cout<<"piesa aleasa este 2"<<"\n";
        setcolor(YELLOW);
        rectangle(150+50*14+20-3, 150-3, 150+50*15+20+3,203);
        setcolor(BLACK);
        rectangle(150+50*13+10-3, 150-3, 150+50*14+10+3,203);
        rectangle(150+50*12-3, 150-3, 150+50*13+3,203);
        rectangle(150+50*15+30-3, 150-3, 150+50*16+30+3,203);
    }
    if(cursorX>150+50*15+30 and cursorX<150+50*16+30 and cursorY>150 and cursorY<200)
    {
        piesaAleasa = 3;
        cout<<"piesa aleasa este 3"<<"\n";
        setcolor(YELLOW);
        rectangle(150+50*15+30-3, 150-3, 150+50*16+30+3,203);
        setcolor(BLACK);
        rectangle(150+50*12-3, 150-3, 150+50*13+3,203);
        rectangle(150+50*13+10-3, 150-3, 150+50*14+10+3,203);
        rectangle(150+50*14+20-3, 150-3, 150+50*15+20+3,203);
    }
    } while(piesaAleasa == 4);

        do
        {
            ok=punerePiesa(marimeaAleasa);
        }
        while (!ok);

        int i,j;
        cout <<"\n\n";
        for (i=0; i<=marimeaAleasa+1; i++)
        {
            for (j=0; j<=marimeaAleasa+1; j++)
                cout << Tabla[i][j] << " ";
            cout << endl;
        }
                if(jucator == 2)
        {
            jucator = 1;
            setcolor(YELLOW);
            outtextxy(680, 250, "Randul jucatorului 1");
        }

        else if(jucator == 1)
        {
            jucator = 2;
            setcolor(YELLOW);
            outtextxy(680, 250, "Randul jucatorului 2");
        }
    }
}
void Play_8x8()
{
    initwindow(1200,700);

    setcolor(WHITE);
    rectangle(20,20,150,70);
    settextstyle(10, HORIZ_DIR, 4);
    outtextxy(45,30, "BACK");

        marimeaAleasa=8;
        initializareTabla(marimeaAleasa);

    draw_Tabla(marimeaAleasa);
    readimagefile("0.jpg", 150 + 50 * 12, 150, 150 + 50 * 11, 200);
    readimagefile("1.jpg", 150 + 50 * 13 + 10, 150, 150 + 50 * 12 + 10, 200);
    readimagefile("2.jpg", 150 + 50 * 14 + 20, 150, 150 + 50 * 13 + 20, 200);
    readimagefile("3.jpg", 150 + 50 * 15 + 30, 150, 150 + 50 * 14 + 30, 200);

    while(true)
    {
        while(!ismouseclick(WM_LBUTTONDOWN));
    getmouseclick(WM_LBUTTONDOWN, cursorX, cursorY);

    if(cursorX>20 and cursorX<150 and cursorY>20 and cursorY<70)
    {
        closegraph();
        Menu();
    }
    do
    {
    if(cursorX>150+50*12 and cursorX<150+50*13 and cursorY>150 and cursorY<200)
    {
        piesaAleasa = 0;
        cout<<"piesa aleasa este 0 "<<"\n";
        setcolor(YELLOW);
        rectangle(150+50*12-3, 150-3, 150+50*13+3,203);
        setcolor(BLACK);
        rectangle(150+50*13+10-3, 150-3, 150+50*14+10+3,203);
        rectangle(150+50*14+20-3, 150-3, 150+50*15+20+3,203);
        rectangle(150+50*15+30-3, 150-3, 150+50*16+30+3,203);
    }
    if(cursorX>150+50*13+10 and cursorX<150+50*14+10 and cursorY>150 and cursorY<200)
    {
        piesaAleasa = 1;
        cout<<"piesa aleasa este 1"<<"\n";
        setcolor(YELLOW);
        rectangle(150+50*13+10-3, 150-3, 150+50*14+10+3,203);
        setcolor(BLACK);
        rectangle(150+50*12-3, 150-3, 150+50*13+3,203);
        rectangle(150+50*14+20-3, 150-3, 150+50*15+20+3,203);
        rectangle(150+50*15+30-3, 150-3, 150+50*16+30+3,203);
    }
    if(cursorX>150+50*14+20 and cursorX<150+50*15+20 and cursorY>150 and cursorY<200)
    {
        piesaAleasa = 2;
        cout<<"piesa aleasa este 2"<<"\n";
        setcolor(YELLOW);
        rectangle(150+50*14+20-3, 150-3, 150+50*15+20+3,203);
        setcolor(BLACK);
        rectangle(150+50*13+10-3, 150-3, 150+50*14+10+3,203);
        rectangle(150+50*12-3, 150-3, 150+50*13+3,203);
        rectangle(150+50*15+30-3, 150-3, 150+50*16+30+3,203);
    }
    if(cursorX>150+50*15+30 and cursorX<150+50*16+30 and cursorY>150 and cursorY<200)
    {
        piesaAleasa = 3;
        cout<<"piesa aleasa este 3"<<"\n";
        setcolor(YELLOW);
        rectangle(150+50*15+30-3, 150-3, 150+50*16+30+3,203);
        setcolor(BLACK);
        rectangle(150+50*12-3, 150-3, 150+50*13+3,203);
        rectangle(150+50*13+10-3, 150-3, 150+50*14+10+3,203);
        rectangle(150+50*14+20-3, 150-3, 150+50*15+20+3,203);
    }
    } while(piesaAleasa == 4);

        if(jucator == 2)
        {
            jucator = 1;
            setcolor(YELLOW);
            outtextxy(680, 250, "Randul jucatorului 1");
        }

        else if(jucator == 1)
        {
            jucator = 2;
            setcolor(YELLOW);
            outtextxy(680, 250, "Randul jucatorului 2");
        }

        do
        {
            ok=punerePiesa(marimeaAleasa);
        }
        while (!ok);

        int i,j;
        cout <<"\n\n";
        for (i=0; i<=marimeaAleasa+1; i++)
        {
            for (j=0; j<=marimeaAleasa+1; j++)
                cout << Tabla[i][j] << " ";
            cout << endl;
        }
    }
}

void draw_Piesa(int tip_piesa , int linie , int coloana)
{
    char fileName[10];

    switch(tip_piesa)
    {
        case 0:
        strcpy(fileName,"0.jpg");
        break;
    case 1:
        strcpy(fileName,"1.jpg");
        break;
    case 2:
        strcpy(fileName,"2.jpg");
        break;
    case 3:
        strcpy(fileName,"3.jpg");
        break;
    }
    readimagefile(fileName, 150 + 50 * coloana, 150 + 50 * linie, 150 + 50 * (coloana + 1) - 2, 150 + 50 * (linie + 1) - 2);
}

void draw_Tabla(int marime_tabla)
{
    int i,j;
    for (i=1; i<=marime_tabla; i++)
    {
        for (j=1; j<=marime_tabla; j++)
        {
            piesaAleasa=Tabla[i][j];
            if(i == marime_tabla and j == marime_tabla) break;
            draw_Piesa(piesaAleasa,i,j);
        }
    }
}

void initializareTabla(int n)
{
    int i,j;
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
            Tabla[i][j]=0;
    Tabla[1][1] = 1;
    Tabla[n][n] = -1;

    //Bordare
    for(i = 1; i <= n; i++)
        Tabla[i][0] = -2;
    for(i = 1; i <= n; i++)
        Tabla[i][n+1] = -2;
    for(j = 1; j <= n; j++)
        Tabla[0][j] = -2;
    for(j = 1; j <= n; j++)
        Tabla[n+1][j] = -2;

}

void verificareDrum(int &directie, int linia, int coloana)
{
    int i = linia;
    int j = coloana;
    while(Tabla[i][j] != -1 && Tabla[i][j] != -2 && Tabla[i][j] != 0)
    {
        if(Tabla[i][j] == 1)
        {
            if(directie == 1)j++;
            if(directie == 2)j--;
            if(directie == 3)i++;
            if(directie == 4)i--;
            cout << linia << " " << coloana << " *" << directie <<"\n";
        }
        else if(Tabla[i][j] == 2)
        {
            if(directie == 1)
            {
                directie = 4;
                i--;
            }

            else  if(directie == 2)
            {
                directie = 3;
                i++;
            }

            else if(directie == 3)
            {
                directie = 2;
                j--;
            }

            else if(directie == 4)
            {
                directie = 1;
                j++;
            }
            cout << linia << " " << coloana << " " << directie <<"\n";

        }
        else if(Tabla[i][j] == 3)
        {
            if(directie == 1)
            {
                directie = 3;
                i++;
            }

            else if(directie == 2)
            {
                directie = 4;
                i--;
            }
            else if(directie == 3)
            {
                directie = 1;
                j++;
            }
            else if(directie == 4)
            {
                directie = 2;
                j--;
            }
            cout << linia << " " << coloana << " " << directie <<"\n";
        }

    }
    if(Tabla[i][j] == -1)
        win(jucator);

    if(Tabla[i][j] == -2)
        lose(jucator);
}

void directieInceput(int &directie, int linia, int coloana, int &ok)
{
    ok = 1;
    if(linia == 2 && coloana == 1 && Tabla[linia][coloana] != 0 && Tabla[1][2] == 0)directie = 3;
    else if(linia == 1 && coloana == 2 && Tabla[linia][coloana] != 0 && Tabla[2][1] == 0)directie = 1;
    else if(linia == 2 && coloana == 1 && Tabla[linia][coloana] == 2 && Tabla[1][2] == 0)
    {
        lose(jucator);
        ok = 0;
    }
    else if(linia == 1 && coloana == 2 && Tabla[linia][coloana] == 2 && Tabla[2][1] == 0)
    {
        lose(jucator);
        ok = 0;
    }
    cout << linia << " "<< coloana << " " << directie << "\n";
}
int  directie = 0;

bool punerePiesa(int n) // n = dimensiunea tablei
{
    int linia, coloana, x, y, corect;
    int stanga = 200, sus = 200;
    int dreapta = 200 + 50 * n, jos = 200 + 50 * n;
    bool ok = false;
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        while(!ismouseclick(WM_LBUTTONDOWN));
    getmouseclick(WM_LBUTTONDOWN, cursorX, cursorY);
        if (cursorX>=stanga and cursorX<=dreapta and cursorY>=sus and cursorY<=jos)
        {
            linia=(cursorY-sus)/50+1;
            coloana=(cursorX-stanga)/50+1;
            if(piesaAleasa != 0)
            {
                if(Tabla[linia][coloana-1] > 0 || Tabla[linia][coloana+1] > 0 ||
                   Tabla[linia-1][coloana] > 0 || Tabla[linia+1][coloana] > 0)//punerea pieselor doar in pozitii vecine
                    if (Tabla[linia][coloana] == 0)
                    {
                        Tabla[linia][coloana] = piesaAleasa;
                        directieInceput(directie, linia, coloana, corect);
                        if(corect == 1)
                            verificareDrum(directie, linia, coloana);
                        draw_Piesa(piesaAleasa,linia,coloana);
                        ok=true;
                    }
            }
            else if(piesaAleasa == 0)
            {
                if(linia != 1 || coloana != 1)
                {
                    Tabla[linia][coloana] = 0;
                    verificareDrum(directie, linia, coloana);
                    draw_Piesa(0, linia, coloana);
                    ok = true;
                    cout<<"-------------------------";
                }

            }

        }
    }
    return ok;
}

int main()
{
    Menu();

    getch(); closegraph();
    return 0;
}

