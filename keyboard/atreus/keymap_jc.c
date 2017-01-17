#include "keymap_common.h"

/*
This layout was created by Jean-Christophe Petkovich, and inspired by the layout
created by Jeremy Cowgar (@jcowgar).

The 5 layers can be viewed graphically:

1. Letters - http://www.keyboard-layout-editor.com/#/gists/cbed8979bba2df4419c738903a623546
2. Symbols - http://www.keyboard-layout-editor.com/#/gists/8956a18b508a78e93b9c38ec3fcccaa5
3. Navigation - http://www.keyboard-layout-editor.com/#/gists/6ed492b714a7f54eb1c5de09b87fd8c4
4. Numbers - http://www.keyboard-layout-editor.com/#/gists/399ceb5624e8388e48a3a5eacac8e973
5. Function Keys - http://www.keyboard-layout-editor.com/#/gists/7fd7dc24c7048316f3724b1893c64e89
*/

// Reduce the time to decision of a tap or hold
#define TAPPING_TERM 100

#define _______ KC_TRNS

// Each layer gets a name for readability, which is then used in the keymap matrix below.
#define ALPH  0 // Alphabet Layer
#define NUMS  1 // Number Layer
#define FKEY  2 // Function Key Layer
#define CURS  3 // Cursor Layer
#define SYMB  4 // Symbol Layer

/* Special Keys */
#define BOOT  0 // Bootloader (not to be confused with default layer)
#define OPBS  5 // Option or Backspace
#define CMDL  6 // Command or Delete
#define SFSP  7 // Left Shift or Space
#define SFET  8 // Right Shift or Enter
#define ALTB 9 // Alt or Tab
#define CTES 10 // Control or Escape
#define ZSFT 11 // Z or Shift
#define SSFT 12 // Slash or Shift

#define FN_BOOT (KC_FN0 + BOOT)
#define FN_NUMS (KC_FN0 + NUMS)
#define FN_FKEY (KC_FN0 + FKEY)
#define FN_CURS (KC_FN0 + CURS)
#define FN_SYMB (KC_FN0 + SYMB)
#define FN_OPBS (KC_FN0 + OPBS)
#define FN_CMDL (KC_FN0 + CMDL)
#define FN_SFSP (KC_FN0 + SFSP)
#define FN_SFET (KC_FN0 + SFET)
#define FN_ALTB (KC_FN0 + ALTB)
#define FN_CTES (KC_FN0 + CTES)
#define FN_ZSFT (KC_FN0 + ZSFT)
#define FN_SSFT (KC_FN0 + SSFT)


#define KEY_SAVE KC_S
#define KEY_CLSE KC_W
#define KEY_OPEN KC_O
#define MY_SCLN  KC_SCLN

/* key macros */
#define KM_SAVE ACTION_MODS_KEY(MOD_LGUI, KEY_SAVE)
#define KM_CLSE ACTION_MODS_KEY(MOD_LGUI, KEY_CLSE)
#define KM_OPEN ACTION_MODS_KEY(MOD_LGUI, KEY_OPEN) // Colemak to Qwerty in software playing games
#define KM_COPY ACTION_MODS_KEY(MOD_LGUI, KC_C)
#define KM_CUT  ACTION_MODS_KEY(MOD_LGUI, KC_X)
#define KM_PAST ACTION_MODS_KEY(MOD_LGUI, KC_V)
#define KM_UNDO ACTION_MODS_KEY(MOD_LGUI, KC_Z)
#define KM_REDO ACTION_MODS_KEY(MOD_LGUI | MOD_LSFT, KC_Z)
#define KM_DLWD ACTION_MODS_KEY(MOD_LCTL, KC_BSPC)
#define KM_LFWD ACTION_MODS_KEY(MOD_LCTL, KC_LEFT)
#define KM_RIWD ACTION_MODS_KEY(MOD_LCTL, KC_RGHT)
#define KM_DSPC ACTION_MODS_KEY(MOD_LALT, KC_BSLS) // delete whitespace

