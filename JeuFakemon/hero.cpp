#include "hero.h"

hero::hero(const sf::Texture& texture) : 
    animatedSprite(texture, std::vector<std::vector<sf::IntRect>>(DOOM_ANIMATION_MOUVEMENT))
{		
	{
		this->sprite.scale(0.7, 0.7);
	}
}

void hero::heroMouvement()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        sprite.move(0.f, -0.7);
        direction = 1;
        sprite.setTextureRect(this->animation_position[direction][this->animation_count]);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        sprite.move(0.f, 0.7);
        direction = 0;
        sprite.setTextureRect(this->animation_position[direction][this->animation_count]);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        sprite.move(-0.7, 0.f);
        direction = 2;
        sprite.setTextureRect(this->animation_position[direction][this->animation_count]);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        sprite.move(0.7, 0.f);
        direction = 3;
        sprite.setTextureRect(this->animation_position[direction][this->animation_count]);
        
    }
}

void hero::heroShooting()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        isHeroShooting = true;
        direction = 0;
        sprite.setTextureRect(this->animation_position[direction][this->animation_count]);

    }
}