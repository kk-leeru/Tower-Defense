#include <string>

#include "SofaEnemy.hpp"
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

SofaEnemy::SofaEnemy(int x, int y) : Enemy("play/enemy-2.png", x, y, 25, 100, 10, 10, 3) { //changed
	// Use bounding circle to detect collision is for simplicity, pixel-perfect collision can be implemented quite easily,
	// and efficiently if we use AABB collision detection first, and then pixel-perfect collision.
}
void SofaEnemy::CreateEnemyBullet() {
	Engine::Point diff = Engine::Point(1, 0);
	float rotation = ALLEGRO_PI / 2;
	getPlayScene()->EnemyBulletGroup->AddNewObject(new FriesEnemyBullet(Position, diff, rotation, this));
	AudioHelper::PlayAudio("gun.wav");
}
