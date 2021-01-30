                                // ******************************************
                                // * MOVIE TICKET BILLING SYSTEM
                                // * THE COMPILER USED IN THIS PROGRAM IS GCC
                                // *********************************************
#include<iostream>
#include"deepesh.h"
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<time.h>

using namespace std;

//********************************************
//*   globally declared data types
//*******************************************
char theatre_name[30];
char movie_name[30];
char timeofmovie[30];
char theatre_name_file[30];
char movie_name_file[30];
char timeofmovie_file[30];
char filename[60];
int xbook[30],ybook[30];
int k=0,q=0;
int seatno[10];
int x_book_file[30],y_book_file[30];
int index=0;

//********************************************
//*   class movie
//*******************************************
class movie
{
    char enter;
    int x,y,move_arrow;
    char arrow_rigth,arrow_left;
    char email_id[30];
    char password[20],password2[20];
    char first_name[20],last_name[20];
    int yseat,xseat,cntseat,how_many_seats,price,selected;
    int a[90];


public:

      movie()
      {
         x=0;
         y=0;
        arrow_left=174;
        arrow_rigth=175;
        yseat=25;
        xseat=0;
        cntseat=0;
        price=0;

                for(int j=0;j<90;j++)
                {
                    a[j]=j+1;
                }

      }
    //basic function
    void animated_page();
    void instruction();
    void loading();
    //login or sign in page
    void login_page_display();
    int login_page();

    //for login in the app
    void login_window_display();
    void password_page_display();
    int login_window();
   //for sign up in app
    void signup_window_display();
     int signup_window();
    //menu or list
     void display_menu();
    int menu();
    //for book ticket
    void book_ticket();
    void display_theatre();
    int theatre();
    void movie_list_display();
    int movie_list(int);
    void timing_of_movie(int);
    void timing_of_movie_display(int);
    //for display seats system
    void display_seat(int x_1,int y_1);
    int seat();
     void biling_display();
    //canceling the ticket
    void canceling_ticket();

};
//********************************************
//*   loading animation
//*******************************************


void movie::loading()
{
    char q=178,i;
    system("cls");
    gotoxy(50,15);
    cout<<"L O A D I N G";
    gotoxy(46,17);
    for(i=0;i<22;i++)
    {
        cout<<q;
         Beep(750,200);
        Sleep(100);
    }
    system("cls");

}
//********************************************
//*   animated logo page of project
//*******************************************
void movie ::animated_page()
{
    int i;

    int x_m1=2,y_m1=25;
    int x_m2=100,y_m2=25;
    for(i=0;i<=15;i++)
    {
        system("cls");
        gotoxy(x_m1,y_m1);
        cout<<"MOVIE";

        gotoxy(x_m2,y_m2);
        cout<<"MANIA";
        Sleep(50);
        y_m1--; y_m2--;
        x_m1++; x_m2--;
    }
    for(i=0;i<=15;i++)
    {
        system("cls");
        gotoxy(x_m1,y_m1);
        cout<<"MOVIE"<<endl;


        gotoxy(x_m2,y_m2);
        cout<<"MANIA";
        Sleep(50);
        y_m1++;    y_m2++;
        x_m1++;    x_m2--;
    }
    for(i=0;i<=14;i++)
    {
        system("cls");
        gotoxy(x_m1,y_m1);
        cout<<"MOVIE";

        gotoxy(x_m2,y_m2);
        cout<<"MANIA";
        Sleep(50);
        y_m1--;     y_m2--;
        x_m1++;     x_m2--;
    }
        x_m1-=1;
       y_m1+=2;
        gotoxy(x_m1,y_m1);
        cout<<"PRESS ENTER";
        x_m1-=3;
        y_m1-=2;

        gotoxy(x_m1,y_m1);
        for(i=0;i<18;i++)       //UPPER BORDER
        {
            cout<<"*";
            Sleep(100);
            x_m1++;
        }
        for(i=0;i<4;i++)       //RIGHT HAND SIDE BORDER
        {
            gotoxy(x_m1,y_m1);
            cout<<"*";
            Sleep(100);
            y_m1++;
        }

        for(i=0;i<=18;i++)       //LOWER BORDER
        {
            gotoxy(x_m1,y_m1);
            cout<<"*";
            Sleep(100);
            x_m1--;
        }
        for(i=0;i<=4;i++)       //LEFT SIDE  BORDER
        {
            gotoxy(x_m1,y_m1);
            cout<<"*";
            Sleep(100);
            y_m1--;
        }
        gotoxy(0,25);

}

//********************************************
//*   instruction page
//*******************************************

void movie :: instruction()
{
    int i;
    char ch=178;
    gotoxy(20,5);
    for(i=0;i<80;i++)
    cout<<ch;
    gotoxy(50,7);
    cout<<"INSTRUCTION";
    gotoxy(30,9);
    cout<<"1) THE WHOLE PROGRAM WORKS ON ARROW KEYS, PRESS ARROW KEY TO MOVE ARROW";
    gotoxy(30,10);
    cout<<"2) TO SELECT  ANY OPTION PRESS ENTER";
    gotoxy(40,12);
    cout<<"NOW ENJOY THE LATEST MOVIE FROM THIS APP";
    gotoxy(20,14);
    for(i=0;i<80;i++)
    cout<<ch;
    gotoxy(30,16);
    system("pause");

}
//********************************************
//*   login or sign page
//*******************************************

void movie::login_page_display()
{
    cout<<"\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t"<<"***********"<<"\t\t"<<"*************"<<endl;
    cout<<"\t\t\t\t\t"<<"*  LOGIN  *"<<"\t\t"<<"*  SIGN_IN  *"<<endl;
    cout<<"\t\t\t\t\t"<<"***********"<<"\t\t"<<"*************"<<endl;

}
int movie::login_page()
{
    int x=35;
    int y=10;
    login_page_display();
    gotoxy(x,y);
    cout<<arrow_rigth;
    while(1)
    {
            move_arrow=getch();
            if(move_arrow!=13)
            move_arrow=getch();

    if(move_arrow==77)
    {
           Beep(750,200);
        x+=25;
        if(x<85)
        {
                system("cls");
                login_page_display();
                gotoxy(x,y);
                cout<<arrow_rigth;
        }else
        {
                x-=25;
        }

    }else if(move_arrow==75)
    {
           Beep(750,200);
        x-=25;
        if(x>10)
        {
                system("cls");
                login_page_display();
                gotoxy(x,y);
                cout<<arrow_rigth;
        }else
        {
            x+=25;
        }


    }else if(move_arrow==13)
            {
                break;
            }


    }
    return x;
    gotoxy(0,20);

}


//********************************************
//*   login  page
//*******************************************

