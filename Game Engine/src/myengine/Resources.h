#include <string>
#include "Component.h"
#include "rend/rend.h"
#include <vector>
#include <memory>
//#include "SoundSource.h"

//dont have a audiofile or a textfile yet, will add them later

namespace myengine
{
	/**
	*struct for resources
	*/
	struct Resources;

	/**
	*struct for resources which includes the functions to load and get the path of the resource that is being used
	*/
	struct Resource
	{
		virtual void onLoad() = 0;
		std::string getPath() const;
	private:
		friend struct Resources;
		std::string m_path;
		void load();
	};

	/**
	*struct for texture which is a resource
	*/
	struct Texture : Resource
	{
		void onLoad()
		{
			m_texture = std::make_shared<rend::Texture>(getPath().c_str());
		}
	private:
		std::shared_ptr<rend::Texture> m_texture;
	};

	//struct Model : Resource
	//{
	//	void onLoad();
	//private:
	//	std::shared_ptr<rend::Model> m_model;
	//};

	//struct Shader : Resource
	//{
	//	void onLoad();
	//private:
	//	std::shared_ptr<rend::Shader> m_shader;
	//};

	//struct SoundSource : Resource
	//{
	//	void onLoadsound();
	//private:
	//	std::shared_ptr<myengine::SoundSource> m_soundsource;
	//};


	/**
	*contains the loop to load a resource, because this is a template the function can go in the header file
	*/
	struct Resources
	{
		template <typename T>
		std::shared_ptr<T> load(const std::string& _path)
		{
			// Search for previously loaded resource
			for (size_t i = 0; i < m_resources.size(); ++i)
			{
				std::cout << "searching for loaded resource" << std::endl;
				// Return it if found
				if (m_resources.at(i)->getPath() == _path)
				{
					std::cout << "found resource" << std::endl;
					return std::dynamic_pointer_cast<T>(m_resources.at(i));
				}
			}
			// Create new instance, construct it and add to cache
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->m_path = _path;
			rtn->load();
			m_resources.push_back(rtn);
			return rtn;
		}

	/**
	*private variables needed for the resources
	*/
	private:
		std::vector<std::shared_ptr<Resource> > m_resources;
	};

}

