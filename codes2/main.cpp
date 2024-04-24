// Class Instructions:  https://lrccd.instructure.com/courses/221016/assignments/5852613?module_item_id=18004612
/* TO DO
Set up private variables for constructor COMPLEXPLANE
Research tutorial functions for vertexarray stuff to use


*/


// Include important C++ libraries here
#include <SFML/Graphics.hpp>	//SFML header
#include <iostream>		//input / output
#include <complex>		//complex numbers
#include <vector>
#include "ComplexPlane.h"

// Make code easier to type with "using namespace"
using namespace sf;  		//get rid of sf:: for sf functions
using namespace std;		//get rid of std:: for std functions



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
	text.setCharacterSize(50);				//char size
	text.setColor(Color::White);
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

					plane.zoomIn();
					plane.setCenter(Vector2i(event.mouseButton.x, event.mouseButton.y));
					
					update = true;
				}

				if (event.mouseButton.button == sf::Mouse::Right)  //Right mouse click will ZOOM OUT
				{
					std::cout << "the right mouse button was pressed" << std::endl;  //Show commands and location to terminal
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;

					plane.zoomOut();
					plane.setCenter(Vector2i(event.mouseButton.x, event.mouseButton.y));

					update = true;
				}
			}

			//Option2: Mouse moved
			if (event.type == sf::Event::MouseMoved)
			{
				plane.setMouseLocation(static Vector2i sf::Mouse::getPosition(const WindowBase & relativeTo)
			}



		}
			
			//Option 3: Quit
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
			plane.updateRender();
			plane.loadText();
			update = false;
		}

	
		/*
		****************************************
		Draw the scene
		****************************************
		*/

		window.clear();
		window.draw(plane);
		window.draw(text);
		window.display();


	} //Window.isOpen END

}  //Main END
