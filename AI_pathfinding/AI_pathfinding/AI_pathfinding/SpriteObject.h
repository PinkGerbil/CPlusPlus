#pragma once
#include "SceneObject.h"
#include <Renderer2D.h>
#include <Texture.h>

namespace aie {
	class Renderer2D;
	class Texture;
}

class SpriteObject : public SceneObject {
public:
	SpriteObject();
	SpriteObject(const char* filename);
	virtual ~SpriteObject();
	bool load(const char* filename);

	virtual void SpriteObject::onDraw(aie::Renderer2D* renderer) {
		renderer->drawSpriteTransformed3x3(m_texture, (float*)&m_globalTransform);
	};

protected:
	aie::Texture* m_texture = nullptr;
};

