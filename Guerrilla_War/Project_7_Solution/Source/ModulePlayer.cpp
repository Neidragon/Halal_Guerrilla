#include "ModulePlayer.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"

#include "SDL/include/SDL_scancode.h"


ModulePlayer::ModulePlayer()
{
	position.x = 250;
	position.y = 300;

	//iddle animation
	torsoiddleAnim.PushBack({ 4,4,26,31 });
	legsiddleAnim.PushBack({ 169, 0, 23, 31 });

	// walk forward animation
	legsup.PushBack({ 0, 33, 32, 32 });
	legsup.PushBack({ 33, 33, 32, 32 });
	legsup.PushBack({ 65, 33, 32, 32 });
	legsup.PushBack({ 97, 33,32, 32 });
	legsup.PushBack({ 130, 34, 32, 32 });
	legsup.PushBack({ 97, 33,32, 32 });
	legsup.PushBack({ 65, 33, 32, 32 });
	legsup.PushBack({ 33, 33, 32, 32 });
	legsup.speed = 0.1f;

	torsoup.PushBack({ 0,1,32,32 });
	torsoup.PushBack({ 33,1,32,32 });
	torsoup.PushBack({ 65,1,32,32 });
	torsoup.PushBack({ 97,1,32,32 });
	torsoup.PushBack({ 130,1,32,32 });
	torsoup.PushBack({ 97,1,32,32 });
	torsoup.PushBack({ 65,1,32,32 });
	torsoup.PushBack({ 33,1,32,32 });
	torsoup.speed = 0.1f;

	//walk down animation

	legsdown.PushBack({ 1,276,32,32 });
	legsdown.PushBack({ 33,276,32,32 });
	legsdown.PushBack({ 65,276,32,32 });
	legsdown.PushBack({ 97,276,32,32 });
	legsdown.PushBack({ 129,276,32,32 });
	legsdown.PushBack({ 97,276,32,32 });
	legsdown.PushBack({ 65,276,32,32 });
	legsdown.PushBack({ 33,276,32,32 });
	legsdown.speed = 0.1f;

	torsodown.PushBack({ 1,244,32,32 });
	torsodown.PushBack({ 33,244,32,32 });
	torsodown.PushBack({ 65,244,32,32 });
	torsodown.PushBack({ 97,244,32,32 });
	torsodown.PushBack({ 129,244,32,32 });
	torsodown.PushBack({ 97,244,32,32 });
	torsodown.PushBack({ 65,244,32,32 });
	torsodown.PushBack({ 33,244,32,32 });
	torsodown.speed = 0.1f;

	//walk left animation

	legsleft.PushBack({ 4,401,32,32 });
	legsleft.PushBack({ 36,401,32,32 });
	legsleft.PushBack({ 68,401,32,32 });
	legsleft.PushBack({ 100,401,32,32 });
	legsleft.PushBack({ 132,401,32,32 });
	legsleft.PushBack({ 100,401,32,32 });
	legsleft.PushBack({ 68,401,32,32 });
	legsleft.PushBack({ 36,401,32,32 });
	legsleft.speed = 0.1f;

	torsoleft.PushBack({ 4, 369, 32, 32 });
	torsoleft.PushBack({ 36, 369, 32, 32 });
	torsoleft.PushBack({ 68, 369, 32, 32 });
	torsoleft.PushBack({ 100, 369, 32, 32 });
	torsoleft.PushBack({ 132, 369, 32, 32 });
	torsoleft.PushBack({ 100, 369, 32, 32 });
	torsoleft.PushBack({ 68, 369, 32, 32 });
	torsoleft.PushBack({ 36, 369, 32, 32 });
	torsoleft.speed = 0.1f;



	//walk right animation

	legsright.PushBack({ 2,155,32,29 });
	legsright.PushBack({ 34,155,32,29 });
	legsright.PushBack({ 66,155,32,29 });
	legsright.PushBack({ 98,155,32,29 });
	legsright.PushBack({ 130,155,32,29 });
	legsright.PushBack({ 98,155,32,29 });
	legsright.PushBack({ 66,155,32,29 });
	legsright.PushBack({ 34,155,32,29 });
	legsright.speed = 0.1f;

	torsoright.PushBack({ 2,123,32,32 });
	torsoright.PushBack({ 34,123,32,32 });
	torsoright.PushBack({ 66,123,32,32 });
	torsoright.PushBack({ 98,123,32,32 });
	torsoright.PushBack({ 130,123,32,32 });
	torsoright.PushBack({ 98,123,32,32 });
	torsoright.PushBack({ 66,123,32,32 });
	torsoright.PushBack({ 34,123,32,32 });
	torsoright.speed = 0.1f;



	torsoright.speed = 0.1f;

	//walk upright animation
	torsoupright.PushBack({ 2,62,32,32 });
	torsoupright.PushBack({ 34,62,32,32 });
	torsoupright.PushBack({ 66,62,32,32 });
	torsoupright.PushBack({ 98,62,32,32 });
	torsoupright.PushBack({ 130,62,32,32 });
	torsoupright.PushBack({ 98,62,32,32 });
	torsoupright.PushBack({ 66,62,32,32 });
	torsoupright.PushBack({ 34,62,32,32 });
	torsoupright.speed = 0.1f;

	legsupright.PushBack({ 2,94,32,32 });
	legsupright.PushBack({ 34,94,32,32 });
	legsupright.PushBack({ 66,94,32,32 });
	legsupright.PushBack({ 98,94,32,32 });
	legsupright.PushBack({ 130,94,32,32 });
	legsupright.PushBack({ 98,94,32,32 });
	legsupright.PushBack({ 66,94,32,32 });
	legsupright.PushBack({ 34,94,32,32 });
	legsupright.speed = 0.1f;


	//walk upleft aimation
	torsoupleft.PushBack({ 4,429,32,32 });
	torsoupleft.PushBack({ 36,429,32,32 });
	torsoupleft.PushBack({ 68,429,32,32 });
	torsoupleft.PushBack({ 100,429,32,32 });
	torsoupleft.PushBack({ 132,429,32,32 });
	torsoupleft.PushBack({ 100,429,32,32 });
	torsoupleft.PushBack({ 68,429,32,32 });
	torsoupleft.PushBack({ 36,429,32,32 });
	torsoupleft.speed = 0.1f;

	legsupleft.PushBack({ 4,461,32,32 });
	legsupleft.PushBack({ 36,461,32,32 });
	legsupleft.PushBack({ 68,461,32,32 });
	legsupleft.PushBack({ 100,461,32,32 });
	legsupleft.PushBack({ 132,461,32,32 });
	legsupleft.PushBack({ 100,461,32,32 });
	legsupleft.PushBack({ 68,461,32,32 });
	legsupleft.PushBack({ 36,461,32,32 });
	legsupleft.speed = 0.1f;

	//walk downright animation
	torsodownright.PushBack({ 2,181,32,32 });
	torsodownright.PushBack({ 34,181,32,32 });
	torsodownright.PushBack({ 66,181,32,32 });
	torsodownright.PushBack({ 98,181,32,32 });
	torsodownright.PushBack({ 130,181,32,32 });
	torsodownright.PushBack({ 98,181,32,32 });
	torsodownright.PushBack({ 66,181,32,32 });
	torsodownright.PushBack({ 34,181,32,32 });
	torsodownright.speed = 0.1f;

	legsdownright.PushBack({ 2,213,32,32 });
	legsdownright.PushBack({ 34,213,32,32 });
	legsdownright.PushBack({ 66,213,32,32 });
	legsdownright.PushBack({ 98,213,32,32 });
	legsdownright.PushBack({ 130,213,32,32 });
	legsdownright.PushBack({ 98,213,32,32 });
	legsdownright.PushBack({ 66,213,32,32 });
	legsdownright.PushBack({ 34,213,32,32 });
	legsdownright.speed = 0.1f;

	//walk downleft aimation
	torsodownleft.PushBack({ 1,306,32,32 });
	torsodownleft.PushBack({ 33,306,32,32 });
	torsodownleft.PushBack({ 65,306,32,32 });
	torsodownleft.PushBack({ 97,306,32,32 });
	torsodownleft.PushBack({ 129,306,32,32 });
	torsodownleft.PushBack({ 97,306,32,32 });
	torsodownleft.PushBack({ 65,306,32,32 });
	torsodownleft.PushBack({ 33,306,32,32 });
	torsodownleft.speed = 0.1f;

	legsdownleft.PushBack({ 1,338,32,32 });
	legsdownleft.PushBack({ 33,338,32,32 });
	legsdownleft.PushBack({ 65,338,32,32 });
	legsdownleft.PushBack({ 97,338,32,32 });
	legsdownleft.PushBack({ 129,338,32,32 });
	legsdownleft.PushBack({ 97,338,32,32 });
	legsdownleft.PushBack({ 65,338,32,32 });
	legsdownleft.PushBack({ 33,338,32,32 });
	legsdownleft.speed = 0.1f;

	//normalweapon up
	normalweapon_up.PushBack({ 17,27,5,16 });
	//weaponup.PushBack({ 18,40,13,24 });

	//weapon down
	normalweapon_down.PushBack({ 170,10,6,24 });
	//weapon right
	normalweapon_right.PushBack({ 73,20,23,16 });
	//weapon left
	normalweapon_left.PushBack({ 238,38,18,13 });
	//weapon upright
	normalweapon_upright.PushBack({ 33,24,15,15 });
	//weapon upleft
	normalweapon_upleft.PushBack({ 274,32,14,14 });
	//weapondownright
	normalweapon_downright.PushBack({ 129,13,19,23 });
	//weapondownleft
	normalweapon_downleft.PushBack({ 204,11,15,20 });

	normalweapon_up_shot.PushBack({ 14,51,13,24 });
	normalweapon_up_shot.PushBack({ 17,27,5,16 });
	normalweapon_up_shot.speed = 0.1f;
	//weapon down shot
	normalweapon_down_shot.PushBack({ 164,46,17,37 });
	//weapon left shot
	normalweapon_left_shot.PushBack({ 229,66,27,17 });
	//weapon right shot
	normalweapon_right_shot.PushBack({ 72,50,32,22 });
	//weapon upright shot
	normalweapon_upright_shot.PushBack({ 14,51,13,24 });
	//weapon upleft shot
	normalweapon_upleft_shot.PushBack({ 32,49,22,23 });
	//weapon downright shot
	normalweapon_downright_shot.PushBack({ 128,50,27,31 });
	//weapon downleft shot
	normalweapon_downleft_shot.PushBack({ 195,49,26,24 });

	//heavyweapon up
	heavyweapon_up.PushBack({ 17,83,8,24 });
	//heavyweapon down
	heavyweapon_down.PushBack({ 168,85,8,30 });
	//heavyweapon right
	heavyweapon_right.PushBack({ 73,91,30,14 });
	//heavyweapon left
	heavyweapon_left.PushBack({ 233,100,23,12 });
	//heavyweapon upright
	heavyweapon_upright.PushBack({ 33,83,20,21 });
	//heavyweapon upleft
	heavyweapon_upleft.PushBack({ 270,92,16,19 });
	//heavyweapon downright
	heavyweapon_downright.PushBack({ 129,88,24,28 });
	//heavyweapon downleft
	heavyweapon_downleft.PushBack({ 198,86,25,25 });


	//heavyweapon up shot
	heavyweapon_up_shot.PushBack({ 11,107,14,32 });
	heavyweapon_up.PushBack({ 17,83,8,24 });
	heavyweapon_up_shot.speed = 0.1f;
	//heavyweapon down shot
	heavyweapon_down_shot.PushBack({ 161,121,25,38 });
	//heavyweapon right shot
	heavyweapon_right_shot.PushBack({ 72,121,34,21 });
	//heavyweapon left shot
	heavyweapon_left_shot.PushBack({ 228,128,28,18 });
	//heavyweapon upright shot
	heavyweapon_upright_shot.PushBack({ 32,109,27,28 });
	//heavyweapon upleft shot
	heavyweapon_upleft_shot.PushBack({ 165,117,24,27 });
	//heavyweapon downright shot
	heavyweapon_downright_shot.PushBack({ 128,127,31,33 });
	//heavyweapon downleft shot
	heavyweapon_downleft_shot.PushBack({ 189,126,33,32 });

}

