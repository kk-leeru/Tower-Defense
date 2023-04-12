#include <allegro5/base.h>
#include <random>
#include <string>

#include "DirtyEffect.hpp"
#include "Enemy.hpp"
#include "FireBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "CoolTurret.hpp";
class Turret;
Enemy* mark;
FireBullet::FireBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent) :
	Bullet("play/bullet-7.png", 500, 3, position, forwardDirection, rotation - ALLEGRO_PI / 2, parent) {
	// TODO 2 (1/8): You can imitate the 2 files: 'FireBullet.hpp', 'FireBullet.cpp' to create a new bullet.
}
void FireBullet::OnExplode(Enemy* enemy) {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(2, 5);
	getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-1.png", dist(rng), enemy->Position.x, enemy->Position.y));
	enemy->slow = true;
	//Sprite::Update(deltaTime);
	PlayScene* scene = getPlayScene();
	Turret* preview;
	preview = new CoolTurret(0, 0);
	preview->Position.x = enemy->Position.x-128/2;
	preview->Position.y = enemy->Position.y;
		//Position.y * 128 + 128 / 2;
	preview->Enabled = true;
	preview->Preview = false;
	preview->Tint = al_map_rgba(255, 255, 255, 255);
	scene->TowerGroup->AddNewObject(preview);
}
//void FireBullet::Update(float deltaTime) {
//	Sprite::Update(deltaTime);
//	PlayScene* scene = getPlayScene();
//	Turret* preview;
//	preview = new BombTurret(0, 0);
//	preview->Position.x = mark->Position.x * 128 + 128 / 2 - 2*128;
//	preview->Position.y = mark->Position.y * 128 + 128 / 2;
//	
//	preview->Enabled = true;
//	preview->Preview = false;
//	preview->Tint = al_map_rgba(255, 255, 255, 255);
//	scene->TowerGroup->AddNewObject(preview);
//}


