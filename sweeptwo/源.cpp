#include "Game.h"

int main()
{
	Game Mine;
	Mine.Initial();
	Mine.player[1].checker();
	Mine.player[2].checker();
	/*while (Mine.window.isOpen())
	{
		Mine.Run();
	}*/
	system("pause");
}