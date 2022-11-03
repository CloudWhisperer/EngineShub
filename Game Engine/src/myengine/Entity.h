#include <list>
#include <memory>

namespace myengine
{
	struct Component;
	struct Core;

	struct Entity
	{
		template <typename T>
		std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();

			m_components.push_back(rtn);

			return rtn;
		}



	private:
		friend struct Core;
		std::list<std::shared_ptr<Component> > m_components;

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