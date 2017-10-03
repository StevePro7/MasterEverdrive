#include "Main.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Engine::Instance().Init();
	Engine::Instance().Play();
	Engine::Instance().Quit();

	return 0;
}