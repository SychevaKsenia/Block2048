#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "../headers/block.hpp"
#include <iostream>
using namespace sf;

int main()
{
    sf::RenderWindow window({600u, 700u}, "Block2028");
    window.setFramerateLimit(144);
    sf::Texture block_texture;
    block_texture.loadFromFile("source/cat1.jpg");

    Block *block = new Block(block_texture, sf::Vector2f(250, 100), 2);
    // Block *block1 = new Block(block_texture, sf::Vector2f(250, 400), 2);

    while (window.isOpen())
    {
        float time = 300.f;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        Color color(255, 165, 0);
        block->Update(time);
        // std::cout << time << std::endl;

        window.clear(sf::Color::White);

        window.draw(block->getSprite());
        // window.draw(block1->getSprite());

        window.display();
    }
}
