#include "ModuleScene.h"
#include "ModulePlayer.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleEnemies.h"

ModuleScene::ModuleScene()
{
	background.x = 0;
	background.y = 0;
	background.w = 1117;
	background.h = 4576;
}

ModuleScene::~ModuleScene()
{

}

// Load assets
bool ModuleScene::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/Guerrilla_War_ARC_Map_Level1 copia.png");
	App->audio->PlayMusic("Assets/gwar-107.ogg");
	
	//left wall colliders
	App->collisions->AddCollider({ -30, 420, 64,105 }, Collider::Type::WALL);
	App->collisions->AddCollider({ -30,381, 93,39 }, Collider::Type::WALL);
	App->collisions->AddCollider({ -30, 345, 124,36 }, Collider::Type::WALL);
	App->collisions->AddCollider({ -30, 240, 160,105 }, Collider::Type::WALL);
	App->collisions->AddCollider({ -30, 200, 200,40 }, Collider::Type::WALL);
	App->collisions->AddCollider({ -30, 25, 230,175 }, Collider::Type::WALL);
	App->collisions->AddCollider({ -30, -35, 200,60 }, Collider::Type::WALL);
	App->collisions->AddCollider({ -30, -65, 170,30 }, Collider::Type::WALL);
	App->collisions->AddCollider({ -30, -95, 140,30 }, Collider::Type::WALL);
	App->collisions->AddCollider({ -30, -265, 125,170 }, Collider::Type::WALL);
	App->collisions->AddCollider({ -30, -330, 165,65 }, Collider::Type::WALL);
	App->collisions->AddCollider({ -30, -365, 195,35 }, Collider::Type::WALL);
	App->collisions->AddCollider({ -30, -535, 230,170 }, Collider::Type::WALL);
	App->collisions->AddCollider({ -30, -595, 200,60 }, Collider::Type::WALL);
	App->collisions->AddCollider({ -30, -625, 170,30 }, Collider::Type::WALL);
	App->collisions->AddCollider({ -30, -655, 140,30 }, Collider::Type::WALL);
	App->collisions->AddCollider({ -30, -825, 125,170 }, Collider::Type::WALL);
	App->collisions->AddCollider({ -30, -870, 165,45 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 135, -890, 280,30 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 135, -920, 310,30 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 135, -1100, 345,180 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 135, -1200, 320,100 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 135, -1315, 290,115 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 135, -1465, 310,150 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 250, -1660, 10,195 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 355, -1585, 70,35 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 250, -1690, 175,30 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 250, -2185, 70,350 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 410, -1920, 20,30 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 410, -2060, 20,30 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 410, -2130, 20,30 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 250, -2290, 105,35 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 250, -2360, 175,70 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 250, -2440, 135,80 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 250, -2480, 175,40 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 320, -2580, 210,100 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 320, -2790, 350,210 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 320, -2830, 310,40 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 320, -2870, 270,40 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 500, -3425, 90,40 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 500, -3635, 135,210 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 500, -3845, 165,210 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 500, -4045, 600,200 }, Collider::Type::WALL);

	//right wall colliders
	App->collisions->AddCollider({ 470, 480, 64,45 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 440, 420, 94,60 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 400, 380, 135,40 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 360, 310, 175,70 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 335, 275, 200,35 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 300, -45, 235,320 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 335, -255, 200,210 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 300, -615, 235,360 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 410, -645, 170,30 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 450, -695, 140,50 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 550, -865, 80,170 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 590, -1165, 120,300 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 615, -1240, 120,75 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 590, -1470, 200,230 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 790, -1660, 40,195 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 605, -1585, 70,35 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 605, -1690, 210,30 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 660, -2185, 190,350 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 550, -1920, 20,30 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 550, -2060, 20,30 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 550, -2130, 20,30 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 710, -2290, 210,35 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 700, -2380, 280,90 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 770, -2420, 200,40 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 880, -2460, 60,40 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 900, -2790, 60,330 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 930, -2830, 100,40 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 970, -2870, 100,40 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 960, -3425, 90,40 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 930, -3735, 135,310 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 920, -3595, 40,35 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 960, -3845, 135,110 }, Collider::Type::WALL);


	//destroyable wall, warsacks, tanktraps and etc

	App->collisions->AddCollider({ 110, -205, 36,25 }, Collider::Type::DESTROYABLE_WALL);
	App->collisions->AddCollider({ 146, -205, 36,25 }, Collider::Type::DESTROYABLE_WALL);

	App->collisions->AddCollider({ 250, -205, 36,25 }, Collider::Type::DESTROYABLE_WALL);
	App->collisions->AddCollider({ 286, -205, 36,25 }, Collider::Type::DESTROYABLE_WALL);

	////First two columns colliders
	//App->collisions->AddCollider({ 1375, 0, 111, 96 }, Collider::Type::WALL);
	//App->collisions->AddCollider({ 1375, 145, 111, 96 }, Collider::Type::WALL);

	//// Enemies ---
	App->enemies->AddEnemy(ENEMY_TYPE::BOMB, 398, -2290);
	//App->enemies->AddEnemy(ENEMY_TYPE::BOMB, 500, -2290); //A partir de 500 capamunt desapareix not sure why
	App->enemies->AddEnemy(ENEMY_TYPE::RED, 250, 200);
	App->enemies->AddEnemy(ENEMY_TYPE::RED, 200, 200);
	App->enemies->AddEnemy(ENEMY_TYPE::RED, 225, -400);
	//App->enemies->AddEnemy(ENEMY_TYPE::TRUCK, 250, 200);
	//App->enemies->AddEnemy(ENEMY_TYPE::REDBIRD, 665, 80);

	//// TODO 1: Add a new wave of red birds
	//App->enemies->AddEnemy(ENEMY_TYPE::REDBIRD, 735, 120);
	//App->enemies->AddEnemy(ENEMY_TYPE::REDBIRD, 750, 120);
	//App->enemies->AddEnemy(ENEMY_TYPE::REDBIRD, 775, 120);
	//App->enemies->AddEnemy(ENEMY_TYPE::REDBIRD, 790, 120);

	//// TODO 2: Add a new wave of brown cookies
	//App->enemies->AddEnemy(ENEMY_TYPE::BROWNSHIP, 830, 100);
	//App->enemies->AddEnemy(ENEMY_TYPE::BROWNSHIP, 850, 100);
	//App->enemies->AddEnemy(ENEMY_TYPE::BROWNSHIP, 870, 100);
	//App->enemies->AddEnemy(ENEMY_TYPE::BROWNSHIP, 890, 100);

	//App->enemies->AddEnemy(ENEMY_TYPE::MECH, 900, 195);


	return ret;
}

update_status ModuleScene::Update()
{
	if (App->player->position.y <= 290) {
		//App->audio->PlayMusic("Assets/gwar-107.wav", 1.0f);
		//Mix_Pause(-1);
		//App->audio->CleanUp();
		//App->audio->Init();
		//App->audio->PlayMusic("Assets/gwar-104.wav", 1.0f);
		//uint boss = App->audio->LoadFx("Assets/gwar-104.wav");
		//App->audio->PlayFx(boss, -1);
		//App->audio->PlayFx(boss, -1);
	}
	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleScene::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, -30, -4050, &background, 1);
	return update_status::UPDATE_CONTINUE;
}