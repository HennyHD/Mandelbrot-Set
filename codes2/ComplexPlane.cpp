#include "ComplexPlane.h"

ComplexPlane::ComplexPlane(int pixelWidth, int pixelHeight)
{
	m_pixel_size = { pixelWidth, pixelHeight };
	m_vArray.setPrimitiveType(Points);
	m_vArray.resize(pixelWidth * pixelHeight);
}

//void ComplexPlane::zoomIn()
//{
//	view.zoom
//}

//void ComplexPlane::zoomOut()
//{
//
//}

void ComplexPlane::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(m_vArray);
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
