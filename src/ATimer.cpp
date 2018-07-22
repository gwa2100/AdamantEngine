#include "ATimer.h"

ATimer::ATimer()
  : m_uStartTicks(0)
  , m_uPausedTicks(0)
  , m_bPaused( false )
  , m_bStarted( false )
{
    //ctor
}

ATimer::~ATimer()
{
    //dtor
}

void ATimer::Start()
{
    //Start the timer
    m_bStarted = true;

    //unpause the timer
    m_bPaused = false;

    //Get the current clock time
    m_uStartTicks = SDL_GetTicks();
}

void ATimer::Stop()
{
    //stop the timer
    m_bStarted = false;

    //Unpause the timer
    m_bPaused = false;

}

Uint32 ATimer::GetTicks() const
{
    //If the timer is running
    if( m_bStarted == true )
    {
        //If the timer is paused
        if( m_bPaused == true )
        {
            //Return the number of ticks when the timer was paused
            return m_uPausedTicks;
        }
        else
        {
            //Return the current time minus the start time
            return SDL_GetTicks() - m_uStartTicks;
        }
    }

    //If the timer isn't running
    return 0;
}

//This will do a GetTicks and give you the delta from the last GetTicks() call
Uint32 ATimer::GetTicksDelta()
{
    m_uPrevTime = m_uCurrTime;
    m_uCurrTime = GetTicks();
    return m_uLastDeltaTime = m_uCurrTime - m_uPrevTime;
}

void ATimer::Pause()
{
    //If the timer is running and isn't already paused
    if( ( m_bStarted == true ) && ( m_bPaused == false ) )
    {
        //Pause the timer
        m_bPaused = true;

        //Calculate the paused ticks
        m_uPausedTicks = SDL_GetTicks() - m_uStartTicks;
    }
}


void ATimer::Resume()
{
    //If the timer is paused
    if( m_bPaused == true )
    {
        //Unpause the timer
        m_bPaused = false;

        //Reset the starting ticks
        m_uStartTicks = SDL_GetTicks() - m_uPausedTicks;

        //Reset the paused ticks
        m_uPausedTicks = 0;
    }
}
