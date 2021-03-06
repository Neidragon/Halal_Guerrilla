#ifndef __MODULE_PARTICLES_H__
#define __MODULE_PARTICLES_H__

#include "Module.h"

#include "Globals.h"
#include "Particle.h"
#include "Collider.h"

#define MAX_ACTIVE_PARTICLES 100

struct SDL_Texture;
struct Collider;

class ModuleParticles : public Module
{
public:
	// Constructor
	// Initializes all the particles in the array to nullptr
	ModuleParticles();

	//Destructor
	~ModuleParticles();

	// Called when the module is activated
	// Loads the necessary textures for the particles
	bool Start() override;

	// Called at the middle of the application loop
	// Iterates all the particles and calls its Update()
	// Removes any "dead" particles
	update_status Update() override;

	// Called at the end of the application loop
	// Iterates all the particles and draws them
	update_status PostUpdate() override;

	// Called on application exit
	// Destroys all active particles left in the array
	bool CleanUp() override;

	// Called when a particle collider hits another collider
	void OnCollision(Collider* c1, Collider* c2) override;

	// Creates a new particle and adds it to the array
	// Param particle	- A template particle from which the new particle will be created
	// Param x, y		- Position x,y in the screen (upper left axis)
	// Param delay		- Delay time from the moment the function is called until the particle is displayed in screen
	void AddParticle(const Particle& particle, int x, int y, Collider::Type colliderType = Collider::Type::NONE, uint delay = 0);

private:
	// Particles spritesheet loaded into an SDL Texture
	SDL_Texture* texture = nullptr;
	SDL_Texture* textureEnemy = nullptr;

	// An array to store and handle all the particles
	Particle* particles[MAX_ACTIVE_PARTICLES] = { nullptr };

public:
	//Template particle for an explosion
	Particle explosion;

	//Template particle for a laser
	Particle normal_hr_shot, normal_hl_shot, normal_up_shot, normal_down_shot, normal_dr_shot, normal_dl_shot, normal_ul_shot, normal_ur_shot;
	Particle grenade_up, grenade_down, grenade_right, grenade_left, grenade_ur, grenade_ul, grenade_dr, grenade_dl;
	Particle upgraded_shot;
	
	
	Particle green_up, green_down, green_left, green_right, green_ul, green_ur, green_dl, green_dr;
	Particle red_up, red_down, red_left, red_right, red_ul, red_ur, red_dl, red_dr;
	Particle bomb_up, bomb_down, bomb_left, bomb_right, bomb_ul, bomb_ur, bomb_dl, bomb_dr;
	Particle boss_up, boss_down, boss_left, boss_right, boss_ul, boss_ur, boss_dl, boss_dr;
};

#endif // !__MODULEPARTICLES_H__


