#include "../include/RenderManager.h"

RenderManager::RenderManager()
{
}

RenderManager::~RenderManager()
{
}

void RenderManager::init()
{
	//init window
	window = new CWindow();
	window->initWindow("parallax", 500, 500);
	window->getWindow()->setSize(sf::Vector2u(600, 500));
	sceneManager.wind = window;
	//init camera
	camera = new CCamera();
	camera->initCamera(0, 0,100,100);
	sceneManager.cam = camera;
	GraphicApi::loadResources(sceneManager,camera, resources);
	deltaTime = new float(0);
	sceneManager.deltaTime = deltaTime;
	sceneManager.onInit();
	//init parallax
	//initParallax();
}

void RenderManager::onUpdate()
{

	ImGui::SFML::Init(*window->getWindow());
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	shape.rotate(100);
	shape.setPosition(320, 240);
	window->getWindow()->setFramerateLimit(30);
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

		camera->Update();
		sceneManager.onUpdate();

		*deltaTime = sf::Time(deltaClock.getElapsedTime()).asSeconds();
		ImGui::SFML::Update(*window->getWindow(), deltaClock.restart());
		//imguiAladdinDebug();
		//imguiParallaxDebug();
		//window->getWindow()->draw(shape);
		window->getWindow()->setView(*camera->getView());
		ImGui::SFML::Render(*window->getWindow());
		window->getWindow()->display();
	}

	ImGui::SFML::Shutdown();
}

void RenderManager::onDelete()
{
	delete deltaTime;
	sceneManager.onDelete();
	//resourceManager.onDelete();
}
//void RenderManager::imguiAladdinDebug()
//{
//	ImGui::Begin("Aladdin");
//	ImGui::InputFloat("actualspeed", aladdin->actualSpeed);
//	float v[2] = { aladdin->direction.x,aladdin->direction.y};
//	ImGui::InputFloat2("direcction", v);
//	int * id=new int(aladdin->animatorID);
//	ImGui::InputInt("AnimID", id);
//	ImGui::SliderFloat("AnimatedSpeed", aladdin->animatedSpeed, 0, 1);
//	delete id;
//	ImGui::End();
//}
//void RenderManager::imguiParallaxDebug()
//{
//	ImGui::Begin("Parallax");
//	float *f =new float( fondo2->getPosition().z);
//	ImGui::SliderFloat("Z", f,6,400);
//	fondo2->setPosition(fondo2->getPosition().x, fondo2->getPosition().y,*f);
//	delete f;
//	ImGui::End();
//}
