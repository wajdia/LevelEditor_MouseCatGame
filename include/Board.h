//Represents the board of the drawing app
// holds mainly a vector of Rows
#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <iostream>
#include "Row.h"

using std::string;

class Board {
public:
    Board();
    void draw(sf::RenderWindow& window);
    void handleTileClick(sf::Vector2f location,
        char clickType,string filename);
    bool isWithinBoard(sf::Vector2f location) const;
    void highlightBorders(sf::Vector2f location);
    void resetTile(sf::Vector2f location);
    void resetAllTiles();
    void saveBoard();
    void resetHighlight();
    int getTilesize() const;
    void recreateBoard(int rows, int cols, int winWidth, int winHeight);
    bool doesHaveMouse() const;
    int getCols() const;
    int getRows() const;
    
private:
    int m_rows;
    int m_cols;
    int m_tileSize;
    std::vector<Row> m_tiles;

    void initializeBoard();
    void createBoardFromFile(std::ifstream& boardFile);
    string charTofile(char c);
    bool doesHaveCheese() const;
};