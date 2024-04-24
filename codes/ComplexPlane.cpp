#include "ComplexPlane.h"

ComplexPlane::ComplexPlane(int pixelWidth, int pixelHeight)
{
	m_pixel_size = { pixelWidth, pixelHeight };
	m_vArray.setPrimitiveType(Points);
	m_vArray.resize(pixelWidth * pixelHeight);
	m_aspectRatio = (float)pixelHeight / (float)pixelWidth;
	m_plane_center = { 0,0 };
	m_plane_size = { BASE_WIDTH, BASE_HEIGHT * m_aspectRatio };
	cout << m_plane_size.x << " " << m_plane_size.y << endl;
	m_zoomCount = 0;
	m_State = State::CALCULATING;
}

Vector2f ComplexPlane::mapPixelToCoords(Vector2i mousePixel)
{
	float real = ((mousePixel.x - 0) / (float)(m_pixel_size. x)) * (m_plane_size.x) + (m_plane_center.x - m_plane_size.x / 2.0);
	float imaginary = ((mousePixel.y) / (float)(m_pixel_size.y)) * (m_plane_size.y) + (m_plane_center.y - m_plane_size.y / 2.0);
	return Vector2f(real, imaginary); 
}

void ComplexPlane::iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b)
{
	if (count == MAX_ITER)
	{
		r = 0;
		g = 0;
		b = 0;
	}
	else
	{
		int region = count % 5;
		if (region == 0) {  //purp
			r = 160;
			g = 32;
			b = 240;
		}
		else if (region == 1)  //blue
		{
			r = 0;
			g = 0;
			b = 255;
		}
		else if (region == 2)  //turq
		{
			r = 64;
			g = 224;
			b = 208;
		}
		else if (region == 3) //yellow
		{
			r = 255;
			g = 255;
			b = 0;
		}
		else if (region == 4) //wht
		{
			r = 255;
			g = 255;
			b = 255;
		}
	}

}

size_t ComplexPlane::countIterations(Vector2f coord) //FIXME
{
	complex<float> z(0, 0);
	complex<float> c(coord.x, coord.y);

	size_t iterations = 0;
	const size_t maxIterations = MAX_ITER;

	// Iterate the Mandelbrot set formula
	while (abs(z) < 2.0 && iterations < maxIterations)
	{
		z = z * z + c;
		iterations++;
	}

	return iterations;
}

void ComplexPlane::loadText(Text& text)
{
	stringstream ss;
	ss << "Mandelbrot Set \n";
	ss << "Center: (" << m_plane_center.x << "," << m_plane_center.y << ")\n";  //Center should not move unless user mouse clicked
	ss << "Cursor: (" << m_mouseLocation.x << "," << m_mouseLocation.y << ")\n";
	ss << "Left-click to Zoom in\n";
	ss << "Right-click to Zoom out" << endl;

	text.setString(ss.str());
}
	
void ComplexPlane::setMouseLocation(Vector2i mousePixel)
{
	Vector2f coord = mapPixelToCoords(mousePixel);
	m_mouseLocation = coord;
}

void ComplexPlane::setCenter(Vector2i mousePixel)
{
	Vector2f coord = mapPixelToCoords(mousePixel);
	m_plane_center = coord;
	m_State = State::CALCULATING;
}

void ComplexPlane::zoomIn()
{
	m_zoomCount++;
	float width = BASE_WIDTH * pow(BASE_ZOOM, m_zoomCount);
	float height = BASE_HEIGHT * m_aspectRatio * pow(BASE_ZOOM, m_zoomCount);
	m_plane_size = { width, height };
	m_State = State::CALCULATING;
}

void ComplexPlane::zoomOut()
{
	m_zoomCount--;
	float width = BASE_WIDTH * pow(BASE_ZOOM, m_zoomCount);
	float height = BASE_HEIGHT * m_aspectRatio * pow(BASE_ZOOM, m_zoomCount);
	m_plane_size = { width, height };
	m_State = State::CALCULATING;
}

void ComplexPlane::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(m_vArray);
}

void ComplexPlane::updateRender()  //Maybe FIXME
{
	
	float pixelHeight = m_pixel_size.y;
	float pixelWidth = m_pixel_size.x;
	if (m_State == CALCULATING) 
	{
		for (int i = 0; i < pixelHeight; ++i)
		{
			for (int j = 0; j < pixelWidth; ++j) 
			{
				m_vArray[i * pixelWidth + j].position = { (float)j, (float)i };
				Vector2f coord = mapPixelToCoords(Vector2i(j, i));
				size_t iterations = countIterations(coord);
				Uint8 r, g ,b;
				iterationsToRGB(iterations, r, g, b);
				m_vArray[i * pixelWidth + j].color = { r,g,b };
			}
		}
		m_State = State::DISPLAYING;

	}
}
