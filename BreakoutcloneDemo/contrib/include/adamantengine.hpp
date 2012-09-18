#ifndef __ADAMANTENGINE_HPP__
#define __ADAMANTENGINE_HPP__

#include "PositionDataTypes.hpp"
#include "GameObject.hpp"
#include "Sprite.hpp"
#include "AnimatedSprite.hpp"
#include "CollisionItem.hpp"

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

class IEngine
{
public:
	virtual bool Initialize() = 0;
	virtual int Execute() = 0;
	virtual void Bind(CGameObject* pBindMe) = 0;
};

//Main control point
AMT_EXPORT IEngine* GetEngine();

//pDstRect the width and height are ignored.
AMT_EXPORT void AmtBlit(HSURFACE hSrcSurface, CRect* pSrcRect, HSURFACE hDstSurface, CRect* pDstRect );




#ifdef __cplusplus
	}
#endif


#endif
