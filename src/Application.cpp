#include "Application.h"
#include "CollisionDetector.h"
#include <random>

Application::~Application()
{
	delete m_player;
	SDL_Quit();
}

void Application::i_run()
{
	i_intro_loop();
	if(m_isGameRunning)
		i_main_loop();
}

void Application::i_intro_loop()
{
	Texture intro(m_window, "../res/gfx/intro.png");
	bool isIntroRunning = true;

	while (isIntroRunning)
	{
		while (m_events.while_events())
		{
			if (m_events.get_event().type == SDL_QUIT) 
			{
				m_isGameRunning = false;
				isIntroRunning = false;
			}

			if (m_events.get_event().type == SDL_KEYDOWN)
			{
				switch (m_events.get_event().key.keysym.sym)
				{
				case SDLK_1:
					m_player = new Agent_A();
					isIntroRunning = false;
					break;
				case SDLK_2:
					m_player = new Agent_B();
					isIntroRunning = false;
					break;
				}
			}
		}

		m_window.clear();
		m_window.render_static_texture(intro.get_texture(), nullptr, nullptr);
		m_window.display();
	}
}

void Application::i_main_loop()
{
	GameMap& gameMap = GameMap::get_instance(m_window);

	std::random_device rd;
	std::mt19937 gen(0);

	Texture playerTex(m_window, "../res/gfx/player_dot.png", texture_type::player, true);
	Texture enemyTex(m_window, "../res/gfx/enemy_dot.png", texture_type::enemy, true);
	Texture mapTex = gameMap.render_map_texture(m_window, gen);

	gen.seed(rd());

	CollisionDetector& collisionDetector = CollisionDetector::get_instance();
	collisionDetector.set_colliders(gameMap);

	SDL_Rect cameraRect;

	m_player->set_dotCenter({ 64, 64 });

	std::vector<Enemy> enemies;
	enemies.reserve(4);
	enemies.emplace_back(Enemy({ 1000, 64 }));
	enemies.emplace_back(Enemy({ 1500, 64 }));
	enemies.emplace_back(Enemy({ 2000, 64 }));
	enemies.emplace_back(Enemy({ 64 * 10, 500 }));

	while (m_isGameRunning)
	{
		while (m_events.while_events()) 
		{
			if (m_events.get_event().type == SDL_QUIT)
				m_isGameRunning = false;

			m_events.handle_events(m_player);
		}

		collisionDetector.move_player(m_player);
		collisionDetector.move_enemies(enemies, gen);
		collisionDetector.detect_player(m_player, enemies);
		if (collisionDetector.is_player_catched(m_player, enemies))
			break;
		m_player->handle_special_ability();
		m_window.handle_Camera(m_player, LEVEL_WIDTH * 64, LEVEL_HEIGHT * 64);
		m_window.clear();
		cameraRect = m_window.get_camera();
		m_window.render_static_texture(mapTex.get_texture(), &cameraRect, nullptr);
		m_window.render_entity(playerTex.get_texture(), m_player);
		for (auto& enemy : enemies)
			m_window.render_entity(enemyTex.get_texture(), &enemy);
		m_window.display();
	}
}