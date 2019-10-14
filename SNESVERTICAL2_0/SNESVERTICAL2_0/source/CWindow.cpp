#include "../include/CWindow.h"

CWindow::CWindow()
{
	renderWindow = nullptr;
}

CWindow::~CWindow()
{
}

void CWindow::initWindow(const int & width, const int & heihgt, const std::string & windowName, const WINDOWTYPE & tipe)
{
	if (isWindowInit)
	{
		std::cout << "this Windows already init\n";
	}
	tipeWin = new WINDOWTYPE;
	std::string tipoWindow;
	switch (tipe)
	{
	case WINDOWTYPE::TRenderWindow:
		renderWindow = new sf::RenderWindow(sf::VideoMode(width, heihgt), windowName);
		tipoWindow = "RenderWindow";
		break;
	case WINDOWTYPE::THandleWindow:
		handleWindow = new sf::WindowHandle();
		tipoWindow = "HandleWindow";
		break;
	case WINDOWTYPE::Twindow:
		window = new sf::Window(sf::VideoMode(width, heihgt), windowName);
		tipoWindow = "window";
		break;
	default:
		std::cout << "Invalid tipe\n";
		return;
		break;
	}
	*tipeWin = tipe;
	std::cout << "Window " << windowName <<" tipe of "<<tipoWindow<< " SUCCES init\n";
	isWindowInit = true;
}

void CWindow::onDelete()
{
	if (window!=nullptr)
	{
		delete window;
		window=nullptr;
	}
	if (handleWindow!= nullptr)
	{
		delete handleWindow;
		handleWindow = nullptr;
	}
	if (renderWindow!= renderWindow)
	{
		delete renderWindow;
		renderWindow = nullptr;
	}
	if (event!=nullptr)
	{
		delete event;
		event = nullptr;
	}
	if (tipeWin != nullptr)
	{
		delete tipeWin;
		tipeWin = nullptr;
	}
}

bool CWindow::onUpdate()
{
	switch (*tipeWin)
	{
	case WINDOWTYPE::TRenderWindow:
		return renderWindow;
		break;
	case WINDOWTYPE::THandleWindow:
		return handleWindow;
		break;
	case WINDOWTYPE::Twindow:
		return window;
		break;
	default:
		return false;
		break;
	}
	return false;
}

bool CWindow::onUpdateRenderW()
{
	if (renderWindow->isOpen())
	{

		while (renderWindow->pollEvent(*event))
		{
			// "close requested" event: we close the window
			if (event->type == sf::Event::Closed)
			{ 
				renderWindow->close();
				return false;
			}
		}
		return true;
	}
	return false;
}

bool CWindow::onUpdateHandleW()
{
	if (renderWindow->isOpen())
	{

		while (renderWindow->pollEvent(*event))
		{
			// "close requested" event: we close the window
			if (event->type == sf::Event::Closed)
			{
				renderWindow->close();
				return false;
			}
		}
		return true;
	}
	return false;
}

bool CWindow::onUpdateW()
{
	if (renderWindow->isOpen())
	{

		while (renderWindow->pollEvent(*event))
		{
			// "close requested" event: we close the window
			if (event->type == sf::Event::Closed)
			{
				renderWindow->close();
				return false;
			}
		}
		return true;
	}
	return false;
}

void CWindow::closeWindow()
{
	switch (*tipeWin)
	{
	case WINDOWTYPE::TRenderWindow:
		renderWindow->close();
		break;
	case WINDOWTYPE::THandleWindow:
		//handleWindow;
		break;
	case WINDOWTYPE::Twindow:
		window->close();
		break;
	default:
		nullptr;
		break;
	}
}

sf::RenderWindow * CWindow::getWindow()
{
	switch (*tipeWin)
	{
	case WINDOWTYPE::TRenderWindow:
		return renderWindow;
		break;
	case WINDOWTYPE::THandleWindow:
		//return handleWindow;
		break;
	case WINDOWTYPE::Twindow:
		//return window;
		break;
	default:
		return nullptr;
		break;
	}
	return nullptr;
}
