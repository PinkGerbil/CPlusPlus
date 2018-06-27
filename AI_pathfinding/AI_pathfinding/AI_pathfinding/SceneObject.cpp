#include "SceneObject.h"
#include <assert.h>


SceneObject::SceneObject()
{

}

SceneObject::~SceneObject()
{
	//if the parent doesn't exist it will remove the child
	if (m_parent != nullptr) {
		m_parent->removeChild(this);
	}
	for (auto child : m_children) {
		child->m_parent = nullptr;
	}
}

void SceneObject::addChild(SceneObject * child)
{
	//add child to the the parent
	assert(child->m_parent == nullptr);
	child->m_parent = this;
	m_children.push_back(child);
}

void SceneObject::removeChild(SceneObject * child)
{
	//remove a child
	auto iter = std::find(m_children.begin(), m_children.end(), child);

	if (iter != m_children.end()) {
		m_children.erase(iter);
		child->m_parent = nullptr;
	}
}

void SceneObject::update(float deltaTime)
{
	//update function
	onUpdate(deltaTime);

	for (auto child : m_children) {
		child->update(deltaTime);
	}
}

void SceneObject::draw(aie::Renderer2D * renderer)
{
	//draw function
	onDraw(renderer);

	for (auto child : m_children) {
		child->draw(renderer);
	}
}

void SceneObject::updateTransform()
{
	//update transform function
	if (m_parent != nullptr) {
		m_globalTransform = m_parent->m_globalTransform * m_localTransform;
	}
	else {
		m_globalTransform = m_localTransform;
	}
	for (auto child : m_children) {
		child->updateTransform();
	}
}

void SceneObject::setPosition(float x, float y)
{
	//sets position
	m_localTransform[2] = { x, y, 1 };
	updateTransform();
}

void SceneObject::setRotate(float radians)
{
	//sets the local transform
	m_localTransform.setRotateZ(radians);
	updateTransform();
}

void SceneObject::setScale(float width, float height)
{
	//sets the scale
	m_localTransform.setScaled(width, height, 1);
	updateTransform();
}

void SceneObject::translate(float x, float y)
{
	//translate function
	m_localTransform.translate(x, y, 1);
	updateTransform();
}

void SceneObject::rotate(float radians)
{
	//rotate function
	m_localTransform.rotateZ(radians);
	updateTransform();
}

void SceneObject::scale(float width, float height)
{
	//scale function
	m_localTransform.setScaled(width, height, 1);
	updateTransform();
}

const Matrix3& SceneObject::getLocalTransform()const
{
	// TODO: insert return statement here
	return m_localTransform;
}

const Matrix3 & SceneObject::getGlobalTransform()const
{
	// TODO: insert return statement here
	return m_globalTransform;
}
