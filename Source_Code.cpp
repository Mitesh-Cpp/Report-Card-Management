#include<fstream.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<string.h>
#include<iomanip.h>
ofstream r; //object of type output file stream class
ifstream t; //object of type input file stream class
void credits(); //for displaying end credits
void menu1(); //for managing TERM 1 results
void menu2(); //for managing TERM 2 results
void terms(); //main parent function that calls other functions
class xii //class to handle name,roll no,marks,percentage
{ //and grades of students
public:
int roll;

char na[20];
int m1,m2,m3,m4,m5;
char g[10];
int t;
int p;
void input() //class' function to input data
{
gotoxy(1,5);
cout<<"\tENTER ROLL NUMBER OF THE STUDENT :";
cin>>roll;
cout<<"\tENTER NAME OF THE STUDENT :";
gets(na);
cout<<"\n\n\tENTER MARKS OF THE 5 SUBJECTS OUT OF 100";
cout<<"\n";
cout<<"\tENTER MARKS IN ENGLISH:";
cin>>m1;
cout<<"\n";
cout<<"\tENTER MARKS IN MATHS:";
cin>>m2;
cout<<"\n";
cout<<"\tENTER MARKS IN PHYSICS:";
cin>>m3;
cout<<"\n";
cout<<"\tENTER MARKS IN CHEMISTRY:";
cin>>m4;
cout<<"\n";
cout<<"\tENTER MARKS IN COMPUTER:";
cin>>m5;
cout<<"\n";
cleardevice();
t=m1+m2+m3+m4+m5;
p=t/5;
gotoxy(1,1);
}
void output() //class' function to output data
{
cout<<"\n"<<" "<<roll<<" "<<na<<"\t";
cout<<" "<<m1<<","<<m2<<","<<m3<<","<<m4<<","<<m5;
cout<<" "<<p<<"%"<<"\t"<<" "<<g<<"\n";
cout<<"\t";
}

}s[30]; //declaring 30 objects of above class
int i,n;
//-------------------------------------------------------------------------
void writes() //function to write data to a file
{
cleardevice();
cout<<"\n";
cout<<"\nENTER THE NUMBER OF RECORDS TO0 BE CREATED:";
cin>>n;
cleardevice();
for(i=0;i<n;i++)
{
s[i].input();
if(s[i].p>=95)
strcpy(s[i].g,"A1");
if(s[i].p>=90&&s[i].p<95)
strcpy(s[i].g,"A2");
if(s[i].p>=80&&s[i].p<90)
strcpy(s[i].g,"B1");
if(s[i].p>=70&&s[i].p<80)
strcpy(s[i].g,"B2");
if(s[i].p>=60&&s[i].p<70)
strcpy(s[i].g,"C1");
if(s[i].p>=50&&s[i].p<60)
strcpy(s[i].g,"C2");
if(s[i].p>=40&&s[i].p<50)
strcpy(s[i].g,"D1");
if(s[i].p<40)
strcpy(s[i].g,"D2");
r.write((char*)&s[i],sizeof(s[i]));
}
}
//--------------------------------------------------------------------------
void append() //function to append data to a file
{
clrscr();
cleardevice();
cout<<"\n";
int k;
cout<<"\t\t\t*-----------*"<<"\n";
cout<<"\t\t\t| APPENDING |"<<"\n";

cout<<"\t\t\t*-----------*"<<"\n"<<"\n";
cout<<"\tENTER THE NUMBER OF RECORDS TO BE APPENDED :";
cin>>k;
cleardevice();
for(i=0;i<k;i++)
{
s[i].input();
if(s[i].p>=95)
strcpy(s[i].g,"A1");
if(s[i].p>=90&&s[i].p<95)
strcpy(s[i].g,"A2");
if(s[i].p>=80&&s[i].p<90)
strcpy(s[i].g,"B1");
if(s[i].p>=70&&s[i].p<80)
strcpy(s[i].g,"B2");
if(s[i].p>=60&&s[i].p<70)
strcpy(s[i].g,"C1");
if(s[i].p>=50&&s[i].p<60)
strcpy(s[i].g,"C2");
if(s[i].p>=40&&s[i].p<50)
strcpy(s[i].g,"D1");
if(s[i].p<40)
strcpy(s[i].g,"D2");
r.write((char*)&s[i],sizeof(s[i]));
}
getch();
n+=k;
}
//--------------------------------------------------------------------------
void search() //function to search record from the file by name
{
clrscr();
cleardevice();
char name[20];
int flag=0;
cout<<"\n";
cout<<"\t\t\t*-----------*"<<"\n";
cout<<"\t\t\t| SEARCHING |"<<"\n";
cout<<"\t\t\t*-----------*"<<"\n"<<"\n";
step:
cout<<"\n\tENTER THE NAME TO BE SEARCHED :";
gets(name);

cout<<"--------------------------------------------------------------------"<<"\n";
cout<<"ROLL NAME MARKS PERCENTAGE GRADE"<<"\n";
cout<<"--------------------------------------------------------------------"<<"\n";
for(i=0;i<n;i++)
{
t.read((char*)&s[i],sizeof(s[i]));
if(strcmp(name,s[i].na)==0)
{
flag=1;
s[i].output();
break;
}
}
if(flag==0)
{
cleardevice();
cout<<"\tSORRY!!\n";
cout<<"\n\tTHE NAME DOES NOT EXIST.\n";
}
getch();
}
//--------------------------------------------------------------------------
void update() //function to give 10 % grace marks to failed students
{ //if a student doesn't pass,even after giving grace,then
clrscr(); //he or she will be declared as "failed"
cleardevice();
cout<<"\t\t\t*------------*\n";
cout<<"\t\t\t|UPDATED LIST|\n";
cout<<"\t\t\t*------------*\n\n";
cout<<"--------------------------------------------------------------------"<<"\n";
cout<<"ROLL NAME MARKS PERCENTAGE GRADE"<<"\n";
cout<<"--------------------------------------------------------------------"<<"\n";
for(i=0;i<n;i++)
{
if(s[i].p<40.0)
s[i].t=s[i].t+(s[i].t/10);
s[i].p=s[i].t/5.0;
if(s[i].p>=50.0&&s[i].p<60.0)
strcpy(s[i].g,"C2");
if(s[i].p>=40.0&&s[i].p<50.0)
strcpy(s[i].g,"D1");
if(s[i].p<40.0)

strcpy(s[i].g,"Failed");
r.write((char*)&s[i],sizeof(s[i]));
s[i].output();
}
getch();
}
//---------------------------------------------------------------------------
void sort() //function to view records in a sorted manner (alphabetically)
{
clrscr();
cleardevice();
xii tp;
cout<<"\t\t\t*-------------*"<<"\n";
cout<<"\t\t\t| SORTED LIST |"<<"\n";
cout<<"\t\t\t*-------------*"<<"\n"<<"\n";
cout<<"ROLL NAME MARKS PERCENTAGE GRADE"<<"\n";
cout<<"-------------------------------------------------------------------"<<"\n";
for(i=0;i<n;i++)
{
t.read((char*)&s[i],sizeof(s[i]));
for(i=0;i<n-1;i++)
{
for(int j=i+1;j<n;j++)
{
if(strcmp(s[i].na,s[j].na)>0)
{
tp=s[i];
s[i]=s[j];
s[j]=tp;
}
}
}
for(i=0;i<n;i++)
s[i].output();
}
getch();
}
//---------------------------------------------------------------------------
void failed() //function to see the list of failed students
{ //if a student gets less than 40 marks in 2 or more
clrscr(); //subjects, then he is declared "failed"
cout<<"\t**----------------------------------------------------------**"<<"\n";

cout<<"\t|| THE LIST OF STUDENTS WHO FAILED IN MORE THAN ONE SUBJECT
||"<<"\n";
cout<<"\t**----------------------------------------------------------**"<<"n\n";
cout<<"ROLL NAME MARKS PERCENTAGE GRADE"<<"\n";
cout<<"-------------------------------------------------------------------"<<"\n";
for(i=0;i<n;i++)
{
int c=0;
t.read((char *) &s[i],sizeof(s[i]));
if (s[i].m1<40) c++;
if (s[i].m2<40) c++;
if (s[i].m3<40) c++;
if (s[i].m4<40) c++;
if (s[i].m5<40) c++;
if(c>=2)
{
s[i].output();
}
}
getch();
}
//------------------------------------------------------------------------
void reads() //function to view all records or results
{
cleardevice();
cout<<"\n";
cout<<"\t**------------------------------------------------**"<<"\n";
cout<<"\t|| THE REPORT CARD OF STUDENTS OF CLASS XII ||"<<"\n";
cout<<"\t**------------------------------------------------**"<<"\n"<<"\n";
cout<<"ROLL NAME MARKS PERCENTAGE GRADE"<<"\n";
cout<<"-------------------------------------------------------------------"<<"\n";
for(i=0;i<n;i++)
{
t.read((char*)&s[i],sizeof(s[i]));
s[i].output();
}
getch();
}
//---------------------------------------------------------------------------
void terms() //parent function that acts like a menu and invokes
{ //all other functions
int gdriver = DETECT, gmode, errorcode;

initgraph(&gdriver,&gmode,"C:\\TurboC3\\BGI");
errorcode = graphresult();
if (errorcode !=grOk) /* an error code occurred */
{
printf("Graphics error: %s\n", grapherrormsg(errorcode));
printf("Press any key to halt:");
getch;
exit(1); /* terminate with an error code */
}
char chc;
rectangle(1,1,getmaxx(),getmaxy());
settextstyle(GOTHIC_FONT,VERT_DIR,5);
settextjustify(LEFT_TEXT,CENTER_TEXT);
outtextxy(50,240,"REPORT CARD");
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,5);
outtextxy(240,50,"SELECT A TERM");
outtextxy(240,90,"OF YOUR CHOICE.");
outtextxy(240,105," ......................................");
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
setbkcolor(BLACK);
outtextxy(300,170,"1.Ist TERM");
outtextxy(300,220,"2.IInd TERM");
outtextxy(300,270,"3.EXIT");
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
outtextxy(400,400,"ENTER CHOICE");
chc=getch();
switch(chc)
{
case '1':cleardevice();
menu1();
break;
case '2':cleardevice();
menu2();
break;
case '3':cleardevice();
credits();
exit(0);
default :clrscr();
cleardevice();
settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
outtextxy(220,210,"WRONG CHOICE !");
outtextxy(170,270,"PLEASE TRY AGAIN.");

sleep(2);
cleardevice();
terms();

}
closegraph();
}
//--------------------------------------------------------------------------
void credits() //function to display end credits
{
cleardevice();
setbkcolor(4);
gotoxy(33,6);
cout<<"-Created By:-";
for(i=70;i>26;i--)
{
gotoxy(i,8);
cout<<"MITESH KHEMANI (0827CS191153) ";
delay(70);
}
for(i=70;i>26;i--)
{
gotoxy(i,10);
cout<<"LAVISH PATLE (0827CS191139) ";
delay(70);
}
for(i=70;i>26;i--)
{
gotoxy(i,12);
cout<<"NAKUL GUPTA (0827CS191159) ";
delay(70);
}
for(i=70;i>20;i--)
{
gotoxy(i,16);
cout<<"ACROPOLIS INSTITUTE OF TECHNOLOGY AND RESEARCH ";
delay(70);
}
gotoxy(28,25);
cout<<"Press any key to exit...";
getch();
exit(0);
}
/***********************************menu1************************************/

