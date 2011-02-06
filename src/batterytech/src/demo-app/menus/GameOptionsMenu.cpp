/*
 * MainMenu.cpp
 *
 *  Created on: Oct 11, 2010
 *      Author: rgreen
 */

#include "GameOptionsMenu.h"
#include <batterytech/primitives.h>
#include <batterytech/ui/SlideAnimator.h>
#include "../UIConstants.h"
#include "SettingsMenu.h"

GameOptionsMenu::GameOptionsMenu(Context *context) : Menu(GAME_OPTIONS_MENU_NAME) {
	this->context = context;
	S32 buttonBgId = context->menuRenderer->addTextureAsset(UI_BUTTON_1);
	S32 buttonPressedBgId = context->menuRenderer->addTextureAsset(UI_BUTTON_1_PRESSED);
	S32 panelBgId = context->menuRenderer->addTextureAsset(UI_PANEL_2);
	buttonLayout = new LinearLayout(LinearLayout::HORIZONTAL);
	settingsButton = new Button("Settings");
	settingsButton->setLayoutParameters(new LayoutParameters(LayoutParameters::LEFT, LayoutParameters::BOTTOM));
	settingsButton->setSize(FILL, 60);
	settingsButton->setMargins(5);
	settingsButton->setBackgroundMenuResource(buttonBgId);
	settingsButton->setPressedBackgroundMenuResource(buttonPressedBgId);
	quitButton = new Button("Quit");
	quitButton->setLayoutParameters(new LayoutParameters(LayoutParameters::LEFT, LayoutParameters::BOTTOM));
	quitButton->setSize(FILL, 60);
	quitButton->setMargins(5);
	quitButton->setBackgroundMenuResource(buttonBgId);
	quitButton->setPressedBackgroundMenuResource(buttonPressedBgId);
	cancelButton = new Button("Cancel");
	cancelButton->setLayoutParameters(new LayoutParameters(LayoutParameters::LEFT, LayoutParameters::BOTTOM));
	cancelButton->setSize(FILL, 60);
	cancelButton->setMargins(5);
	cancelButton->setBackgroundMenuResource(buttonBgId);
	cancelButton->setPressedBackgroundMenuResource(buttonPressedBgId);
	buttonLayout->addComponent(settingsButton);
	buttonLayout->addComponent(quitButton);
	buttonLayout->addComponent(cancelButton);
	buttonLayout->setHeight(WRAP);
	buttonLayout->setWidth(FILL);
	buttonLayout->setBackgroundMenuResource(panelBgId);
	buttonLayout->setLayoutParameters(new LayoutParameters(LayoutParameters::HORIZONTAL_CENTER, LayoutParameters::BOTTOM));
	buttonLayout->setEnterAnimator(new SlideAnimator(SlideAnimator::BOTTOM, SlideAnimator::SLIDE_IN, 0.2f));
	buttonLayout->setExitAnimator(new SlideAnimator(SlideAnimator::BOTTOM, SlideAnimator::SLIDE_OUT, 0.2f));
	setRootComponent(buttonLayout);
}

void GameOptionsMenu::onClickDown(UIComponent *component){
}

void GameOptionsMenu::onClickUp(UIComponent *component){
	this->context->uiManager->popMenu();
	if (component == quitButton) {
		this->context->world->gameState = GAMESTATE_READY;
		//this->context->uiManager->showMenu(LEVELS_MENU_NAME);
	} else if (component == settingsButton) {
		this->context->uiManager->showMenu(SETTINGS_MENU_NAME);
	}
}

GameOptionsMenu::~GameOptionsMenu() {
	this->context = NULL;
	delete quitButton;
	delete cancelButton;
	delete buttonLayout;
}
