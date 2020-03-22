#pragma once
#include <SFML/Graphics.hpp>

#include "../Math/Mat4.h"
#include "../Math/Vec3.h"

#include "Entity.h"


#define CORE_CAMERA_VIEWFRUSTUM_FOVY  50.0f
#define CORE_CAMERA_VIEWFRUSTUM_AR    1.3333f
#define CORE_CAMERA_VIEWFRUSTUM_ZNEAR 0.0001f
#define CORE_CAMERA_VIEWFRUSTUM_ZFAR  1000.0f

namespace core
{

enum class Direction
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Camera : public Entity
{
	struct _ViewFrustum
	{
		float fovy			= CORE_CAMERA_VIEWFRUSTUM_FOVY;
		float aspectRatio   = CORE_CAMERA_VIEWFRUSTUM_AR;
		float zNear			= CORE_CAMERA_VIEWFRUSTUM_ZNEAR;
		float zFar			= CORE_CAMERA_VIEWFRUSTUM_ZFAR;
	};

	struct _Transform
	{
		Vec3 position;
		Vec3 forward;
		Vec3 up;
	};

public:
	Camera(const Vec3& position = { 0, 0, 0 });
	Camera(const Vec3& position, float fovy, float aspectRatio, float zNear, float zFar);

	virtual void update(unsigned int deltaTime) override;

	const Vec3& getPosition() const;
	void setPosition(const Vec3& position);

	const Mat4& getViewMatrix();
	const Mat4& getProjMatrix();

protected:
	_Transform m_transform;
	_ViewFrustum m_viewFrustum;

	Mat4 m_viewMatrix;
	Mat4 m_projMatrix;

	bool m_hasProjMatrixModified = true;
};

}