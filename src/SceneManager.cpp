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
#include "../include/ISceneManager.h"

class SceneManager : public ISceneManager, public IBase
{
private:
	vector<Scene*> m_SceneVector;

public:
	SceneManager() {
		log("SceneManager: constructor");
	}

	~SceneManager() {
		log("SceneManager: destructor");

		if (m_SceneVector.size() > 0)
		{
			for (auto it : m_SceneVector) {
				delete it;
				it = nullptr;
			}
			m_SceneVector.clear();
		}
	}

	void addScene(Scene* p_scene)
	{
		log("SceneManager: add scene");
		m_SceneVector.push_back(p_scene);
	}

	void deleteScene(Scene* p_scene)
	{
		log("SceneManager: delete scene");
		for (auto it : m_SceneVector) {
		}
	}

	void update()
	{
		log("SceneManager: update scene");
		for (auto it : m_SceneVector) {
			it->update();
		}
	}
};