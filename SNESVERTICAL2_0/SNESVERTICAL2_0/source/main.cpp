#include <imgui-SFML.h>
#include <imgui.h>
#include "../incluide/CWindow.h"
void imguiInterfaz();
int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "AWEBO");
	window.setFramerateLimit(60);
	ImGui::SFML::Init(window);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	shape.rotate(100);
	shape.setPosition(320,240);

	sf::Clock deltaClock;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			ImGui::SFML::ProcessEvent(event);
			ImGuiIO& io = ImGui::GetIO();
			if (io.WantCaptureMouse)
			{

			}
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			{
				exit(1);
			}
		}
		ImGui::SFML::Update(window, deltaClock.restart());
		imguiInterfaz();

		window.clear();
		window.draw(shape);
		ImGui::SFML::Render(window);
		window.display();
	}

	ImGui::SFML::Shutdown();
	return 0;
}
void imguiInterfaz()
{
	ImGui::Begin("una ventana");
	ImGui::Text("que cosas no?");
	ImGui::End();
}
