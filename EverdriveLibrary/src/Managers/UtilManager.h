#ifndef _UTIL_MANAGER_H_
#define _UTIL_MANAGER_H_

#include "Defines.h"

namespace Everdrive
{
	class UtilManager
	{
	public:

		template< typename T >
		bool TestBit( T data, int position )
		{
			T mask = 1 << position;
			return ( data & mask ) ? true : false;
		}

		template< typename T >
		T BitGetVal( T data, int position )
		{
			T mask = 1 << position;
			return ( data & mask ) ? 1 : 0;
		}

		template< typename T >
		T BitGet( T data, int position )
		{
			T mask = 1 << position;
			return mask;
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
		BYTE BitResetPages( BYTE data )
		{
			BYTE page;
			page = BitReset( data, 7 );
			page = BitReset( page, 6 );
			page = BitReset( page, 5 );
			return page;
		}

		template< typename T >
		int BitCount( T data, int total )
		{
			int result = 0;
			for( int i = 0; i < total; i++ )
			{
				if( TestBit( data, i ) )
				{
					result++;
				}
			}

			return result;
		}

	};
}

#endif//_UTIL_MANAGER_H_