/*
 * Label.cpp
 *
 *  Created on: Sep 24, 2010
 *      Author: rgreen
 */

#include "TextField.h"
#include <string.h>
#include "../platform/platformgeneral.h"

TextField::~TextField() {
}

void TextField::onKeyPressed(U8 key) {
	if (key == 8) {
		deleteChar();
	} else if (key >= 32 && key < 127) {
		if (!allowNumeric && key > 47 && key < 58) {
			// ignore
		} else {
			addChar(key);
		}
	} else if (key == 13 || key == 10) {
		// enter/return/newline
		_platform_hide_keyboard();
	}
}

void TextField::addChar(U8 key) {
	if (text) {
		S32 textLength = strlen(text);
		char *oldText = text;
		text = new char[textLength + 2];
		strcpy(text, oldText);
		delete [] oldText;
		text[textLength] = key;
		text[textLength + 1] = '\0';
	} else {
		this->text = new char[2];
		text[0] = key;
		text[1] = '\0';
	}
}

void TextField::deleteChar() {
	if (text) {
		S32 textLength = strlen(text);
		if (textLength == 1) {
			delete [] text;
			text = NULL;
		} else {
			char *oldText = text;
			text = new char[textLength];
			strncpy(text, oldText, textLength - 1);
			delete [] oldText;
			text[textLength - 1] = '\0';
			logmsg(text);
		}
	}
}

void TextField::onSelected() {
	_platform_show_keyboard();
}