void movie:: login_window_display()
{
    cout<<"\n\n\n";
    cout<<"\t\t\t********************************************************************"<<endl;
    cout<<"\t\t\t*                        MOVIE-MANIA                               *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*    SIGN IN                                                       *"<<endl;
    cout<<"\t\t\t*    to continue to movie mania                                    *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*    ENTER YOUR EMAIL-ID                                           *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*    _____________________________________________________         *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                           THEN PRESS ENTER       *"<<endl;
    cout<<"\t\t\t*                                             to proceed           *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t********************************************************************"<<endl;
}
void movie:: password_page_display()
{
    cout<<"\n\n\n";
    cout<<"\t\t\t********************************************************************"<<endl;
    cout<<"\t\t\t*                        MOVIE-MANIA                               *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*    WELCOME                                                       *"<<endl;
    cout<<"\t\t\t*    "<<email_id<<"                                                "<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*    ENTER YOUR PASWORD                                            *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*    _____________________________________________________         *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                           THEN PRESS ENTER       *"<<endl;
    cout<<"\t\t\t*                                             to proceed           *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*   press esc for backspace                                        *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t*                                                                  *"<<endl;
    cout<<"\t\t\t********************************************************************"<<endl;

}
int movie ::login_window()
{
    ifstream infile;
    infile.open("login_email_id.txt");
    char email_id_check[30];
    char password_check[20];
    char input,read_char;
    int i=0,j,flag=0,pass;
    a:
    system("cls");
    login_window_display();
    gotoxy(30,13);
    gets(email_id);

    infile.seekg(0);
    while(!infile.eof())
    {
                    infile>>email_id_check;

                    if(strcmp(email_id_check,email_id)==0)
                    {

                        flag=0;
                        break;

                    }else
                    {

                        flag=1;
                    }
                    if(infile.eof()!=0)
                        break;
    }
        infile.close();

    if(flag==0)
    {
            Sleep(400);
            gotoxy(30,16);
            cout<<"LOADING";
            for(i=0;i<5;i++)
            {
                cout<<".";
                Sleep(100);
            }

            again:
            system("cls");
            password_page_display();
            i=0;
            gotoxy(30,13);
            while(1)
            {
                input=getch();
                if(input==27)
                {
                    flag=1;
                    break;
                }

                cout<<"*";

                if(input!=13)
                {
                    password[i]=input;
                    i++;

                }else
                {
                    break;
                }
            }
            if(flag==1)
            {
                flag=0;
                goto again;
            }
             ifstream infile;
            infile.open("login_password.txt");


            int k=0;
          while(!infile.eof())
            {


                for(j=0;j<i;j++)
                {
                    infile>>pass;

                    if(pass!=13)
                    password_check[j]=pass;
                    else
                        break;

                }
                if(strcmp(password_check,password)==0)
                {
                    flag=0;
                    break;
                }else
                {
                    flag=1;
                    k++;
                    infile.seekg(k);

                }if(infile.eof()==0)
                break;
            }
            return 0;

}else
{
    char in;
    cout<<"NO EMAIL ID FOUND TRY AGAIN "<<endl;
    cout<<"press enter to continue or esc to goto sign page"<<endl;
    in=getch();
    if(in==13)
    {
        goto a;
    }else if(in==27)
    {
        return 1;
    }
}



}

//********************************************
//*   sign in function
//*******************************************

