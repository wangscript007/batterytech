/*
 * MenuRenderer.h
 *
 *  Created on: Oct 7, 2010
 *      Author: rgreen
 */

#ifndef MENURENDERER_H_
#define MENURENDERER_H_

#include "GraphicsConfiguration.h"
#include "TextRasterRenderer.h"
#include "../primitives.h"
#include "../platform/platformgl.h"
#include "../ui/UIManager.h"
#include "../util/ManagedArray.h"

class MenuRenderer {
public:
	MenuRenderer(GraphicsConfiguration *gConfig);
	S32 addTextureAsset(const char *asset);
	void init(UIManager *uiManager);
	void render(UIManager *uiManager);
	void render(UIComponent *component);
	virtual ~MenuRenderer();
private:
	void loadTexture(const char *assetName);
	void drawTexturedQuad(S32 top, S32 right, S32 bottom, S32 left);
	GraphicsConfiguration *gConfig;
	ManagedArray<const char> *assetNames;
	GLuint *textureIds;
	S32 activeResourceId;
	TextRasterRenderer *textRenderer;
};

#endif /* MENURENDERER_H_ */