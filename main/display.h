#ifndef JALC_DISPLAY_H_
#define JALC_DISPLAY_H_

#include <SSD1322_for_Adafruit_GFX.h>


//HW clk pin 18 
//HW MOSI pin 23
#define OLED_DC 19
#define OLED_RESET 27
#define OLED_CS 5




namespace jalc
{


struct XYCoord_t
{
  unsigned char x, y;  
};

class Display {
public:
  Display();
  // ~Display();

  
  unsigned int GetRotation() const;

  unsigned int Height() const;

  unsigned int Width() const;

  void SetRotation( const unsigned char mode );

  void Update();

  void Clear();

  void SetCursor( XYCoord_t pos );

  void Print( const char * msg );

  void Print( const unsigned char ascii );

  void SetTextSize( const unsigned char texSize );

  void SetTextColor( const unsigned char color );

  void PrintBitMap( const XYCoord_t corner,
                    const unsigned char w,
                    const unsigned char h,
                    const unsigned char *bitmap,
                    const unsigned char color);


  void DrawTriangle( const XYCoord_t a,
                     const XYCoord_t b,
                     const XYCoord_t c,
                     const unsigned char color,
                     bool fill);

  void DrawCircle( const XYCoord_t center,
                   const unsigned char r,
                   const unsigned char color,
                   bool fill);

  void DrawRect( const XYCoord_t corner,
                 const unsigned char w,
                 const unsigned char h,
                 const unsigned char color,
                 bool fill);

  void DrawLine( const XYCoord_t a,
                 const XYCoord_t b,
                 const unsigned char color);
  // void DrawRoundRect();

private:
  Adafruit_SSD1322 screen;
  
};

};


#endif
