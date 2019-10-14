#ifndef ERGODOX_EZ_UNICODE_H
#define ERGODOX_EZ_UNICODE_H

int is_unicode_input_active = 0;

int activate_unicode_input(void) {
  if (!is_unicode_input_active) {
    SEND_STRING(SS_DOWN(X_LCTRL)" "SS_UP(X_LCTRL));
    is_unicode_input_active = 1;
    return 1;
  }
  return 0;
}

int deactivate_unicode_input(void) {
  if (is_unicode_input_active) {
    SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LALT)" "SS_UP(X_LCTRL)SS_UP(X_LALT));
    is_unicode_input_active = 0;
    return 1;
  }
  return 0;
}

void emit_unicode_hex(char *hex_str, int count) {
  // int had_to_activate;
  if (activate_unicode_input()) {
    _delay_ms(50);
  }
  SEND_STRING(SS_DOWN(X_LALT));
  for (int i = 0; i < count; i++) {
    send_string(hex_str);
  }
  SEND_STRING(SS_UP(X_LALT));
    _delay_ms(50);
  if(deactivate_unicode_input()) {
    _delay_ms(50);
  }
}

#endif
