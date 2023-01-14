#include "Component.h"
#include <AL/al.h>
#include <string>

namespace myengine
{
	struct SoundSource : Component
	{
		/// @brief prepares the sound and plays it
		SoundSource();
		//SoundSource(std::string _path = NULL)

		/// @brief ontick function for the audiosource
		void onTick();

	private:
		ALuint sourceId;
	};

}