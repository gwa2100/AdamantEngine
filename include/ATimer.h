#ifndef ATIMER_H
#define ATIMER_H

#include <stdint.h>
#include <SDL2/SDL_timer.h>

class ATimer
{
    public:
        /** Default constructor */
        ATimer();

        /** Default destructor */
        virtual ~ATimer();

        void Start();
        void Stop();
        void Pause();
        void Resume();

        /** Get the clocks current time
         * \return The current time in Ticks
         */
        uint32_t GetTicks() const;

        uint32_t GetTicksDelta();


        /** Access m_uPrevTime
         * \return The current value of m_uPrevTime
         */
        uint32_t GetuPrevTime() const{ return m_uPrevTime; };


        /** Access m_uCurrTime
         * \return The current value of m_uCurrTime
         */
        uint32_t GetuCurrTime() const{ return m_uCurrTime; };


        //Get the last delta time we found.
        uint32_t GetLastDeltaTime() const{ return m_uLastDeltaTime; };

        bool IsStarted() const {return m_bStarted;};

        bool IsPaused() const {return m_bPaused;};




    private:
        uint32_t m_uPrevTime; //!< Member variable "m_uPrevTime"
        uint32_t m_uCurrTime; //!< Member variable "m_uCurrTime"
        uint32_t m_uLastDeltaTime; //The last delta we recorded
        uint32_t m_uStartTicks;  //clock ticks when the timer was started
        uint32_t m_uPausedTicks; //clock ticks when the timer was paused
        bool m_bPaused; //!< Member variable "m_bPaused"
        bool m_bStarted; //!< Member variable "m_bStarted"
};

#endif // ATIMER_H
