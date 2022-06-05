#include "Pong.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#define FPS_LIMIT 60
#define MOVE_SPEED 1000
#define TOP_LIMIT 0
#define BALL_SPEED 1500
#define RADIUS 10

const float p_WIDTH = 20.0f;
const float p_HEIGHT = 200.0f;

Pong::Pong(int W, int H, std::string font_path) {
	if(!font.loadFromFile(font_path)) {
		std::cout << "no valid font dir or no read premission is given" << std::endl;
		return;
	}
	
	s1 = 0;
	s2 = 0;
	
	width = W;
	height = H;
	
	window.create(sf::VideoMode(W, H), "Pong", sf::Style::Close | sf::Style::Fullscreen);
	auto desktop = sf::VideoMode::getDesktopMode();
	window.setPosition(sf::Vector2i(desktop.width/2 - window.getSize().x/2, desktop.height/2 - window.getSize().y/2));
	window.setFramerateLimit(FPS_LIMIT);
	
	pad1.setSize(sf::Vector2f(p_WIDTH, p_HEIGHT));
	pad1.setPosition(10, (H/2)-(p_HEIGHT/2));
	pad1.setFillColor(sf::Color(255, 255, 255));


	pad2.setSize(sf::Vector2f(p_WIDTH, p_HEIGHT));
	pad2.setPosition(W-p_WIDTH-10, (H/2)-(p_HEIGHT/2));
	pad2.setFillColor(sf::Color(255, 255, 255));

	ball.setRadius(RADIUS);
	ball.setPosition(W/2, H/2);

	t2.setFont(font);
	t2.setString("0");
	t2.setCharacterSize(50);	
	t2.setPosition(50, 20);	
	t2.setFillColor(sf::Color::White);

	t1.setFont(font);
	t1.setString("0");
	t1.setCharacterSize(50);	
	t1.setPosition(W-50-50, 20);	
	t1.setFillColor(sf::Color::White);
	
	p.setFont(font);
	p.setCharacterSize(65);	
	p.setPosition(W/4-50, (H/2)-50);	
	p.setFillColor(sf::Color::White);
}

void Pong::input() {
	sf::Event e;	
	while(window.pollEvent(e)) {
		if(e.type == sf::Event::Closed) {
			window.close();
		}
	}
}


void Pong::loop() {
END:
	while(window.isOpen()) {
		this->input();
		if(!window.isOpen()) goto END;
		this->update();
		this->render();
	}
}

void Pong::exit() {
	window.close();
}


void Pong::render() {
	window.clear(sf::Color(0, 0, 0));
	window.draw(pad1);	
	window.draw(pad2);
	window.draw(ball);	
	window.draw(t1);
	window.draw(t2);	
	window.display();
}

void Pong::update() {
	float dt = clock.getElapsedTime().asSeconds();
	int p1 = pad1.getGlobalBounds().intersects(ball.getGlobalBounds());
	int p2 = pad2.getGlobalBounds().intersects(ball.getGlobalBounds());
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if(pad1.getPosition().y > TOP_LIMIT) {
			pad1.move(0, -MOVE_SPEED * dt);
		}
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if(pad1.getPosition().y < height-p_HEIGHT) {
			pad1.move(0, MOVE_SPEED * dt);
		}
	} 
 	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if(pad2.getPosition().y > TOP_LIMIT) {
			pad2.move(0, -MOVE_SPEED * dt);
		}
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if(pad2.getPosition().y < height-p_HEIGHT) {
			pad2.move(0, MOVE_SPEED * dt);
		}
	}
	if(p1) {
		dir = LEFT;
	} else if(p2) {
		dir = RIGHT;
	} else if(ball.getPosition().x < 0 || ball.getPosition().x > width) {
		if(dir == RIGHT) {
			s2 += 1;
			t1.setString(std::to_string(s2));
			if(s2 == 10) {
				this->end("Player Two");
			}
		} else if(dir == LEFT) {
			s1 += 1;
			t2.setString(std::to_string(s1));
			if(s1 == 10) {
				this->end("Player One");	
			}
		}
		ball.setPosition(width / 2, height / 2);
	}


 	if(dir == LEFT) {
		ball.move(BALL_SPEED * dt, yv * dt);
	} else {
		ball.move(-BALL_SPEED * dt, yv * dt);
	}

	int by = ball.getPosition().y;
	if(by > height || by < 0) {
		yv *= -1.1f;
		ball.move(0, by < 0 ? 30 : -30);
	} 

	clock.restart();
}

void Pong::end(std::string s) {
	p.setString(s + " Won");
	window.clear(sf::Color(0, 0, 0));
	window.draw(p);
	window.display();
	sf::Time t = sf::seconds(5);
	sf::sleep(t);
	this->exit();
}
