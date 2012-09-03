#ifndef __APP_HPP__
#define __APP_HPP__

namespace adamantengine {

class CApp
{
public:
	CApp();
	~CApp();
	
	int Execute();
	
private:

	void OnInit();
	void OnInput();
	void OnUpdate();
	void OnRender();
	

	bool m_bRunning;
};


}


#endif