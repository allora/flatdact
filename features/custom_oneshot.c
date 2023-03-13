/* Copyright 2021 @vvhg1
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * This is intended as a cheap workaround to save space by defining NO_ACTION_TAPPING or NO_ACTION_ONESHOT and still use some oneshot functionality
 * more modifiers can be added easily, but I want to keep it as lightweight as I can for my use.
 */
#include "custom_oneshot.h"
#include "keycodes.h"


__attribute__((weak)) bool process_custom_one_shot(uint16_t keycode, const keyrecord_t *record)
{
    switch (keycode)
    {
    case MR_sft:
        if (record->event.pressed)
        {
            if (!rshift_on)
            {
                rshift_on = true;
                register_code(KC_RSFT);
                one_shot_timer = timer_read();
            }
            else
            {
                rshift_on = false;
                is_oneshot_rshift = false;
            }
        }
        else
        {
            if ((rshift_on) && (!lshift_on) && (timer_elapsed(one_shot_timer) < 500))
            {
                is_oneshot_rshift = true;
            }
            else
            {
                if (timer_elapsed(one_shot_timer) >= 500)
                {
                    is_oneshot_rshift = false;
                }
                if (lshift_on)
                {
                    is_oneshot_lshift = false;
                    lshift_on = false;
                    unregister_code(KC_LSFT);
                }
                is_oneshot_rshift = false;
                rshift_on = false;
                unregister_code(KC_RSFT);
            }
        }
        return true;
    case ML_sft:
        if (record->event.pressed)
        {
            if (!lshift_on)
            {
                lshift_on = true;
                register_code(KC_LSFT);
                one_shot_timer = timer_read();
            }
            else
            {
                lshift_on = false;
                is_oneshot_lshift = false;
            }
        }
        else
        {
            if ((!rshift_on) && (lshift_on) && (timer_elapsed(one_shot_timer) < 500))
            {
                is_oneshot_lshift = true;
            }
            else
            {
                if (timer_elapsed(one_shot_timer) >= 500)
                {
                    is_oneshot_lshift = false;
                }
                if (rshift_on)
                {
                    is_oneshot_rshift = false;
                    rshift_on = false;
                    unregister_code(KC_RSFT);
                }
                is_oneshot_lshift = false;
                lshift_on = false;
                unregister_code(KC_LSFT);
            }
        }
        return true;
    case ML_alt:
        if (record->event.pressed)
        {
            if (!lalt_on)
            {
                lalt_on = true;
                register_code(KC_LALT);
                one_shot_timer = timer_read();
            }
            else
            {
                lalt_on = false;
                is_oneshot_lalt = false;
            }
        }
        else
        {
            if (lalt_on && (timer_elapsed(one_shot_timer) < 500))
            {
                is_oneshot_lalt = true;
            }
            else
            {
                is_oneshot_lalt = false;
                lalt_on = false;
                unregister_code(KC_LALT);
            }
        }
        return true;
    case ML_ctl:
        if (record->event.pressed)
        {
            if (!lctl_on)
            {
                lctl_on = true;
                register_code(KC_LCTL);
                one_shot_timer = timer_read();
            }
            else
            {
                lctl_on = false;
                is_oneshot_lctl = false;
            }
        }
        else
        {
            if (lctl_on && (timer_elapsed(one_shot_timer) < 500))
            {
                is_oneshot_lctl = true;
            }
            else
            {
                is_oneshot_lctl = false;
                lctl_on = false;
                unregister_code(KC_LCTL);
            }
        }
        return true;
    case MR_gui:
        if (record->event.pressed)
        {
            if (!rgui_on)
            {
                rgui_on = true;
                register_code(KC_RGUI);
                one_shot_timer = timer_read();
            }
            else
            {
                rgui_on = false;
                is_oneshot_rgui = false;
            }
        }
        else
        {
            if (rgui_on && (timer_elapsed(one_shot_timer) < 500))
            {
                is_oneshot_rgui = true;
            }
            else
            {
                is_oneshot_rgui = false;
                rgui_on = false;
                unregister_code(KC_RGUI);
            }
        }
        return true;
    default:
        return true;
    }
}

void release_custom_one_shot(uint16_t keycode, const keyrecord_t *record)
{
    if (record->event.pressed)
    {
        switch (keycode)
        {
        case ML_alt:
        case ML_ctl:
        case ML_sft:
        case MR_sft:
        case MR_gui:
            break;

        default:
            if (is_oneshot_rgui)
            {
                unregister_code(KC_RGUI);
                is_oneshot_rgui = false;
            }
            if (is_oneshot_rshift)
            {
                unregister_code(KC_RSFT);
                is_oneshot_rshift = false;
            }
            if (rshift_on)
            {
                rshift_on = false;
            }

            if (is_oneshot_lshift)
            {
                unregister_code(KC_LSFT);
                is_oneshot_lshift = false;
            }
            if (lshift_on)
            {
                lshift_on = false;
            }
            if (is_oneshot_lalt)
            {
                unregister_code(KC_LALT);
                is_oneshot_lalt = false;
            }
            if (lalt_on)
            {
                lalt_on = false;
            }
            if (is_oneshot_lctl)
            {
                unregister_code(KC_LCTL);
                is_oneshot_lctl = false;
            }
            if (lctl_on)
            {
                lctl_on = false;
            }
        }
    }
}
