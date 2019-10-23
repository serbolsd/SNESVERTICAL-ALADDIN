
#include <imgui-SFML.h>
#include <imgui.h>
#include "../include/CWindow.h"
#include "../include/CCamera.h"
//void imguiInterfaz();
//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(640, 480), "AWEBO");
//	window.setFramerateLimit(60);
//	ImGui::SFML::Init(window);
//	sf::CircleShape shape(100.f);
//	shape.setFillColor(sf::Color::Green);
//	shape.rotate(100);
//	shape.setPosition(320,240);
//
//	sf::Clock deltaClock;
//	while (window.isOpen()) {
//		sf::Event event;
//		while (window.pollEvent(event)) {
//			ImGui::SFML::ProcessEvent(event);
//			ImGuiIO& io = ImGui::GetIO();
//			if (io.WantCaptureMouse)
//			{
//
//			}
//			if (event.type == sf::Event::Closed) {
//				window.close();
//			}
//			if (sf::priv::InputImpl::isKeyPressed(sf::Keyboard::Key::Escape))
//			{
//				exit(1);
//			}
//		}
//		ImGui::SFML::Update(window, deltaClock.restart());
//		imguiInterfaz();
//
//		window.clear();
//		window.draw(shape);
//		ImGui::SFML::Render(window);
//		window.display();
//	}
//
//	ImGui::SFML::Shutdown();
//	return 0;
//}
//void imguiInterfaz()
//{
//	ImGui::Begin("una ventana");
//	ImGui::Text("que cosas no?");
	//ImGui::End();
//}
int main()
{
	sf::CircleShape GameObject;
	sf::CircleShape GameObject2;
	
	GameObject.setRadius(5);
	GameObject2.setRadius(10);
	GameObject.setFillColor(sf::Color(255, 0, 0));
	GameObject2.setFillColor(sf::Color(255,255, 0));
	sf::RenderWindow Sure(sf::VideoMode(800, 600), "TESTIng");
	sf::Keyboard Teclado;
	CCamera pog;
	sf::Vector2f* pos=new sf::Vector2f(0,0);
	GameObject.setPosition(*pos);
	int follow = 1;
	float x, y;
	x = 0;
	y = 0;
	pog.initCamera(GameObject.getPosition().x, GameObject.getPosition().y, 800, 600);
	pog.setView(pos, 800, 600);
	while (Sure.isOpen())
	{
		
		sf::Event Momevment;
		while (Sure.pollEvent(Momevment))
		{
			if (Momevment.type == Momevment.KeyPressed)
			{
				if (sf::priv::InputImpl::isKeyPressed(Teclado.D))
				{
					x += 1;
				}
				else if (sf::priv::InputImpl::isKeyPressed(Teclado.A))
				{
					x -= 1;
				}
				else if (sf::priv::InputImpl::isKeyPressed(Teclado.S))
				{
					y += 1;
				}
				else if (sf::priv::InputImpl::isKeyPressed(Teclado.W))
				{
					y -= 1;
				}
				if (sf::priv::InputImpl::isKeyPressed(Teclado.Z))
				{
					follow *= -1;
				}
				*pos = { x, y };
				GameObject.setPosition(*pos);
			}
		}
		if (follow==1)
		{
			pog.Update();
		}
		Sure.clear();
		Sure.draw(GameObject);
		Sure.draw(GameObject2);
		Sure.display();
		
		Sure.setView(*pog.getView());

	}


}