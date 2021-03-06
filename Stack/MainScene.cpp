#include "MainScene.h"
#include "InputClass.h"
#include "GameScene.h"
#include "ConstVars.h"
#include "UISprite.h"

void MainScene::Start(Camera& camera)
{

	if (!SystemClass::GetInstance()->GetBoolVariable("started"))
	{
		SystemClass::GetInstance()->SetBoolVariable("started", true);

		//��� ����.
		SystemClass::GetInstance()->SetBoolVariable("isEnd", false);

		SystemClass::GetInstance()->LoadTexture(ConstVars::CONCREAT_TEX_FILE);
		SystemClass::GetInstance()->LoadTexture(ConstVars::FEBRIC_TEX_FILE);
		SystemClass::GetInstance()->LoadTexture(ConstVars::PLANE_TEX_FILE);
		SystemClass::GetInstance()->LoadTexture(ConstVars::COLORFUL_TILE_TEX_FILE);
		SystemClass::GetInstance()->LoadTexture(ConstVars::MAIN_MENU_TEX_FILE);
		SystemClass::GetInstance()->LoadTexture(ConstVars::CHAR_TEX_FILE);
		SystemClass::GetInstance()->LoadTexture(ConstVars::ITALIAN_TILE_TEX_FILE);

		SystemClass::GetInstance()->PreLoadSoundFile(ConstVars::SOUND_FILE1);
		SystemClass::GetInstance()->PreLoadSoundFile(ConstVars::SOUND_FILE2);
		SystemClass::GetInstance()->PreLoadSoundFile(ConstVars::SOUND_FILE3);
		SystemClass::GetInstance()->PreLoadSoundFile(ConstVars::SOUND_FILE4);
		SystemClass::GetInstance()->PreLoadSoundFile(ConstVars::SOUND_FILE5);
		SystemClass::GetInstance()->PreLoadSoundFile(ConstVars::SOUND_FILE6);
		SystemClass::GetInstance()->PreLoadSoundFile(ConstVars::SOUND_FILE7);
		SystemClass::GetInstance()->PreLoadSoundFile(ConstVars::SOUND_FILE8);
	}


	camera.InitCamera();
	float viewWidth = ConstVars::DEFAULT_VIEW_WIDTH;
	float viewHeight = ConstVars::DEFAULT_VIEW_HEIGHT;
	camera.SetProjection(viewWidth, viewHeight);
	m_background = new UISprite();
	m_background->SetPosition(0.0f, 0.0f, 0.0f);
	m_background->SetUISize(2.0f, 2.0f);
	m_background->SetRGB(1, 1, 1);
	m_background->SetToRect();
	m_background->SetTextureName(ConstVars::MAIN_MENU_TEX_FILE);
	m_UISprites.emplace_back(m_background);
}

bool MainScene::Update(float dt, InputClass& input, Camera& camera)
{

	if (input.IsKeyDown(VK_SPACE))
	{
		SystemClass::GetInstance()->SetScene(new GameScene());
		return false;
	}
	return true;
}

void MainScene::ShutDown()
{
	delete m_background;
}
