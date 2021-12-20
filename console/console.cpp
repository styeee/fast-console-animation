#include <iostream>
using namespace std;
#include <windows.h>

inline void SetWindowSize(short w,short h)
{
	w--;h--;
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(handle,{0,0});
	SetConsoleWindowInfo(handle,true,new _SMALL_RECT{0,0,w,h});
}

int main()
{
    const short w=16;
    const short h=16;
	
	SetWindowSize(w,h);
    const size_t wh=w*h;

    char screen[wh+1];
    for(size_t i=0;i<wh;i++)screen[i]=rand()%100+32;

	HANDLE console=CreateConsoleScreenBuffer(GENERIC_READ|GENERIC_WRITE,0,0,CONSOLE_TEXTMODE_BUFFER,0);
	SetConsoleActiveScreenBuffer(console);

	screen[0]='@';

	 unsigned long count;
	for(size_t i=0;true;i=(i+1)%(wh))
	{
		screen[i]='.'; screen[i+1]='@';
		WriteConsoleOutputCharacterA(console,screen,wh,{0,0},&count);
		Sleep(1);
	}

    return 0;
}