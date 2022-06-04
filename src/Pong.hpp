#ifndef PONG
#define PONG

#include <SFML/Graphics.hpp>

typedef enum {
	RIGHT,
	LEFT
} Dir;


class Pong {
	public:	
		Pong(int, int);
		void loop();
		void exit();
		void input();
		void render();
		void update();

	private:	
		int width, height;
		sf::RenderWindow window;
		sf::Clock clock, bclock;
		sf::RectangleShape pad1, pad2;
		sf::CircleShape ball;
		Dir dir = RIGHT;
};


#endif
