#include "Tile.h"
//c-tor
Tile::Tile() : m_location(0.f, 0.f),
	m_type(EMPTY),m_texture(sf::Texture()),
	m_highlightColor(TILE_PLACE_COLOR), m_tileSize(RECTANGLE_SIZE)
{}
//===============================
//c-tor
Tile::Tile(sf::Vector2f location) :m_location(location), m_type(EMPTY),
	m_texture(sf::Texture()), m_highlightColor(sf::Color())
{}
//===============================
//copy c-tor
Tile::Tile(const Tile& other)
	: m_location(other.m_location),
	m_type(other.m_type),
	m_texture(other.m_texture),
	m_highlightColor(other.m_highlightColor),
	m_tileSize(other.m_tileSize)
{}
//===============================
//assignment operator
Tile& Tile::operator=(const Tile& other) 
{
	//self-assignment
	if (this != &other) 
	{
		m_location = other.m_location;
		m_type = other.m_type;
		m_highlightColor = other.m_highlightColor;
		m_tileSize = other.m_tileSize;
		m_texture = other.m_texture;
	}
	return *this;
}
//===============================
sf::Vector2f Tile::getLocation() const
{
	return m_location;
}
//===============================
void Tile::setLocation(const sf::Vector2f location)
{
	m_location = location;
}
//===============================
void Tile::setSize(int size)
{
	m_tileSize = size;
}
//===============================
int Tile::getSize() const
{
	return m_tileSize;
}
//===============================
char Tile::getType() const
{
	return m_type;
}
//===============================
void Tile::setType(char type)
{
	m_type = type;
}
//===============================
void Tile::setTexture(string fileName)
{
	m_texture.loadFromFile(fileName);
}
//===============================
sf::Texture Tile::getTexture()
{
	return m_texture;
}
//===============================
void Tile::handleClick(sf::Vector2f location, char clickType)
{
	if (createShape().getGlobalBounds().contains(location))
	{
		m_type = clickType;
	}
}
//===============================
void Tile::remove()
{
	m_texture = sf::Texture();
	m_type = EMPTY;
}
//===============================
void Tile::draw(sf::RenderWindow& window) const
{
	auto sprite = sf::Sprite(m_texture);
	sprite.setPosition(m_location);
	sprite.setScale((float) m_tileSize / ICON_SIZE,
		(float)m_tileSize / ICON_SIZE );
	window.draw(sprite);
}
//===============================
sf::RectangleShape Tile::createShape() const
{
	auto shape = sf::RectangleShape({ (float)m_tileSize,(float)m_tileSize });
	shape.setFillColor(MAIN_BACKGROUND_COLOR);
	shape.setPosition(m_location);
	return shape;
}
//===============================
void Tile::setHighlightColor(sf::Color highlightcolor)
{
	m_highlightColor = highlightcolor;
}
//===============================
sf::Color Tile::getHighlightColor() const
{
	return m_highlightColor;
}
//===============================
void Tile::resetHighlightColor() 
{
	m_highlightColor = sf::Color(TILE_PLACE_COLOR);
}


