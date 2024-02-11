#pragma once
#include <SFML/Graphics.hpp>

const char CAT = '^';
const char WALL = '#';
const char MOUSE = '%';
const char EMPTY = ' ';
const char CHEESE = '*';
const char GIFT = '$';
const char DOOR = 'D';
const char KEY = 'F';
const char REMOVE = 'R';
const char SAVE = 'S';
const char NEW_PAGE = 'N';

const sf::Color SELECTED_COLOR(255, 232, 255);
const sf::Color MAIN_BACKGROUND_COLOR(255, 233, 232);
const sf::Color highlightColor(240, 240, 255,100);
const sf::Color MENU_BACKGROUND_COLOR(167, 168, 205);
const sf::Color TILE_PLACE_COLOR(100, 2, 2,30);
const sf::Color SHADED_COLOR(80, 80, 80, 120);

const int WIDTH_FACTOR = 3;
const int HEIGHT_FACTOR = 6;
const int BOARD_2WINDOW_FACTOR = 2;

const int WINDOW_HEIGHT = 900;
const int WINDOW_WIDTH = 900;
const int MENU_HEIGHT = 900;
const int MENU_WIDTH = 100;
const int PADDING = 20;
const int BUTTON_SIZE = 70;
const float STANDARD_THICKNESS = 0.5f;
const float SELECTED_THICKNESS = 2.f;
const int RECTANGLE_SIZE = 60;
const int ICON_SIZE = 200;
const int OBJECTS_NUM = 7;
const int START_X_COORD = 110;
const int START_Y_COORD = 10;
const int DEF_WIDTH = 10;
const int DEF_HEIGHT = 10;
const int NUM_OF_ICONS = 10;
const int MINIMAL_TILE_SIZE = 50;
const int MAXIMAL_WINDOW_WIDTH = 1800;



