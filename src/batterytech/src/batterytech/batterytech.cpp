//============================================================================
// Name        : batterytech.cpp
// Author      : Robert Green
// Version     : 1.0
// Copyright   : Copyright 2010 Battery Powered Games, LLC
// Description : main hooks for battery tech mobile game platform
//============================================================================

#include <stdio.h>
#include "batterytech.h"
#include "Logger.h"
#include "sound/SoundManager.h"
#include "platform/platformgl.h"
#include "platform/platformgeneral.h"
#include "game/World.h"
#include "render/WorldRenderer.h"
#include "ui/Button.h"
#include "ui/LinearLayout.h"
#include "ui/LinearLayoutParameters.h"
#include "render/MenuRenderer.h"
#include "Context.h"

#define REFERENCE_WIDTH 800
#define REFERENCE_HEIGHT 480

static Context *context;
static GraphicsConfiguration *gConfig;

void loadSound();
void createMenu(S32 width, S32 height);

void btInit(GraphicsConfiguration *graphicsConfig, S32 width, S32 height) {
	log("BatteryTech 1.0 Initializing...");
	gConfig = graphicsConfig;
	// platform will have determined gpu capabilities and set into gConfig
	btSetScreenSize(width, height);
	context = new Context(gConfig);
	loadSound();
	createMenu(width, height);
	log("Ready");
}

void btSetScreenSize(S32 width, S32 height) {
	gConfig->viewportWidth = width;
	gConfig->viewportHeight = height;
	gConfig->scaleX2d = width / (F32)REFERENCE_WIDTH;
	gConfig->scaleY2d = height / (F32)REFERENCE_HEIGHT;
	if (width > height) {
		gConfig->uiScale = gConfig->scaleY2d;
	} else {
		gConfig->uiScale = gConfig->scaleX2d;
	}
}

void loadSound() {
	log("Loading sound");
	U16 sndId = context->soundManager->loadSound("level_1_song.ogg");
	//U16 sndId2 = soundManager->loadSound("battery_powered_splash.ogg");
	//U16 sndId3 = soundManager->loadSound("score_session_end_big.ogg");
	//soundManager->playSound(sndId, -1, 1.0f);
	//soundManager->playSound(sndId2, -1, 1.0f);
	//soundManager->playSound(sndId3, -1, 1.0f);
}

void createMenu(S32 width, S32 height) {
	S32 buttonBgId = context->menuRenderer->addTextureAsset("text_bg_tex.jpg");
	LinearLayout *buttonLayout = new LinearLayout(LinearLayout::VERTICAL);
	Button *button1 = new Button();
	button1->setLayoutParameters(new LinearLayoutParameters(LinearLayoutParameters::LEFT, LinearLayoutParameters::TOP));
	button1->setSize(120, 40);
	button1->setBackgroundMenuResource(buttonBgId);
	Button *button2 = new Button();
	button2->setLayoutParameters(new LinearLayoutParameters(LinearLayoutParameters::LEFT, LinearLayoutParameters::TOP));
	button2->setSize(120, 40);
	button2->setBackgroundMenuResource(buttonBgId);
	buttonLayout->addComponent(button1);
	buttonLayout->addComponent(button2);
	Menu *mainMenu = new Menu(buttonLayout);
	S32 mainMenuId = context->uiManager->addMenu(mainMenu);
	context->uiManager->showMenu(mainMenuId);
}

void btUpdate(F32 delta) {
	// todo - just tick the game engine with the delta
	context->world->tickDelta = delta;
	context->uiManager->updateMenus(delta);
	//char buf[32];
	//sprintf(buf, "update %3.5g theta is %3.5g", delta, theta);
	//log(buf);
}


void btDraw() {
	context->worldRenderer->render(context->world);
	context->menuRenderer->render(context->uiManager);
}

void btSuspend() {
}

void btResume() {
}

void btSetPointerState(S32 pointerId, BOOL32 down, S32 x, S32 y) {
	// TODO - move this all to app context - entire app needs it
	//char buf[32];
	World *world = context->world;
	if (down) {
		if (pointerId == 0) {
			world->down1 = TRUE;
			world->x1 = x;
			world->y1 = y;
		} else if (pointerId == 1) {
			world->down2 = TRUE;
			world->x2 = x;
			world->y2 = y;
		}
		//sprintf(buf, "pointer %d down at %d %d", pointerId, x, y);
	} else {
		if (pointerId == 0) {
			world->down1 = FALSE;
		} else if (pointerId == 1) {
			world->down2 = FALSE;
		}
		//sprintf(buf, "pointer %d up", pointerId);
	}
	//log(buf);
}

void btRelease() {
	gConfig = NULL;
	delete context;
	context = NULL;
}
