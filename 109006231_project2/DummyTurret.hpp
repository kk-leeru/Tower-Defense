#ifndef DUMMYTURRET_HPP
#define DUMMYTURRET_HPP
#include "Turret.hpp"

class DummyTurret : public Turret {
public:
	static const int Price;
	DummyTurret(float x, float y);
	void CreateBullet() override;
};
#endif // DUMMYTURRET_HPP
