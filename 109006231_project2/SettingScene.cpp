#include <functional>
#include <string>

#include "AudioHelper.hpp"
#include "GameEngine.hpp"
#include "Image.hpp"
#include "ImageButton.hpp"
#include "Label.hpp"
#include "LoseScene.hpp"
#include "PlayScene.hpp"
#include "SettingScene.hpp"
#include "Point.hpp"
#include "Slider.hpp"

void SettingScene::Initialize() {
	// TODO 1 (2/3): You can imitate the 2 files: 'LoseScene.hpp', 'LoseScene.cpp' to implement your setting scene.
	int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
	int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
	int halfW = w / 2;
	int halfH = h / 2;
	
	Engine::ImageButton* btn;
	btn = new Engine::ImageButton("win/dirt.png", "win/floor.png", halfW - 200, halfH * 7 / 4 - 50, 400, 100);
	btn->SetOnClickCallback(std::bind(&SettingScene::BackOnClick, this, 2));
	AddNewControlObject(btn);
	AddNewObject(new Engine::Label("Back", "pirulen.ttf", 48, halfW, halfH * 7 / 4, 0, 0, 0, 255, 0.5, 0.5));
	//
	Slider* sliderBGM, * sliderSFX;
	sliderBGM = new Slider(40 + halfW - 95, halfH - 50 - 2, 190, 4);
	sliderBGM->SetOnValueChangedCallback(std::bind(&SettingScene::BGMSlideOnValueChanged, this, std::placeholders::_1));
	AddNewControlObject(sliderBGM);
	AddNewObject(new Engine::Label("BGM: ", "pirulen.ttf", 28, 40 + halfW - 60 - 95, halfH - 50, 255, 255, 255, 255, 0.5, 0.5));
	sliderSFX = new Slider(40 + halfW - 95, halfH + 50 - 2, 190, 4);
	sliderSFX->SetOnValueChangedCallback(std::bind(&SettingScene::SFXSlideOnValueChanged, this, std::placeholders::_1));
	AddNewControlObject(sliderSFX);
	AddNewObject(new Engine::Label("SFX: ", "pirulen.ttf", 28, 40 + halfW - 60 - 95, halfH + 50, 255, 255, 255, 255, 0.5, 0.5));
	
	bgmInstance = AudioHelper::PlaySample("select.ogg", false, AudioHelper::BGMVolume, PlayScene::DangerTime);
	sliderBGM->SetValue(AudioHelper::BGMVolume);
	sliderSFX->SetValue(AudioHelper::SFXVolume);
}
void SettingScene::Terminate() {
	AudioHelper::StopSample(bgmInstance);
	bgmInstance = std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE>();
	IScene::Terminate();
}
void SettingScene::BackOnClick(int stage) {
	// Change to select scene.
	Engine::GameEngine::GetInstance().ChangeScene("stage-select");
}
void SettingScene::BGMSlideOnValueChanged(float value) {
	AudioHelper::ChangeSampleVolume(bgmInstance, value);
	AudioHelper::BGMVolume = value;
}
void SettingScene::SFXSlideOnValueChanged(float value) {
	AudioHelper::SFXVolume = value;
}

