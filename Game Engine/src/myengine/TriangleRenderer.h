#include "myengine/Component.h"
#include <rend/rend.h>
namespace myengine
{
	struct TriangleRenderer : Component
	{
		/// <summary>
		/// a function that renders a triangle of choice, takes in a few parameters to adjust triangle.
		/// </summary>
		TriangleRenderer();
	private:
		rend::Mesh m_mesh;
		rend::Mesh m_enemy;
		rend::Mesh m_enemy2;
		rend::Shader m_shader;
		void onDisplay();
	};
}