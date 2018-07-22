#include "Engine.h"

//Z Comparison (DEPTH)
//bool operator < (const CGameObject& left, const CGameObject& right)
//{
//	if  (left.GetPosition().z < right.GetPosition().z) return true;
//	return false;
//}


Engine::Engine()
 : m_bRunning( true )
 , m_pSurfDisplay(NULL)
 , m_uPrevTime(0)
 , m_uCurrTime(0)
 , m_uAccTime(0)
 , m_nGravRate(0)
 , m_nGravFrame(0)
 , m_bJump(false)
 , m_bAlreadyJump(false)
 , m_nJumpTime(0)
 , m_nJumpPower(0)

{
}

Engine::~Engine()
{
    //dtor
}