// Helpers for my symbol layer
#define KC_EXLM ACTION_MODS_KEY(MOD_LSFT, KC_1)
#define KC_AT   ACTION_MODS_KEY(MOD_LSFT, KC_2)
#define KC_HASH ACTION_MODS_KEY(MOD_LSFT, KC_3)
#define KC_DLR  ACTION_MODS_KEY(MOD_LSFT, KC_4)
#define KC_PERC ACTION_MODS_KEY(MOD_LSFT, KC_5)
#define KC_CIRC ACTION_MODS_KEY(MOD_LSFT, KC_6)
#define KC_AMPR ACTION_MODS_KEY(MOD_LSFT, KC_7)
#define KC_ASTR ACTION_MODS_KEY(MOD_LSFT, KC_8)
#define KC_LPRN ACTION_MODS_KEY(MOD_LSFT, KC_9)
#define KC_RPRN ACTION_MODS_KEY(MOD_LSFT, KC_0)
#define KC_UNDS ACTION_MODS_KEY(MOD_LSFT, KC_MINUS)
#define KC_PLUS ACTION_MODS_KEY(MOD_LSFT, KC_EQL)
#define MY_COLN ACTION_MODS_KEY(MOD_LSFT, MY_SCLN)
#define KC_QUES ACTION_MODS_KEY(MOD_LSFT, KC_SLSH)
#define KC_TILD ACTION_MODS_KEY(MOD_LSFT, KC_GRV)
#define KC_PIPE ACTION_MODS_KEY(MOD_LSFT, KC_BSLS)
#define KC_LCBR ACTION_MODS_KEY(MOD_LSFT, KC_LBRC)
#define KC_RCBR ACTION_MODS_KEY(MOD_LSFT, KC_RBRC)
#define KC_DQT  ACTION_MODS_KEY(MOD_LSFT, KC_QUOT)
#define KC_LABK ACTION_MODS_KEY(MOD_LSFT, KC_COMM)
#define KC_RABK ACTION_MODS_KEY(MOD_LSFT, KC_DOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[ALPH] = {
  {KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    _______, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN},
  {KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    _______, KC_H,    KC_N,    KC_E,    KC_I,    KC_O},
  {FN_ZSFT, FN_NUMS, FN_FKEY, KC_V,    KC_B,    FN_CMDL, KC_K,    KC_M,    FN_CURS, FN_SYMB, FN_SSFT},
  {KC_ESC,  KC_LCBR, KC_RCBR, FN_ALTB, KC_SPC,  KC_ENT,  KC_BSPC, FN_CTES, KC_MINS, KC_QUOT, KC_ENT}
},
[NUMS] = {
  {_______, _______, _______, KC_ASTR, KC_SLSH, _______, _______, KC_7,    KC_8,    KC_9,    KC_SLSH},
  {_______, _______, KC_EQL,  KC_PLUS, KC_MINS, _______, KC_LPRN, KC_4,    KC_5,    KC_6,    KC_ASTR},
  {_______, _______, KC_DOT,  KC_COMM, KC_SCLN, _______, KC_RPRN, KC_1,    KC_2,    KC_3,    KC_MINS},
  {_______, _______, _______, _______, _______, _______, _______, KC_0,    KC_DOT,  KC_EQL,  KC_PLUS}
},
[FKEY] = {
  {_______, _______, _______, _______, _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_F4,   KC_F5,   KC_F6,   _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KM_DSPC},
  {_______, _______, _______, _______, _______, _______, _______, KC_F10,  KC_F11,  KC_F12,  _______}
},
[CURS] = {
  {KM_DLWD, KM_LFWD, KC_UP,   KM_RIWD, KC_PGUP, _______, _______, KM_SAVE, _______, KM_OPEN, _______},
  {_______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, KM_UNDO, KC_LALT, _______, KC_LGUI, _______},
  {_______, KC_VOLD, KC_MUTE, KC_VOLU, KC_MPLY, _______, KM_REDO, KM_CLSE, _______, _______, _______},
  {_______, KC_INS,  FN_BOOT, _______, KC_TAB,  _______, KM_PAST, _______, _______, _______, _______}
},
[SYMB] = {
  {KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, KC_CIRC, KC_AMPR, KC_ASTR, _______, _______},
  {KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_PIPE, _______, KC_COMM, _______, _______, _______, _______},
  {_______, KC_LPRN, KC_RPRN, KC_GRV,  KC_TILD, _______, _______, KC_LABK, KC_RABK, _______, KC_BSLS},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}};

const uint16_t PROGMEM fn_actions[] = {
	[BOOT] = ACTION_FUNCTION(BOOTLOADER),
	[NUMS] = ACTION_LAYER_TAP_KEY(NUMS, KC_X),
	[FKEY] = ACTION_LAYER_TAP_KEY(FKEY, KC_C),
	[CURS] = ACTION_LAYER_TAP_KEY(CURS, KC_COMM),
	[SYMB] = ACTION_LAYER_TAP_KEY(SYMB, KC_DOT),
	[OPBS] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_BSPC),
	[CMDL] = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_DEL),
	[SFSP] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_SPC),
	[SFET] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_ENT),
	[ALTB] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_TAB),
	[CTES] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ESC),
	[ZSFT] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_Z),
	[SSFT] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_SLSH)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
