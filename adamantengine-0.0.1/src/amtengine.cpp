#include "../include/amtengine.h"
#include "platform.hpp"
#include "defines.h"

#include "App.hpp"
using adamantengine::app_t;

#include "GameObject.hpp"
#include "Sprite.hpp"

//Application functions

HAPP amt_app_init(void)
{
	app_t* pApp = new app_t;
	bool bValid = pApp->Intialize();
	if ( !bValid )
	{
		amt_app_destroy( pApp );
		pApp = NULL;
	}

	return pApp;
}

int amt_app_execute(HAPP app)
{
	app_t* pApp = (app_t*)app;
	return pApp->Execute();
}

void amt_app_destroy(HAPP app)
{
	app_t* pApp = (app_t*)app;
	delete pApp;
}

void amt_app_object_bind(HAPP app, HGAMEOBJECT object)
{
	app_t* pApp = (app_t*)app;
	pApp->BindObject( (adamantengine::gameobject_t*)object );
}

void amt_app_set_offscreen_col(HAPP app, int flags )
{
	((app_t*)app)->SetDetectOffscreenCollision( flags == 1 );
}

HGAMEOBJECT amt_gobj_init( pos3f_t* position, pos2f_t* dimension, rect_t* box )
{
	return (HGAMEOBJECT)new adamantengine::gameobject_t( position, dimension, box );
}

void amt_gobj_destroy( HGAMEOBJECT gobj )
{
	delete ((adamantengine::gameobject_t*)gobj);
}

void amt_gobj_set_use_collision(HGAMEOBJECT gobj, int use )
{
	((adamantengine::gameobject_t*)gobj)->SetUseCollision( use == 1 );
}

void amt_gobj_set_use_update(HGAMEOBJECT gobj, int use )
{
	((adamantengine::gameobject_t*)gobj)->SetUseUpdate( use == 1 );
}

void amt_gobj_set_use_render(HGAMEOBJECT gobj, int use )
{
	((adamantengine::gameobject_t*)gobj)->SetUseRender( use == 1 );
}

void amt_gobj_set_use_event(HGAMEOBJECT gobj, int use )
{
	((adamantengine::gameobject_t*)gobj)->SetUseEvent( use == 1 );
}

void amt_gobj_set_use_cleanup(HGAMEOBJECT gobj, int use )
{
	((adamantengine::gameobject_t*)gobj)->SetUseCleanup( use == 1 );
}

void amt_gobj_set_use_time(HGAMEOBJECT gobj, int use )
{
	((adamantengine::gameobject_t*)gobj)->SetUseTime( use == 1 );
}

void amt_gobj_set_position(HGAMEOBJECT gobj, pos3f_t* pos )
{
	if ( pos == NULL ) return;

	((adamantengine::gameobject_t*)gobj)->SetPosition( *pos );
}

void amt_gobj_set_velocity(HGAMEOBJECT gobj, pos2f_t* velocity )
{
	if ( velocity == NULL ) return;
	((adamantengine::gameobject_t*)gobj)->SetVelocity( *velocity );
}

void amt_gobj_set_dimension(HGAMEOBJECT gobj, pos2f_t* dim )
{
	if ( dim == NULL ) return;
	((adamantengine::gameobject_t*)gobj)->SetDimension( *dim );
}

void amt_gobj_set_userdata(HGAMEOBJECT gobj, void* userdata)
{
	((adamantengine::gameobject_t*)gobj)->SetUserData( userdata );
}

int amt_gobj_get_use_collision(HGAMEOBJECT gobj)
{
	return ((adamantengine::gameobject_t*)gobj)->UseCollision() ? 1 : 0;
}

int amt_gobj_get_use_update(HGAMEOBJECT gobj)
{
	return ((adamantengine::gameobject_t*)gobj)->UseUpdate() ? 1 : 0;
}

int amt_gobj_get_use_render(HGAMEOBJECT gobj)
{
	return ((adamantengine::gameobject_t*)gobj)->UseRender() ? 1 : 0;
}

