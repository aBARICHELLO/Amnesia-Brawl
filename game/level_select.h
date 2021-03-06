#pragma once

#include "stdafx.h"
#include "map.h"

class LevelSelect {
public:
    LevelSelect();

    void Update();
    void Draw(sf::RenderWindow& window);

    sf::Texture controls_texture;
    sf::RectangleShape control_shape;
    sf::Font arial;
    sf::Font banksia;

    int selection = 900;
    std::vector<sf::Text> level_text_array; // Texts in level selection

private:
    sf::Text level_select;
    sf::Text level1;
    sf::Text level2;
    sf::Text level3;
};
