#include <vector>


/**
* Component providing position information of the Entity.
* /
struct Transform : Component
{
	/**
	* Generate the model matrix based on the position, rotation and
	* scale.
	*
	* \return The generated model matrix
	*/
	rend::mat4 getModel();
	/**
	* Set the position.
	*
	* \param _position The new position
	*/
	void setPosition(const vec3& _position);
private:
	vec3 m_position; ///< X, Y, Z location of Entity
	vec3 m_rotation; ///< Rotation of Entity in euler angles
	vec3 m_scale; ///< Scale of Entity
};