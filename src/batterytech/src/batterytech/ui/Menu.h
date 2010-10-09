/*
 * Menu.h
 *
 *  Created on: Oct 8, 2010
 *      Author: rgreen
 */

#ifndef MENU_H_
#define MENU_H_

#include "UIComponent.h"

class Menu {
public:
	Menu();
	Menu(UIComponent *component) {
		this->rootComponent = component;
	}
	virtual void setRootComponent(UIComponent *component) {
		this->rootComponent = component;
	}
	virtual UIComponent* getRootComponent() {
		return rootComponent;
	}
	virtual ~Menu();
	S32 menuId;
private:
	UIComponent *rootComponent;
};

#endif /* MENU_H_ */
