// Class Instructions:  https://lrccd.instructure.com/courses/221016/assignments/5852613?module_item_id=18004612
/* TO DO
Set up private variables for constructor COMPLEXPLANE
Research tutorial functions for vertexarray stuff to use


*/


// Include important C++ libraries here
#include <SFML/Graphics.hpp>	//SFML header
#include <iostream>		//input / output
#include <complex>		//complex numbers
#include 
//using ComplexPlane.h

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
	ComplexPlane(int pixelWidth, int pixelHeight);  //check
	void draw(RenderTarget& target, RenderStates states) const override;  //check
	//void zoomIn();  //FIXME
	//void zoomOut();  //FIXME
	//void setCenter(Vector2i mousePixel);  //FIXME
	//void setMouseLocation(Vector2i mousePixel);
	//void loadText(Text& text);
	void updateRender(); //FIXME
private:
	VertexArray m_vArray;
	//State m_state;  //FIXME
	Vector2f m_mouseLocation;
	Vector2i m_pixel_size;
	Vector2f m_plane_center;
	Vector2f m_plane_size;
	//int m_zoomCount;  //FIXME
	//float m_aspectRatio;  //FIXME

	//int countIterations(Vector2f coord);  //FIXME
	//void iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b); //FIXME
	//Vector2f mapPixelToCoords(Vector2i mousePixel); //FIXME
};



// Function Definitions
void ComplexPlane::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(m_vArray);
}

ComplexPlane::ComplexPlane(int pixelWidth, int pixelHeight)
{
	m_pixel_size = { pixelWidth, pixelHeight };
	m_vArray.setPrimitiveType(Points);
	m_vArray.resize(pixelWidth * pixelHeight);
}

void ComplexPlane::updateRender()
{
	int pixelHeight = m_pixel_size.y;
	int pixelWidth = m_pixel_size.x;

	for (int i = 0; i < pixelHeight; i++)
	{
		//random color for each row  FIXME
		Uint8 r, g, b;
		r = rand() % 256;
		g = rand() % 256;
		b = rand() % 256;
		for (int j = 0; j < pixelWidth; j++)
		{
			m_vArray[i * pixelWidth + j].position = { (float)j, (float)i };
			m_vArray[i * pixelWidth + j].color = { r,g,b };
		}
	}
}


//Main BEGIN
int main()
{ 
	// Create a video mode object
	int pixelWidth = VideoMode::getDesktopMode().width;  	//Get desktop resolution
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
	ComplexPlane plane(pixelWidth, pixelHeight); //Our Complex Plane we will manipulate is called "plane"

	// Constructing Font
	Font font; 						//create font class
	if(!font.loadFromFile("Romanesco-Regular.ttf"))		//load a ttf file (font file, put with cpp)
	{
		throw("FONT FAILED TO LOAD");			//throw a text if failed
	}
	
	// Constructing a Text
	Text text;
	text.setFont(font);  					//link font ttf file to text
	text.setCharacterSize(30);				//char size
	text.setColor(Color::Red);
	text.setString("Hello World");
	
	bool update = true;
	
	// EXE LOOP
	while (window.isOpen())
	{ //Window loop BEGIN
		
		/*
		****************************************
		Handle the players input  
  		What options does the player have?
		****************************************
		*/
		
		// pollevent 
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)  //if event is closed, then execute close command.
			{ window.close(); }
			
			//Option 1: Mouse presses
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)  //Left mouse click will ZOOM IN
				{
					std::cout << "the left mouse button was pressed" << std::endl;  //Show commands and location to terminal
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;

					//plane.zoomIn();  //FIXME
					//plane.setCenter(Vector2i(event.mouseButton.x, event.mouseButton.y));
					
					update = true;
				}

				if (event.mouseButton.button == sf::Mouse::Right)  //Right mouse click will ZOOM OUT
				{
					std::cout << "the right mouse button was pressed" << std::endl;  //Show commands and location to terminal
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;

					//plane.zoomIn();  //FIXME
					//plane.setCenter(Vector2i(event.mouseButton.x, event.mouseButton.y));

					update = true;
				}
			}
		}


			
		//Option 2: Quit
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}

	
		/*
		****************************************
		Update the scene
  		What will change after an input?
		****************************************
		*/

		if (update)
		{
			plane.updateRender(); //FIXME
			update = false;
		}

	
		/*
		****************************************
		Draw the scene
		****************************************
		*/

		window.clear();
		window.draw(plane);
		window.display();


	} //Window.isOpen END

}  //Main END
