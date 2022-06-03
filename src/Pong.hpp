#ifndef PONG
#define PONG

#include <SFML/Graphics.hpp>


class Pong {
	public:	
		Pong(int, int);
		void loop();
		void exit();
		void input();
		void render();
		void update();

	private:	
		int width;
		int height;
		sf::RenderWindow window;
		sf::Clock clock;
		sf::RectangleShape pad1;
		sf::RectangleShape pad2;
		sf::CircleShape ball;
};


#endif
