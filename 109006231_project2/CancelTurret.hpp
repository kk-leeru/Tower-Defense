#ifndef CACNELTURRET_HPP
#define CANCELTURRET_HPP
#include "Turret.hpp"

class CancelTurret : public Turret {
public:
	static const int Price;
	CancelTurret(float x, float y);
	void CreateBullet() override;
};
#endif // CANCELTURRET_HPP
#pragma once
