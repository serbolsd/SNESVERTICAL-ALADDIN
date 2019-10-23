#include "../include/mainManager.h"

mainManager::mainManager()
{
}

mainManager::~mainManager()
{
}

void mainManager::init()
{
	window = new CWindow();
	window->initWindow("parallax", 512, 512);
	window->getWindow()->setSize(sf::Vector2u(600, 500));
	sceneManager.wind = window;
	camera = new CCamera();
	camera->initCamera(0, 0, 600, 500);
	sceneManager.cam = camera;
	aladdin = new Aladdin();
	aladdin->onInit();
	sceneManager.addObject(aladdin);
	initParallax();
}

void mainManager::onUpdate()
{

	ImGui::SFML::Init(*window->getWindow());
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	shape.rotate(100);
	shape.setPosition(320, 240);

	sf::Clock deltaClock;
	while (window->getWindow()->isOpen()) {
		sf::Event event;
		while (window->getWindow()->pollEvent(event)) {
			ImGui::SFML::ProcessEvent(event);
			ImGuiIO& io = ImGui::GetIO();
			if (io.WantCaptureMouse)
			{

			}
			if (event.type == sf::Event::Closed) {
				window->getWindow()->close();
			}
			if (sf::priv::InputImpl::isKeyPressed(sf::Keyboard::Key::Escape))
			{
				exit(1);
			}
		}
		sceneManager.onUpdate();
		ImGui::SFML::Update(*window->getWindow(), deltaClock.restart());
		imguiAladdinDebug();
		imguiParallaxDebug();
		//window->getWindow()->draw(shape);
		ImGui::SFML::Render(*window->getWindow());
		window->getWindow()->display();
	}

	ImGui::SFML::Shutdown();
}

void mainManager::onDelete()
{
	//aladdin->onDelete();
	//delete aladdin;
	//aladdin = nullptr;
	sceneManager.onDelete();
	resourceManager.onDelete();
}
void mainManager::imguiAladdinDebug()
{
	ImGui::Begin("Aladdin");
	ImGui::InputFloat("actualspeed", aladdin->actualSpeed);
	float v[2] = { aladdin->direction.x,aladdin->direction.y};
	ImGui::InputFloat2("direcction", v);
	ImGui::End();
}
void mainManager::imguiParallaxDebug()
{
	ImGui::Begin("Parallax");
	float *f =new float( fondo2->getPosition().z);
	ImGui::SliderFloat("Z", f,6,400);
	fondo2->setPosition(fondo2->getPosition().x, fondo2->getPosition().y,*f);
	delete f;
	ImGui::End();
}
void mainManager::initParallax()
{
	int idtex;
	fondo1 = new GameObject();
	sceneManager.addObject(fondo1);

	resourceManager.loadTextures("resources\\fondo1.png", idtex, sceneManager.gameObjects[fondo1->getID()]->sprite);
	sceneManager.gameObjects[fondo1->getID()]->setTextureID(idtex);
	sceneManager.gameObjects[fondo1->getID()]->setPosition(0, 0, 5);

	fondo2 = new GameObject();
	fondo2->setComponente(new Parallax(aladdin));
	sceneManager.addObject(fondo2);

	resourceManager.loadTextures("resources\\fondo2.jpg", idtex, sceneManager.gameObjects[fondo2->getID()]->sprite);
	sceneManager.gameObjects[fondo2->getID()]->setTextureID(idtex);
	sceneManager.gameObjects[fondo2->getID()]->setPosition(0, 0, 6);
}