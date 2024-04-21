// Class Instructions:  https://lrccd.instructure.com/courses/221016/assignments/5852613?module_item_id=18004612

// Include important C++ libraries here
#include <SFML/Graphics.hpp>	//SFML header
#include <iostream>		//input / output
#include <complex>		//complex numbers

// Make code easier to type with "using namespace"
using namespace sf;  		//get rid of sf:: for sf functions
using namespace std;		//get rid of std:: for std functions

// Class Declarations
class ComplexPlane : public Drawable  	//Class name ComplexPlane;  using public class from SFML called Drawable. 
					//Drawable allows access to sf::Shape, Sprite, Text, VertexArray, and VertexBuffer
					//For more info:  https://www.sfml-dev.org/documentation/2.6.0/classsf_1_1Drawable.php
// Implementing the UML 
{
public:
	ComplexPlane(int pixelWidth, int pixelHeight);
	void draw(RenderTarget& target, RenderStates states) const override;
	void zoomIn();
	void zoomOut();
	void setCenter(Vector2i mousePixel);
	void setMosueLocation(Vector2i mousePixel);
	void loadText(Text& text);
	void updateRender();
private:
	VertexArray m_vArray;
	State m_state;
	Vector2f m_mouseLocation;
	Vector2i m_pixel_size;
	Vector2f m_plane_center;
	Vector2f m_plane_size;
	int m_zoomCount;
	float m_aspectRatio;

	int countIterations(Vector2f coord);
	void iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b);
	Vector2f mapPixelToCoords(Vector2i mousePixel);
};

// Function Definitions


int main() 
{
	// Create a video mode object
	int pixelWidth = VideoMode::getDesktopMode().width;  //Get desktop resolution
	int pixelHeight = VideoMode::getDesktopMode().height;
	VideoMode vm(pixelWidth, pixelHeight);

  	// Create and open a window for the game
	RenderWindow window(vm, "Mandelbrot-Set", Style::Default);

 	// Resize window for different resolutions
	View view;
	view.setSize(pixelWidth, pixelHeight);
	view.setCenter(VideoMode::getDesktopMode().width / 2, VideoMode::getDesktopMode().height / 2);
	window.setView(view);

	// Constructing a plane
	ComplexPlane plane(pixelWidth, pixelHeight);


	
		/*
		****************************************
		Handle the players input
		****************************************
		*/


	
	
		/*
		****************************************
		Update the scene
		****************************************
		*/



	
		/*
		****************************************
		Draw the scene
		****************************************
		*/


	

}
