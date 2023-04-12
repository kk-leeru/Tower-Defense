#ifndef ENEMYBULLET_HPP
#define ENEMYBULLET_HPP
#include <string>

#include "Sprite.hpp"

class Enemy;
class PlayScene;
class Turret;
namespace Engine {
	struct Point;
}  // namespace Engine

class EnemyBullet : public Engine::Sprite {
protected:
	float speed;
	float damage;
	Enemy* parent; //changed
	PlayScene* getPlayScene();
	virtual void OnExplode(Turret* turret); //changed
public:
	Turret* TargetT = nullptr; //changed
	explicit EnemyBullet(std::string img, float speed, float damage, Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent); //changed
	void Update(float deltaTime) override;
};
#endif // ENEMYBULLET_HPP
#pragma once
