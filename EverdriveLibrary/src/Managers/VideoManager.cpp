#include "VideoManager.h"
#include "Defines.h"
#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"

namespace Everdrive
{
	void VideoManager::Init()
	{
		m_Width = WINDOWWIDTH * SCREENSCALE;
		m_Height = WINDOWHEIGHT * SCREENSCALE;
		m_UseGFXOpt = false;
	}

	void VideoManager::Load()
	{
		if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
		{
			return;
		}

		SDL_WM_SetCaption( "Master System", NULL );
		SDL_WM_SetIcon( SDL_LoadBMP( "sega.bmp" ), NULL );
		if( SDL_SetVideoMode( m_Width, m_Height, 8, SDL_OPENGL ) == NULL )
		{
			return;
		}

		// InitGL
		glViewport( 0, 0, m_Width, m_Height );
		glMatrixMode( GL_MODELVIEW );
		glLoadIdentity();
		glOrtho( 0, m_Width, m_Height, 0, -1.0, 1.0 );
		glClearColor( 0, 0, 0, 1.0 );
		glClear( GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT );
		glShadeModel( GL_FLAT );

		glEnable( GL_TEXTURE_2D );
		glDisable( GL_DEPTH_TEST );
		glDisable( GL_CULL_FACE );
		glDisable( GL_DITHER );
		glDisable( GL_BLEND );

		return;
	}
}