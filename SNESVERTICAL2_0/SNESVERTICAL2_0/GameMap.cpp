#include "include/GameMap.h"

void GameMap::Init(string file)
{
	ifstream openfile(file);//Abrimos el archivo
	string in;

	m_loadCounter = sf::Vector2i(0, 0);

	if (openfile.is_open())
	{
		openfile >> in;
		m_background.loadFromFile(in);//El primer elemento es la textura de fondo
		m_back.setTexture(m_background);
		openfile >> in;
		m_tileTexture.loadFromFile(in);//El segundo elemento es el Tile Sheet
		m_tiles.setTexture(m_tileTexture);

		while (!openfile.eof())//Continuamos leyendo el mapa
		{
			openfile >> in;
			char x = in[0], y = in[2];
			if (!isdigit(x) || !isdigit(y)) 
			{//Si las coordenadas no son números entonces esa posición esta vacia
				m_map[m_loadCounter.x][m_loadCounter.y] = sf::Vector2i(-1, -1);
			}
			else
			{//Si hay dígitos entonces le pasamos la coordenada del tile que va en esa posición
				m_map[m_loadCounter.x][m_loadCounter.y] = sf::Vector2i(x - '0', y - '0');
			}
			
			if (openfile.peek() == '\n')
			{//Si lo leido es un salto de línea entonces ya sabemos cuanto mide el mapa en X
			//Reposicionamos X a 0 y a Y le sumamos 1
				m_nx = m_loadCounter.x;
				m_loadCounter.x = 0;
				m_loadCounter.y++;
			}
			else
			{//De lo contrario leemos el siguiente valor de la misma fila
				m_loadCounter.x++;
			}
		}
		//Al final ya sabemos el valor en Y del mapa
		m_ny = m_loadCounter.y;
	}
}

void GameMap::draw(sf::RenderWindow& win, float size)
{//Primero dibujamos el fondo
	win.draw(m_back);
	//Ahora empezamos a dibujar cada tile
	for (int i = 0; i < m_nx+1; i++)
	{
		for (int j = 0; j < m_ny; j++)
		{//Si los valores en esa posición no son negativos entonces dibujamos
			if (m_map[i][j].x != -1 && m_map[i][j].y != -1)
			{
			//size es el tamaño en pixeles de un tile
			//Como son cuadrados solo necesitamos conocer el size de X o Y
			//Seteamos la posición de donde va a empezar a tomar el tile
			//Toma el tile completo y luego lo dibuja
				m_tiles.setPosition(i*size*((640.0f/size)/(m_nx+1)), j*size*((480.0f/size)/m_ny));
				m_tiles.setTextureRect(sf::IntRect(m_map[i][j].x*size, m_map[i][j].y*size, size, size));
				m_tiles.setScale(sf::Vector2f(((640.0f / size) / (m_nx + 1)), ((480.0f / size) / m_ny)));
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
