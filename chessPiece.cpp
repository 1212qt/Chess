#include "stdafx.h"
#include "chessPiece.h"

const sf::IntRect chessPiece::whiteKingTexturePos(38, 40, 255, 257);
const sf::IntRect chessPiece::whiteQueenTexturePos(355, 37, 290, 260);
const sf::IntRect chessPiece::whiteBishopTexturePos(705, 37, 258, 250);
const sf::IntRect chessPiece::whiteKnightTexturePos(1040, 44, 250, 250);
const sf::IntRect chessPiece::whiteRookTexturePos(1390, 50, 230, 250);
const sf::IntRect chessPiece::whitePawnTexturePos(1720, 50, 218, 250);
const sf::IntRect chessPiece::blackKingTexturePos(37, 365, 260, 275);
const sf::IntRect chessPiece::blackQueenTexturePos(350, 365, 300, 275);
const sf::IntRect chessPiece::blackBishopTexturePos(680, 365, 300, 275);
const sf::IntRect chessPiece::blackKnightTexturePos(1015, 365, 300, 275);
const sf::IntRect chessPiece::blackRookTexturePos(1350, 365, 300, 275);
const sf::IntRect chessPiece::blackPawnTexturePos(1675, 365, 300, 275);




chessPiece::chessPiece(Board& board, const sf::Texture& texture)

{
	
	fieldsPositions = std::vector<std::vector<sf::Vector2f>>(9, std::vector<sf::Vector2f > (9));
	pieces = std::map<std::string, sf::RectangleShape>();
	
	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			fieldsPositions[i][j] = sf::Vector2f(
				board.backgroundBoard.getPosition().x + board.textureBorderThickness + (i - 1) * 61,
				board.backgroundBoard.getPosition().y + board.textureBorderThickness + (j - 1) * 61);
		}
	}
	
	pieces.insert(std::pair<std::string, sf::RectangleShape>("whitePawn1", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("whitePawn1").setTexture(&texture);
	pieces.at("whitePawn1").setTextureRect(chessPiece::whitePawnTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("whitePawn2", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("whitePawn2").setTexture(&texture);
	pieces.at("whitePawn2").setTextureRect(chessPiece::whitePawnTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("whitePawn3", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("whitePawn3").setTexture(&texture);
	pieces.at("whitePawn3").setTextureRect(chessPiece::whitePawnTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("whitePawn4", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("whitePawn4").setTexture(&texture);
	pieces.at("whitePawn4").setTextureRect(chessPiece::whitePawnTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("whitePawn5", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("whitePawn5").setTexture(&texture);
	pieces.at("whitePawn5").setTextureRect(chessPiece::whitePawnTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("whitePawn6", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("whitePawn6").setTexture(&texture);
	pieces.at("whitePawn6").setTextureRect(chessPiece::whitePawnTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("whitePawn7", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("whitePawn7").setTexture(&texture);
	pieces.at("whitePawn7").setTextureRect(chessPiece::whitePawnTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("whitePawn8", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("whitePawn8").setTexture(&texture);
	pieces.at("whitePawn8").setTextureRect(chessPiece::whitePawnTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("whiteKing", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("whiteKing").setTexture(&texture);
	pieces.at("whiteKing").setTextureRect(chessPiece::whiteKingTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("whiteQueen", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("whiteQueen").setTexture(&texture);
	pieces.at("whiteQueen").setTextureRect(chessPiece::whiteQueenTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("whiteRook1", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("whiteRook1").setTexture(&texture);
	pieces.at("whiteRook1").setTextureRect(chessPiece::whiteRookTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("whiteRook2", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("whiteRook2").setTexture(&texture);
	pieces.at("whiteRook2").setTextureRect(chessPiece::whiteRookTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("whiteBishop1", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("whiteBishop1").setTexture(&texture);
	pieces.at("whiteBishop1").setTextureRect(chessPiece::whiteBishopTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("whiteBishop2", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("whiteBishop2").setTexture(&texture);
	pieces.at("whiteBishop2").setTextureRect(chessPiece::whiteBishopTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("whiteKnight1", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("whiteKnight1").setTexture(&texture);
	pieces.at("whiteKnight1").setTextureRect(chessPiece::whiteKnightTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("whiteKnight2", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("whiteKnight2").setTexture(&texture);
	pieces.at("whiteKnight2").setTextureRect(chessPiece::whiteKnightTexturePos);

	pieces.insert(std::pair<std::string, sf::RectangleShape>("blackPawn1", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("blackPawn1").setTexture(&texture);
	pieces.at("blackPawn1").setTextureRect(chessPiece::blackPawnTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("blackPawn2", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("blackPawn2").setTexture(&texture);
	pieces.at("blackPawn2").setTextureRect(chessPiece::blackPawnTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("blackPawn3", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("blackPawn3").setTexture(&texture);
	pieces.at("blackPawn3").setTextureRect(chessPiece::blackPawnTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("blackPawn4", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("blackPawn4").setTexture(&texture);
	pieces.at("blackPawn4").setTextureRect(chessPiece::blackPawnTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("blackPawn5", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("blackPawn5").setTexture(&texture);
	pieces.at("blackPawn5").setTextureRect(chessPiece::blackPawnTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("blackPawn6", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("blackPawn6").setTexture(&texture);
	pieces.at("blackPawn6").setTextureRect(chessPiece::blackPawnTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("blackPawn7", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("blackPawn7").setTexture(&texture);
	pieces.at("blackPawn7").setTextureRect(chessPiece::blackPawnTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("blackPawn8", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("blackPawn8").setTexture(&texture);
	pieces.at("blackPawn8").setTextureRect(chessPiece::blackPawnTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("blackKing", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("blackKing").setTexture(&texture);
	pieces.at("blackKing").setTextureRect(chessPiece::blackKingTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("blackQueen", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("blackQueen").setTexture(&texture);
	pieces.at("blackQueen").setTextureRect(chessPiece::blackQueenTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("blackRook1", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("blackRook1").setTexture(&texture);
	pieces.at("blackRook1").setTextureRect(chessPiece::blackRookTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("blackRook2", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("blackRook2").setTexture(&texture);
	pieces.at("blackRook2").setTextureRect(chessPiece::blackRookTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("blackBishop1", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("blackBishop1").setTexture(&texture);
	pieces.at("blackBishop1").setTextureRect(chessPiece::blackBishopTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("blackBishop2", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("blackBishop2").setTexture(&texture);
	pieces.at("blackBishop2").setTextureRect(chessPiece::blackBishopTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("blackKnight1", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("blackKnight1").setTexture(&texture);
	pieces.at("blackKnight1").setTextureRect(chessPiece::blackKnightTexturePos);
	pieces.insert(std::pair<std::string, sf::RectangleShape>("blackKnight2", sf::RectangleShape(
		sf::Vector2f(59, 59))));
	pieces.at("blackKnight2").setTexture(&texture);
	pieces.at("blackKnight2").setTextureRect(chessPiece::blackKnightTexturePos);
}


chessPiece::~chessPiece()
{
}
