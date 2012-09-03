#ifndef __AMTENGINE_H
#define __AMTENGINE_H

#ifdef __cplusplus
extern "C" {
#endif
/* Thanks ZeroMQ */
#if defined _MSC_VER
#	if !defined DLL_EXPORT && defined AMT_STATIC
#		define DLL_EXPORT
#	endif
#	if defined DLL_EXPORT
#		define AMT_EXPORT __declspec(dllexport)
#	else
#		define AMT_EXPORT __declspec(dllimport)
#	endif
#else
#   if defined __SUNPRO_C  || defined __SUNPRO_CC
#       define AMT_EXPORT __global
#   elif (defined __GNUC__ && __GNUC__ >= 4) || defined __INTEL_COMPILER
#       define AMT_EXPORT __attribute__ ((visibility("default")))
#   else
#       define AMT_EXPORT
#   endif
#endif

typedef void* HAPP;
typedef void* HGAMEOBJECT;
typedef HGAMEOBJECT HSPRITEOBJECT;

AMT_EXPORT HAPP amt_app_init(void);
AMT_EXPORT int amt_app_execute(HAPP app);
AMT_EXPORT void amt_app_destroy(HAPP app);
AMT_EXPORT void amt_app_object_bind(HAPP app, HGAMEOBJECT object);


typedef struct {
	int x;
	int y;
} pos2i_t;

typedef struct {
	int x;
	int y;
	int z;
} pos3i_t;

typedef struct {
	int top;
	int left;
	int width;
	int height;
} rect_t;

/* Game objects stuff */
/* Allows for custom functions */
AMT_EXPORT HGAMEOBJECT 	amt_gobj_init( pos3i_t* position, pos2i_t* dimension, rect_t* box );
AMT_EXPORT void			amt_gobj_destroy( HGAMEOBJECT gobj );

AMT_EXPORT void 		amt_gobj_set_use_collision(HGAMEOBJECT gobj, int use );
AMT_EXPORT void 		amt_gobj_set_use_update(HGAMEOBJECT gobj, int use );
AMT_EXPORT void 		amt_gobj_set_use_render(HGAMEOBJECT gobj, int use );
AMT_EXPORT void 		amt_gobj_set_use_event(HGAMEOBJECT gobj, int use );
AMT_EXPORT void 		amt_gobj_set_use_cleanup(HGAMEOBJECT gobj, int use );
AMT_EXPORT void 		amt_gobj_set_use_time(HGAMEOBJECT gobj, int use );
AMT_EXPORT void 		amt_gobj_set_position(HGAMEOBJECT gobj, pos3i_t* pos );
AMT_EXPORT void 		amt_gobj_set_velocity(HGAMEOBJECT gobj, pos2i_t* velocity );
AMT_EXPORT void 		amt_gobj_set_dimension(HGAMEOBJECT gobj, pos2i_t* dim );

AMT_EXPORT int 			amt_gobj_get_use_collision(HGAMEOBJECT gobj);
AMT_EXPORT int 			amt_gobj_get_use_update(HGAMEOBJECT gobj);
AMT_EXPORT int 			amt_gobj_get_use_render(HGAMEOBJECT gobj);
AMT_EXPORT int 			amt_gobj_get_use_event(HGAMEOBJECT gobj);
AMT_EXPORT int 			amt_gobj_get_use_cleanup(HGAMEOBJECT gobj);
AMT_EXPORT int 			amt_gobj_get_use_time(HGAMEOBJECT gobj);
AMT_EXPORT pos3i_t* 	amt_gobj_get_position(HGAMEOBJECT gobj);
AMT_EXPORT pos2i_t* 	amt_gobj_get_velocity(HGAMEOBJECT gobj);
AMT_EXPORT pos2i_t* 	amt_gobj_get_dimension(HGAMEOBJECT gobj);

AMT_EXPORT void 		amt_gobj_move_position(HGAMEOBJECT gobj, pos3i_t* pos );
AMT_EXPORT void 		amt_gobj_move_velocity(HGAMEOBJECT gobj, pos2i_t* velocity );

typedef void 			(*update_func)( HGAMEOBJECT gobj, float deltatime );
typedef void 			(*render_func)( HGAMEOBJECT gobj, void* surface );
typedef void 			(*input_func)( HGAMEOBJECT gobj, pos2i_t* input );
typedef void			(*cleanup_func)( HGAMEOBJECT gobj );
typedef void			(*init_func)( HGAMEOBJECT gobj );
typedef void			(*collision_func)( HGAMEOBJECT gobj, int collision );

AMT_EXPORT void 		amt_gobj_on_update(HGAMEOBJECT gobj, update_func update );
AMT_EXPORT void 		amt_gobj_on_render(HGAMEOBJECT gobj, render_func render );
AMT_EXPORT void 		amt_gobj_on_input(HGAMEOBJECT gobj, input_func input );
AMT_EXPORT void 		amt_gobj_on_cleanup(HGAMEOBJECT gobj, cleanup_func cleanup );
AMT_EXPORT void 		amt_gobj_on_init(HGAMEOBJECT gobj, init_func init );
AMT_EXPORT void 		amt_gobj_on_collision(HGAMEOBJECT gobj, collision_func collision );


#ifdef __cplusplus
}
#endif

#endif