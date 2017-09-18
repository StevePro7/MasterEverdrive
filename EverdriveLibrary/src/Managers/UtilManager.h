#ifndef _UTIL_MANAGER_H_
#define _UTIL_MANAGER_H_

namespace Everdrive
{
	class UtilManager
	{
	public:

		bool GetData() { return true; }

		template< typename T >
		bool TestBit( T data, int position )
		{
			T mask = 1 << position;
			return ( data & mask );
		}
	};
}

#endif//_UTIL_MANAGER_H_