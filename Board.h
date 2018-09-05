#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>

class Board
{
	

public:
	//std::vector<std::vector<sf::RectangleShape>> boardFields;
	sf::RectangleShape backgroundBoard;
	//std::vector<std::vector<std::size_t>> actualPositions;
	//void change(int pX, int pY, int cX, int cY, 
	//	const sf::IntRect cords);
	const int textureBorderThickness;
	/*static sf::Texture loadBoardTexture();*/
	Board(sf::Vector2f backgroundBoardSize_, 
		sf::Vector2f backgroundBoardPos_, int textureBorderThickness_);
	~Board();
};

