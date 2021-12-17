#include <iostream>
using namespace std;
#include <windows.h>

inline void SetWindowSize(const short w,const short h)
{
	_COORD coord;
	coord.X=w;
	coord.Y=h;
	_SMALL_RECT rect;
	rect.Top=0;
	rect.Left=0;
	rect.Bottom=h-1;
	rect.Right=w-1;
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(handle,coord);
	SetConsoleWindowInfo(handle,true,&rect);
}

int main()
{
    const short w=16;
    const short h=16;
	SetWindowSize(w,h);
    const size_t wh=w*h;

    char screen[wh+1];
    memset(screen,'.',wh);

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