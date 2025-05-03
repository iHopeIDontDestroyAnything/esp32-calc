#ifndef JAJO_EVENT_H_
#define JAJO_EVENT_H_

// #include "key_event.h"
#include <vector>


namespace jalc
{


enum class EventType
{
  NONE = 0,
  KEY_PRESSED, KEY_RELEASED,
  APPLICATION_EVENT,
  EMERGENCY_QUIT
};



class EventHandler
{
public:
  EventHandler();
  ~EventHandler();

  void          SendEvent( const EventType &t);
  bool          PollEvents();
  EventType     Type();

private:
  EventType               m_CurrentEvent;
  std::vector<EventType>  m_EventBuffer;

};





}
#endif
