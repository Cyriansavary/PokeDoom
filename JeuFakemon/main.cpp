#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "game.h"
#include "animatedSprite.h"
#include "entity.h"
#include "hero.h"


int main()
{
	game g;
	int state = 0;

	sf::Texture texture;
	if (!texture.loadFromFile(DOOM_TEXTURE))
	{
		printf("error");
		// error...
	}

	hero doom = hero(texture);

	int count = 0;
	g.set_values();
	g.set_values_options();
	while (g.windowIsOpen())
	{
		g.clear();
		if (state == 0)
		{
			state = g.run_menu();
		}
		else if (state == 1) {
			g.windowGame();

			doom.heroMouvement();
			if (count % 20 == 0)
			{
				doom.nextAnimation();
				count = 0;
			}
			count++;
			g.drawEntity(doom);
		}
		else if (state == 2)
		{
			state = g.run_options();
		}
		g.display();
	}

	return 0;
}