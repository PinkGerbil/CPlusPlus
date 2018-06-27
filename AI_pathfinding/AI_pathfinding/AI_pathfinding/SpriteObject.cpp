#include "SpriteObject.h"


SpriteObject::SpriteObject()
{
}

SpriteObject::SpriteObject(const char * filename)
{
	//load a file
	load(filename);
}


SpriteObject::~SpriteObject()
{
	//deletes the textures of the sprite
	delete m_texture;
}


bool SpriteObject::load(const char * filename)
{
	//deletes sprite then generates a new sprite
	delete m_texture;
	m_texture = nullptr;
	m_texture = new aie::Texture(filename);
	return m_texture != nullptr;
}
