#include "Window.h"

//c-tor
Window::Window() :m_board(Board())
{
	for (int i = 0; i < NUM_OF_ICONS; i++)
	{
		m_buttons[i]= Button(m_menuIcons[i],
			{10.f,(float)i * (BUTTON_SIZE + PADDING)}, m_types[i]);
	}
	optimizeDimensions(m_board.getRows(),m_board.getCols());
	
	
	m_window.create(sf::VideoMode(m_windowWidth,m_windowHeight),
			"Level Editor", sf::Style::Close | sf::Style::Titlebar);
}
//===============================
void Window::run()
{
	do
	{
		drawDisplayElements();
		if (auto event = sf::Event{}; m_window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;

			case sf::Event::MouseButtonReleased :
				handleClick(event.mouseButton);
				drawDisplayElements();
				break;

			case sf::Event::MouseMoved:
				handleMove(event.mouseMove);
				break;
			}
		}
	}while (m_window.isOpen());
}

//===============================
void Window::drawDisplayElements()
{
	m_window.clear(MAIN_BACKGROUND_COLOR);
	
	auto menuPlace = sf::RectangleShape({ MENU_WIDTH, MENU_HEIGHT });
	
	menuPlace.setFillColor(MENU_BACKGROUND_COLOR);
	menuPlace.setPosition(0.f, 0.f);

	m_window.draw(menuPlace);
	
	//draw the buttons
	for (int i = 0; i < NUM_OF_ICONS; i++)
	{
		m_buttons[i].draw(m_window);
	}
	
	m_board.draw(m_window);
	m_window.display();
}

//===============================
void Window::handleClick(const sf::Event::MouseButtonEvent& event)
{
	int i; 
	bool isButtonClicked = false;

	for (i = 0; i < NUM_OF_ICONS; i++)
	{
		if (m_buttons[i].handleClick(m_window.mapPixelToCoords({ event.x, event.y })))
		{
			for (int j = 0; j < NUM_OF_ICONS; j++)
			{
				if (i != j)
				{
					m_buttons[j].unselect();
				}
			}
			isButtonClicked = true;
			break;
		}
	}
	
	if (isButtonClicked)
	{
		m_selectedButton = m_buttons[i].getType();
	}

	if (m_selectedButton == NEW_PAGE)
	{
		m_board.resetAllTiles();
		m_window.close();

		int newRows, newCols;
		std::cout << "Enter the dimensions of your board: ROWS COLS\n";
		std::cin >> newRows >> newCols;
		
		optimizeDimensions(newRows,newCols);
		
		m_window.create(sf::VideoMode(m_windowWidth, m_windowHeight),
			"Level Editor", sf::Style::Close | sf::Style::Titlebar);
		m_selectedButton = EMPTY;
		m_buttons[NUM_OF_ICONS-1].unselect();
		run();
	}

	if (m_selectedButton == SAVE)
	{
		m_board.saveBoard();
	}

	if (m_board.isWithinBoard(m_window.mapPixelToCoords({ event.x, event.y })))
	{
		handleBoardDrawing(m_window.mapPixelToCoords({ event.x, event.y }));
	}

}

//===============================
void Window::handleBoardDrawing(sf::Vector2f location) 
{
	if (m_selectedButton == CAT || m_selectedButton == DOOR || 
		m_selectedButton == CHEESE ||m_selectedButton == GIFT ||
		m_selectedButton == KEY || m_selectedButton == WALL ||
		m_selectedButton == MOUSE)
	{
		int i;
		for (i = 0; i < NUM_OF_ICONS; i++)
		{
			if (m_buttons[i].getType() == m_selectedButton)
			{
				break;
			}
		}
		//if not mouse btn clicked nor board has mouse, draw the tile:
		if (m_selectedButton != MOUSE || !m_board.doesHaveMouse())
		{
			m_board.handleTileClick(location, m_selectedButton, m_menuIcons[i]);
		}
	}
	else
	{
		//remove tile
		if (m_selectedButton == REMOVE)
		{
			m_board.resetTile(location);
		}
	}
}

//===============================
//handle mouse move
void Window::handleMove(const sf::Event::MouseMoveEvent& event)
{
	if (m_board.isWithinBoard(m_window.mapPixelToCoords({ event.x, event.y })))
	{
		m_board.highlightBorders(m_window.mapPixelToCoords({ event.x, event.y }));
	}
	else
	{
		m_board.resetHighlight();
	}
}

//===============================
void Window::optimizeDimensions(int newRows, int newCols)
{
	int suggestedWidth = newCols * MINIMAL_TILE_SIZE + MENU_WIDTH + 
		BOARD_2WINDOW_FACTOR * PADDING;
	int suggestedHeight = newRows * MINIMAL_TILE_SIZE + 
		BOARD_2WINDOW_FACTOR* PADDING;

	int maximalWidth = sf::VideoMode::getDesktopMode().width - 
		WIDTH_FACTOR * PADDING;
	int maximalHeight = sf::VideoMode::getDesktopMode().height - 
		HEIGHT_FACTOR* PADDING;

	m_windowWidth = std::max(std::min(suggestedWidth, maximalWidth),
		WINDOW_WIDTH);
	m_windowHeight = std::max(std::min(suggestedHeight, maximalHeight),
		WINDOW_HEIGHT); 

	m_board.recreateBoard(newRows, newCols, m_windowWidth, m_windowHeight);
}

