#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <time.h>
#include <windows.h>
using namespace std;

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

const int R = 1e3 + 5;
const int T = 40;

int n = 1,x = 0,y = 0;
char text[R][R];
int tl/*text long*/[R];

bool check(char c)
{//检测某个按键是否按下
	if(!KEY_DOWN(c))return 0;
	else return 1;
}

void setpos(int x,int y)//设置光标位置 
{
    HANDLE winHandle;//句柄
    COORD pos = {x,y};
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    //设置光标位置 
    SetConsoleCursorPosition(winHandle,pos); 
}

void out()
{
	for (int i = 0;i < n;i ++){
		for (int j = 0;j < tl[i];j ++)
			cout << text[j][i];
		cout << endl;
	}
}

void in()
{
	for (int i = '0';i <= '9';i ++){
		if (check((char)i)){
			text[x][y] = (char)i;
			tl[y] ++;
			x ++;
			Sleep(T);
			system("cls");
			out();
			break;
		}
	}
	
	for (int i = 'A';i <= 'Z';i ++){
		if (check((char)i)){
			text[x][y] = (char)i - 'A' + 'a';
			tl[y] ++;
			x ++;
			Sleep(T);
			system("cls");
			out();
			break;
		}
	}
	
	if (check((char)32)){//Space
		text[x][y] = ' ';
		tl[y] ++;
		x ++;
		Sleep(T);
		system("cls");
		out();
	}
	
	if (check((char)8)){//Backspace
		if (x == 0){
			if (y == 0) ;
			else {
				y --;
				x = tl[y];
				n --;
			}
		}
		else {
			text[x][y] = NULL;
			tl[y] --;
			x --;
		}
		Sleep(T - 10);
		system("cls");
		out();
	}
	
	if (check((char)13)){//Enter
		n ++;
		y ++;
		x = 0;
		Sleep(T);
		system("cls");
		out();
	}
	
//	if (check((char)27)){//Esc(save)
//    	freopen("text.txt", "w", stdout);
//		 
//    	for (int i = 0;i < n;i ++){
//			for (int j = 0;j < tl[i];j ++)
//				cout << text[j][i];
//			cout << endl;
//		}
//			
//    	fclose(stdout);
//	}
	
}

int main()
{
	POINT p;
	HANDLE hOutput;
    COORD coord={0,0};
    hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
    memset(tl,0,sizeof(tl));
    
	for (;;)
	{
		in();
		
		setpos(x,y);
	}
}
