#ifndef SpriteBatch_h__
#define SpriteBatch_h__
#include <glew.h>
#include "ColorExtender.h"
#include "TextureManager.h"
#include "JargShader.h"
#include "Font.h"
#include "VertexPositionTexture.h"
#include <detail\type_vec.hpp>

class Batched{
private:
	GLuint m_vertexBuffer, m_textureBuffer, m_indecesBuffer, m_colorBuffer, m_vao;
	glm::vec2* uv;
	glm::vec3* vertex;
	glm::vec4* color;
	GLuint* index;

	GLuint m_lineVertexBuffer, m_lineColorBuffer, m_lineIndecesBuffer, m_lvao;
	glm::vec3* m_lineVertex;
	glm::vec4* m_lineColor;
	GLuint* m_lineIndex;

	GLuint dvao;
	GLuint* dvbo;
	VertexPositionColor* dvertex;
	GLuint* dindex;

	float curz;
	int curn, lcurn, dcurn;
	int dc;

	const Texture* m_currentTex;
	Texture* m_blankTex;
	const Font* m_currentFont;
	const JargShader* m_texturedShader;
	const JargShader* m_coloredShader;
public:
	Batched();
	~Batched();

	Texture* atlasTexture;

	void Initialize(const JargShader* tex, const JargShader* col);

	void DrawString(glm::vec2 pos, std::string text, const Font& font);
	void DrawQuad(glm::vec2 pos, glm::vec2 size, float rotation, const Texture& tex, Rect sub);
	void DrawQuad(glm::vec2 pos, glm::vec2 size, float rotation, const Texture& tex, int atl);
	void DrawQuad(glm::vec2 pos, glm::vec2 size, float rotation, const Texture& tex);
	void DrawQuad(glm::vec2 pos, glm::vec2 size, const Texture& tex);
	void DrawLine(glm::vec2 from, glm::vec2 to, float w, glm::vec4 col);
	void DrawRectangle(glm::vec2 from, glm::vec2 to, glm::vec4 col);
	void DrawLine3d(glm::vec3 from, glm::vec3 to, glm::vec4 col);


	int RenderFinally();
	int RenderFinallyWorld();


private:
	inline void innerDraw(glm::vec2 pos, glm::vec2 size, float rotation, const Texture& tex, Rect sub);
	void lineRender();
	void Render();
	void line3dRender();

};
#endif // SpriteBatch_h__
