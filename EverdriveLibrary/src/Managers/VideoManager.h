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
		void Load();

		int GetWidth() const { return m_Width; }
		int GetHeight() const { return m_Height; }
		bool GetUseGFXOpt() const { return m_UseGFXOpt; }

	private:
		int m_Width;
		int m_Height;
		bool m_UseGFXOpt ;
	};
}

#endif//_VIDEO_MANAGER_H_