ModulePlayer::~ModulePlayer()
{

}

bool ModulePlayer::Start()
{
	LOG("Loading player textures");

	bool ret = true;
	normalweapon = true;
	heavyweapon = false;
	dead == false;

	texture = App->textures->Load("Assets/Guerrilla War Player 1 Spritesheet OK.png");
	weapon_texture = App->textures->Load("Assets/Guerrilla War Weapon Spritesheet1.png");
	currentAnimationlegs = &legsup;
	currentAnimationtorso = &torsoup;
	weapon = &normalweapon_up;
	faceu = true;



	collider = App->collisions->AddCollider({ position.x, position.y, 32, 64 }, Collider::Type::PLAYER, this);

	return ret;
}

update_status ModulePlayer::Update()
{
	//Reset the currentAnimation back to idle before updating the logic

	legsiddleAnim.frames[0] = currentAnimationlegs->frames[currentAnimationlegs->GetCurrentFrameint()];
	torsoiddleAnim.frames[0] = currentAnimationtorso->frames[currentAnimationtorso->GetCurrentFrameint()];

	currentAnimationlegs = &legsiddleAnim;
	currentAnimationtorso = &torsoiddleAnim;


	//up
	if (faceu == true && App->input->keys[SDL_SCANCODE_W] == KEY_REPEAT) {
		currentAnimationtorso = &torsoup;
	}
	/*else if (faced == true && App->input->keys[SDL_SCANCODE_W] == KEY_REPEAT) {
		currentAnimationlegs = &legsdown;
	}*/
	if (App->input->keys[SDL_SCANCODE_W] == KEY_REPEAT)
	{
		currentAnimationlegs = &legsup;
		position.y -= speed;
	}
	//down
	if (faced == true && App->input->keys[SDL_SCANCODE_S] == KEY_REPEAT) {
		currentAnimationtorso = &torsodown;
	}
	if (App->input->keys[SDL_SCANCODE_S] == KEY_REPEAT)
	{
		currentAnimationlegs = &legsdown;
		position.y += speed;
	}

	//right
	if (facer == true && App->input->keys[SDL_SCANCODE_D] == KEY_REPEAT) {
		currentAnimationtorso = &torsoright;
	}
	if (App->input->keys[SDL_SCANCODE_D] == KEY_REPEAT)
	{
		currentAnimationlegs = &legsright;
		position.x += speed;
	}

	//left
	if (facel == true && App->input->keys[SDL_SCANCODE_A] == KEY_REPEAT) {
		currentAnimationtorso = &torsoleft;
	}
	if (App->input->keys[SDL_SCANCODE_A] == KEY_REPEAT)
	{
		currentAnimationlegs = &legsleft;
		position.x -= speed;
	}

	//upright
	if (faceur == true && App->input->keys[SDL_SCANCODE_W] == KEY_REPEAT && App->input->keys[SDL_SCANCODE_D] == KEY_REPEAT) {
		currentAnimationtorso = &torsoupright;
	}
	if (App->input->keys[SDL_SCANCODE_W] == KEY_REPEAT && App->input->keys[SDL_SCANCODE_D] == KEY_REPEAT)
	{
		currentAnimationlegs = &legsupright;
	}

	//upleft
	if (faceul == true && App->input->keys[SDL_SCANCODE_W] == KEY_REPEAT && App->input->keys[SDL_SCANCODE_A] == KEY_REPEAT) {
		currentAnimationtorso = &torsoupleft;
	}
	if (App->input->keys[SDL_SCANCODE_W] == KEY_REPEAT && App->input->keys[SDL_SCANCODE_A] == KEY_REPEAT)
	{
		currentAnimationlegs = &legsupleft;
	}

	//downright
	if (facedr == true && App->input->keys[SDL_SCANCODE_S] == KEY_REPEAT && App->input->keys[SDL_SCANCODE_D] == KEY_REPEAT) {
		currentAnimationtorso = &torsodownright;
	}
	if (App->input->keys[SDL_SCANCODE_S] == KEY_REPEAT && App->input->keys[SDL_SCANCODE_D] == KEY_REPEAT)
	{
		currentAnimationlegs = &legsdownright;
	}

	//down left
	if (facedl == true && App->input->keys[SDL_SCANCODE_S] == KEY_REPEAT && App->input->keys[SDL_SCANCODE_A] == KEY_REPEAT) {
		currentAnimationtorso = &torsodownleft;
	}
	if (App->input->keys[SDL_SCANCODE_S] == KEY_REPEAT && App->input->keys[SDL_SCANCODE_A] == KEY_REPEAT)
	{
		currentAnimationlegs = &legsdownleft;
	}


	if (normalweapon == true && heavyweapon == false) {
		//look up
		if (App->input->keys[SDL_SCANCODE_UP] == KEY_DOWN)
		{
			//App->particles->AddParticle(App->particles->normal_up_shot, position.x +20, position.y+20, Collider::Type::PLAYER_SHOT);
			currentAnimationtorso = &torsoup;
			weapon = &normalweapon_up;
			faceu = true;
			faced = false;
			facer = false;
			facel = false;
			faceur = false;
			faceul = false;
			facedr = false;
			facedl = false;
		}

		//look down
		if (App->input->keys[SDL_SCANCODE_DOWN] == KEY_DOWN)
		{
			currentAnimationtorso = &torsodown;
			weapon = &normalweapon_down;
			faceu = false;
			faced = true;
			facer = false;
			facel = false;
			faceur = false;
			faceul = false;
			facedr = false;
			facedl = false;
		}

		//look right
		if (App->input->keys[SDL_SCANCODE_RIGHT] == KEY_DOWN)
		{
			currentAnimationtorso = &torsoright;
			weapon = &normalweapon_right;
			faceu = false;
			faced = false;
			facer = true;
			facel = false;
			faceur = false;
			faceul = false;
			facedr = false;
			facedl = false;
		}

		//look left
		if (App->input->keys[SDL_SCANCODE_LEFT] == KEY_DOWN)
		{
			currentAnimationtorso = &torsoleft;
			weapon = &normalweapon_left;
			faceu = false;
			faced = false;
			facer = false;
			facel = true;
			faceur = false;
			faceul = false;
			facedr = false;
			facedl = false;
		}
		//look upright
		if (App->input->keys[SDL_SCANCODE_RIGHT] == KEY_DOWN && App->input->keys[SDL_SCANCODE_UP] == KEY_DOWN)
		{
			currentAnimationtorso = &torsoupright;
			weapon = &normalweapon_upright;
			faceu = false;
			faced = false;
			facer = false;
			facel = false;
			faceur = true;
			faceul = false;
			facedr = false;
			facedl = false;
		}
		//look upleft
		if (App->input->keys[SDL_SCANCODE_LEFT] == KEY_DOWN && App->input->keys[SDL_SCANCODE_UP] == KEY_DOWN)
		{
			currentAnimationtorso = &torsoupleft;
			weapon = &normalweapon_upleft;
			faceu = false;
			faced = false;
			facer = false;
			facel = false;
			faceur = false;
			faceul = true;
			facedr = false;
			facedl = false;
		}
		//look downright
		if (App->input->keys[SDL_SCANCODE_RIGHT] == KEY_DOWN && App->input->keys[SDL_SCANCODE_DOWN] == KEY_DOWN)
		{
			currentAnimationtorso = &torsodownright;
			weapon = &normalweapon_downright;
			faceu = false;
			faced = false;
			facer = false;
			facel = false;
			faceur = false;
			faceul = false;
			facedr = true;
			facedl = false;
		}
		//look downleft
		if (App->input->keys[SDL_SCANCODE_LEFT] == KEY_DOWN && App->input->keys[SDL_SCANCODE_DOWN] == KEY_DOWN)
		{
			currentAnimationtorso = &torsodownleft;
			weapon = &normalweapon_downleft;
			faceu = false;
			faced = false;
			facer = false;
			facel = false;
			faceur = false;
			faceul = false;
			facedr = false;
			facedl = true;
		}
		//shots

		if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_DOWN)
		{
			if (faceu == true) {
				App->particles->AddParticle(App->particles->normal_up_shot, position.x + 22, position.y + 4, Collider::Type::PLAYER_SHOT);
				//weapon = &weapon_up_shot;
			}
			else if (faced == true) {
				App->particles->AddParticle(App->particles->normal_down_shot, position.x + 8, position.y + 35, Collider::Type::PLAYER_SHOT);
			}
			else if (facer == true) {
				App->particles->AddParticle(App->particles->normal_hr_shot, position.x + 20, position.y + 24, Collider::Type::PLAYER_SHOT);
			}
			else if (facel == true) {
				App->particles->AddParticle(App->particles->normal_hl_shot, position.x - 4, position.y + 21, Collider::Type::PLAYER_SHOT);
			}
			else if (faceur == true) {
				App->particles->AddParticle(App->particles->normal_ur_shot, position.x + 20, position.y + 20, Collider::Type::PLAYER_SHOT);
			}
			else if (faceul == true) {
				App->particles->AddParticle(App->particles->normal_ul_shot, position.x + 6, position.y + 10, Collider::Type::PLAYER_SHOT);
			}
			else if (facedr == true) {
				App->particles->AddParticle(App->particles->normal_dr_shot, position.x + 18, position.y + 35, Collider::Type::PLAYER_SHOT);
			}
			else if (facedl == true) {
				App->particles->AddParticle(App->particles->normal_dl_shot, position.x + 2, position.y + 26, Collider::Type::PLAYER_SHOT);
			}
		}
	}
	else if (heavyweapon == true && normalweapon == false) {
		//look up
		if (App->input->keys[SDL_SCANCODE_UP] == KEY_DOWN)
		{
			//App->particles->AddParticle(App->particles->normal_up_shot, position.x +20, position.y+20, Collider::Type::PLAYER_SHOT);
			currentAnimationtorso = &torsoup;
			weapon = &heavyweapon_up;
			faceu = true;
			faced = false;
			facer = false;
			facel = false;
			faceur = false;
			faceul = false;
			facedr = false;
			facedl = false;
		}

		//look down
		if (App->input->keys[SDL_SCANCODE_DOWN] == KEY_DOWN)
		{
			currentAnimationtorso = &torsodown;
			weapon = &heavyweapon_down;
			faceu = false;
			faced = true;
			facer = false;
			facel = false;
			faceur = false;
			faceul = false;
			facedr = false;
			facedl = false;
		}

		//look right
		if (App->input->keys[SDL_SCANCODE_RIGHT] == KEY_DOWN)
		{
			currentAnimationtorso = &torsoright;
			weapon = &heavyweapon_right;
			faceu = false;
			faced = false;
			facer = true;
			facel = false;
			faceur = false;
			faceul = false;
			facedr = false;
			facedl = false;
		}

		//look left
		if (App->input->keys[SDL_SCANCODE_LEFT] == KEY_DOWN)
		{
			currentAnimationtorso = &torsoleft;
			weapon = &heavyweapon_left;
			faceu = false;
			faced = false;
			facer = false;
			facel = true;
			faceur = false;
			faceul = false;
			facedr = false;
			facedl = false;
		}
		//look upright
		if (App->input->keys[SDL_SCANCODE_RIGHT] == KEY_DOWN && App->input->keys[SDL_SCANCODE_UP] == KEY_DOWN)
		{
			currentAnimationtorso = &torsoupright;
			weapon = &heavyweapon_upright;
			faceu = false;
			faced = false;
			facer = false;
			facel = false;
			faceur = true;
			faceul = false;
			facedr = false;
			facedl = false;
		}
		//look upleft
		if (App->input->keys[SDL_SCANCODE_LEFT] == KEY_DOWN && App->input->keys[SDL_SCANCODE_UP] == KEY_DOWN)
		{
			currentAnimationtorso = &torsoupleft;
			weapon = &heavyweapon_upleft;
			faceu = false;
			faced = false;
			facer = false;
			facel = false;
			faceur = false;
			faceul = true;
			facedr = false;
			facedl = false;
		}
		//look downright
		if (App->input->keys[SDL_SCANCODE_RIGHT] == KEY_DOWN && App->input->keys[SDL_SCANCODE_DOWN] == KEY_DOWN)
		{
			currentAnimationtorso = &torsodownright;
			weapon = &heavyweapon_downright;
			faceu = false;
			faced = false;
			facer = false;
			facel = false;
			faceur = false;
			faceul = false;
			facedr = true;
			facedl = false;
		}
		//look downleft
		if (App->input->keys[SDL_SCANCODE_LEFT] == KEY_DOWN && App->input->keys[SDL_SCANCODE_DOWN] == KEY_DOWN)
		{
			currentAnimationtorso = &torsodownleft;
			weapon = &heavyweapon_downleft;
			faceu = false;
			faced = false;
			facer = false;
			facel = false;
			faceur = false;
			faceul = false;
			facedr = false;
			facedl = true;
		}
		//shots

		if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_DOWN)
		{
			uint shoot = App->audio->LoadFx("Assets/gwar-137.wav");
			if (faceu == true) {
				App->particles->AddParticle(App->particles->normal_up_shot, position.x + 22, position.y + 4, Collider::Type::PLAYER_SHOT);
				//weapon = &weapon_up_shot;
				App->audio->PlayFx(shoot, 0);
			}
			else if (faced == true) {
				App->audio->PlayFx(shoot, 0);
				App->particles->AddParticle(App->particles->normal_down_shot, position.x + 8, position.y + 35, Collider::Type::PLAYER_SHOT);
			}
			else if (facer == true) {
				App->audio->PlayFx(shoot, 0);
				App->particles->AddParticle(App->particles->normal_hr_shot, position.x + 20, position.y + 24, Collider::Type::PLAYER_SHOT);
			}
			else if (facel == true) {
				App->audio->PlayFx(shoot, 0);
				App->particles->AddParticle(App->particles->normal_hl_shot, position.x - 4, position.y + 21, Collider::Type::PLAYER_SHOT);
			}
			else if (faceur == true) {
				App->audio->PlayFx(shoot, 0);
				App->particles->AddParticle(App->particles->normal_ur_shot, position.x + 20, position.y + 20, Collider::Type::PLAYER_SHOT);
			}
			else if (faceul == true) {
				App->audio->PlayFx(shoot, 0);
				App->particles->AddParticle(App->particles->normal_ul_shot, position.x + 6, position.y + 10, Collider::Type::PLAYER_SHOT);
			}
			else if (facedr == true) {
				App->audio->PlayFx(shoot, 0);
				App->particles->AddParticle(App->particles->normal_dr_shot, position.x + 18, position.y + 35, Collider::Type::PLAYER_SHOT);
			}
			else if (facedl == true) {
				App->audio->PlayFx(shoot, 0);
				App->particles->AddParticle(App->particles->normal_dl_shot, position.x + 2, position.y + 26, Collider::Type::PLAYER_SHOT);
			}
		}
	}


	////grenade
	//if (App->input->keys[SDL_SCANCODE_LALT] == KEY_DOWN )
	//{
	//	App->particles->AddParticle(App->particles->grenade_up, position.x + 20, position.y + 20, Collider::Type::PLAYER_SHOT);
	//	
	//}

	collider->SetPos(position.x, position.y);

	currentAnimationlegs->Update();
	currentAnimationtorso->Update();
	weapon->Update();

	if (dead)
	{
		destroyedCountdown--;
		if (destroyedCountdown <= 0)
			return update_status::UPDATE_STOP;
	}

	return update_status::UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate()
{
	if (!dead)
	{
		//render legs
		SDL_Rect rect2 = currentAnimationlegs->GetCurrentFrame();
		App->render->Blit(texture, position.x, position.y + 32, &rect2);
		//render weapon
		SDL_Rect rect3 = weapon->GetCurrentFrame();
		if (faceu == true) {
			App->render->Blit(weapon_texture, position.x + 21, position.y + 2, &rect3);
		}
		else if (faced == true) {
			App->render->Blit(weapon_texture, position.x + 7, position.y + 22, &rect3);
		}
		else if (facel == true) {
			App->render->Blit(weapon_texture, position.x - 6, position.y + 20, &rect3);
		}
		else if (faceur == true) {
			App->render->Blit(weapon_texture, position.x + 19, position.y + 12, &rect3);
		}
		else if (faceul == true) {
			App->render->Blit(weapon_texture, position.x, position.y + 4, &rect3);
		}
		else if (facedr == true) {
			App->render->Blit(weapon_texture, position.x + 7, position.y + 22, &rect3);
		}

		//render torso
		SDL_Rect rect1 = currentAnimationtorso->GetCurrentFrame();
		App->render->Blit(texture, position.x, position.y, &rect1);

		if (facedl == true) {
			App->render->Blit(weapon_texture, position.x, position.y + 22, &rect3);
		}
		else if (facer == true) {
			App->render->Blit(weapon_texture, position.x + 8, position.y + 22, &rect3);
		}

	}

	return update_status::UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (c1 == collider && dead == false)
	{

		switch (c2->type) {
		case (Collider::Type::WALL):
			if (collider->Intersects(c2->rect)) {
				if (position.x >= c2->rect.x) {

					if (position.y > c2->rect.y + c2->rect.h - 2) {
						position.y += speed;
						if (position.y <= App->render->cameralimits.y + 1) {
							App->render->camera.y -= App->render->cameraSpeed;
						}
					}
					else if (position.y < c2->rect.y - c1->rect.h + 2) {
						position.y -= speed;
						if (position.y + 64 >= App->render->cameralimits.y + App->render->cameralimits.h - 1) {
							App->render->camera.y += App->render->cameraSpeed;
						}
					}
					else {
						position.x += speed;
						if (position.x <= App->render->cameralimits.x + 1) {
							App->render->camera.x -= App->render->cameraSpeed;
						}
					}

				}

				if (position.x < c2->rect.x) {

					if (position.y > c2->rect.y + c2->rect.h - 2) {
						position.y += speed;
						if (position.y <= App->render->cameralimits.y + 1) {
							App->render->camera.y -= App->render->cameraSpeed;
						}
					}
					else if (position.y < c2->rect.y - c1->rect.h + 2) {
						position.y -= speed;
						if (position.y + 64 >= App->render->cameralimits.y + App->render->cameralimits.h - 1) {
							App->render->camera.y += App->render->cameraSpeed;
						}

					}
					else {
						position.x -= speed;
						if (App->player->position.x + 32 >= App->render->cameralimits.x + App->render->cameralimits.w - 1) {
							App->render->camera.x += App->render->cameraSpeed;
						}
					}
				}
			}
			break;
		case (Collider::Type::DESTROYABLE_WALL):
			if (c1->Intersects(c2->rect)) {
				if (position.x >= c2->rect.x) {

					if (position.y > c2->rect.y + c2->rect.h - 2) {
						position.y += speed;
						if (position.y <= App->render->cameralimits.y + 1) {
							App->render->camera.y -= App->render->cameraSpeed;
						}
					}
					else if (position.y < c2->rect.y - c1->rect.h + 2) {
						position.y -= speed;
						if (position.y + 64 >= App->render->cameralimits.y + App->render->cameralimits.h - 1) {
							App->render->camera.y += App->render->cameraSpeed;
						}
					}
					else {
						position.x += speed;
						if (position.x <= App->render->cameralimits.x + 1) {
							App->render->camera.x -= App->render->cameraSpeed;
						}
					}

				}

				if (position.x < c2->rect.x) {

					if (position.y > c2->rect.y + c2->rect.h - 2) {
						position.y += speed;
						if (position.y <= App->render->cameralimits.y + 1) {
							App->render->camera.y -= App->render->cameraSpeed;
						}
					}
					else if (position.y < c2->rect.y - c1->rect.h + 2) {
						position.y -= speed;
						if (position.y + 64 >= App->render->cameralimits.y + App->render->cameralimits.h - 1) {
							App->render->camera.y += App->render->cameraSpeed;
						}

					}
					else {
						position.x -= speed;
						if (App->player->position.x + 32 >= App->render->cameralimits.x + App->render->cameralimits.w - 1) {
							App->render->camera.x += App->render->cameraSpeed;
						}
					}
				}
			}
			break;
		case(Collider::Type::ENEMY_SHOT):
			if (collider->Intersects(c2->rect)) {
				//currentAnimation = &death;
				//currentAnimation->Update();
				dead = true;
			}
			break;
		case (Collider::Type::POWERUP):
			if (collider->Intersects(c2->rect)) {
				heavyweapon = true;
				normalweapon = false;
			}
		}

	}
}