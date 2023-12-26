/*
* Copyright (c) 2023 Julio Cesar Pescuite Goncalves Batista
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#include "../include/IBase.h"
#include "../include/IGameEngine.h"
#include "SceneManager.cpp"

class GameEngine : public IGameEngine, public IBase
{
private:
	SceneManager* m_pSceneManager;

public:
	GameEngine() {
		log("GameEngine: constructor");
		m_pSceneManager = new SceneManager();
	}

	~GameEngine() {
		log("GameEngine: destructor");

		delete m_pSceneManager;
		m_pSceneManager = nullptr;
	}

	void init()
	{
		log("Game Engine initialization");
	}

	void addScene(Scene* p_scene)
	{
		m_pSceneManager->addScene(p_scene);
	}

	void loop()
	{
		log("Game Engine loop");
		m_pSceneManager->update();
	}

	void shutdown()
	{
		log("Game Engine shutdown");

		if (m_pSceneManager)
		{
			delete m_pSceneManager;
			m_pSceneManager = nullptr;
		}
	}
};