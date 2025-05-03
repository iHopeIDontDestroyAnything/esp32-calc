#include "display.h"
#include "stdio.h"

namespace jalc
{

unsigned int Display::Height() const
{
  return screen.height();
}

unsigned int Display::Width() const
{
  return screen.width();
}

unsigned int Display::GetRotation() const
{
  return screen.getRotation();
}

void Display::SetRotation( const unsigned char mode )
{
  if( mode > 3 || mode < 0 )
  {
    printf("Wrong Display SetRotation mode");
    return;
  }
  screen.setRotation( mode );
}


Display::Display()
:screen(256, 64, &SPI, OLED_DC, OLED_RESET, OLED_CS)
{
  if ( ! screen.begin(0x3D) ) {
    printf("Unable to initialize OLED");
  }
}


void Display::Update()
{
  screen.display();
}

void Display::Clear()
{
  screen.clearDisplay();
}


void Display::SetCursor( XYCoord_t pos )
{
  screen.setCursor( pos.x, pos.y );
}

void Display::Print( const char * msg)
{
  screen.setTextWrap( false );
  screen.write( msg );
}

void Display::Print( const unsigned char ascii )
{
  screen.write( ascii );
}

 
void Display::SetTextSize( const unsigned char texSize )
{
  screen.setTextSize( texSize );
}

void Display::SetTextColor( const unsigned char color )
{
  screen.setTextColor( color );
}



void Display::PrintBitMap( const XYCoord_t corner,
                           const unsigned char w,
                           const unsigned char h,
                           const unsigned char *bitmap,
                           unsigned char color) 
{
  screen.drawBitmap( corner.x, corner.y, bitmap, w, h, color);
}


void Display::DrawTriangle( const XYCoord_t a,
                            const XYCoord_t b,
                            const XYCoord_t c,
                            const unsigned char color,
                            bool fill)
{
  if(!fill)
  screen.drawTriangle(  a.x, a.y,
                        b.x, b.y,
                        c.x, c.y,
                        color);
  else
  screen.fillTriangle(  a.x, a.y,
                        b.x, b.y,
                        c.x, c.y,
                        color);
}



void Display::DrawRect( const XYCoord_t corner,
                        const unsigned char w,
                        const unsigned char h,
                        const unsigned char color,
                        bool fill)
{
  if(!fill)
    screen.drawRect( corner.x, corner.y,
                     w, h,
                     color);
  else
    screen.fillRect( corner.x, corner.y,
                     w, h,
                     color);
}


void Display::DrawLine( const XYCoord_t a,
                        const XYCoord_t b,
                        const unsigned char color)
{
  screen.drawLine( a.x, a.y,
                   b.x, b.y,
                   color);
}


void Display::DrawCircle( const XYCoord_t center,
                                const unsigned char r,
                                const unsigned char color,
                                bool fill)
{
  if(!fill)
    screen.drawCircle( center.x, center.y, r, color);
  else
    screen.fillCircle( center.x, center.y, r, color);
}



}










