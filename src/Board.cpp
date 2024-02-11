#include "Board.h"

//c-tor
Board::Board() : m_rows(DEF_HEIGHT), m_cols(DEF_WIDTH)
{
    std::ifstream boardFile;
    if (std::filesystem::exists("Board.txt"))
    {
        boardFile.open("Board.txt");
        boardFile >> m_rows >> m_cols;

        if (m_rows <= 0 || m_cols <= 0)
        {
            m_rows = DEF_HEIGHT;
            m_cols = DEF_WIDTH;
        }

        if (boardFile.is_open())
        {
            createBoardFromFile(boardFile);
        }
    }
    else
    {
        std::cout << "Enter the dimensions of your board: ROWS COLS"
            << std::endl;
        std::cin >> m_rows >> m_cols;
        if (m_rows <= 0 || m_cols <= 0)
        {
            m_rows = DEF_HEIGHT;
            m_cols = DEF_WIDTH;
        }
    }
    recreateBoard(m_rows, m_cols, WINDOW_WIDTH, WINDOW_HEIGHT);
}

//===============================
//create board according to given rows and cols
// mainly calculating tile size
void Board::recreateBoard(int rows, int cols, int wWidth, int wHeight)
{
    m_rows = rows;
    m_cols = cols;
    int maximalShrink = (m_cols > m_rows) ? m_cols : m_rows;
    m_tileSize = std::min((wWidth - MENU_WIDTH - PADDING) / maximalShrink,
        (int)(wHeight - PADDING) / m_rows);

    initializeBoard();
}
//===============================
int Board::getTilesize() const
{
    return m_tileSize;
}
//===============================
int Board::getCols() const
{
    return m_cols;
}
//===============================
int Board::getRows() const
{
    return m_rows;
}
//===============================
void Board::initializeBoard()
{
    m_tiles.resize(m_rows);

    sf::Vector2f startLocation((float)START_X_COORD, (float)START_Y_COORD);

    for (int i = 0; i < m_rows; i++)
    {
        m_tiles[i].resize(m_cols);
        for (int j = 0; j < m_cols; j++)
        {
            m_tiles[i].at(j).setLocation(startLocation +
                sf::Vector2f((float)j * m_tileSize, (float)i * m_tileSize));
            m_tiles[i].at(j).setSize(m_tileSize);
        }
    }
}
//===============================
//draw the board and the borders
void Board::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            m_tiles[i].at(j).draw(window);

            sf::RectangleShape 
                tileRepresention(sf::Vector2f((float)m_tileSize, (float)m_tileSize));
           
            tileRepresention.setPosition(m_tiles[i].at(j).getLocation().x + 1.f,
                m_tiles[i].at(j).getLocation().y + 1.f);
            
            tileRepresention.setFillColor(m_tiles[i].at(j).getHighlightColor());
            
            window.draw(tileRepresention);
        }
    }
}
//===============================
void Board::handleTileClick(sf::Vector2f location, char clickType, string filename)
{
    //get the row and column based on the location
    int row = (int)((location.y - START_Y_COORD) / m_tileSize);
    int col = (int)((location.x - START_X_COORD) / m_tileSize);

    //std::cout << "CLICKED row:" << row << " col:" << col<<"\n";
    //ensure indices are within the valid range
    if (row >= 0 && row < m_rows && col >= 0 && col < m_cols)
    {
        m_tiles[row].at(col).handleClick(location, clickType);
        m_tiles[row].at(col).setTexture(filename);
    }
}
//===============================
void Board::resetTile(sf::Vector2f location)
{
    int row = (int)((location.y - START_Y_COORD) / m_tileSize);
    int col = (int)((location.x - START_X_COORD) / m_tileSize);

    if (row >= 0 && row < m_rows && col >= 0 && col < m_cols)
    {
        m_tiles[row].at(col).remove();
    }
}
//===============================
void Board::resetAllTiles()
{
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            m_tiles[i].at(j).remove();
        }
    }
}
//===============================
bool Board::isWithinBoard(sf::Vector2f location) const
{
    if (location.x >= START_X_COORD && location.x <
        START_X_COORD + m_cols * m_tileSize &&
        location.y >= START_Y_COORD && location.y <
        START_Y_COORD + m_rows * m_tileSize)
    {
        //std::cout << "click in board!" << "\n";
        return true;
    }
    else
    {
        return false;
    }
}
//===============================
void Board::highlightBorders(sf::Vector2f location)
{
    // Calculate the row and column based on the location
    int row = (int)((location.y - START_Y_COORD) / m_tileSize);
    int col = (int)((location.x - START_X_COORD) / m_tileSize);

    // reset highlight color for all other tiles
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            if (row != i || col != j)
            {
                m_tiles[i].at(j).resetHighlightColor();
            }
        }
    }
    //ensure the indices are within the valid range to highlight
    if (row >= 0 && row < m_rows && col >= 0 && col < m_cols)
    {
        m_tiles[row].at(col).setHighlightColor(highlightColor);
    }
}
//===============================
void Board::resetHighlight()
{
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            m_tiles[i].at(j).resetHighlightColor();
        }
    }
}
//===============================
void Board::createBoardFromFile(std::ifstream& boardFile)
{
    //create vector of rows
    for (int i = 0; i < m_rows; i++)
    {
        Row row(m_cols,Tile());      
        m_tiles.push_back(row);
    }

    char c;
    for (int i = 0; i < m_rows; i++)
    {
        c = char(boardFile.get());  //new Line

        for (int j = 0; j < m_cols; j++)
        {
            c = char(boardFile.get());
            m_tiles[i].at(j).setType(c);

            if (c != EMPTY)
            {
                m_tiles[i].at(j).setTexture(charTofile(c));
            }
        }
    }
}
//===============================
string Board::charTofile(char c)
{
    switch (c)
    {
    case MOUSE:
        return "Mouse.png";
        break;
    case CAT:
        return "Cat.png";
        break;
    case WALL:
        return "Wall.png";
        break;
    case KEY:
        return "Key.png";
        break;
    case CHEESE:
        return "Cheese.png";
        break;
    case DOOR:
        return "Door.png";
        break;
    case GIFT:
        return "Gift.png";
        break;
    default:
        return "";
        break;
    }
}
//===============================
bool Board::doesHaveMouse() const
{
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            if (m_tiles[i].at(j).getType() == MOUSE)
            {
                return true;
            }
        }
    }
    return false;
}
//===============================
bool Board::doesHaveCheese() const
{
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            if (m_tiles[i].at(j).getType() == CHEESE)
            {
                return true;
            }
        }
    }
    return false;
}
//===============================
void Board::saveBoard()
{
    //save only if board is legal
    if (doesHaveMouse() && doesHaveCheese())
    {
        std::ofstream boardFile;
        boardFile.open("Board.txt");

        if (boardFile.is_open())
        {
            boardFile << m_rows << ' ' << m_cols << std::endl;

            for (int i = 0; i < m_rows; i++)
            {
                for (int j = 0; j < m_cols; j++)
                {
                    boardFile << m_tiles[i].at(j).getType();
                }
                boardFile << '\n';
            }
            boardFile.close();
        }
    }
}


