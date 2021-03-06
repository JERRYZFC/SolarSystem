#pragma once
#include "Renderable.h"

namespace OpenGL {

	class VertexBufferRenderable :
		public Renderable
	{
	protected:
		VertexBufferObject vbo;
	public:
		VertexBufferRenderable();
		virtual ~VertexBufferRenderable();

		virtual void Draw() = 0;

		virtual void Bind() override;
		virtual void UnBind() override;

		void setData(void *data, unsigned int len, GLenum type = GL_STATIC_DRAW);
	};


}
