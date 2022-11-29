#include "game.h"

game::game() : window(sf::VideoMode(1920, 1080), "PokeDoom")
{
	this->window.setFramerateLimit(60);
    winclose = new sf::RectangleShape();
    font = new sf::Font();
    image = new sf::Texture();
    bg = new sf::Sprite();
    
}

bool game::windowIsOpen()
{
	return this->window.isOpen();
}

void game::windowGame()
{
	sf::Event event;
	while (this->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			this->window.close();
		}
	}
}

void game::clear()
{
	this->window.clear();
}

void game::display()
{
	this->window.display();
}

void game::drawEntity(const entity &entity)
{
	this->window.draw(entity.getSprite());
}

void game::set_values() {
    this->window.setPosition(sf::Vector2i(0, 0));

    pos = 0;
    pressed = theselect = false;
    font->loadFromFile("./AmazDooMLeft.ttf");
    image->loadFromFile("./Doom_menu.jpg");

    bg->setTexture(*image);
    bg->setScale(1.5, 1.5);

    pos_mouse = { 0,0 };
    mouse_coord = { 0, 0 };

    options = { "PokeDoom", "Play", "Options", "About", "Quit" };
    texts.resize(5);
    coords = { {650,60},{915,286.5},{915,423},{915,555},{915,685.5} };
    sizes = { 250,100,100,100,100 };


    for (std::size_t i{}; i < texts.size(); ++i) {
        texts[i].setFont(*font);
        texts[i].setString(options[i]);
        texts[i].setCharacterSize(sizes[i]);
        texts[i].setOutlineColor(sf::Color::Red);
        texts[i].setOrigin(1.f, 1.f);
        texts[i].setPosition(coords[i]);
    }
    texts[1].setOutlineThickness(10);
    pos = 1;

    winclose->setSize(sf::Vector2f(34.5, 39));
    winclose->setPosition(1767, 58.5);
    winclose->setFillColor(sf::Color::Transparent);

}
int game::loop_events() {
    sf::Event event;

    while (this->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            this->window.close();
        }

        pos_mouse = sf::Mouse::getPosition(window);
        mouse_coord = this->window.mapPixelToCoords(pos_mouse);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed) {
            if (pos < 4) {
                ++pos;
                pressed = true;
                texts[pos].setOutlineThickness(10);
                texts[pos - 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed) {
            if (pos > 1) {
                --pos;
                pressed = true;
                texts[pos].setOutlineThickness(10);
                texts[pos + 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
            theselect = true;
            if (pos == 4) {
                this->window.close();
            }
            if (pos == 1) {
                return 1;


            }
            std::cout << options[pos] << '\n';
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (winclose->getGlobalBounds().contains(mouse_coord)) {
                //std::cout << "Close the window!" << '\n';
                this->window.close();
            }
        }
    }
}


void game::draw_all() {
    this->window.clear();
    this->window.draw(*bg);
    for (auto t : texts) {
        this->window.draw(t);
    }
    this->window.display();
}

int game::run_menu() {
    int state = 0;
    while (this->window.isOpen()) {
        state = loop_events();
        draw_all();
        if (state == 1)
        {
            std::cout << "aled" << std::endl;
            return state;
        }
    }
}

