#include "EnemyBullet.hpp"
#include "Collider.hpp"
#include "Turret.hpp" //changed
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IObject.hpp"
#include "IScene.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Sprite.hpp"

PlayScene* EnemyBullet::getPlayScene() {
	return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}
void EnemyBullet::OnExplode(Turret* turret) {
}
EnemyBullet::EnemyBullet(std::string img, float speed, float damage, Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent) : //changed
	Sprite(img, position.x, position.y), speed(speed), damage(damage), parent(parent) {
	Velocity = -1*forwardDirection * speed;
	Rotation = rotation;
	CollisionRadius = 4;
}
void EnemyBullet::Update(float deltaTime) {
	Sprite::Update(deltaTime);
	PlayScene* scene = getPlayScene();
	// Can be improved by Spatial Hash, Quad Tree, ...
	// However simply loop through all enemies is enough for this program.
	//printf("enemy shoots bullet\n");
	for (auto& it : scene->TowerGroup->GetObjects()) { //changed
		Turret* turret = dynamic_cast<Turret*>(it);
		if (!turret->Visible)
			continue;
		if (Engine::Collider::IsCircleOverlap(Position, CollisionRadius, turret->Position, turret->CollisionRadius)) {
			OnExplode(turret);
			turret->TurretHit(damage);
			getPlayScene()->EnemyBulletGroup->RemoveObject(objectIterator);
			return;
		}
	}
	// Check if out of boundary.
	if (!Engine::Collider::IsRectOverlap(Position - Size / 2, Position + Size / 2, Engine::Point(0, 0), PlayScene::GetClientSize()))
		getPlayScene()->EnemyBulletGroup->RemoveObject(objectIterator);
}
