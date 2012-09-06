#ifdef _WIN32
#include <Windows.h>
#endif

#include "amtengine.hpp"

int main( int argc, char* argv[] )
{
//Remove the console..
#ifdef _WIN32
	HWND hWnd = GetConsoleWindow();
	ShowWindow( hWnd, SW_HIDE );
#endif
	adamantengine::CApp app;
	adamantengine::CSprite Ball( "test_ball.bmp" );
	app.Bind( Ball );
	app.SetDetectOffscreenCollision( true );
	Ball.SetPosition( adamantengine::CPosition( 50.0f, 50.0f) );
	Ball.SetVelocity( adamantengine::CVelocity( 0.7f, 0.7f) );
	Ball.SetUseUpdate( true );
	Ball.SetUseCollision( true );
	return app.Execute();
}