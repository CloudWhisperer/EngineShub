#include <vector>
#include "Component.h"
#include <rend/rend.h>

namespace myengine
{
	struct Transform : Component
	{
		Transform();

		rend::mat4 getModel();

		void setPosition(const rend::vec3& _position);
		rend::vec3 getPosition();
		void setRotation(const rend::vec3& _rotation);

	private:
		rend::vec3 m_position;
		rend::vec3 m_rotation;
		rend::vec3 m_scale;

	};
};
