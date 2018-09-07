
#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "chessPiece.h"
#include "Board.h"
#include <windows.h>

sf::Texture loadChessPiecesTexture();
sf::Texture loadBoardTexture();
void setup(Board& , chessPiece&);
void whitePawnMove(int&, int&, chessPiece&, sf::RenderWindow&);
void blackPawnMove(int&, int&, chessPiece&, sf::RenderWindow&);



bool isPressed = false;
std::string pieceTaken;
sf::Vector2i tmpPos;
bool ready = false;


std::vector<std::vector<std::string>> piecesPos(9, std::vector<std::string>(9));

int main()
{	
	sf::RenderWindow window(sf::VideoMode(900, 600), "Czachy");
	std::string phase = "setup";
	Board board(sf::Vector2f(500,500), sf::Vector2f(350,50), 6);

	sf::Texture chessPiecesTexture = loadChessPiecesTexture();
	sf::Texture boardTexture = loadBoardTexture();
	
	sf::Font font;
	if (font.loadFromFile("arial.ttf")) {
		std::cout << "Ladowanie czcionki pomyslne"<<std::endl;
	}
	else {
		std::cout << "Blad ladowania czcionki" << std::endl;
	}

	chessPiece piecesObj(board, chessPiecesTexture);
	
	

	board.backgroundBoard.setTexture(&boardTexture);

	sf::RectangleShape resetButton;
	sf::RectangleShape startButton;
	startButton.setPosition(sf::Vector2f(50, 50));
	startButton.setSize(sf::Vector2f(100, 50));
	startButton.setFillColor(sf::Color::Green);
	sf::Text startText;
	startText.setPosition(sf::Vector2f(65, 55));
	startText.setFont(font);
	startText.setFillColor(sf::Color::Black);
	startText.setString("Start");



	
	while (window.isOpen()) {
		sf::Event event;	
			
			while (window.pollEvent(event)) {

				if (event.type == sf::Event::MouseButtonPressed) {
					
					if (event.type == sf::Event::MouseButtonPressed) {
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
							if (startButton.getGlobalBounds().contains(sf::Vector2f(
								sf::Mouse::getPosition(window)))) {
								setup(board, piecesObj);
							}
						}
					}
					
					if (!isPressed) {
						for (int i = 1; i < 9; i++) {
							for (int j = 1; j < 9; j++) {
								if (!piecesPos[i][j].empty()) {
									sf::FloatRect pos = piecesObj.pieces.at(piecesPos[i][j]).getGlobalBounds();
									if (pos.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
										pieceTaken = piecesPos[i][j];
										piecesPos[i][j].clear();
										isPressed = true;
										tmpPos = sf::Vector2i(i, j);
										ready = false;
										
										
									}
								}


							}
						}
					}else if (isPressed && !pieceTaken.empty()) {
						for (int i = 1; i < 9; i++) {
							for (int j = 1; j < 9; j++) {

								
									
								if (pieceTaken.find("whitePawn") != std::string::npos) {									
									whitePawnMove(i, j, piecesObj, window);									
								}
								else if (pieceTaken.find("blackPawn") != std::string::npos) {
									blackPawnMove(i, j, piecesObj, window);
								}
								
								
								isPressed = false;

							}
						}
						if (!ready) {
							piecesPos[tmpPos.x][tmpPos.y] = pieceTaken;

						}
					}
					 
				}

				if (event.type == sf::Event::Closed) {
					std::cout << "Zamkniecie okna" << std::endl;
					window.close();
				}
			}
			
			
			window.clear(sf::Color::White);


			window.draw(board.backgroundBoard);
			for (int i = 1; i < 9; i++) {
				for (int j = 1; j < 9; j++) {
					if (!piecesPos[i][j].empty()) {
						piecesObj.pieces.at(piecesPos[i][j]).
							setPosition(sf::Vector2f(piecesObj.fieldsPositions[i][j]));
						window.draw(piecesObj.pieces.at(piecesPos[i][j]));
					}
					
						
				}
				
			
			}
			window.draw(startButton);
			window.draw(startText);
			
			Sleep(10);
		
			
			
			
			
			
		window.display();
	}
		
	
	return 0;
}
    




