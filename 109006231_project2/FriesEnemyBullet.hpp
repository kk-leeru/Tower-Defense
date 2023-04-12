#ifndef FRIESENEMYBULLET_HPP
#define FRIESENEMYBULLET_HPP
#include "EnemyBullet.hpp"

class Enemy;
class Turret;
namespace Engine {
	struct Point;
}  // namespace Engine

class FriesEnemyBullet : public EnemyBullet {
public:
	explicit FriesEnemyBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent);
	void OnExplode(Turret* turret) override;
};
#endif // ICECREAMBULLET_HPP
#pragma once
