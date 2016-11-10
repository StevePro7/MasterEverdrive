#ifndef _ROM_CARTRIDGE_H_
#define _ROM_CARTRIDGE_H_

namespace Everdrive
{
	class RomCartridge
	{
	public:
		RomCartridge(int data) : m_data(data) 
		{
		}

		~RomCartridge()	{}
		int GetData()	{return m_data; }

	private:
		int m_data;
	};
}

#endif//_ROM_CARTRIDGE_H_