#ifndef __AMTENGINE_HPP__
#define __AMTENGINE_HPP__

#include "amtengine.h"

namespace adamantengine {
	
class app_t
{
public:
	inline app_t()
	{
		m_app = amt_app_init();
	}
	
	inline ~app_t()
	{
		amt_app_destroy( m_app );
	}
	
	inline execute()
	{
		amt_app_execute( m_app );
	}

private:

	HAPP m_app;
};

}
#endif