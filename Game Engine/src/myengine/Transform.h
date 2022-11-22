#include <vector>
#include "Component.h"
#include <rend/rend.h>

namespace myengine
{
	struct transform : Component
	{
		Transform();

		rend::mat4 getModel();

	private:
		rend::vec3 m_position;
		rend::vec3 m_rotation;
		rend::vec3 m_scale;

	};
};