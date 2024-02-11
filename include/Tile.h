//Represents a Tile in the game board
// holds the type and main functions of tile in board
#pragma once

#include <string>
#include "Constants.h"
using std::string;

class Tile {

public:

	Tile();
	Tile(const sf::Vector2f location);
	Tile(const Tile& other);
	Tile& operator=(const Tile& other);

	sf::Vector2f getLocation() const;
	void setLocation(const sf::Vector2f location);
	
	char getType() const;
	void setType(char type);
	
	void setTexture(string fileName);
	sf::Texture getTexture();

	void setSize(int size);
	int getSize() const;

	void setHighlightColor(sf::Color highlightColor);
	sf::Color getHighlightColor() const;

	void handleClick(sf::Vector2f location, char clickType);
	void remove();

	void draw(sf::RenderWindow& window) const;
	void resetHighlightColor();

private:
	sf::Color m_highlightColor;
	char m_type;
	sf::Vector2f m_location;
	sf::Texture m_texture;
	int m_tileSize = RECTANGLE_SIZE;

	sf::RectangleShape createShape() const;

};