int	amt_gobj_get_use_event(HGAMEOBJECT gobj)
{
	return ((adamantengine::gameobject_t*)gobj)->UseEvent() ? 1 : 0;
}

int amt_gobj_get_use_cleanup(HGAMEOBJECT gobj)
{
	return ((adamantengine::gameobject_t*)gobj)->UseCleanup() ? 1 : 0;
}

int	amt_gobj_get_use_time(HGAMEOBJECT gobj)
{
	return ((adamantengine::gameobject_t*)gobj)->UseTime() ? 1 : 0;
}

pos3f_t* amt_gobj_get_position(HGAMEOBJECT gobj)
{
	return &((adamantengine::gameobject_t*)gobj)->Position();
}

pos2f_t* amt_gobj_get_velocity(HGAMEOBJECT gobj)
{
	return &((adamantengine::gameobject_t*)gobj)->Velocity();
}

pos2f_t* amt_gobj_get_dimension(HGAMEOBJECT gobj)
{
	return &((adamantengine::gameobject_t*)gobj)->Dimension();
}

void amt_gobj_move_position(HGAMEOBJECT gobj, pos3f_t* pos )
{
	if ( pos == NULL ) return;

	((adamantengine::gameobject_t*)gobj)->MovePosition( *pos );
}

void amt_gobj_move_velocity(HGAMEOBJECT gobj, pos2f_t* velocity )
{
	if ( velocity == NULL ) return;

	((adamantengine::gameobject_t*)gobj)->MoveVelocity( *velocity );
}

void amt_gobj_on_update(HGAMEOBJECT gobj, update_func update )
{
	((adamantengine::gameobject_t*)gobj)->SetOnUpdate( update );
}

void amt_gobj_on_render(HGAMEOBJECT gobj, render_func render )
{
	((adamantengine::gameobject_t*)gobj)->SetOnRender( render );
}

void amt_gobj_on_input(HGAMEOBJECT gobj, input_func input )
{
	((adamantengine::gameobject_t*)gobj)->SetOnInput( input );
}

void amt_gobj_on_cleanup(HGAMEOBJECT gobj, cleanup_func cleanup )
{
	((adamantengine::gameobject_t*)gobj)->SetOnCleanup( cleanup );
}

void amt_gobj_on_init(HGAMEOBJECT gobj, init_func init )
{
	((adamantengine::gameobject_t*)gobj)->SetOnInit( init );
}

void amt_gobj_on_collision(HGAMEOBJECT gobj, collision_func collision )
{
	((adamantengine::gameobject_t*)gobj)->SetOnCollision( collision );
}

HSPRITEOBJECT amt_spr_create( const char* pszFileName )
{
	return new adamantengine::sprite_t( pszFileName );
}

void amt_spr_render( HSPRITEOBJECT spr, void* dest_surface )
{
	((adamantengine::sprite_t*)spr)->Render( (SDL_Surface*)dest_surface );
}

void amt_blit( HSPRITEOBJECT hSprite, rect_t* source_rc, void* display_surface, rect_t* display_rc )
{
	SDL_Rect source = {0};
	SDL_Rect* pSourceRC = NULL;
	if ( source_rc != NULL )
	{
		pSourceRC = &source;
		source.x = source_rc->left;
		source.y = source_rc->top;
		source.h = source_rc->height;
		source.w = source_rc->width;
	}

	SDL_Rect dest = {0};
	SDL_Rect* pDestRC = NULL;
	if ( display_rc != NULL )
	{
		pDestRC = &dest;
		dest.x = display_rc->left;
		dest.y = display_rc->top;
		dest.h = display_rc->height;
		dest.w = display_rc->width;
	}

	SDL_Surface* pSource = ((adamantengine::sprite_t*)hSprite)->GetSurface();
	SDL_BlitSurface( pSource, pSourceRC, (SDL_Surface*)display_surface, pDestRC ); 
}