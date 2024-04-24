#pragma once
const unsigned int MAX_ITER = 64;
const float BASE_WIDTH = 4.0;
const float BASE_HEIGHT = 4.0;
const float BASE_ZOOM = 0.5;
enum State {CALCULATING, DISPLAYING};

// Include important C++ libraries here
#include <SFML/Graphics.hpp>	//SFML header
#include <iostream>		//input / output
#include <complex>		//complex numbers
#include <vector>
#include <sstream>

// Make code easier to type with "using namespace"
using namespace sf;  		//get rid of sf:: for sf functions
using namespace std;		//get rid of std:: for std functions

// Class Declarations
class ComplexPlane : public Drawable  		//Class name ComplexPlane;  using public class from SFML called Drawable. 
{											//Drawable allows access to sf::Shape, Sprite, Text, VertexArray, and VertexBuffer
											//For more info:  https://www.sfml-dev.org/documentation/2.6.0/classsf_1_1Drawable.php
// Implementing the UML 
public:
	ComplexPlane(int pixelWidth, int pixelHeight);  
	void draw(RenderTarget& target, RenderStates states) const override;  
	void zoomIn();
	void zoomOut();
	void setCenter(Vector2i mousePixel);  
	void setMouseLocation(Vector2i mousePixel);
	void loadText(Text& text);
	void updateRender(); //FIXME
private:
	VertexArray m_vArray;
	State m_State;  
	Vector2f m_mouseLocation;
	Vector2i m_pixel_size;
	Vector2f m_plane_center;
	Vector2f m_plane_size;
	int m_zoomCount;  
	float m_aspectRatio;  

	size_t countIterations(Vector2f coord);  //FIXME
	void iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b); //FIXME
	Vector2f mapPixelToCoords(Vector2i mousePixel); //FIXME
};
