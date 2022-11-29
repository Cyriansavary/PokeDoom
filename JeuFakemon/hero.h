#pragma once

#include "animatedSprite.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


#define DOOM_TEXTURE "hero.png"
#define DOOM_ANIMATION_MOUVEMENT																\
{\
	{																					\
		sf::IntRect(0, 0, 30, 48), sf::IntRect(32, 0, 30, 48), sf::IntRect(65, 0, 30, 48), sf::IntRect(96, 0, 30, 48)							\
	},\
	{ \
		sf::IntRect(0, 144, 27, 48), sf::IntRect(30, 144, 27, 48), sf::IntRect(64, 144, 27, 48), sf::IntRect(98, 144, 27, 48)\
	},\
	{\
		sf::IntRect(0, 48, 27, 48), sf::IntRect(32, 48, 27, 48), sf::IntRect(65, 48, 27, 48), sf::IntRect(101, 48, 27, 48)\
	},\
	{\
		sf::IntRect(0, 96, 27, 48), sf::IntRect(35, 94, 27, 48), sf::IntRect(67, 95, 27, 48), sf::IntRect(94, 96, 27, 48)\
	}\
}\






						//

class hero : public animatedSprite
{
public: 
	hero(const sf::Texture& texture);
	void heroMouvement();
	void heroShooting();
protected :
	bool isHeroShooting = false;


};

