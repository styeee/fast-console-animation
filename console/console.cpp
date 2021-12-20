//#include <iostream>
//using namespace std;
#include <windows.h>//for win api
#include <time.h>//for fix fps

inline void SetWindowSize(const short w,const short h)
{
	const HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(handle,{0,0});
	SetConsoleWindowInfo(handle,true,new _SMALL_RECT{0,0,w,h});
}

int main()
{
    const short w=16;
    const short h=16;
	SetWindowSize(w-1,h-1);
    const size_t wh=w*h;

    char screen[wh+1];//an array that will be puted on the screen
    for(size_t i=0;i<wh;i++)screen[i]=rand()%100+32;//fill the array with some trash

	const HANDLE console=CreateConsoleScreenBuffer(GENERIC_READ|GENERIC_WRITE,0,0,CONSOLE_TEXTMODE_BUFFER,0);
	SetConsoleActiveScreenBuffer(console);

	screen[0]='@';

	 unsigned long count;
	for(size_t i=0;true;i=(i+1)%(wh))
	{
		screen[i]='.'; screen[i+1]='@';
		WriteConsoleOutputCharacterA(console,screen,wh,{0,0},&count);

		const size_t dt=CLOCKS_PER_SEC/60;
		for(size_t t=clock();(clock()-t)<dt;);
	}

    return 0;
}