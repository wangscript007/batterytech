/*
 * HighScoresMenu.cpp
 *
 *  Created on: Dec 30, 2010
 *      Author: rgreen
 */

#include "ErrorMenu.h"
#include "../UIConstants.h"
#include "../GameConstants.h"
#include <batterytech/audio/AudioManager.h>
#include <batterytech/VibrationManager.h>
#include <batterytech/util/PropertiesIO.h>
#include <batterytech/platform/platformgeneral.h>
#include <string.h>
#include "../level/LevelIO.h"
#include "../Game.h"

#define ERROR_BG "ui/error_bg.jpg"
#define DEFAULT_WIDTH 700

ErrorMenu::ErrorMenu(GameContext *context) : Menu(ERROR_MENU_NAME) {
	this->context = context;
	S32 panelBgId = context->menuRenderer->addTextureAsset(ERROR_BG);
	mainLayout = new LinearLayout(LinearLayout::VERTICAL);
	S32 buttonBgId = context->menuRenderer->addTextureAsset(UI_BUTTON_1);
	S32 buttonPressedBgId = context->menuRenderer->addTextureAsset(UI_BUTTON_1_PRESSED);
	okButton = new Button("Ok");
	okButton->userId = 1;
	okButton->setLayoutParameters(new LayoutParameters(LayoutParameters::HORIZONTAL_CENTER, LayoutParameters::TOP));
	okButton->setSize(120, 60);
	okButton->setMargins(5);
	okButton->setBackgroundMenuResource(buttonBgId);
	okButton->setPressedBackgroundMenuResource(buttonPressedBgId);
	okButton->setClickDownSoundAsset(UI_CLICK_DOWN_ASSETNAME);
	restartButton = new Button("Restart");
	restartButton->userId = 2;
	restartButton->setLayoutParameters(new LayoutParameters(LayoutParameters::HORIZONTAL_CENTER, LayoutParameters::TOP));
	restartButton->setSize(120, 60);
	restartButton->setMargins(5);
	restartButton->setBackgroundMenuResource(buttonBgId);
	restartButton->setPressedBackgroundMenuResource(buttonPressedBgId);
	restartButton->setClickDownSoundAsset(UI_CLICK_DOWN_ASSETNAME);
	titleLabel = new Label("Title");
	titleLabel->setHeight(60);
	titleLabel->setMargins(10);
	titleLabel->setWidth(FILL);
	titleLabel->setLayoutParameters(new LayoutParameters(LayoutParameters::HORIZONTAL_CENTER, LayoutParameters::TOP));
	titleLabel->setTextAlignment(UIComponent::HORIZONTAL_CENTER, UIComponent::TOP);
	errorMessage = new Label("ErrorMessage");
	errorMessage->setHeight(WRAP);
	errorMessage->setWidth(FILL);
	errorMessage->setPadding(10);
	errorMessage->setLayoutParameters(new LayoutParameters(LayoutParameters::HORIZONTAL_CENTER, LayoutParameters::TOP));
	mainLayout->setHeight(250);
	mainLayout->setWidth(DEFAULT_WIDTH);
	mainLayout->setBackgroundMenuResource(panelBgId);
	mainLayout->setLayoutParameters(new LayoutParameters(LayoutParameters::HORIZONTAL_CENTER, LayoutParameters::VERTICAL_CENTER));
	mainLayout->addComponent(titleLabel);
	mainLayout->addComponent(errorMessage);
	mainLayout->addComponent(okButton);
	mainLayout->addComponent(restartButton);
	setRootComponent(mainLayout);
}

ErrorMenu::~ErrorMenu() {
	delete mainLayout;
	mainLayout = NULL;
	delete titleLabel;
	titleLabel = NULL;
	delete errorMessage;
	errorMessage = NULL;
	delete okButton;
	okButton = NULL;
	delete restartButton;
	restartButton = NULL;
}

void ErrorMenu::onClickUp(UIComponent *component) {
	if (component == okButton) {
		context->game->clearError();
		context->uiManager->popMenu();
	} else if (component == restartButton) {
		context->game->clearError();
		context->game->reset();
		context->uiManager->popMenu();
	}
}

void ErrorMenu::onPreShow() {
}

void ErrorMenu::setData(void *data) {
	if (data) {
		ErrorMessage *em = (ErrorMessage*)data;
		titleLabel->setText(em->title);
		errorMessage->setText(em->message);
		mainLayout->components->remove(this->restartButton);
		if(em->showRestart) {
			mainLayout->addComponent(restartButton);
		} 
		if (em->width != 0) {
			mainLayout->setWidth(em->width);
		} else {
			mainLayout->setWidth(DEFAULT_WIDTH);
		}
		delete em;
	}
}

void ErrorMenu::onSpecialKey(SpecialKey sKey) {
}