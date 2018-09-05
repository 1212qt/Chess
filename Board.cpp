#include "stdafx.h"
#include "Board.h"



//sf::Texture Board::loadBoardTexture()
//{
//	
//}

//void Board::change(int pX, int pY, int cX, int cY,
//	const sf::IntRect cords)
//{
//	
//	this->actualPositions[cX][cY] = this->actualPositions[pX][pY];
//	this->actualPositions[pX][pY] = 0;
//	
//	
//	/*this->boardFields[pX][pY].setTexture(NULL);
//	this->boardFields[cX][cY].setTexture(&texture);
//	this->boardFields[cX][cY].setTextureRect(cords);*/
//
//}

Board::Board(sf::Vector2f backgroundBoardSize_,
	sf::Vector2f backgroundBoardPos_, int textureBorderThickness_)
	: textureBorderThickness(textureBorderThickness_)
{
	
	backgroundBoard.setSize(backgroundBoardSize_);
	backgroundBoard.setPosition(backgroundBoardPos_);
	//	
	//boardFields = std::vector<std::vector<sf::RectangleShape>>
	//	(9, std::vector<sf::RectangleShape>(9));
	//actualPositions = std::vector<std::vector<size_t>>
	//	(9, std::vector<size_t>(9));

	/*for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			boardFields[i][j] = sf::RectangleShape(sf::Vector2f(59, 59));
			boardFields[i][j].setPosition(sf::Vector2f(
				backgroundBoard.getPosition().x + textureBorderThickness + (i-1)*61,
				backgroundBoard.getPosition().y + textureBorderThickness + (j-1)*61));
			
			actualPositions[i][j] = 0;
		}
	}*/
}



Board::~Board()
{
}
