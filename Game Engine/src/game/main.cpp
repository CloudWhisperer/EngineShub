#include <iostream>
#include <myengine/myengine.h>
#include <iostream>

using namespace myengine;
const Uint8* state = SDL_GetKeyboardState(NULL);

struct Player : Component
{
	Player() :
		m_angle(0),
		m_position(0),
		m_positiony(0)
	{ }

	void onTick()
	{
		m_angle += 0.4f;

		if (state[SDL_SCANCODE_RIGHT])
		{
			std::cout << "right arrow key press" << std::endl;
			getEntity()->getTransform()->setPosition(rend::vec3(m_position += 0.2 , m_positiony, -20));
			m_angle += 9.0f;
		}
		if (state[SDL_SCANCODE_LEFT])
		{
			std::cout << "left arrow key press" << std::endl;
			getEntity()->getTransform()->setPosition(rend::vec3(m_position -= 0.2, m_positiony, -20));
			m_angle += 9.0f;
		}
		if (state[SDL_SCANCODE_UP])
		{
			std::cout << "up arrow key press" << std::endl;
			getEntity()->getTransform()->setPosition(rend::vec3(m_position, m_positiony += 0.2, -20));
			m_angle += 9.0f;
		}
		if (state[SDL_SCANCODE_DOWN])
		{
			std::cout << "up arrow key press" << std::endl;
			getEntity()->getTransform()->setPosition(rend::vec3(m_position, m_positiony -= 0.2, -20));
			m_angle += 9.0f;
		}

		getEntity()->getTransform()->setRotation(rend::vec3(m_angle, m_angle, m_angle));
	}

private:
	float m_angle;
	float m_position;
	float m_positiony;

};

struct Enemy : Component
{
	Enemy() :
		enemy_angle(0),
		enemy_position(0),
		enemy_positiony(10)
	{ }

	void onTick()
	{
		enemy_angle += 10.0f;

		getEntity()->getTransform()->setRotation(rend::vec3(enemy_angle, enemy_angle, enemy_angle));

		getEntity()->getTransform()->setPosition(rend::vec3(enemy_position, enemy_positiony -=0.1, -20));
	}

private:
	float enemy_angle;
	float enemy_position;
	float enemy_positiony;
		
};

int main(int argc, char* argv[])
{

	std::cout << "SHUBENGINE LOADED SUCCESSFULLY" << std::endl;

	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> e = core->addEntity();
	e->addComponent<Player>();
	e->addComponent<TriangleRenderer>();
	e->addComponent<SoundSource>();
	e->addComponent<irccomponent>();

	//std::shared_ptr<Texture> cattext = core->getResources()->load<Texture>("Textures/cat.png");

	e->getTransform()->setPosition(rend::vec3(0, 0, -5));

	std::shared_ptr<Entity> e2 = core->addEntity();
	e2->addComponent<TriangleRenderer>();
	e2->addComponent<Enemy>();

	core->start();

	return 0;

}