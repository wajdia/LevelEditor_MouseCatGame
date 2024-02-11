#include "Row.h"

//c-tor
Row::Row(int size, const Tile& value )
    : m_size(size), m_rowTiles(new Tile[size]) 
{
    for (int i = 0; i < size; ++i) 
    {
        m_rowTiles[i] = value;
    }
}
//===============================
//Copy c-tor
Row::Row(const Row& other) 
    : m_size(other.m_size), m_rowTiles(new Tile[other.m_size]) 
{
    for (int i = 0; i < m_size; ++i) 
    {
        m_rowTiles[i] = other.m_rowTiles[i];
    }
}
//===============================
// d-tor
Row::~Row() 
{
    delete[] m_rowTiles;
}
//===============================
//assignment operator
Row& Row::operator=(const Row& other) 
{
    if (this != &other) 
    {
        delete[] m_rowTiles;
        m_size = other.m_size;
        m_rowTiles = new Tile[m_size];
        for (int i = 0; i < m_size; ++i) 
        {
            m_rowTiles[i] = other.m_rowTiles[i];
        }
    }
    return *this;
}
//===============================
//read-only access to tile at index
const Tile& Row::at(int index) const 
{
    return m_rowTiles[index];
}
//===============================
//write access to tile at index
Tile& Row::at(int index) 
{
    return m_rowTiles[index];
}
//===============================
int Row::size() const 
{
    return m_size;
}
//===============================
void Row::resize(int newSize)
{
    Tile* newTiles = new Tile[newSize];

    int minSize = std::min(newSize, m_size);
    for (int i = 0; i < minSize; ++i) 
    {
        newTiles[i] = m_rowTiles[i];
    }

    //manage dynamic memry
    delete[] m_rowTiles;
    m_rowTiles = newTiles;

    m_size = newSize;
}
//===============================
//push back like vector
void Row::push_back(const Tile& val) 
{
    Tile* newTiles = new Tile[m_size + 1];
    for (int i = 0; i < m_size; ++i) 
    {
        newTiles[i] = m_rowTiles[i];
    }

    //manage dynamic memory
    newTiles[m_size] = val;
    delete[] m_rowTiles;
    m_rowTiles = newTiles;
    m_size++;
}
//===============================
bool Row::empty() const 
{
    return m_size == 0;
}

