#include <string>

#include "NormalEnemy.hpp"
//new below
#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "FriesEnemyBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Turret.hpp" //chnage to turret
NormalEnemy::NormalEnemy(int x, int y) : Enemy("play/enemy-1.png", x, y, 10, 50, 5, 5, 6) {//add cooldown
}
void NormalEnemy::CreateEnemyBullet() {
	Engine::Point diff = Engine::Point(1, 0);
	float rotation = ALLEGRO_PI / 2;
	getPlayScene()->EnemyBulletGroup->AddNewObject(new FriesEnemyBullet(Position, diff, rotation, this));
	AudioHelper::PlayAudio("gun.wav");
}

