#include <list>
#include <memory>

namespace myengine
{
	struct Component;
	struct Core;
	struct Transform;

	struct Entity
	{
		template <typename T>
		/// @brief adds a component to the engine
		/// @tparam T 
		/// @return returns te entity with the component in it
		std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();

			rtn->m_entity = m_self;

			m_components.push_back(rtn);

			return rtn;
		}

		std::shared_ptr<Core> getCore();
		std::shared_ptr<Transform> getTransform();

		template <typename T>
		std::shared_ptr<T> getComponent()
		{
			for (std::list<std::shared_ptr<Component> >::iterator it = m_components.begin();
				it != m_components.end();
				it++)
			{
				std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(*it);
				if (rtn)
				{
					return rtn;
				}
			}
			throw std::runtime_error("cannot find specified component");
		}

	private:
		friend struct Core;

		/// creates pointers to itself and core
		std::weak_ptr<Core> m_core;
		std::weak_ptr<Entity> m_self;
		std::list<std::shared_ptr<Component> > m_components;
		bool m_alive;
		std::weak_ptr<Transform> m_transform;

		/// <summary>
		/// calculates the tick rate of the engine
		/// </summary>
		void tick();

		/// <summary>
		/// displays the tick rate of the engine in the command prompt
		/// </summary>
		void display();

	};

}