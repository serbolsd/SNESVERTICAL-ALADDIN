#include "../include/mainManager.h"

mainManager::mainManager()
{
}

mainManager::~mainManager()
{
}

void mainManager::init()
{
	deltaTime = new float(0);
	//init window
	window = new CWindow();
	window->initWindow("parallax", 500, 500);
	window->getWindow()->setSize(sf::Vector2u(600, 500));
	sceneManager.wind = window;
	//init camera
	camera = new CCamera();
	camera->initCamera(0, 0, 600, 500);
	sceneManager.cam = camera;
	//animator descriptor
	AnimatorDesc PathDescriptor;
	PathDescriptor.RunPath = "resources\\AladdinAnimations\\sprint.png";
	PathDescriptor.runProportion = sf::Vector2u(11, 1);
	PathDescriptor.SwingPath = "resources\\AladdinAnimations\\swing.png";
	PathDescriptor.IdlePath = "resources\\AladdinAnimations\\idle_Pos.png";
	PathDescriptor.idleProportion = sf::Vector2u(1, 1);
	//init aladdin
	aladdin = new Aladdin();
	aladdin->onInit();
	aladdin->deltaTime = deltaTime;
		Animator *AladdinAnimation= new Animator;
		//init animator
		AladdinAnimation->Init(PathDescriptor,aladdin->getshape(), 0);
		Component* castAnimator = AladdinAnimation;
		//set animator to aladin
		aladdin->setComponente(castAnimator);
	sceneManager.addObject(aladdin);
	//init parallax
	initParallax();
}

void mainManager::onUpdate()
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

		sceneManager.onUpdate();

		*deltaTime += sf::Time(deltaClock.getElapsedTime()).asSeconds();
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
	delete deltaTime;
	sceneManager.onDelete();
	resourceManager.onDelete();
}
void mainManager::imguiAladdinDebug()
{
	ImGui::Begin("Aladdin");
	ImGui::InputFloat("actualspeed", aladdin->actualSpeed);
	float v[2] = { aladdin->direction.x,aladdin->direction.y};
	ImGui::InputFloat2("direcction", v);
	int * id=new int(aladdin->animatorID);
	ImGui::InputInt("AnimID", id);
	delete id;
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

	resourceManager.loadTextures("resources\\Levels\\level1.gif", idtex, sceneManager.gameObjects[fondo1->getID()]->sprite);
	sceneManager.gameObjects[fondo1->getID()]->setTextureID(idtex);
	sceneManager.gameObjects[fondo1->getID()]->setPosition(0, 0, 5);

	fondo2 = new GameObject();
	fondo2->setComponente(new Parallax(aladdin));
	sceneManager.addObject(fondo2);

	resourceManager.loadTextures("resources\\fondo2.jpg", idtex, sceneManager.gameObjects[fondo2->getID()]->sprite);
	sceneManager.gameObjects[fondo2->getID()]->setTextureID(idtex);
	sceneManager.gameObjects[fondo2->getID()]->setPosition(0, 0, 6);
}