#include "Main.h"

int main(int argc, char* argv[])
{
	Engine::Instance().Init();
	Engine::Instance().Play();
	Engine::Instance().Quit();

	return 0;
}