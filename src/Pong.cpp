#include "Pong.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

#define FPS_LIMIT 60
#define MOVE_SPEED 100
#define TOP_LIMIT 0
#define BALL_SPEED 30

const float p_WIDTH = 20.0f;
const float p_HEIGHT = 200.0f;

Pong::Pong(int W, int H) {
	width = W;
	height = H;
	window.create(sf::VideoMode(W, H), "Pong", sf::Style::Close);
	auto desktop = sf::VideoMode::getDesktopMode();
	window.setPosition(sf::Vector2i(desktop.width/2 - window.getSize().x/2, desktop.height/2 - window.getSize().y/2));
	window.setFramerateLimit(FPS_LIMIT);
	
	pad1.setSize(sf::Vector2f(p_WIDTH, p_HEIGHT));
	pad1.setPosition(10, (H/2)-(p_HEIGHT/2));
	pad1.setFillColor(sf::Color(255, 255, 255));


	pad2.setSize(sf::Vector2f(p_WIDTH, p_HEIGHT));
	pad2.setPosition(W-p_WIDTH-10, (H/2)-(p_HEIGHT/2));
	pad2.setFillColor(sf::Color(255, 255, 255));

	ball.setRadius(10);
	ball.setPosition(W/2, H/2);
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
	window.display();
}

void Pong::update() {
	sf::Time dt = clock.getElapsedTime();
	sf::Time bt = bclock.getElapsedTime();
	if(bt > sf::seconds(0.03)) {
		if(ball.getPosition().x + BALL_SPEED + p_WIDTH >=	pad2.getPosition().x || ball.getPosition().x - BALL_SPEED <= 0) {
			if(dir == LEFT) {
				dir = RIGHT;
			} else {
				dir = LEFT;
			}
		}
		ball.move(dir == LEFT ? -BALL_SPEED : BALL_SPEED, 0);

		bclock.restart();
	}
	if(dt < sf::seconds(0.1)) return;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if(pad1.getPosition().y > TOP_LIMIT) {
			pad1.move(0, -MOVE_SPEED);
		}
	} 
 if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if(pad1.getPosition().y < height-p_HEIGHT) {
			pad1.move(0, MOVE_SPEED);
		}
	} 
 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if(pad2.getPosition().y > TOP_LIMIT) {
			pad2.move(0, -MOVE_SPEED);
		}
	} 
 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if(pad2.getPosition().y < height-p_HEIGHT) {
			pad2.move(0, MOVE_SPEED);
		}
	}

	clock.restart();
}
