#include "Pong.hpp"

#define WIDTH 1200
#define HEIGHT 900

int main() {
	Pong p(WIDTH, HEIGHT);
	p.loop();
	p.exit();
	return 0;
}