sf::Texture loadChessPiecesTexture()
{
	sf::Texture chessPiecesTexture;
	if (chessPiecesTexture.loadFromFile("Chess_Pieces.png")) {
		std::cout << "Ladowanie tekstury szchow pomyslne" << std::endl;
	}
	else {
		std::cout << "Blad w ladowaniu tekstury szchow" << std::endl;
	}
	return chessPiecesTexture;
}

sf::Texture loadBoardTexture()
{
	sf::Texture chessBoardTexture;
	if (chessBoardTexture.loadFromFile("Chess_Board2.png")) {
		std::cout << "Ladowanie tekstury planszy pomyslne" << std::endl;
	}
	else {
		std::cout << "Blad w ladowaniu tekstury planszy" << std::endl;
	}
	return chessBoardTexture;
}

void setup(Board& board, chessPiece& pieceObj) {
		
	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			piecesPos[i][j].clear();
		}
	}

	piecesPos[1][1] = "whiteRook1";
	piecesPos[2][1] = "whiteKnight1";
	piecesPos[3][1] = "whiteBishop1";
	piecesPos[4][1] = "whiteKing";
	piecesPos[5][1] = "whiteQueen";
	piecesPos[6][1] = "whiteBishop2";
	piecesPos[7][1] = "whiteKnight2";
	piecesPos[8][1] = "whiteRook2";
	piecesPos[1][2] = "whitePawn1";
	piecesPos[2][2] = "whitePawn2";
	piecesPos[3][2] = "whitePawn3";
	piecesPos[4][2] = "whitePawn4";
	piecesPos[5][2] = "whitePawn5";
	piecesPos[6][2] = "whitePawn6";
	piecesPos[7][2] = "whitePawn7";
	piecesPos[8][2] = "whitePawn8";

	piecesPos[1][8] = "blackRook1";
	piecesPos[2][8] = "blackKnight1";
	piecesPos[3][8] = "blackBishop1";
	piecesPos[4][8] = "blackKing";
	piecesPos[5][8] = "blackQueen";
	piecesPos[6][8] = "blackBishop2";
	piecesPos[7][8] = "blackKnight2";
	piecesPos[8][8] = "blackRook2";
	piecesPos[1][7] = "blackPawn1";
	piecesPos[2][7] = "blackPawn2";
	piecesPos[3][7] = "blackPawn3";
	piecesPos[4][7] = "blackPawn4";
	piecesPos[5][7] = "blackPawn5";
	piecesPos[6][7] = "blackPawn6";
	piecesPos[7][7] = "blackPawn7";
	piecesPos[8][7] = "blackPawn8";

		
		

	
}

void whitePawnMove(int& i, int& j, chessPiece& piecesObj, sf::RenderWindow& window)
{
	sf::FloatRect pos = sf::FloatRect(piecesObj.fieldsPositions[i][j],
		sf::Vector2f(59, 59));

	if ((i == tmpPos.x && j == tmpPos.y + 1 && piecesPos[i][j].empty()) ||
		((i == tmpPos.x + 1 && j == tmpPos.y + 1 && !piecesPos[i][j].empty()) ||
		(i == tmpPos.x - 1 && j == tmpPos.y + 1 && !piecesPos[i][j].empty())) ||
		(i == tmpPos.x && j == tmpPos.y + 2 && piecesPos[i][j].empty() && piecesPos[i][j-1].empty()
			&& tmpPos.y == 2)) 
	
	{
		if (pos.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {

			piecesPos[i][j] = pieceTaken;


			ready = true;
			i = j = 2137; 
			
		}
	}
}

void blackPawnMove(int& i, int& j, chessPiece& piecesObj, sf::RenderWindow& window) {
	sf::FloatRect pos = sf::FloatRect(piecesObj.fieldsPositions[i][j],
		sf::Vector2f(59, 59));

	if ((i == tmpPos.x && j == tmpPos.y - 1 && piecesPos[i][j].empty()) ||
		((i == tmpPos.x + 1 && j == tmpPos.y - 1 && !piecesPos[i][j].empty()) ||
		(i == tmpPos.x - 1 && j == tmpPos.y - 1 && !piecesPos[i][j].empty())) ||
		(i == tmpPos.x && j == tmpPos.y - 2 && piecesPos[i][j].empty() && piecesPos[i][j + 1].empty()
			&& tmpPos.y == 7)) {
		if (pos.contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {

			piecesPos[i][j] = pieceTaken;


			ready = true;
			i = j = 2137;
			
		}
	}
}