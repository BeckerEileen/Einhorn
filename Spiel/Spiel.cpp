// Spiel.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

using namespace std;

int x = 640;
int y = 480;
int d = 0;
double m;
double n;
bool lmt;
Gosu::Color c; 


class GameWindow : public Gosu::Window {
public:
	Gosu::Image Bild;
	GameWindow()
		: Window(x, y), Bild("Rakete.png")
	{
		set_caption("Gosu Tutorial Game");
	}
	void update() override {
		if (lmt) { c = Gosu::Color::BLUE; }
		else { c = Gosu::Color::WHITE; }

		d = (d + 1) % 300;
		m = input().mouse_x();
		n = input().mouse_y();
		lmt = input().down(Gosu::MS_LEFT);

	}
	void draw() override {

		graphics().draw_triangle(
				10, m, Gosu::Color::RED,
				n, 100, Gosu::Color::GREEN,
			    d,50, c,
				0.0
		
		);
		
		Bild.draw(200, 200, 200);
		
	}


};
int main() {
	GameWindow window;
	window.show();
	return 0;
}
