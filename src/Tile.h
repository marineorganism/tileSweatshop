//A tile that contains graphics information
//I know you're going to just love it!


#ifndef TILE_H
#define TILE_H

#include <iostream>

#include <gtk/gtk.h>


class Tile
{
public:
  //the width of the tile
  int const width;

  //the height of the tile
  int const height;

  //creates a tile with no existing data
  //pWidth is the width of the tile
  //pHeight is the height of the tile
  Tile(int pWidth,int pHeight);

  //creates a tile with existing data
  //pPixels is the data
  //pWidth is the width of the tile
  //pHeight is the height of the tile
  Tile(int * pPixels,int pWidth,int pHeight);

  //creates a tile with data from an input stream
  //pixelStream
  Tile(std::istream * pixelStream,int pWidth,int pHeight);

  //destroys the to death
  ~Tile();

  //duplicates this tile and returns a pointer to a copy
  Tile * duplicate();

  //gets the value of a pixel
  //x is the x position
  //y is the y position
  int getPixel(int x,int y);

  //sets the value of a pixel
  //x is the x position
  //y is the y position
  //value is the value to set it to
  void setPixel(int x,int y,int value);

  //displays the tile
  //xPos is the horizontal position
  //yPos is the vertical position
  //scale is the scale to display it at
  //cr is the drawing thingy
  void render(int xPos,int yPos,float scale,cairo_t * cr);

  //shifts the pixel data
  //xShift is the horizontal shift amount
  //yShift is the vertical shift amount
  void shift(int xShift,int yShift);

  //writes the tile's data to an output stream
  //pixelStream is that very stream
  void writeToStream(std::ostream * pixelStream);

private:
  //the tile's pixel data
  int * pixels;
};

#endif
