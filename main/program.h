#ifndef JALC_PROGRAM_H_
#define JALC_PROGRAM_H_



#include <string>
#include "display.h"
#include "event/event.h"
#include "event/key_event.h"

namespace jalc
{

class Program
{
public:
  // Program();
  virtual ~Program();

  virtual void OnDraw() const = 0;
  virtual void OnUpdate( EventHandler &eh, KeyEventHandler &keh ) = 0;
protected:


};



class ProgramMenu: public Program
{
public:
  ProgramMenu( Display &display );
  ~ProgramMenu();

  void OnDraw() const;
  void OnUpdate( EventHandler &eh, KeyEventHandler &keh );

private:
  Display        *m_Display;
  int             m_Cursor;
  std::string    *m_Apps;
  unsigned int    m_AppCount;


};


}


#endif
