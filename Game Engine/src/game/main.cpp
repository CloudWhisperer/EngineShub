#include <iostream>
#include <myengine/myengine.h>
#include <iostream>

using namespace myengine;

struct Player : Component
{
	Player() :
		m_angle(0),
		m_position(0)
	{ }

	void onTick()
	{
		m_angle += 4.0f;

		//m_position += 0.1f;

		getEntity()->getTransform()->setRotation(rend::vec3(m_angle, m_angle, m_angle));

		getEntity()->getTransform()->setPosition(rend::vec3(m_position, 0, -20));

		std::cout << getEntity()->getTransform()->getPosition().x << std::endl;
		std::cout << getEntity()->getTransform()->getPosition().y << std::endl;

		//std::cout << "Ticking" << std::endl;

		//if (m_count > 600)
		//{
			//another way to stop the engine, preferred to get the core first then just getting the entity
			//getEntity()->kill();
			//getEntity()->getCore()->stop();
		//}
	}

private:
	float m_angle;
	float m_position;

};

int main(int argc, char* argv[])
{

	std::cout << "hello world" << std::endl;

	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> e = core->addEntity();
	e->addComponent<Player>();
	e->addComponent<TriangleRenderer>();
	e->addComponent<SoundSource>();

	//how does rend work without include???
	e->getTransform()->setPosition(rend::vec3(0, 0, -5));

	core->start();

	return 0;

}