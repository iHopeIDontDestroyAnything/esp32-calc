#ifndef JALC_KEY_EVENT_H_
#define JALC_KEY_EVENT_H_

#include <unordered_map>
#include <vector>


//CALCULATOR BUTTON PINS WITH NUMBERS

#define BUT_ZERO    13
#define BUT_ONE     14
#define BUT_TWO     12
#define BUT_THREE   12
#define BUT_FOUR    12
#define BUT_FIVE    12
#define BUT_SIX     12
#define BUT_SEVEN   12
#define BUT_EIGHT   12
#define BUT_NINE    12



namespace jalc
{

class EventHandler;

enum class Scancode
{
  ZERO = 0, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, 
  EQUALS, PLUS, MINUS, MULTIPLY, DEVIDE, 
  SIN, COS, TAN, POW, SQRT,
  RESET
};


class KeyEventHandler
{
public:
  KeyEventHandler();
  ~KeyEventHandler();

  bool IsPressed( Scancode scancode );
  bool ISReleased( Scancode scancode );
  // void IgnoreUntilReleased( Scancode scancode );
  // void SetEmergencyQuitKey( Scancode scancode );
  void PrintStateMap();

private:

  friend void CacheKeyEvents( EventHandler &eh, KeyEventHandler &kh );

  Scancode                                               *m_EmergencyQuitButton;
  std::vector<unsigned char>                              m_ButtonPins;
  std::unordered_map<int, Scancode>                       m_PinToScancode;
  std::unordered_map<Scancode, std::pair<bool,bool> >     m_KeyStateMap;



};

void CacheKeyEvents( EventHandler &eh, KeyEventHandler &kh );

}


#endif
