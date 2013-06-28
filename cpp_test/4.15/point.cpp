#include <graphics.h>
#include <conio.h>

class location {
protected:
	int x, y;
public:
	location(int intx, int inty)
	{
		x = intx; y = inty;
	}
};

class point : public location
{
public:
	point(int intx, int inty) : location(intx, inty)
	{  }
	void show(void)
	{
		putpixel(x, y, getcolor());
	}
	void hide(void)
	{
		putpixel(x, y, getbkcolor());
	}
	void moveto(int newx, int newy)
	{
		hide();
		x = newx;
		y = newy;
		show();	
	}
};

class circles : public point
{
private:
	int radius;
public:
	circles(int initx, int inity, int initradius);
	void show(void);	
	void hide(void);
	void zoomin(int expandby);
	void moveto(int nx, int ny);
	void zoomout(int contractby);
};

circles::circles(int initx, int inity, int initradius) : point(initx, inity)
{
	radius = initradius;
	
}

circles::show()
{
	circle(x, y, radius);
}

circles::hide()
{
	unsigned int tempcolor;
	tempcolor = getcolor();
	setcolor(getbkcolor());
	circle(x, y, radius);
	setcolor(tempcolor); //restore current color
}

circles::moveto(int nx, int ny)
{
	hide();
	x = nx;
	y = ny;
	show();
}

circles::zoomin(int expandby)
{
	hide();
	radius += expandby;
	if (radius < 0)
		radius = 0;
	show();
}

circles::zoomout(int contractby)
{
	zoomin(- contractby);
}

int main(void)
{
	int gdriver = DETECT, gmode;
	initgrap(
}
