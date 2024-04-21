// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <iostream>

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

//Desktop Resolution
int main() 
{
  // Create a video mode object
	int pixelWidth = VideoMode::getDesktopMode().width;
	int pixelHeight = VideoMode::getDesktopMode().height;
	VideoMode vm(pixelWidth, pixelHeight);

  // Create and open a window for the game
	RenderWindow window(vm, "Rainbow Screen", Style::Default);

  //resize window for different resolutions
	View view;
	view.setSize(pixelWidth, pixelHeight);
	view.setCenter(VideoMode::getDesktopMode().width / 2, VideoMode::getDesktopMode().height / 2);
	window.setView(view);

  

}
