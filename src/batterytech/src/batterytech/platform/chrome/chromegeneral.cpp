/*
 * BatteryTech
 * Copyright (c) 2010 Battery Powered Games LLC.
 *
 * This code is a component of BatteryTech and is subject to the 'BatteryTech
 * End User License Agreement'.  Among other important provisions, this
 * license prohibits the distribution of source code to anyone other than
 * authorized parties.  If you have any questions or would like an additional
 * copy of the license, please contact: support@batterypoweredgames.com
 */

//============================================================================
// Name        : chromegeneral.cpp
// Description : Chrome platform general functions
// Usage       : See platformgeneral.h for usage
//============================================================================

#ifdef CHROME

#include "../platformgeneral.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "../../audio/AudioManager.h"

using namespace BatteryTech;

void _platform_log(const char* message) {
	// we should be using cout but there's a bug where the output isn't properly redirected to console when run outside of dev env
	printf(message);
	printf("\n");
}

unsigned char* _platform_load_internal_asset(const char *filename, S32 *size) {
	return NULL;
}

void _platform_free_asset(unsigned char *ptr) {
}

S32 _platform_get_asset_length(const char *filename) {
	return 0;
}

S32 _platform_read_asset_chunk(const char *filename, S32 offset, unsigned char *buffer, S32 bufferLength, BOOL32 *eof) {
	return 0;
}

void _platform_init_sound(AudioManager *audioManager) {
}

void _platform_stop_sound() {
}

void _platform_get_external_storage_dir_name(char* buf, S32 buflen) {
}

void _platform_get_application_storage_dir_name(char* buf, S32 buflen) {
}

const char* _platform_get_path_separator() {
	return "/";
}

BOOL32 _platform_path_exists(const char* path) {
	return FALSE;
}

BOOL32 _platform_path_can_read(const char* path) {
	return FALSE;
}

BOOL32 _platform_path_can_write(const char* path) {
	return FALSE;
}

BOOL32 _platform_path_create(const char* path) {
	return FALSE;
}

void _platform_play_vibration_effect(S32 effectId, F32 intensity) {
}

void _platform_start_vibration_effect(S32 effectId, F32 intensity) {
}

void _platform_stop_vibration_effect(S32 effectId) {
}

void _platform_stop_all_vibration_effects() {
}

BOOL32 _platform_implements_soundpool() {
	return FALSE;
}


void _platform_init_audiomanagement(S32 streams){}
void _platform_release_audiomanagement(){}
void _platform_load_sound(const char* asset){}
S32 _platform_play_sound(const char* asset, F32 leftVol, F32 rightVol, S32 loops, F32 rate){ return -1; }
void _platform_stop_sound(S32 streamId){}
void _platform_stop_sound(const char* asset){}
void _platform_stop_all_sounds(){}
void _platform_unload_sound(const char *asset){}
void _platform_sound_set_loops(S32 streamId, S32 loops){}
void _platform_sound_set_volume(S32 streamId, F32 leftVol, F32 rightVol){}
void _platform_sound_set_rate(S32 streamId, F32 rate){}
S32 _platform_play_streaming_sound(const char *assetName, S16 loops, F32 leftVol, F32 rightVol, F32 rate){ return -1; }
void _platform_stop_streaming_sound(const char *assetName){}
void _platform_show_keyboard(){}
void _platform_hide_keyboard(){}

void _platform_init_network() {
}

void _platform_release_network() {
}

void _platform_make_non_blocking(SOCKET socket) {
}

S32 _platform_get_socket_last_error() {
	return 0;
}

void _platform_exit() {
}

void _platform_show_ad() {
}

void _platform_hide_ad() {
}

void _platform_hook(const char *hook, char *result, S32 resultLen) {
}

BOOL32 _platform_has_special_key(BatteryTech::SpecialKey sKey) {
	return FALSE;
}

char** _platform_get_ifaddrs(int *count) {
	return NULL;
}

void _platform_free_ifaddrs(char** ifaddrs, int count) {
}

U64 _platform_get_time_nanos() {
	return 0;
}



#endif /* CHROME */