void movie::signup_window_display()
{
    gotoxy(10,3);
    cout<<"MOVIE MANIA\n\n";
    cout<<"-----------------------------------------------------------------------------------------------------------------------\n\n\n";
    gotoxy(40,7);
    cout<<"CREATE YOUR ACCOUNT ON MOVIE MANIA";
    gotoxy(10,9);
    cout<<"NAME";
    gotoxy(10,10);
    cout<<"FIRST NAME";
    gotoxy(8,11);
    cout<<"----------------------------------------";
    gotoxy(8,12);
    cout<<"|                                      |";
    gotoxy(8,13);
    cout<<"----------------------------------------";
    gotoxy(60,10);
    cout<<"LAST NAME";
    gotoxy(60,11);
    cout<<"----------------------------------------";
    gotoxy(60,12);
    cout<<"|                                      |";
    gotoxy(60,13);
    cout<<"----------------------------------------";
    gotoxy(10,15);
    cout<<"ENTER YOUR EMAIL ID";
    gotoxy(8,16);
    cout<<"-------------------------------------------------------------------------------------";
    gotoxy(8,17);
    cout<<"|                                                                                   |";
    gotoxy(8,18);
    cout<<"-------------------------------------------------------------------------------------";

    gotoxy(10,19);
    cout<<"ENTER YOUR PASSWORD";
    gotoxy(8,20);
    cout<<"----------------------------------------------------";
    gotoxy(8,21);
    cout<<"|                                                  |";
    gotoxy(8,22);
    cout<<"----------------------------------------------------";
    gotoxy(10,23);
    cout<<"CONFIRM YOUR PASSWORD";
    gotoxy(8,24);
    cout<<"----------------------------------------------------";
    gotoxy(8,25);
    cout<<"|                                                  |";
    gotoxy(8,26);
    cout<<"----------------------------------------------------";

}
int movie :: signup_window()
{
    int i=0,flag=0;

    signup_window_display();
    gotoxy(10,12);
    gets(first_name);
    gotoxy(62,12);
    gets(last_name);
    gotoxy(10,17);
    gets(email_id);
    again:


    i=0;
    gotoxy(10,21);
    fflush(stdin);
    while(1)
    {
        move_arrow=getch();

        if(move_arrow!=13)
        {
            cout<<"*";
            password[i]=move_arrow;
              i++;


        }else
        {
            i--;
            break;
        }

    }


    if(i<7)
    {
        gotoxy(60,22);
        cout<<"PASSWORD IS TO SHORT";
        Sleep(1000);

        system("cls");
        signup_window_display();
        gotoxy(10,12);
        puts(first_name);
        gotoxy(62,12);
        puts(last_name);
        gotoxy(10,17);
        puts(email_id);
        goto again;
    }
    again2:
        //fflush(stdin);
   int j=0;
    gotoxy(10,25);
    while(1)
    {

        move_arrow=getch();

        if(move_arrow!=13)
        {
                cout<<"*";
                password2[j]=move_arrow;
                j++;
        }else
        {
           j--;
            break;
        }


    }
    if(i!=j)
    {   a1:
        gotoxy(60,26);
        cout<<"PASSWORD DOES NOT MATCH !! TRY AGAIN";
        Sleep(1000);

        system("cls");
        signup_window_display();
        gotoxy(10,12);
        puts(first_name);
        gotoxy(62,12);
        puts(last_name);
        gotoxy(10,17);
        puts(email_id);
        gotoxy(10,21);



        for(int index=0;index<i;index++)
            cout<<"*";

        goto again2;

    }else
    {
                for(int i=0;i<j;i++)
                {
                    if(password2[i]!=password[i])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                {
                    goto a1;
                }
    }

    fstream fout;
    fout.open("sign.txt",ios::app);
    fout<<"First name:"<<first_name<<endl;
    fout<<"Last name:"<<last_name<<endl;
    fout<<"Email Id:"<<email_id<<endl;
    fout<<"password:"<<endl;
    for(i=0;i<=j;i++)
    {
            fout<<password[i]<<endl;
    }

    fout<<endl;
    fout.close();
    fstream fout1;
    fout1.open("login_email_id.txt",ios::app);
    fout1<<email_id<<endl;
    fout1.close();
    fstream fout2;
    fout2.open("login_password.txt",ios::app);
    for(int index=0;index<i;index++)
    {
            fout2<<password[index]<<" ";
    }

    fout2<<endl;
    fout2.close();
    return 0;


}
//********************************************
//*   menu or list of option
//*******************************************
void movie::display_menu()
{

    cout<<"\n\n\n\n";
    cout<<"\t\t\t\t=================== MENU ================="<<endl;
    cout<<"\t\t\t\t||                                     ||"<<endl;
    cout<<"\t\t\t\t||                                     ||"<<endl;
    cout<<"\t\t\t\t||          1) BOOK TICKET             ||"<<endl;
    cout<<"\t\t\t\t||          2) CANCEL TICKET           ||"<<endl;
    cout<<"\t\t\t\t||          3) LOGOUT                  ||"<<endl;
    cout<<"\t\t\t\t||                                     ||"<<endl;
    cout<<"\t\t\t\t||                                     ||"<<endl;
    cout<<"\t\t\t\t========================================="<<endl;

}
//********************************************
//*   menu or list of option
//*******************************************

int movie::menu()
{
    x=40;
    y=7;

    display_menu();
    gotoxy(x,y);
    cout<<arrow_rigth;

    while(1)
    {
            move_arrow=getch();
            if(move_arrow!=13)
            move_arrow=getch();

            if(move_arrow==72)
            {
                    Beep(750,200);
                    y--;
                    if(y>=7)
                    {
                            system("cls");
                            display_menu();
                            gotoxy(x,y);
                            cout<<arrow_rigth;
                    }else
                    {
                        y++;
                    }

            }else if(move_arrow==80)
                    {
                         Beep(750,200);
                        y++;
                        if(y<=9)
                        {
                                system("cls");
                                display_menu();
                                gotoxy(x,y);
                                cout<<arrow_rigth;

                        }else
                        {
                            y--;
                        }

                    }else if(move_arrow==13)
                            {
                                    break;
                            }

                gotoxy(0,20);

    }
        return y;

}
//********************************************
//*   displaying theatre
//*******************************************


void movie :: display_theatre()
{

        cout<<"\n\n";
        cout<<"\t\t\t\t  **********************************************"<<endl;
        cout<<"\t\t\t\t  *                                            *"<<endl;
        cout<<"\t\t\t\t  *   SELECT THE THEATRE FROM THE GIVEN LIST   *"<<endl;
        cout<<"\t\t\t\t  *                                            *"<<endl;
        cout<<"\t\t\t\t  **********************************************"<<endl;
        cout<<"\n\n\n";


        cout<<"\t\t\t\t\t1) PVR CINEMA\n"<<endl;
        cout<<"\t\t\t\t\t2) GALAXY THEARTRE\n"<<endl;
        cout<<"\t\t\t\t\t3) OM CINEPLEX\n"<<endl;
        cout<<"\t\t\t\t\t4) VINAY CINEMA\n"<<endl;
        cout<<"\t\t\t\t\t5) DBZ CINEMA\n"<<endl;


}
int movie :: theatre()
{
        x=35;
        y=10;

        display_theatre();
        gotoxy(x,y);
        cout<<arrow_rigth;
        while(1)
        {
                move_arrow=getch();
                if(move_arrow!=13)
                move_arrow=getch();


                if(move_arrow==72)
                {
                    Beep(750,200);
                    y-=2;
                    if(y>=10)
                    {
                        system("cls");
                        display_theatre();
                        gotoxy(x,y);
                        cout<<arrow_rigth;

                    }else
                    {
                        y+=2;
                    }
                }else if(move_arrow==80)
                {
                     Beep(750,200);
                    y+=2;
                    if(y<=18)
                    {
                        system("cls");
                        display_theatre();
                        gotoxy(x,y);
                        cout<<arrow_rigth;

                    }else
                    {
                        y-=2;
                    }
                }else if(move_arrow==13)
                {
                     Beep(750,200);
                    break;
                }
                gotoxy(0,20);

        }

        return y;


}
//********************************************
//*   display movie list
//*******************************************

void movie::movie_list_display()
{
        cout<<"\n";
        cout<<"\t\t\t\t  **********************************************"<<endl;
        cout<<"\t\t\t\t                                                "<<endl;
        cout<<"\t\t\t\t          WELCOME TO "<<theatre_name<<"         "<<endl;
        cout<<"\t\t\t\t                                                "<<endl;
        cout<<"\t\t\t\t  **********************************************"<<endl;
        cout<<"\n";
        cout<<"\t\t\t\t\t1) GOLMAAL AGAIN\n"<<endl;
        cout<<"\t\t\t\t\t2) THOR REGNAROK(ENGLISH)\n"<<endl;
        cout<<"\t\t\t\t\t3) SECRET SUPERSTAR\n"<<endl;
        cout<<"\t\t\t\t\t4) KINGS MAN GOLDEN CIRCLE(ENGLISH)\n"<<endl;
        cout<<"\t\t\t\t\t5) JUNGLE\n"<<endl;
}
int movie::movie_list(int option)
{

    x=35;
    y=7;
    movie_list_display();
    gotoxy(x,y);
        cout<<arrow_rigth;
        while(1)
        {
                move_arrow=getch();
                if(move_arrow!=13)
                move_arrow=getch();

                if(move_arrow==72)
                {
                     Beep(750,200);
                    y-=2;
                    if(y>=7)
                    {
                        system("cls");
                        movie_list_display();
                        gotoxy(x,y);
                        cout<<arrow_rigth;

                    }else
                    {
                        y+=2;
                    }
                }else if(move_arrow==80)
                {
                     Beep(750,200);
                    y+=2;
                    if(y<=15)
                    {
                        system("cls");
                        movie_list_display();
                        gotoxy(x,y);
                        cout<<arrow_rigth;

                    }else
                    {
                        y-=2;
                    }
                }else if(move_arrow==13)
                {
                    Beep(750,200);
                    break;
                }
                gotoxy(0,20);

        }

        return y;

}
//********************************************
//*   display timing of movie
//*******************************************

void movie::timing_of_movie_display(int option)
{
        cout<<"\n";
        cout<<"\t\t\t\t  **********************************************"<<endl;
        cout<<"\t\t\t\t                                                "<<endl;
        cout<<"\t\t\t\t            SO HERE ARE THE TIMING              "<<endl;
        cout<<"\t\t\t\t                                                "<<endl;
        cout<<"\t\t\t\t  **********************************************"<<endl;
        cout<<"\n";
        cout<<"\t\t\t\t\t1) GOLMAAL AGAIN\n"<<endl;
        if(option==7)
        {
            cout<<"\t\t\t\t\t|-> 8:30 am to 11:30\n"<<endl;
            cout<<"\t\t\t\t\t|-> 11:45 pm to 2:45 pm\n"<<endl;
            cout<<"\t\t\t\t\t|-> 3:00 pm to 5:15 pm\n"<<endl;
            cout<<"\t\t\t\t\t|-> 5:30 pm to 7:30 pm\n"<<endl;
            cout<<"\t\t\t\t\t|-> 7:45 pm to 9:45 pm\n"<<endl;
        }
        cout<<"\t\t\t\t\t2) THOR REGNAROK(ENGLISH)\n"<<endl;
        if(option==9)
        {
            cout<<"\t\t\t\t\t|-> 8:30 am to 11:30\n"<<endl;
            cout<<"\t\t\t\t\t|-> 11:45 pm to 2:45 pm\n"<<endl;
            cout<<"\t\t\t\t\t|-> 3:00 pm to 5:15 pm\n"<<endl;
            cout<<"\t\t\t\t\t|-> 5:30 pm to 7:30 pm\n"<<endl;
            cout<<"\t\t\t\t\t|-> 7:45 pm to 9:45 pm\n"<<endl;

        }

        cout<<"\t\t\t\t\t3) SECRET SUPERSTAR\n"<<endl;
        if(option==11)
        {
            cout<<"\t\t\t\t\t|-> 8:30 am to 11:30\n"<<endl;
            cout<<"\t\t\t\t\t|-> 11:45 pm to 2:45 pm\n"<<endl;
            cout<<"\t\t\t\t\t|-> 3:00 pm to 5:15 pm\n"<<endl;
            cout<<"\t\t\t\t\t|-> 5:30 pm to 7:30 pm\n"<<endl;
            cout<<"\t\t\t\t\t|-> 7:45 pm to 9:45 pm\n"<<endl;

        }
        cout<<"\t\t\t\t\t4) KINGS MAN GOLDEN CIRCLE(ENGLISH)\n"<<endl;
        if(option==13)
        {
            cout<<"\t\t\t\t\t|-> 8:30 am to 11:30\n"<<endl;
            cout<<"\t\t\t\t\t|-> 11:45 pm to 2:45 pm\n"<<endl;
            cout<<"\t\t\t\t\t|-> 3:00 pm to 5:15 pm\n"<<endl;
            cout<<"\t\t\t\t\t|-> 5:30 pm to 7:30 pm\n"<<endl;
            cout<<"\t\t\t\t\t|-> 7:45 pm to 9:45 pm\n"<<endl;
        }
        cout<<"\t\t\t\t\t5) JUNGLE\n"<<endl;
        if(option==15)
        {
            cout<<"\t\t\t\t\t|-> 8:30 am to 11:30\n"<<endl;
            cout<<"\t\t\t\t\t|-> 11:45 pm to 2:45 pm\n"<<endl;
            cout<<"\t\t\t\t\t|-> 3:00 pm to 5:15 pm\n"<<endl;
            cout<<"\t\t\t\t\t|-> 5:30 pm to 7:30 pm\n"<<endl;
            cout<<"\t\t\t\t\t|-> 7:45 pm to 9:45 pm\n"<<endl;

        }
        cout<<endl;
        cout<<"\t\t\t SELECT THE TIMING OF THE MOVIE"<<endl;

}
void movie::timing_of_movie(int option)
{

    switch(option)
            {
                    case 7:
                        x=35;
                        y=9;
                        gotoxy(x ,y);
                        cout<<arrow_rigth;
                        while(1)
                        {
                                move_arrow=getch();
                                if(move_arrow!=13)
                                move_arrow=getch();
                                if(move_arrow==72)
                                {
                                         Beep(750,200);
                                        y-=2;
                                        if(y>=9)
                                        {
                                            system("cls");
                                            timing_of_movie_display(7);
                                            gotoxy(x,y);
                                            cout<<arrow_rigth;

                                        }else
                                        {
                                                y+=2;
                                        }
                                }else if(move_arrow==80)
                                {
                                         Beep(750,200);
                                                y+=2;
                                        if(y<=17)
                                        {
                                            system("cls");
                                            timing_of_movie_display(7);
                                            gotoxy(x,y);
                                            cout<<arrow_rigth;

                                        }else
                                        {
                                            y-=2;
                                        }
                                }else if(move_arrow==13)
                                {
                                        if(y==9)
                                        {
                                            strcpy(timeofmovie_file,"8_");
                                            strcpy(timeofmovie,"8:30 am to 11:30");
                                        }else if(y==11)
                                        {
                                            strcpy(timeofmovie,"11:45 pm to 2:45");
                                             strcpy(timeofmovie_file,"11_");
                                        }
                                        }else if(y==13)
                                        {
                                              strcpy(timeofmovie_file,"3_");
                                             strcpy(timeofmovie,"3:00 pm to 5:15 pm");
                                        }else if(y==15)
                                        {
                                             strcpy(timeofmovie,"5:30 pm to 7:30 pm");
                                               strcpy(timeofmovie_file,"5_");

                                        }else if(y==17)
                                        {
                                             strcpy(timeofmovie," 7:45 pm to 9:45 pm");
                                               strcpy(timeofmovie_file,"7_");

                                        }
                                        Beep(750,200);
                                        break;
                                }
                                        gotoxy(0,30);


                        break;
                    case 9:
                        x=35;
                        y=11;
                        gotoxy(x,y);
                        cout<<arrow_rigth;
                        while(1)
                        {
                                move_arrow=getch();
                                if(move_arrow!=13)
                                move_arrow=getch();

                                if(move_arrow==72)
                                {
                                        Beep(750,200);
                                        y-=2;
                                        if(y>=9)
                                        {
                                            system("cls");
                                            timing_of_movie_display(9);
                                            gotoxy(x,y);
                                            cout<<arrow_rigth;

                                        }else
                                        {
                                                y+=2;
                                        }
                                }else if(move_arrow==80)
                                {
                                        Beep(750,200);
                                                 y+=2;
                                        if(y<=17)
                                        {
                                            system("cls");
                                            timing_of_movie_display(9);
                                            gotoxy(x,y);
                                            cout<<arrow_rigth;

                                        }else
                                        {
                                            y-=2;
                                        }
                                }else if(move_arrow==13)
                                {
                                         if(y==9)
                                        {
                                            strcpy(timeofmovie,"8:30 am to 11:30 pm");
                                              strcpy(timeofmovie_file,"8_");
                                        }else if(y==11)
                                        {
                                            strcpy(timeofmovie,"11:45 pm to 2:45 pm");
                                              strcpy(timeofmovie_file,"11_");
                                        }
                                        }else if(y==13)
                                        {
                                             strcpy(timeofmovie," 3:00 pm to 5:15 pm");
                                               strcpy(timeofmovie_file,"3_");
                                        }else if(y==15)
                                        {
                                             strcpy(timeofmovie,"5:30 pm to 7:30 pm");
                                               strcpy(timeofmovie_file,"5_");

                                        }else if(y==17)
                                        {
                                             strcpy(timeofmovie," 7:45 pm to 9:45 pm");
                                               strcpy(timeofmovie_file,"7_");

                                        }


                                         Beep(750,200);
                                        break;
                                }
                                        gotoxy(0,30);


                        break;
                    case 11:
                            x=35;
                            y=13;
                            gotoxy(x,y);
                            cout<<arrow_rigth;
                            while(1)
                        {
                                move_arrow=getch();
                                if(move_arrow!=13)
                                move_arrow=getch();

                                if(move_arrow==72)
                                {
                                        Beep(750,200);
                                        y-=2;
                                        if(y>=13)
                                        {
                                            system("cls");
                                            timing_of_movie_display(11);
                                            gotoxy(x,y);
                                            cout<<arrow_rigth;

                                        }else
                                        {
                                                y+=2;
                                        }
                                }else if(move_arrow==80)
                                {
                                                Beep(750,200);
                                                y+=2;
                                        if(y<=21)
                                        {
                                            system("cls");
                                            timing_of_movie_display(11);
                                            gotoxy(x,y);
                                            cout<<arrow_rigth;

                                        }else
                                        {
                                            y-=2;
                                        }
                                }else if(move_arrow==13)
                                {
                                        if(y==13)
                                        {
                                            strcpy(timeofmovie,"8:30 am to 11:30 pm");
                                              strcpy(timeofmovie_file,"8_");
                                        }else if(y==15)
                                        {
                                            strcpy(timeofmovie," 11:45 pm to 2:45 pm");
                                              strcpy(timeofmovie_file,"11_");
                                        }
                                        }else if(y==17)
                                        {
                                             strcpy(timeofmovie,"3:00 pm to 5:15 pm");
                                               strcpy(timeofmovie_file,"3_");
                                        }else if(y==19)
                                        {
                                             strcpy(timeofmovie,"5:30 pm to 7:30 pm");
                                               strcpy(timeofmovie_file,"5_");

                                        }else if(y==21)
                                        {
                                             strcpy(timeofmovie," 7:45 pm to 9:45 pm");
                                               strcpy(timeofmovie_file,"7_");

                                        }
                                        Beep(750,200);
                                        break;
                                }
                                        gotoxy(0,30);


                        break;


                    case 13:
                        x=35;
                        y=15;
                        gotoxy(x,y);
                        cout<<arrow_rigth;
                        while(1)
                        {
                                move_arrow=getch();
                               if(move_arrow!=13)
                                move_arrow=getch();
                                if(move_arrow==72)
                                {
                                        Beep(750,200);
                                        y-=2;
                                        if(y>=15)
                                        {
                                            system("cls");
                                            timing_of_movie_display(13);
                                            gotoxy(x,y);
                                            cout<<arrow_rigth;

                                        }else
                                        {
                                                y+=2;
                                        }
                                }else if(move_arrow==80)
                                {
                                                Beep(750,200);
                                                y+=2;
                                        if(y<=23)
                                        {
                                            system("cls");
                                            timing_of_movie_display(13);
                                            gotoxy(x,y);
                                            cout<<arrow_rigth;

                                        }else
                                        {
                                            y-=2;
                                        }
                                }else if(move_arrow==13)
                                {
                                        if(y==15)
                                        {
                                            strcpy(timeofmovie,"8:30 am to 11:30 pm");
                                              strcpy(timeofmovie_file,"8_");
                                        }else if(y==17)
                                        {
                                            strcpy(timeofmovie," 11:45 pm to 2:45 pm");
                                              strcpy(timeofmovie_file,"11_");
                                        }
                                        }else if(y==19)
                                        {
                                             strcpy(timeofmovie," 3:00 pm to 5:15 pm");
                                               strcpy(timeofmovie_file,"3_");
                                        }else if(y==21)
                                        {
                                             strcpy(timeofmovie,"5:30 pm to 7:30 pm");
                                               strcpy(timeofmovie_file,"5_");

                                        }else if(y==23)
                                        {
                                             strcpy(timeofmovie," 7:45 pm to 9:45 pm");
                                               strcpy(timeofmovie_file,"7_");

                                        }
                                        Beep(750,200);
                                        break;
                                }
                                        gotoxy(0,30);


                        break;


                    case 15:
                        x=35;
                        y=17;
                        gotoxy(x,y);
                        cout<<"-->";
                        while(1)
                        {
                                move_arrow=getch();
                                if(move_arrow!=13)
                                move_arrow=getch();
                                if(move_arrow==72)
                                {
                                         Beep(750,200);
                                        y-=2;
                                        if(y>=17)
                                        {
                                            system("cls");
                                            timing_of_movie_display(15);
                                            gotoxy(x,y);
                                            cout<<arrow_rigth;

                                        }else
                                        {
                                                y+=2;
                                        }
                                }else if(move_arrow==80)
                                {
                                            Beep(750,200);
                                                y+=2;
                                        if(y<=25)
                                        {
                                            system("cls");
                                            timing_of_movie_display(15);
                                            gotoxy(x,y);
                                            cout<<arrow_rigth;

                                        }else
                                        {
                                            y-=2;
                                        }
                                }else if(move_arrow==13)
                                {
                                        if(y==17)
                                        {
                                            strcpy(timeofmovie,"8:30 am to 11:30 pm");
                                              strcpy(timeofmovie_file,"8_");
                                        }else if(y==19)
                                        {
                                            strcpy(timeofmovie," 11:45 pm to 2:45 pm");
                                              strcpy(timeofmovie_file,"11_");
                                        }
                                        }else if(y==21)
                                        {
                                             strcpy(timeofmovie," 3:00 pm to 5:15 pm");
                                               strcpy(timeofmovie_file,"3_");
                                        }else if(y==23)
                                        {
                                             strcpy(timeofmovie,"5:30 pm to 7:30 pm");
                                               strcpy(timeofmovie_file,"5_");

                                        }else if(y==25)
                                        {
                                             strcpy(timeofmovie," 7:45 pm to 9:45 pm");
                                               strcpy(timeofmovie_file,"7_");

                                        }
                                        Beep(750,200);
                                        break;
                                }
                                        gotoxy(0,30);


                        break;


            }


}
//********************************************
//*   for booking seats
//*******************************************
void movie:: display_seat(int x_1,int y_1)
{
    int i,j,m,n=0,count_no=0;
    int xp,yp;
    int flag=0;
    char s=65;

    for(i=0;i<index-1;i++)
    {
        gotoxy(xbook[i],ybook[i]);
        cout<<"XX";

    }
    gotoxy(0,0);


    for(i=1;i<=3;i++)
    {
        if(i==1)
        {
            cout<<"\t\t\t.........................PLATINUM..............................\n\n";
        }else if(i==2)
        {
            cout<<"\t\t\t..........................GOLD..............................\n\n";
        }else if(i==3)
        {
            cout<<"\t\t\t.........................SILVER..............................\n\n";
        }

        for(j=1;j<=3;j++)
        {
            cout<<"\t"<<s<<"\t";
            for(m=1;m<=10;m++)
            {
                cout<<"[ ";

                xp=wherex();
                yp=wherey();
                    if(xp==x_1 && yp==y_1)
                    {
                                    xbook[k]=x_1;
                                    ybook[k]=y_1;
                                    seatno[q]=a[n];
                                    q++;
                                    k++;
                    }

                cout<<a[n];
                cout<<" ]\t";
                n++;
            }
            s++;
            cout<<endl;
        }
        cout<<endl;
    }



        if(x_1==-1 && y_1==-1)
        {
               k--;
        }
                            for(i=0;i<k-1;i++)
                            {
                                if(x_1==xbook[i] && y_1==ybook[i])
                                {
                                    flag=1;
                                    k--;
                                    q--;
                                     cntseat--;
                                    break;
                                }
                            }
                            if(flag==0)
                            {

                                        for(i=0;i<k;i++)
                                        {
                                                x_1=xbook[i];
                                                y_1=ybook[i];
                                                gotoxy(x_1,y_1);
                                                cout<<"XX";
                                        }
                                        gotoxy(0,25);
                                        cout<<"booked seats are:";
                                        for(i=0;i<q;i++)
                                        {
                                            cout<<seatno[i]<<",";
                                        }
                            }else
                            {
                                gotoxy(0,27);
                                cout<<"SORRY CANNOT BOOK THIS TICKET";
                            }


}

int movie::seat()
{

        ifstream infile;

        infile.open(filename,ios::in);
        if(infile!=NULL)
        {



            while(!infile.eof())
                {
                    infile>>seatno[index]>>x_book_file[index]>>y_book_file[index];
                    index++;
                }
                infile.close();
                for(int i=0;i<index-1;i++)
                {
                    xbook[i]=x_book_file[i];
                    ybook[i]=y_book_file[i];
                    k++;

                }

        }
    infile.close();


        int a[2];
        gotoxy(40,10);
        cout<<"how many seats you wanna book:";
        cin>>how_many_seats;
        p1:
        x=90;
        y=0;

        system("cls");
        display_seat(0,0);

        gotoxy(x,y);
        cout<<"<--";
        while(1)
        {
                move_arrow=getch();
                if(move_arrow!=13)
                move_arrow=getch();

                if(move_arrow==80)
                {
                        Beep(750,200);
                        y+=6;
                        if(y<=12)
                        {
                                system("cls");
                                display_seat(0,0);
                                gotoxy(x,y);
                                cout<<"<--";
                        }else
                        {
                                y-=6;
                        }

                }else if(move_arrow==72)
                {
                        Beep(750,200);
                        y-=6;
                        if(y>=0)
                        {
                                system("cls");
                                display_seat(0,0);
                                gotoxy(x,y);
                                cout<<"<--";
                        }else
                        {
                                y+=6;
                        }

                }else if(move_arrow==13)
                {
                    Beep(750,200);

                    if(y==0)            //for platinum
                    {
                        selected=1;
                        x=18;
                        y=2;
                        system("cls");
                        display_seat(0,0);
                        gotoxy(x,y);
                        cout<<"X";
                        while(1)
                        {
                            move_arrow=getch();
                             if(move_arrow!=13)
                                move_arrow=getch();

                            if(move_arrow==72)
                            {
                                 Beep(750,200);
                                y--;
                                if(y>=2)
                                {
                                        system("cls");
                                        display_seat(0,0);
                                        gotoxy(x,y);
                                        cout<<"X";
                                }else
                                {
                                        y++;
                                }
                            }else if(move_arrow==80)
                            {
                                  Beep(750,200);
                                y++;
                                if(y<=4)
                                {
                                        system("cls");
                                        display_seat(0,0);
                                        gotoxy(x,y);
                                        cout<<"X";
                                }else
                                {
                                        y--;
                                }
                            }else if(move_arrow==77)
                            {
                                  Beep(750,200);
                                x+=8;
                                if(x<=90)
                                {
                                        system("cls");
                                        display_seat(0,0);
                                        gotoxy(x,y);
                                        cout<<"X";
                                }else
                                {
                                        x-=8;
                                }
                            }else if(move_arrow==75)
                            {
                                  Beep(750,200);
                                x-=8;
                                if(x>=18)
                                {
                                        system("cls");
                                        display_seat(0,0);
                                        gotoxy(x,y);
                                        cout<<"X";
                                }else
                                {
                                        x+=8;
                                }
                            }else if(move_arrow==13)
                            {
                                     Beep(750,200);


                                    system("cls");
                                    display_seat(x,y);
                                 cntseat++;
                                    if(cntseat==how_many_seats)
                                    {

                                       gotoxy(0,25);
                                       cout<<"ARE YOU SURE YOU WANNA BOOK THESE SEATS:";
                                       move_arrow=getch();
                                       if(move_arrow==13)
                                       {
                                           break;
                                       }

                                        system("cls");

                                    }
                            }else if(move_arrow==8)
                            {
                                system("cls");
                                display_seat(-1,-1);
                                cntseat--;
                                if(cntseat==-1)
                                {
                                    goto p1;
                                }
                            }


                        }
                    }else if(y==6)      //for gold
                    {
                        selected=2;
                        x=18;
                        y=8;
                        system("cls");
                        display_seat(0,0);
                        gotoxy(x,y);
                        cout<<"X";
                        while(1)
                        {
                            move_arrow=getch();
                             if(move_arrow!=13)
                                move_arrow=getch();

                            if(move_arrow==72)
                            {
                                  Beep(750,200);
                                y--;
                                if(y>=8)
                                {
                                        system("cls");
                                        display_seat(0,0);
                                        gotoxy(x,y);
                                        cout<<"X";
                                }else
                                {
                                        y++;
                                }
                            }else if(move_arrow==80)
                            {
                                 Beep(750,200);
                                    y++;
                                if(y<=10)
                                {
                                        system("cls");
                                        display_seat(0,0);
                                        gotoxy(x,y);
                                        cout<<"X";
                                }else
                                {
                                        y--;
                                }
                            }else if(move_arrow==77)
                            {
                                 Beep(750,200);
                                x+=8;
                                if(x<=90)
                                {
                                        system("cls");
                                        display_seat(0,0);
                                        gotoxy(x,y);
                                        cout<<"X";
                                }else
                                {
                                        x-=8;
                                }
                            }else if(move_arrow==75)
                            {
                                Beep(750,200);
                                x-=8;
                                if(x>=18)
                                {
                                        system("cls");
                                        display_seat(0,0);
                                        gotoxy(x,y);
                                        cout<<"X";
                                }else
                                {
                                        x+=8;
                                }
                            }else if(move_arrow==13)
                            {

                                    system("cls");
                                    display_seat(x,y);
                                     cntseat++;
                                    if(cntseat==how_many_seats)
                                    {

                                       gotoxy(0,25);
                                       cout<<"ARE YOU SURE YOU WANNA BOOK THESE SEATS:";
                                       move_arrow=getch();
                                       if(move_arrow==13)
                                       {
                                           break;
                                       }

                                        system("cls");

                                    }
                            }else if(move_arrow==8)
                            {
                                system("cls");
                                display_seat(-1,-1);
                                cntseat--;
                            }

                        }

                    }else if(y==12)     //for silver
                    {
                       selected=3;
                        x=18;
                        y=14;
                        system("cls");
                        display_seat(0,0);
                        gotoxy(x,y);
                        cout<<"X";
                        while(1)
                        {
                            move_arrow=getch();
                             if(move_arrow!=13)
                                move_arrow=getch();

                            if(move_arrow==72)
                            {
                                 Beep(750,200);
                                y--;
                                if(y>=14)
                                {
                                        system("cls");
                                        display_seat(0,0);
                                        gotoxy(x,y);
                                        cout<<"X";
                                }else
                                {
                                        y++;
                                }
                            }else if(move_arrow==80)
                            {
                                 Beep(750,200);
                                y++;
                                if(y<=16)
                                {
                                        system("cls");
                                        display_seat(0,0);
                                        gotoxy(x,y);
                                        cout<<"X";
                                }else
                                {
                                        y--;
                                }
                            }else if(move_arrow==77)
                            {
                                 Beep(750,200);
                                x+=8;
                                if(x<=90)
                                {
                                        system("cls");
                                        display_seat(0,0);
                                        gotoxy(x,y);
                                        cout<<"X";
                                }else
                                {
                                        x-=8;
                                }
                            }else if(move_arrow==75)
                            {
                                 Beep(750,200);
                                x-=8;
                                if(x>=18)
                                {
                                        system("cls");
                                        display_seat(0,0);
                                        gotoxy(x,y);
                                        cout<<"X";
                                }else
                                {
                                        x+=8;
                                }
                            }else if(move_arrow==13)
                            {

                                    Beep(750,200);
                                    system("cls");
                                    display_seat(x,y);
                                     cntseat++;
                                    if(cntseat==how_many_seats)
                                    {

                                       gotoxy(0,25);
                                       cout<<"ARE YOU SURE YOU WANNA BOOK THESE SEATS:";
                                       move_arrow=getch();
                                       if(move_arrow==13)
                                       {
                                           break;
                                       }

                                        system("cls");

                                    }
                            }else if(move_arrow==8)
                            {
                                system("cls");
                                display_seat(-1,-1);
                                cntseat--;
                            }

                        }

                    }
                }
                            if(cntseat==how_many_seats)
                            {
                                           system("cls");
                                           gotoxy(40,10);
                                           cout<<"THANK YOU YOUR SEATS HAVE BEEN BOOKED"<<endl;
                                                system("pause");
                                            ofstream fout;
                                            fout.open(filename,ios::app);



                                            for(int i=0;i<k;i++)
                                            {
                                                    fout<<seatno[i]<<" "<<xbook[i]<<" "<<ybook[i]<<endl;
                                            }
                                                fout.close();

                                                biling_display();

                                           Sleep(1000);
                                           break;
                            }

                                gotoxy(0,20);
        }

}
//********************************************
//*   BILLING PART
//*******************************************
void movie :: biling_display()
{
    system("cls");
    int i,bill_no;

    srand(time(NULL));
    bill_no=rand()%65000;

    char ch=178;
    gotoxy(20,5);
    for(i=0;i<80;i++)
        cout<<ch;
    gotoxy(50,7);
    cout<<"BILL OF TICKET";
    gotoxy(50,8);
    if(selected==1)
    {
        cout<<"P L A T I N U M";
        price=200;
    }else if(selected==2)
    {
        cout<<"G O L D";
        price=150;
    }else if(selected==3)
    {
        cout<<"S I L V E R";
        price=100;
    }
    gotoxy(30,9);
    cout<<"S E A T NO :  ";
    for(i=0;i<q;i++)
    cout<<seatno[i]<<",";
    gotoxy(30,11);
    cout<<"T O T A L NO OF S E A T S :  "<<how_many_seats;
    gotoxy(30,13);
    price=price*how_many_seats;
    cout<<"P R I C E :  "<<price;
    gotoxy(30,15);
    cout<<"B I L L NO :  "<<bill_no;
    gotoxy(30,17);
    cout<<"T I M I N G OF M O V I E:"<<timeofmovie;
    gotoxy(30,19);
    cout<<"N A M E OF M O V I E :  "<<movie_name;
    gotoxy(55,22);
    cout<<"THANK YOU :)";
    gotoxy(20,24);
    for(i=0;i<80;i++)
        cout<<ch;
        //ofstream()

}

//********************************************
//*   canceling the ticket
//*******************************************

void movie::canceling_ticket()
{
    char ch=178,thea_name[20],mov_name[20];
    int i,billno,seat_no,g[20],x_book_fi,y_book_fi;
    char thea_name_check[20],mov_name_check[20],time_in[20];
    gotoxy(20,5);
    for(i=0;i<80;i++)
    cout<<ch;
    gotoxy(50,7);
    cout<<"C A N C E L  T I C K E T";
    gotoxy(30,9);
    fflush(stdin);
    cout<<"ENTER THE THEATRE NAME :";
    gets(thea_name);
    if(strcmp(thea_name,"PVR CINEMA")==0)
    {
        strcpy(thea_name_check,"P_");

    }else if(strcmp(thea_name,"GALAXY THEATRE")==0)
    {
        strcpy(thea_name_check,"G_");

    }else if(strcmp(thea_name,"OM CINEPLEX")==0)
    {
        strcpy(thea_name_check,"O_");
    }else if(strcmp(thea_name,"VINAY CINEMA")==0)
    {
        strcpy(thea_name_check,"V_");
    }else if(strcmp(thea_name,"DBZ CINEMA")==0)
    {
        strcpy(thea_name_check,"D_");
    }
    gotoxy(30,11);
    cout<<"ENTER THE MOVIE NAME :";
    gets(mov_name);
    if(strcmp(mov_name,"GOLMAAL AGIAN")==0)
    {
        strcpy(mov_name_check,"G_");

    }else if(strcmp(mov_name,"THOR RAGNAROK")==0)
    {
        strcpy(mov_name_check,"T_");

    }else if(strcmp(mov_name,"Secret super star")==0)
    {
        strcpy(mov_name_check,"SSS_");

    }else if(strcmp(mov_name,"KINGSMAN 2")==0)
    {
        strcpy(mov_name_check,"K2_");

    }else if(strcmp(mov_name,"JUNGLE")==0)
    {
        strcpy(mov_name_check,"J_");

    }

    gotoxy(30,13);
    cout<<"ENTER THE TIME OF  MOVIE (e.g,8:30 am to 11:30 pm) :";
    gets(time_in);

    if(strcmp(time_in,"8:30 am to 11:30 pm")==0)
    {

        strcpy(timeofmovie_file,"8_");
    }else if(strcmp(time_in,"11:45 pm to 2:45 pm")==0)
    {

        strcpy(timeofmovie_file,"11_");

    }else if(strcmp(time_in,"3:00 pm to 5:15 pm")==0)
    {

        strcpy(timeofmovie_file,"3_");
    }else if(strcmp(time_in,"5:30 pm to 7:30 pm")==0)
    {

            strcpy(timeofmovie_file,"5_");

    }else if( strcmp(time_in,"7:45 pm to 9:45 pm")==0)
    {

        strcpy(timeofmovie_file,"7_");

    }
    gotoxy(30,15);
    cout<<"ENTER THE NO OF SEATS  :";
    cin>>seat_no;
    gotoxy(30,17);
    cout<<"ENTER THE SEATS NO :";
    for(int i=0;i<seat_no;i++)
    {
        cin>>g[i];
    }
    gotoxy(30,19);
    cout<<"ENTER THE BILL NO :";
    cin>>billno;
    gotoxy(20,21);
    for(i=0;i<80;i++)
    cout<<ch;
    strcpy(filename,thea_name_check);
    strcat(filename,mov_name_check);
    strcat(filename,timeofmovie_file);
    strcat(filename,".txt");

    fstream fin,fout;
    fin.open(filename,ios::in);
    fout.open("DEMO.txt",ios::app);
    i=0;
    while(fin>>seat_no>>x_book_fi>>y_book_fi)
    {
        if(seat_no!=g[i])
        {
            fout<<seat_no<<" "<<x_book_fi<<" "<<y_book_fi<<endl;
        }
        if(fin.eof()==0)
        break;

    }

    fin.close();
    fout.close();
    delete(filename);
    rename("DEMO.txt",filename);



    Sleep(300);
    gotoxy(50,23);
    cout<<"YOUR REQUEST IS BEING PROCESSED..."<<endl;
    gotoxy(50,25);
    cout<<"you ticket has been cancled"<<endl;




}

//********************************************
//*   the main function
//*******************************************

int main()
{
    int option;
    char enter;
    //first page of project
    movie m;
    m.animated_page();
    enter=getch();
    if(enter==13)
    {
        system("cls");
        m.instruction();
        Sleep(300);
        system("cls");
        option=m.login_page();

        m.loading();
        if(option==35)
        {
            option=m.login_window();

        }else
        {
            option=m.signup_window();
        }
        m.loading();
        if(option==0)
        {
            menu_of_user:
            option=m.menu();
            if(option==7)
            {
                m.loading();
                system("cls");
                option=m.theatre();

    switch(option)
    {
            case 10:
                strcpy(theatre_name,"PVR CINEMA");
                strcpy(theatre_name_file,"P_");

                break;
            case 12:
                strcpy(theatre_name,"GALAXY THEATRE");
                strcpy(theatre_name_file,"G_");
                break;
            case 14:
                strcpy(theatre_name,"OM CINEPLEX");
                strcpy(theatre_name_file,"O_");
                break;
            case 16:
                strcpy(theatre_name,"VINAY CINEMA");
                strcpy(theatre_name_file,"V_");
                break;
            case 18:
                strcpy(theatre_name,"DBZ CINEMA");
                strcpy(theatre_name_file,"D_");
                break;
    }
    system("cls");
    m.loading();
    system("cls");
    option=m.movie_list(option);
    system("cls");
    switch(option)
    {
        case 7:
        strcpy(movie_name,"GOLMAAL AGIAN");
        strcpy(movie_name_file,"G_");
        break;

        case 9:
        strcpy(movie_name,"THOR RAGNAROK");
        strcpy(movie_name_file,"T_");
        break;

        case 11:
        strcpy(movie_name,"Secret super star");
        strcpy(movie_name_file,"SSS_");
        break;

        case 13:
        strcpy(movie_name,"KINGSMAN 2");
        strcpy(movie_name_file,"K2_");
        break;

        case 15:
        strcpy(movie_name,"JUNGLE");
        strcpy(movie_name_file,"J_");
        break;
    }
    m.timing_of_movie_display(option);
    Sleep(300);
    m.timing_of_movie(option);

    strcpy(filename,theatre_name_file);
    strcat(filename,movie_name_file);
    strcat(filename,timeofmovie_file);
    strcat(filename,".txt");


    system("pause");
    system("cls");
    m.seat();
    system("pause");
    system("cls");
    goto menu_of_user;


            }else if(option==8)
            {
                system("cls");
                m.canceling_ticket();
                gotoxy(50,27);
                system("pause");
                system("cls");
                gotoxy(0,0);

                goto menu_of_user;
            }else
            {
                system("cls");
                gotoxy(40,10);
                cout<<"THANK YOU VIST AGAIN"<<endl;
            }
        }
    }
return 0;
}
