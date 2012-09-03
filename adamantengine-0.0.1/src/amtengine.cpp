#include "../include/amtengine.h"
#include "platform.hpp"
#include "defines.h"

#include "App.hpp"
using adamantengine::app_t;

#include "GameObject.hpp"

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

HGAMEOBJECT amt_gobj_init( pos3i_t* position, pos2i_t* dimension, rect_t* box )
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

void amt_gobj_set_position(HGAMEOBJECT gobj, pos3i_t* pos )
{
	if ( pos == NULL ) return;

	((adamantengine::gameobject_t*)gobj)->SetPosition( *pos );
}

void amt_gobj_set_velocity(HGAMEOBJECT gobj, pos2i_t* velocity )
{
	if ( velocity == NULL ) return;
	((adamantengine::gameobject_t*)gobj)->SetVelocity( *velocity );
}

void amt_gobj_set_dimension(HGAMEOBJECT gobj, pos2i_t* dim )
{
	if ( dim == NULL ) return;
	((adamantengine::gameobject_t*)gobj)->SetDimension( *dim );
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

pos3i_t* amt_gobj_get_position(HGAMEOBJECT gobj)
{
	return &((adamantengine::gameobject_t*)gobj)->Position();
}

pos2i_t* amt_gobj_get_velocity(HGAMEOBJECT gobj)
{
	return &((adamantengine::gameobject_t*)gobj)->Velocity();
}

pos2i_t* amt_gobj_get_dimension(HGAMEOBJECT gobj)
{
	return &((adamantengine::gameobject_t*)gobj)->Dimension();
}

void amt_gobj_move_position(HGAMEOBJECT gobj, pos3i_t* pos )
{
	if ( pos == NULL ) return;

	((adamantengine::gameobject_t*)gobj)->MovePosition( *pos );
}

void amt_gobj_move_velocity(HGAMEOBJECT gobj, pos2i_t* velocity )
{
	if ( velocity == NULL ) return;

	((adamantengine::gameobject_t*)gobj)->MoveVelocity( *velocity );
}

void amt_gobj_on_update(HGAMEOBJECT gobj, update_func update )
{
}

void amt_gobj_on_render(HGAMEOBJECT gobj, render_func render )
{
}

void amt_gobj_on_input(HGAMEOBJECT gobj, input_func input )
{
}

void amt_gobj_on_cleanup(HGAMEOBJECT gobj, cleanup_func cleanup )
{

}

void amt_gobj_on_init(HGAMEOBJECT gobj, init_func init )
{

}

void amt_gobj_on_collision(HGAMEOBJECT gobj, collision_func collision )
{
}
