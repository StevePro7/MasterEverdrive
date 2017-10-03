#ifndef _VIDEO_MANAGER_H_
#define _VIDEO_MANAGER_H_

namespace Everdrive
{
	class VideoManager
	{
	public:
		VideoManager()     {}
		~VideoManager()    {}

		void Init();

	private:
		int m_Width;
		int m_Height;
	};
}

#endif//_VIDEO_MANAGER_H_