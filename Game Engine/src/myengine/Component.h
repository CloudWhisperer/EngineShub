#ifndef MYENGINE_COMPONENT_H
#define MYENGINE_COMPONENT_H

#include <memory>

namespace myengine
{
	/**
	*struct for Entity which contains a whole lot of information about the components thats is connected to it
	*/
	struct Entity;
	struct Component
	{
		std::shared_ptr<Entity> getEntity();///function to get entity

	private:
		friend struct Entity;

		std::weak_ptr<Entity> m_entity;

		virtual void onTick();///function that runs on tick
		virtual void onDisplay();///function thats displays the screen

		void tick();
		void display();

		//std::weak_ptr<Entity> m_entity;
	};

}

#endif