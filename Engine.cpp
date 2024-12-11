//THIS WHOLE FILE IS NEW
#include "Engine.h"
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
using namespace sf;
using namespace std;


	// A regular RenderWindow
	RenderWindow m_Window;

	//vector for Particles
	vector<Particle> m_particles;

	// Private functions for internal use only
	void Engine::input()
	{
		//DO ME
		Event e;
		while (m_Window.pollEvent(e))
		{
			if (e.type == Event::Closed) { m_Window.close(); }

			if (Keyboard::isKeyPressed(Keyboard::Escape)) { m_Window.close(); }

			if (e.type == Event::MouseButtonPressed)
			{
				if (e.mouseButton.button == Mouse::Left)
				{
					cout << "left button pressed :)" << endl;
					for (int i = 0; i < 5; i++)
					{
						Particle p(m_Window, 25, { e.mouseButton.x, e.mouseButton.y });
					}
				}
				if (e.mouseButton.button == Mouse::Right)
				{
					cout << "right button pressed (:" << endl;
					for (int i = 0; i < 3; i++)
					{
						Particle p(m_Window, 15, { e.mouseButton.x, e.mouseButton.y });
					}
				}
			}
		}
	}

	void Engine::update(float dtAsSeconds)
	{
		//DO ME
	}

	void Engine::draw()
	{
		//DO ME
		m_Window.clear();
		for (int i = 0; i < m_particles.size(); i++)
		{
			m_Window.draw(m_particles.at(i));
		}
	}

	// The Engine constructor
	Engine::Engine()
	{
		//DO ME
		m_Window.create(VideoMode{ 960,520 }, "Particles !!!! :D", Style::Default);
	}

	// Run will call all the private functions
	void Engine::run()
	{
		//DO ME
		Clock c;
		//Time t = c.getElapsedTime();
		cout << "Starting Particle unit tests..." << endl;
		Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
		p.unitTests();
		cout << "Unit tests complete.  Starting engine..." << endl;
		while (m_Window.isOpen())
		{
			//t = c.restart();
			input();
			update(c.restart().asSeconds());
			draw();
		}
	}
