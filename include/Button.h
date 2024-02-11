//Represents a button in the Controller object (Window)
//Better design was to let NewPage and Save buttons to be inherited from
//this class
#pragma once

#include <string>
#include "Constants.h"
using std::string;

class Button {

public:
	Button();
	Button(string fileName, sf::Vector2f location,char type);

	void draw(sf::RenderWindow& window) const;
	bool handleClick(sf::Vector2f location);
	
	bool isSelected() const;
	char getType() const;
	void unselect();
	
private:
	char m_type;
	bool m_selected;
	sf::Texture m_texture;
	sf::Vector2f m_location;
};