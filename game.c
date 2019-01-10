#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
void number_put(int,int[]);
int number_check(int[],int[]);
main(void)
{
char check,know;
int answer[3],user[3],random,chance=0,answer_temp,a=0,b=0,right=0,progress=0,question,user_question_time=0,digit=1,question_save;
printf("還迎大家來到軒軒所製作的小遊戲，更新版本1308240141\n今天所帶來的是AB猜數字遊戲，如果你已經知道規則請按1，不知道規則請按2\n");
know=getch();
system("cls");
switch(know)
{
case '1':
printf("若要電腦隨機選擇數字，請按1\n如果要自己指定題目，請按2\n若要分析答案，請按3\n");
break;
case '2':
printf("當你填入一個4位數的數字，會顯示*A*B(\"*\"為不定數)\nA代表數字一樣且位置也一樣，但不確定是哪個數字\nB代表有數字跟題目一樣，但位置不同，也不能確定是哪個數\n 假設題目是1234\n而你填的答案是2534\n則\"3\"和\"4\"同數字且同位置為2A\n至於\"2\"同數字但不同位置為1B，合起來是2A1B\n這樣你懂了嗎?\n\n若要電腦隨機選擇數字，請按1\n如果要自己指定題目，請按2\n若要分析答案，請按3\n");
break;
default:
printf("\n您的輸入不正確，將停止執行程式");
}
check=getche();
switch(check)
{
case '1':
printf("\n製作題目的時間不定，請耐心等待，了解之後");
system("PAUSE");
srand(time(NULL));
do
{
random=(rand()%8999)+1000;
//printf("\nrandom:%d",random);
number_put(random,answer);
if(progress==0)
printf("題目製作中");
printf(".");
progress=progress+1;
if(progress==800)
{
system("cls");
progress=0;
}
//system("pause");
}while(answer[0]==answer[1]||answer[0]==answer[2]||answer[0]==answer[3]||answer[1]==answer[2]||answer[1]==answer[3]||answer[2]==answer[3]);
//上一行確認數字不重複
system("cls"); 
//printf("\n0:%d 1:%d 2:%d 3:%d random:%d",answer[0],answer[1],answer[2],answer[3],random);
printf("\n題目已產生，你準備好挑戰了嗎?\n");
system("PAUSE");
for(chance=0;chance<=9;chance++)
{
if(chance==0)
printf("您目前有10次機會");
if(chance<7&&chance>0)
printf("您目前還有%d次機會\n",10-chance);
if(chance==0)
printf("開始作答\n");
if(chance>=7&&chance<9)
printf("注意!!注意!!你還剩%d次機會而已\n",10-chance);
if(chance==9)
printf("你還剩最後一次機會，請把握!\n");
printf("%d:",chance+1);
scanf("%d",&answer_temp);
number_put(answer_temp,user);
right=number_check(answer,user);
if(right==1)
{
system("cls");
printf("恭喜你答對了，答案就是%d%d%d%d\n祝你好運，你一共花了%d次作答。\n我們下次再見囉!!掰掰\n",answer[0],answer[1],answer[2],answer[3],chance+1);
break;
}
else
{
if(chance==9&&right==0)
{
printf("答案是%d%d%d%d\n挑戰失敗，下次再接再厲吧!!掰掰\n",answer[0],answer[1],answer[2],answer[3]);
}
}
}
break;
case '2':
system("cls");
do{
digit=1;
if(user_question_time!=0)
printf("\n數字不可重複!!");
printf("\n請輸入題目，數字不可重複:");
scanf("%d",&question);
question_save=question;
//偵測位數用 
for (;;)
{
question/= 10;
if (question==0)
break;
digit++;
}
if(digit!=4)
{ 
printf("只能輸入四位數喔!!");
continue;
}
//偵測位數結束 
user_question_time++;
number_put(question_save,answer);
//printf("%d%d%d%d",answer[0],answer[1],answer[2],answer[3]);
}while(answer[0]==answer[1]||answer[0]==answer[2]||answer[0]==answer[3]||answer[1]==answer[2]||answer[1]==answer[3]||answer[2]==answer[3]);
printf("\n請確認題目為:%d，程式將把題目隱藏。\n",question_save);
system("pause");
system("cls");
for(chance=0;chance<=9;chance++)
{
if(chance==0)
printf("您目前有10次機會");
if(chance<7&&chance>0)
printf("您目前還有%d次機會\n",10-chance);
if(chance==0)
printf("開始作答\n");
if(chance>=7&&chance<9)
printf("注意!!注意!!你還剩%d次機會而已\n",10-chance);
if(chance==9)
printf("你還剩最後一次機會，請把握!\n");
printf("%d:",chance+1);
scanf("%d",&answer_temp);
number_put(answer_temp,user);
right=number_check(answer,user);
if(right==1)
{
system("cls");
printf("恭喜你答對了，答案就是%d%d%d%d\n，你一共花了%d次作答。\n我們下次再見囉!!掰掰\n",answer[0],answer[1],answer[2],answer[3],chance+1);
break;
}
else
{
if(chance==9&&right==0)
{
printf("答案是%d%d%d%d\n挑戰失敗，下次再接再厲吧!!掰掰\n",answer[0],answer[1],answer[2],answer[3]);
}
}
}

break;
case '3':

break;
default:
printf("\n您的輸入不正確，將停止執行程式");
}
system("PAUSE");
}
//以下為函式庫 
void number_put(int a,int b[])
{
int i;
for(i=3;i>=0;i--)//[0]為千位數[3]為個位數 ，a為原本的數字變數，b要轉換的 
{
b[i]=a%10;
a=a/10;
//printf("第%d個:%d",i,b[i]);
}
}

int number_check(int answer[],int user[])//第1為正解，第2為使用者答案 
{
int a=0,b=0,right=0;
if(answer[0]==user[1])
b++;
if(answer[0]==user[2])
b++;
if(answer[0]==user[3])
b++;
if(answer[1]==user[0])
b++;
if(answer[1]==user[2])
b++;
if(answer[1]==user[3])
b++;
if(answer[2]==user[0])
b++;
if(answer[2]==user[1])
b++;
if(answer[2]==user[3])
b++;
if(answer[3]==user[0])
b++;
if(answer[3]==user[1])
b++;
if(answer[3]==user[2])
b++;
if(answer[0]==user[0])
a++;
if(answer[1]==user[1])
a++;
if(answer[2]==user[2])
a++;
if(answer[3]==user[3])
a++; 
printf("==>%dA%dB\n",a,b);
if(a==4&&b==0)
{
right=1;
return right; 
}
else
{
right=0;
return right;
}
}