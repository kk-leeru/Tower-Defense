#ifndef BOMBTURRET_HPP
#define BOMBTURRET_HPP
#include "Turret.hpp"

class BombTurret : public Turret {
public:
	static const int Price;
	BombTurret(float x, float y);
	void CreateBullet() override;
	//void Turret::TurretHit(float damage) override;
	//void Update(float deltaTime) override;
};
#endif // BOMBTURRET_HPP
#pragma once
