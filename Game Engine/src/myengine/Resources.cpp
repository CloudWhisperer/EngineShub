#include "Resources.h"

std::string myengine::Resource::getPath() const
{
	return m_path;
}

void myengine::Resource::load()
{
	//for (size_t i = 0; i < m_resources.size(); ++i)
	//{
	//	if (m_resources.at(i)->getPath() == m_path)
	//	{
	//		return m_resources.at(i);
	//	}
	//}
}
