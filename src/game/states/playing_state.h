#ifndef PLAYING_STATE_H_
#define PLAYING_STATE_H_

#include "../../engine/control/state_manager.h"
#include "../player.h"
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
	std::vector<Bullet *> bullet_container;


	void initPlayer();

};

#endif  // PLAYING_STATE_H_