void menu1() //menu for managing TERM 1 results
{
cleardevice();
char ch;
back:
settextstyle(GOTHIC_FONT,VERT_DIR,5);
settextjustify(LEFT_TEXT,CENTER_TEXT);
outtextxy(50,240,"REPORT CARD");
settextstyle(SANS_SERIF_FONT,VERT_DIR,4);
setbkcolor(BLACK);
settextjustify(LEFT_TEXT,CENTER_TEXT);
outtextxy(110,240,"Ist TERM");
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
outtextxy(290,50,"1.MAKE REPORT CARD");
outtextxy(290,90,"2.APPEND NAMES");
outtextxy(290,130,"3.SORT NAMES");
outtextxy(290,170,"4.SEARCH A NAME");
outtextxy(290,210,"5.UPDATE GRADE");
outtextxy(290,250,"6.VIEW REPORT CARD");
outtextxy(290,290,"7.LIST OF FAILURES");
outtextxy(290,330,"8.MAIN MENU");
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
outtextxy(400,420,"ENTER CHOICE");
ch=getch();
switch(ch)
{
case '1': r.open("report_1");
writes();
r.close();
cleardevice();
goto back;
case '2': r.open("report_1",ios::app|ios::out);
append();
r.close();
cleardevice();
goto back;
case '3': t.open("report_1");
sort();
t.close();
cleardevice();
goto back;
case '4': t.open("report_1");

search();
t.close();
cleardevice();
goto back;
case '5': r.open("report_1",ios::end);
update();
r.close();
cleardevice();
goto back;
case '6': t.open("report_1");
reads();
t.close();
cleardevice();
goto back;
case '7': t.open("report_1");
failed();
t.close();
cleardevice();
goto back;
case '8': closegraph();
terms();
default :clrscr();
cleardevice();
settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
outtextxy(220,240,"WRONG CHOICE !");
outtextxy(190,280,"PLEASE TRY AGAIN.");
sleep(2);
cleardevice();
goto back;
}
}
/***************************************menu2********************************************/
void menu2() //menu for managing TERM 2 results
{
cleardevice;
char ch;
back:
settextstyle(GOTHIC_FONT,VERT_DIR,5);
settextjustify(LEFT_TEXT,CENTER_TEXT);
outtextxy(50,240,"REPORT CARD");
settextstyle(SANS_SERIF_FONT,VERT_DIR,4);
setbkcolor(BLACK);
settextjustify(LEFT_TEXT,CENTER_TEXT);

outtextxy(110,240,"IInd TERM");
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
outtextxy(290,50,"1.MAKE REPORT CARD");
outtextxy(290,90,"2.APPEND NAMES");
outtextxy(290,130,"3.SORT NAMES");
outtextxy(290,170,"4.SEARCH A NAME");
outtextxy(290,210,"5.UPDATE GRADE");
outtextxy(290,250,"6.VIEW REPORT CARD");
outtextxy(290,290,"7.LIST OF FAILURES");
outtextxy(290,330,"8.MAIN MENU");
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
outtextxy(400,420,"ENTER CHOICE");
ch=getch();
switch(ch)
{
case '1': r.open("report_2");
writes();
r.close();
cleardevice();
goto back;
case '2': r.open("report_2",ios::app|ios::out);
append();
r.close();
cleardevice();
goto back;
case '3': t.open("report_2");
sort();
t.close();
cleardevice();
goto back;
case '4': t.open("report_2");
search();
t.close();
cleardevice();
goto back;
case '5': r.open("report_2",ios::end);
update();
r.close();
cleardevice();
goto back;
case '6': t.open("report_2");
reads();
t.close();

cleardevice();
goto back;
case '7': t.open("report_2");
failed();
t.close();
cleardevice();
goto back;
case '8': closegraph();
terms();
default :clrscr();
cleardevice();
settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
outtextxy(220,240,"WRONG CHOICE !");
outtextxy(190,280,"PLEASE TRY AGAIN.");
sleep(2);
cleardevice();
goto back;
}
}
/***********************************MAIN*************************************/
void main()
{
clrscr();
int gdriver=DETECT,gmode,errorcode;
initgraph(&gdriver,&gmode,"C:\\TurboC3\\BGI");
errorcode = graphresult();
if (errorcode != grOk) /*an error occurred*/
{
printf("Graphics error: %s\n", grapherrormsg(errorcode));
printf("Press any key to halt:");
getch();
exit(1);
} /* terminate with an error code */
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,5);
rectangle(1,1,getmaxx(),getmaxy());
setbkcolor(9);
outtextxy(300,100,"A");
delay(500);
outtextxy(200,170,"PROJECT ON");
delay(500);
outtextxy(60,240,"REPORT CARD MANAGEMENT");
delay(500);
for(int i=0;i<360;i++)

{
ellipse(320,240,0,i,300,200); //predefined function from graphics.h
delay(12); //header file to draw an ellipse
}
closegraph();
terms();
}
