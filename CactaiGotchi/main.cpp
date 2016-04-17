#include "StateMachine.hpp"

int main(int ac, char **av)
{
	cactaigotchi::WindowSystem win;
	cactaigotchi::StateMachine state(win);

	while (win.isOpen())
	{
		win.clear();
		state.render();
		win.display();
	}
	return 0;
}