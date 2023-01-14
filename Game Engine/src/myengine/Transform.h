#include <vector>
#include "Component.h"
#include <rend/rend.h>

namespace myengine
{
	struct Transform : Component
	{
		/// @brief gets the model and sets rotation,scale, and position in the world
		Transform();

		/// @brief gets the model
		/// @return mat4
		rend::mat4 getModel();

		/// @brief sets position of the object
		/// @param _position 
		void setPosition(const rend::vec3& _position);

		/// @brief gets position of the object
		/// @return vector 3
		rend::vec3 getPosition();

		/// @brief sets the rotation of the 3d model
		/// @param _rotation 
		void setRotation(const rend::vec3& _rotation);

	private:
		rend::vec3 m_position;
		rend::vec3 m_rotation;
		rend::vec3 m_scale;

	};
};
