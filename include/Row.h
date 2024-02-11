//Represents like vector class
// manages dynamic memory, holds array of Tiles
#pragma once
#include "Tile.h" 

class Row {
public:
    
    explicit Row(int size = 0, const Tile& value = Tile());
    Row(const Row& other);
    ~Row();

    Row& operator=(const Row& other); 
    //for read only
    const Tile& at(int index) const;
    //for write
    Tile& at(int index);
    int size() const; 
    void push_back(const Tile& val);
    bool empty() const;
    void resize(int newSize);

private:
    int m_size;
    Tile* m_rowTiles;
};

