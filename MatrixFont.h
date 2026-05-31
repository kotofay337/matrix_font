#include <string.h>
#include <Adafruit_GFX.h>

class MatrixFont {
private:

    Adafruit_GFX * raster;
    unsigned char * currentPrinting;
    uint16_t x, y;
    int SYMBOL_WIDTH;

public:
    uint16_t h;
    uint16_t bg, fg;

    MatrixFont( Adafruit_GFX * r );
    void putPixel( bool dot );
    void putScanline( int row );
    void drawString( char * s, int x, int y );
    size_t printf( uint16_t fg, uint16_t bg, const char * format, ... );
    static void drawString( Adafruit_GFX & raster, uint16_t fg, uint16_t bg, char * s, int x, int y);
};
