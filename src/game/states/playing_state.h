#ifndef PLAYING_STATE_H_
#define PLAYING_STATE_H_

#include "../../engine/control/state_manager.h"
#include "../player.h"
#include "../creature.h"
#include "../building.h"
#include <SFML/Graphics/Texture.hpp>
#include "../../engine/control/texture_manager.h"


class PlayingState : public State {

public:
	PlayingState(StateData *);
	virtual ~PlayingState();

	void render();

	void update(const float &);



private:

	Player *player;
	Building *house;
	std::vector<Bullet *> bullet_container;

	sf::Clock *shoot_timer;
	sf::Time shoot_cooldown;
	sf::Time shoot_cooldown_dt;

	bool flag;


	void initPlayer();

	void initHouse();

};

#endif  // PLAYING_STATE_H_