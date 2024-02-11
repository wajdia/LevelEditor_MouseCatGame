#include "Button.h"
//c-tor
Button::Button() : m_selected(false),
	m_texture(sf::Texture()), m_location({-1,-1}),m_type(EMPTY)
{}
//===============================
//c-tor
Button::Button(string fileName, sf::Vector2f location,char type)
{
	m_location = location;
	if (!m_texture.loadFromFile(fileName))
	{
		exit(EXIT_FAILURE);
	}
	m_selected = false;
	m_type = type;
}
//===============================
void Button::draw(sf::RenderWindow& window) const
{
	auto sprite = sf::Sprite(m_texture);
	sprite.setPosition(m_location);
	sprite.setScale((float)BUTTON_SIZE/ICON_SIZE,
		(float)BUTTON_SIZE / ICON_SIZE);

	//inheritance required instead
	if (this->getType() != NEW_PAGE)
	{
		sprite.setColor(SHADED_COLOR);
	}
	
	if (m_selected)
	{
		sprite.setColor(SELECTED_COLOR);
		auto shape = sf::RectangleShape(
			{ (float)BUTTON_SIZE,(float)BUTTON_SIZE });
		shape.setFillColor(MAIN_BACKGROUND_COLOR);
		shape.setOutlineThickness(2.f);
		shape.setOutlineColor(SHADED_COLOR);
		shape.setPosition(m_location);
		window.draw(shape);
	}

	window.draw(sprite);
}
//===============================
bool Button::isSelected() const
{
	return m_selected;
}
//===============================
char Button::getType() const
{
	return m_type;
}
//===============================
void Button::unselect()
{
	m_selected = false;
}
//===============================
bool Button::handleClick(sf::Vector2f location)
{
	auto sprite = sf::Sprite(m_texture);
	sprite.setPosition(m_location);
	sprite.setScale((float)BUTTON_SIZE / ICON_SIZE,
		(float)BUTTON_SIZE / ICON_SIZE);

	if (sprite.getGlobalBounds().contains(location))
	{
		m_selected = true;
		return true;
	}
	return false;
}
