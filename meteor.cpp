#include"Meteor.h"
#include"sethings.h"

std::string Meteor::meteor_file_names[] = {
	"meteorBrown_big1.png",
	"meteorBrown_big2.png",
	"meteorBrown_big3.png",
	"meteorBrown_big4.png",
	"meteorBrown_med1.png",
	"meteorBrown_med3.png",
	"meteorBrown_small1.png",
	"meteorBrown_small2.png"
};
Meteor::Meteor(){
	size_t num = rand() % METEORS_TYPE_QTY;
	texture.loadFromFile(IMAGES_FOLDER + meteor_file_names[num]);
	sprite.setTexture(texture);
	
	spawn();
	}
void Meteor::update(){
	sf::FloatRect g_bound = sprite.getGlobalBounds();
	sprite.move(speedx, speedy);
	if (sprite.getPosition().x < 0 - g_bound.width ||
		sprite.getPosition().x > WINDOW_WIDTH ||
		sprite.getPosition().x > WINDOW_HEIGHT)
	{
		spawn();
	}
}
void Meteor::draw(sf::RenderWindow& window){

}
void Meteor::spawn() {
	sf::FloatRect g_bound = sprite.getGlobalBounds();
	float x = rand() % (static_cast<size_t>(WINDOW_WIDTH) - static_cast<size_t>(g_bound.width));
	float y = rand() % (static_cast<size_t>(WINDOW_HEIGHT)) - WINDOW_HEIGHT;
	sprite.setPosition(x, y);
	speedx = rand() % 5 - 2;
	speedy = rand() % 8 + 2;
}