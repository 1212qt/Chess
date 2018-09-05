#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"


class chessPiece 
{
public:
	const static sf::IntRect whiteKingTexturePos;
	const static std::size_t whiteKingId = 6;
	const static sf::IntRect whiteQueenTexturePos;
	const static std::size_t whiteQueenId = 5;
	const static sf::IntRect whiteBishopTexturePos;
	const static std::size_t whiteBishopId = 2;
	const static sf::IntRect whiteKnightTexturePos;
	const static std::size_t whiteKnightId = 3;
	const static sf::IntRect whiteRookTexturePos;
	const static std::size_t whiteRookId = 4;
	const static sf::IntRect whitePawnTexturePos;
	const static std::size_t whitePawnId = 1;
	const static sf::IntRect blackKingTexturePos;
	const static std::size_t blackKingId = 16;
	const static sf::IntRect blackQueenTexturePos;
	const static std::size_t blackQueenId= 15;
	const static sf::IntRect blackBishopTexturePos;
	const static std::size_t blackBishopId = 12;
	const static sf::IntRect blackKnightTexturePos;
	const static std::size_t blackKnightId = 13;
	const static sf::IntRect blackRookTexturePos;
	const static std::size_t blackRookId = 14;
	const static sf::IntRect blackPawnTexturePos;
	const static std::size_t blackPawnId = 11;
	
	std::vector<std::vector<sf::Vector2f>> fieldsPositions;
	std::map<std::string, sf::RectangleShape> pieces;
	chessPiece(Board& board, const sf::Texture& texture);
	~chessPiece();
};

