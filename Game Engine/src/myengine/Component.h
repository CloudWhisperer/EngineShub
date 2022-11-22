#ifndef MYENGINE_COMPONENT_H
#define MYENGINE_COMPONENT_H

#include <memory>

namespace myengine
{
	struct Entity;
	struct Component
	{
		std::shared_ptr<Entity> getEntity();

	private:
		friend struct Entity;

		std::weak_ptr<Entity> m_entity;

		virtual void onTick();
		virtual void onDisplay();

		void tick();
		void display();

		//std::weak_ptr<Entity> m_entity;
	};

}

#endif