#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "IceCreamBullet.hpp"
#include "Group.hpp"
#include "BombTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Enemy.hpp"
#include "Collider.hpp"

const int BombTurret::Price = 70;
BombTurret::BombTurret(float x, float y) :
	Turret("play/bomb.png", x, y, 400, 4, Price, 0.5) { //add radius and hp
	// Move center downward, since we the turret head is slightly biased upward.
	Anchor.y += 8.0f / GetBitmapHeight();
}
void BombTurret::CreateBullet() {
	return;
	/*Engine::Point diff = Engine::Point(1,0);
	float rotation = ALLEGRO_PI / 2;
	getPlayScene()->BulletGroup->AddNewObject(new IceCreamBullet(Position , diff, rotation, this));
	AudioHelper::PlayAudio("gun.wav");*/
}
//void BombTurret::Update(float deltaTime) {
//	Sprite::Update(deltaTime);
//	PlayScene* scene = getPlayScene();
//	if (hp <= 0) {
//		for (auto& c : scene->EnemyGroup->GetObjects()) {
//			Enemy* enemy = dynamic_cast<Enemy*>(c);
//			if (Engine::Collider::IsCircleOverlap(Position, CollisionRadius, enemy->Position, enemy->CollisionRadius)) {
//				enemy->Hit(100);
//			}
//		}
//	}
//}