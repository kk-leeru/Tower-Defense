#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "FireBullet.hpp"
#include "Group.hpp"
#include "CoolTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Enemy.hpp"

const int CoolTurret::Price = 1;
CoolTurret::CoolTurret(float x, float y) :
	Turret("play/fire.png", x, y, 15, 1, Price, 0.5) { //add radius and hp
	// Move center downward, since we the turret head is slightly biased upward.
	Anchor.y -= 8.0f / GetBitmapHeight();
}
void CoolTurret::CreateBullet() {
	return;
	/*Engine::Point diff = Engine::Point(1, 0);
	float rotation = ALLEGRO_PI / 2;
	getPlayScene()->BulletGroup->AddNewObject(new IceCreamBullet(Position, diff, rotation, this));
	AudioHelper::PlayAudio("gun.wav");*/
}

