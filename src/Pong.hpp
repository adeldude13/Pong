#ifndef PONG
#define PONG

#include <string>
#include <inttypes.h>
#include <SFML/Graphics.hpp>

typedef enum {
	RIGHT,
	LEFT
} Dir;


class Pong {
	public:	
		Pong(int, int, std::string);
		void loop();
		void exit();
		void input();
		void render();
		void update();
		void end(std::string);
	private:	
		int width, height;
		sf::RenderWindow window;
		sf::Clock clock, bclock;
		sf::RectangleShape pad1, pad2;
		sf::CircleShape ball;
		int s1, s2;
		Dir dir = RIGHT;
		float yv = 60.0f;
		sf::Font font;
		sf::Text t1, t2, p;
};


#endif
