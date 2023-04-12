#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "IceCreamBullet.hpp"
#include "Group.hpp"
#include "CancelTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Enemy.hpp"

const int CancelTurret::Price = 0;
CancelTurret::CancelTurret(float x, float y) :
	Turret("play/target-invalid.png", x, y, 15, 0, Price, 0.5) { //add radius and hp
	// Move center downward, since we the turret head is slightly biased upward.
	Anchor.y += 8.0f / GetBitmapHeight();
}
void CancelTurret::CreateBullet() {
	return;
	/*Engine::Point diff = Engine::Point(1, 0);
	float rotation = ALLEGRO_PI / 2;
	getPlayScene()->BulletGroup->AddNewObject(new IceCreamBullet(Position, diff, rotation, this));
	AudioHelper::PlayAudio("gun.wav");*/
}

