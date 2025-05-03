#include "key_event.h"
#include "event.h"
#include <Arduino.h>



namespace jalc
{


jalc::KeyEventHandler::KeyEventHandler()
{
  m_EmergencyQuitButton = NULL;
  //not set
  
  m_KeyStateMap[Scancode::ZERO].first = 0;
  m_KeyStateMap[Scancode::ZERO].second = 0;
  m_PinToScancode[BUT_ZERO] = Scancode::ZERO;
  pinMode(BUT_ZERO, INPUT_PULLUP);
  m_ButtonPins.push_back(BUT_ZERO);

  m_KeyStateMap[Scancode::ONE].first = 0;
  m_KeyStateMap[Scancode::ONE].second = 0;
  m_PinToScancode[BUT_ONE] = Scancode::ONE;
  pinMode(BUT_ONE, INPUT_PULLUP);
  m_ButtonPins.push_back(BUT_ONE);

  m_KeyStateMap[Scancode::TWO].first = 0;
  m_KeyStateMap[Scancode::TWO].second = 0;
  m_PinToScancode[BUT_TWO] = Scancode::TWO;
  pinMode(BUT_TWO, INPUT_PULLUP);
  m_ButtonPins.push_back(BUT_TWO);

  m_KeyStateMap[Scancode::THREE].first = 0;
  m_KeyStateMap[Scancode::THREE].second = 0;
  m_PinToScancode[BUT_THREE] = Scancode::THREE;
  pinMode(BUT_THREE, INPUT_PULLUP);
  m_ButtonPins.push_back(BUT_THREE);

  m_KeyStateMap[Scancode::FOUR].first = 0;
  m_KeyStateMap[Scancode::FOUR].second = 0;
  m_PinToScancode[BUT_FOUR] = Scancode::FOUR;
  pinMode(BUT_FOUR, INPUT_PULLUP);
  m_ButtonPins.push_back(BUT_FOUR);
  m_KeyStateMap[Scancode::FIVE].first = 0;
  m_KeyStateMap[Scancode::FIVE].second = 0;
  m_PinToScancode[BUT_FIVE] = Scancode::FIVE;
  pinMode(BUT_FIVE, INPUT_PULLUP);
  m_ButtonPins.push_back(BUT_FIVE);

  m_KeyStateMap[Scancode::SIX].first = 0;
  m_KeyStateMap[Scancode::SIX].second = 0;
  m_PinToScancode[BUT_SIX] = Scancode::SIX;
  pinMode(BUT_SIX, INPUT_PULLUP);
  m_ButtonPins.push_back(BUT_SIX);

  m_KeyStateMap[Scancode::SEVEN].first = 0;
  m_KeyStateMap[Scancode::SEVEN].second = 0;
  m_PinToScancode[BUT_SEVEN] = Scancode::SEVEN;
  pinMode(BUT_SEVEN, INPUT_PULLUP);
  m_ButtonPins.push_back(BUT_SEVEN);

  m_KeyStateMap[Scancode::EIGHT].first = 0;
  m_KeyStateMap[Scancode::EIGHT].second = 0;
  m_PinToScancode[BUT_EIGHT] = Scancode::EIGHT;
  pinMode(BUT_EIGHT, INPUT_PULLUP);
  m_ButtonPins.push_back(BUT_EIGHT);

  m_KeyStateMap[Scancode::NINE].first = 0;
  m_KeyStateMap[Scancode::NINE].second = 0;
  m_PinToScancode[BUT_NINE] = Scancode::NINE;
  pinMode(BUT_NINE, INPUT_PULLUP);
  m_ButtonPins.push_back(BUT_NINE);


}

jalc::KeyEventHandler::~KeyEventHandler()
{

}

void CacheKeyEvents( EventHandler &eh, KeyEventHandler &kh )
{
  for( auto const& pin : kh.m_ButtonPins )
  {
    int pinStateBefore;
    if(kh.m_KeyStateMap[ kh.m_PinToScancode[pin] ].first == 1)
      pinStateBefore = (int)EventType::KEY_PRESSED;
    else
      pinStateBefore = (int)EventType::KEY_RELEASED;
    //checks what state was the button last time

    if( !digitalRead(pin) )
    {
      kh.m_KeyStateMap[ kh.m_PinToScancode[pin] ].first = 1;
      if(pinStateBefore == (int)EventType::KEY_RELEASED)
        eh.SendEvent(EventType::KEY_PRESSED);
    }
    else
    {
      kh.m_KeyStateMap[ kh.m_PinToScancode[pin] ].first = 0;
      if(pinStateBefore == (int)EventType::KEY_PRESSED)
        eh.SendEvent(EventType::KEY_RELEASED);
    }
  }
}

void KeyEventHandler::PrintStateMap()
{
  for( auto const& state : m_KeyStateMap )
  {
    printf("SCANCODE:%d VALUE:%d IGNORED:%d \n",  (int)state.first,
                                                  state.second.first,
                                                  state.second.second);
  }
  // for(auto const& pin : m_ButtonPins )
  // {
  //   printf("PIN:%d\n",pin);
  // }
}



bool KeyEventHandler::IsPressed( Scancode scancode )
{
  if( m_KeyStateMap[scancode].first == 1)
    return 1;
  return 0;
}

bool KeyEventHandler::ISReleased( Scancode scancode )
{
  if( m_KeyStateMap[scancode].first == 0)
    return 1;
  return 0;
}


}



