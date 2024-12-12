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
		//DONE
		int numVertices = rand() % 26 + 25;
		int numParticles = rand() % 11 + 5;
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
					for (int i = 0; i < numParticles; i++)
					{
						Particle p(m_Window, numVertices, { e.mouseButton.x, e.mouseButton.y });
						m_particles.push_back(p);
					}
				}
				if (e.mouseButton.button == Mouse::Right)
				{
					cout << "right button pressed (:" << endl;
					for (int i = 0; i < numParticles; i++)
					{
						Particle p(m_Window, numVertices, { e.mouseButton.x, e.mouseButton.y });
						m_particles.push_back(p);
					}
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::E))   //this should generate only 1 star while 'E' is being held
			{
				cout << "E pressed :D" << endl;
				Particle p(m_Window, numVertices, Mouse::getPosition(m_Window));
				m_particles.push_back(p);
			}
		}
	}

	void Engine::update(float dtAsSeconds)
	{
		//DO ME
		for (int i = 0; i < m_particles.size();)
		{
			if (m_particles.at(i).getTTL() > 0.0)
			{
				m_particles.at(i).update(dtAsSeconds);
				i++;
			}
			else
			{
				m_particles.erase(m_particles.begin() + i);
			}
		}
	}

	void Engine::draw()
	{
		//DONE
		m_Window.clear();
		for (int i = 0; i < m_particles.size(); i++)
		{
			m_Window.draw(m_particles.at(i));
		}
		m_Window.display();
	}

	// The Engine constructor
	Engine::Engine()
	{
		//DONE
		m_Window.create(VideoMode{ 1920,1080 }, "Particles !!!! :D", Style::Default);
	}

	// Run will call all the private functions
	void Engine::run()
	{
		//DONE
		Clock c;
		cout << "Starting Particle unit tests..." << endl;
		Particle p(m_Window, 8, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
		p.unitTests();
		cout << "Unit tests complete.  Starting engine..." << endl;
		while (m_Window.isOpen())
		{
			float dtAsSeconds = c.restart().asSeconds();
			input();
			update(dtAsSeconds);
			draw();
		}
	}
