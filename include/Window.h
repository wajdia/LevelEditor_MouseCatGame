// Represents the Controller (named Window)
// controls all the operations in the app
#pragma once

#include "Button.h"
#include "Board.h"

class Window {

public:

	Window();
	void run();
	
private:
	Board m_board;
	char m_selectedButton;
	sf::RenderWindow m_window;
	int m_windowWidth = WINDOW_WIDTH;
	int m_windowHeight = WINDOW_HEIGHT;
	Button m_buttons[NUM_OF_ICONS];

	string m_menuIcons[NUM_OF_ICONS] = { "Mouse.png","Cat.png",
		"Wall.png","Cheese.png","Gift.png","Door.png","Key.png",
		"Save.png","Delete.png","NewPage.png" };
	
	char m_types[NUM_OF_ICONS] = { MOUSE,CAT,WALL,CHEESE,GIFT,DOOR,
		KEY,SAVE,REMOVE,NEW_PAGE };

	void handleClick(const sf::Event::MouseButtonEvent& event);
	void drawDisplayElements();

	void handleBoardDrawing(sf::Vector2f location);
	void handleMove(const sf::Event::MouseMoveEvent& event);
	void optimizeDimensions(int newRows,int  newCols);
};