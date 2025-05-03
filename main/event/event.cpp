#include "event.h"
#include <stdlib.h>



namespace jalc
{

EventHandler::EventHandler()
: m_CurrentEvent(EventType::NONE)
{
}

EventHandler::~EventHandler()
{
}

void EventHandler::SendEvent( const EventType &t)
{
  m_EventBuffer.push_back(t); 
}

bool EventHandler::PollEvents()
{
  if(m_EventBuffer.size() == 0)
  {
    m_CurrentEvent = EventType::NONE;
    return 0;
  }
  m_CurrentEvent = m_EventBuffer.front();
  m_EventBuffer.erase( m_EventBuffer.begin() );
  return 1;
}


EventType EventHandler::Type()
{
  return m_CurrentEvent;
}

}


