/*
 * RenderItem.h
 *
 *  Created on: Jul 11, 2011
 *      Author: rgreen
 */

#ifndef RENDERITEM_H_
#define RENDERITEM_H_

#include <batterytech/primitives.h>
#include <batterytech/math/Matrix4.h>
#include <batterytech/math/Vector3.h>
#include <batterytech/math/Quaternion.h>

#define RENDERITEM_FLAG_HAS_MATRIX 1
#define RENDERITEM_FLAG_IS_OPAQUE 2
#define RENDERITEM_FLAG_NO_FOG 4
#define RENDERITEM_FLAG_USE_CAMERA_CLOSEST_POINT_LIGHTS 8
#define RENDERITEM_FLAG_NODES_CULL_FRUSTUM_TEST 16
#define RENDERITEM_FLAG_NO_DIR_LIGHT 32
#define RENDERITEM_FLAG_NO_SHADOW_GEN 64
#define RENDERITEM_FLAG_NO_SHADOW_RECV 128
#define RENDERITEM_FLAG_DRAW_FIRST 256
#define RENDERITEM_FLAG_TWO_SIDED 512
#define RENDERITEM_FLAG_MULTILINE_TEXT 1024

using namespace BatteryTech;

namespace BatteryTech { class AssimpAnimator; }

struct RenderDefaults {
	RenderDefaults() {
		dirLightEnabled = FALSE;
		fogEnabled = FALSE;
		fogNear = 2;
		fogFar = 500;
        fogColor = Vector4f(0.05f, 0.05f, 0.2f, 1.0f);
	}
	BOOL32 dirLightEnabled;
	BOOL32 fogEnabled;
	S32 fogNear;
	S32 fogFar;
    Vector4f fogColor;
};

class RenderItem {
public:
	enum RenderType { RENDERTYPE_OBJ = 1, RENDERTYPE_BB = 2, RENDERTYPE_2D = 4, RENDERTYPE_2DBG = 8, RENDERTYPE_TEXT2D = 16, RENDERTYPE_ASSIMP = 32};
	enum Alignment { ALIGN_LEFT, ALIGN_CENTER, ALIGN_RIGHT };
	RenderItem();
	virtual ~RenderItem();
	void reset();
	Vector3f getTranslation();
	RenderType renderType;
	Alignment alignment;
	char textureName[255];
	char resourceName[255];
	char attr1[255];
	char attr2[255];
	U32 flags;
	Matrix4f mat;
	Vector3f pos;
	Vector3f scale;
	Vector4f uvs;
	Quatf orientation;
	Vector4f colorFilter;
	S32 maxPointLights;
	AssimpAnimator *animator;
	Vector4i viewport;
    F32 sortValue;
};

#endif /* RENDERITEM_H_ */
