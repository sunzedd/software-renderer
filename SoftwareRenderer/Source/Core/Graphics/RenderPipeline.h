#pragma once
#include <vector>
#include <string>

#include "../Exceptions.h"

#include "IShaderProgram.h"
#include "FrameBuffer.h"
#include "Rasterizer.h"
#include "Triangle.h"
#include "Common.h"

namespace Core {

class RenderPipeline final
{
	struct _Properties
	{
		bool backFaceCullingFlag;
		bool wireframeFlag;
	};

	struct _Viewport
	{
		int topLeftX;
		int topLeftY;
		int width;
		int height;
	};

public:
	RenderPipeline( FrameBuffer& frameBuf );

	void toogleBackFaceCulling(bool enable);
	void toogleWireframeRendering(bool enable);
	void setViewport(int topLeftX, int topLeftY, int width, int height);

	void bindShaderProgram(std::shared_ptr<IShaderProgram> shader);

	// Renderer entry point
	void beginFrame();
	
	void drawIndexedTriangles(const std::vector<Vertex>& vertexBuf,
		const std::vector<unsigned short>& indexBuf);
	
	void drawLines(const std::vector<LineV3>& lineBuf, const Vec4& color);

private:
	bool backFaceTest(Triangle<VSO>& polygon) const;
	void clip(Triangle<VSO>& polygon);
	void renderClippedPolygon(Triangle<VSO>& polygon);
	void perspectiveDivide(VSO& vso) const;
	void viewport(VSO& vso) const;

private:
	Rasterizer m_rasterizer;
	std::shared_ptr<IShaderProgram> m_shader;

	_Properties m_properties;
	_Viewport m_viewport;
};

} // namespace Core