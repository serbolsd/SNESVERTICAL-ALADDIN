#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <iostream>
enum WINDOWTYPE
{
	TRenderWindow = 0,
	THandleWindow,
	Twindow
};

class CWindow
{
public:
	CWindow();
	~CWindow();
	void initWindow(const std::string & windowName = "Uname", const int & width = 600, const int &heihgt = 500, const WINDOWTYPE &tipe =WINDOWTYPE::TRenderWindow);
	void onDelete();
	bool onUpdate();
	bool onUpdateRenderW();
	bool onUpdateHandleW();
	bool onUpdateW();
	void closeWindow();
	sf::RenderWindow* getWindow();
	void setEvent(sf::Event *eve) { event = eve; };
private:
	sf::RenderWindow* renderWindow = nullptr;
	sf::WindowHandle* handleWindow = nullptr;
	sf::Window* window = nullptr;
	bool isWindowInit = false;
	WINDOWTYPE *tipeWin = nullptr;
	sf::Event* event=nullptr;
};

