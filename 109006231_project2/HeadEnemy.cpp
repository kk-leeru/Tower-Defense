#include <string>

#include "HeadEnemy.hpp"
//new
#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "FriesEnemyBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Turret.hpp" //chnage to turret

HeadEnemy::HeadEnemy(int x, int y) : Enemy("play/enemy-4.png", x, y, 30, 50, 10, 15, 4) {//cooldown added
    // TODO 2 (6/8): You can imitate the 2 files: 'NormalEnemy.hpp', 'NormalEnemy.cpp' to create a new enemy.
}
void HeadEnemy::CreateEnemyBullet() {
	Engine::Point diff = Engine::Point(1, 0);
	float rotation = ALLEGRO_PI / 2;
	getPlayScene()->EnemyBulletGroup->AddNewObject(new FriesEnemyBullet(Position, diff, rotation, this));
	AudioHelper::PlayAudio("gun.wav");
}
