#ifndef _UTIL_MANAGER_H_
#define _UTIL_MANAGER_H_

namespace Everdrive
{
	class UtilManager
	{
	public:

		template< typename T >
		bool TestBit( T data, int position )
		{
			T mask = 1 << position;
			return ( data & mask );
		}

		template< typename T >
		T BitSet( T data, int position )
		{
			T mask = 1 << position;
			data |= mask;

			return data;
		}

		template< typename T >
		T BitReset( T data, int position )
		{
			T mask = 1 << position;
			data &= ~mask;

			return data;
		}

	};
}

#endif//_UTIL_MANAGER_H_