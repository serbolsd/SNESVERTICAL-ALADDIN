#include "include/GameMap.h"

void GameMap::Init(string file)
{
	ifstream openfile(file);
	string in;

	m_loadCounter = sf::Vector2i(0, 0);

	if (openfile.is_open())
	{
		openfile >> in;
		m_background.loadFromFile(in);
		m_back.setTexture(m_background);
		openfile >> in;
		m_tileTexture.loadFromFile(in);
		m_tiles.setTexture(m_tileTexture);

		while (!openfile.eof())
		{
			openfile >> in;
			char x = in[0], y = in[2];
			if (!isdigit(x) || !isdigit(y))
			{
				m_map[m_loadCounter.x][m_loadCounter.y] = sf::Vector2i(-1, -1);
			}
			else
			{
				m_map[m_loadCounter.x][m_loadCounter.y] = sf::Vector2i(x - '0', y - '0');
			}
			
			if (openfile.peek() == '\n')
			{
				m_loadCounter.x = 0;
				m_loadCounter.y++;
			}
			else
			{
				m_loadCounter.x++;
			}
		}
		m_loadCounter.y++;

	}
	sf::Vector2u size = m_background.getSize();
	m_back.setOrigin(size.x / 2, size.y / 2);
}

void GameMap::draw(sf::RenderWindow& win)
{
	//win.draw(m_back);

	for (int i = 0; i < m_loadCounter.x; i++)
	{
		for (int j = 0; j < m_loadCounter.y; j++)
		{
			if (m_map[i][j].x != -1 && m_map[i][j].y != -1)
			{
				m_tiles.setPosition(i*32, j*32);
				m_tiles.setTextureRect(sf::IntRect(m_map[i][j].x*33, m_map[i][j].y*33, 33, 33));
				win.draw(m_tiles);
			}
		}
	}
}

GameMap::GameMap()
{
}

GameMap::~GameMap()
{
}
