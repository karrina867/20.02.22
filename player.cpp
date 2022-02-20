#include "plaer.h"
#include "sethings.h"
Player::Player(){
	texture.loadFromFile(IMAGES_FOLDER + PLAYER_FILE_NAME);
	sprite.setTexture(texture);
	sprite.setPosition(WINDOW_WIDTH/2 - sprite.getGlobalBounds().width/2,WINDOW_HEIGHT - sprite.getGlobalBounds().height- PLAYER_OFFET_Y);
}
void Player::update(){
	sf::Vector2f position = sprite.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)&&
		position.x>0)
		sprite.move(-PLAYER_SPEED_X, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&
		position.x < WINDOW_WIDTH - sprite.getGlobalBounds().width)
		sprite.move(PLAYER_SPEED_X, 0.f);
}
void Player::draw(sf::RenderWindow& window) { window.draw(sprite); }