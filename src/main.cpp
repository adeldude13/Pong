#include "Pong.hpp"

#define WIDTH 1600
#define HEIGHT 900

int main() {
	Pong p(WIDTH, HEIGHT, "../Fonts/font.ttf");
	p.loop();
	return 0;
}
