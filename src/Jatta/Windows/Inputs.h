/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../External/Defines.h"

namespace Jatta
{
    namespace MouseButtons
    {
        const unsigned char left = 0,
                middle = 1,
                right = 2;
    }

    // TODO: Linux and Mac keys

    namespace Keys
    {
        #ifdef WINDOWS
        const unsigned char back = 0x08,
                tab = 0x09,
                clear = 0x0c,
                enter = 0x0d,
                shift = 0x10,
                control = 0x11, // = ctrl = key,
                menu = 0x12, // = alt = key,
                pause = 0x13, // = pause = key,
                capital = 0x14, // = caps = lock = key,
                kana = 0x15, // = input = method = editor = (ime) = kana = mode,
                hangul = 0x15, // = ime = hangul = mode,
                junja = 0x17, // = ime = junja = mode,
                final = 0x18, // = ime = final = mode,
                hanja = 0x19, // = ime = hanja = mode = ,
                kanji = 0x19, // = ime = kanji = mode,
                escape = 0x1b, // = esc = key,
                convert = 0x1c, // = ime = convert,
                nonconvert = 0x1d, // = ime = nonconvert,
                accept = 0x1e, // = ime = accept,
                modechange = 0x1f, // = ime = mode = change = request,
                space = 0x20, // = space = key,
                prior = 0x21, // = page = up = key,
                next = 0x22, // = page = down = key,
                end = 0x23, // = end = key,
                home = 0x24, // = home = key,
                left = 0x25, // = left = arrow = key,
                up = 0x26, // = up = arrow = key,
                right = 0x27, // = right = arrow = key,
                down = 0x28, // = down = arrow = key,
                select = 0x29, // = select = key,
                print = 0x2a, // = print = key,
                execute = 0x2b, // = execute = key,
                snapshot = 0x2c, // = print = screen = key,
                insert = 0x2d, // = ins = key,
                del = 0x2e, // = del = key,
                help = 0x2f, // = help = key,
                zero = 0x30,
                one = 0x31,
                two = 0x32,
                three = 0x33,
                four = 0x34,
                five = 0x35,
                six = 0x36,
                seven = 0x37,
                eight = 0x38,
                nine = 0x39,
                a = 0x41,
                b = 0x42,
                c = 0x43,
                d = 0x44,
                e = 0x45,
                f = 0x46,
                g = 0x47,
                h = 0x48,
                i = 0x49,
                j = 0x4a,
                k = 0x4b,
                l = 0x4c,
                m = 0x4d,
                n = 0x4e,
                o = 0x4f,
                p = 0x50,
                q = 0x51,
                r = 0x52,
                s = 0x53,
                t = 0x54,
                u = 0x55,
                v = 0x56,
                w = 0x57,
                x = 0x58,
                y = 0x59,
                z = 0x5a,
                lwin = 0x5b, // = left = windows = key = (microsoft = natural = keyboard),
                rwin = 0x5c, // = right = windows = key = (natural = keyboard),
                apps = 0x5d, // = applications = key = (natural = keyboard),
                sleep = 0x5f, // = computer = sleep = key,
                // = num = pad = keys,
                numpad0 = 0x60,
                numpad1 = 0x61,
                numpad2 = 0x62,
                numpad3 = 0x63,
                numpad4 = 0x64,
                numpad5 = 0x65,
                numpad6 = 0x66,
                numpad7 = 0x67,
                numpad8 = 0x68,
                numpad9 = 0x69,
                multiply = 0x6a,
                add = 0x6b,
                separator = 0x6c,
                subtract = 0x6d,
                decimal = 0x6e,
                divide = 0x6f,
                f1 = 0x70,
                f2 = 0x71,
                f3 = 0x72,
                f4 = 0x73,
                f5 = 0x74,
                f6 = 0x75,
                f7 = 0x76,
                f8 = 0x77,
                f9 = 0x78,
                f10 = 0x79,
                f11 = 0x7a,
                f12 = 0x7b,
                f13 = 0x7c,
                f14 = 0x7d,
                f15 = 0x7e,
                f16 = 0x7f,
                f17 = 0x80,
                f18 = 0x81,
                f19 = 0x82,
                f20 = 0x83,
                f21 = 0x84,
                f22 = 0x85,
                f23 = 0x86,
                f24 = 0x87,
                numlock = 0x90,
                scroll = 0x91,
                lshift = 0xa0,
                rshift = 0xa1,
                lcontrol = 0xa2,
                rcontrol = 0xa3,
                lmenu = 0xa4,
                rmenu = 0xa5,
                browser_back = 0xa6, // = windows = 2000/xp: = browser = back = key,
                browser_forward = 0xa7, // = windows = 2000/xp: = browser = forward = key,
                browser_refresh = 0xa8, // = windows = 2000/xp: = browser = refresh = key,
                browser_stop = 0xa9, // = windows = 2000/xp: = browser = stop = key,
                browser_search = 0xaa, // = windows = 2000/xp: = browser = search = key,
                browser_favorites = 0xab, // = windows = 2000/xp: = browser = favorites = key,
                browser_home = 0xac, // = windows = 2000/xp: = browser = start = and = home = key,
                volume_mute = 0xad, // = windows = 2000/xp: = volume = mute = key,
                volume_down = 0xae, // = windows = 2000/xp: = volume = down = key,
                volume_up = 0xaf, // = windows = 2000/xp: = volume = up = key,
                media_next_track = 0xb0, // = windows = 2000/xp: = next = track = key,
                media_prev_track = 0xb1, // = windows = 2000/xp: = previous = track = key,
                media_stop = 0xb2, // = windows = 2000/xp: = stop = media = key,
                media_play_pause = 0xb3, // = windows = 2000/xp: = play/pause = media = key,
                media_launch_mail = 0xb4, // = windows = 2000/xp: = start = mail = key,
                media_launch_media_select = 0xb5, // = windows = 2000/xp: = select = media = key,
                media_launch_app1 = 0xb6, // = launch_app1 = (b6) = windows = 2000/xp: = start = application = 1 = key,
                media_launch_app2 = 0xb7, // = launch_app2 = (b7) = windows = 2000/xp: = start = application = 2 = key,
                // = oem_1 = (ba) = used = for = miscellaneous = characters; = it = can = vary = by = keyboard. = windows = 2000/xp: = for = the = us = standard = keyboard, = the = ';:' = key,
                oem_1 = 0xba,
                // = windows = 2000/xp: = for = any = country/region, = the = '+' = key,
                oem_plus = 0xbb,
                // = windows = 2000/xp: = for = any = country/region, = the = ',' = key,
                oem_comma = 0xbc,
                // = windows = 2000/xp: = for = any = country/region, = the = '-' = key,
                oem_minus = 0xbd,
                // = windows = 2000/xp: = for = any = country/region, = the = '.' = key,
                oem_period = 0xbe,
                // = oem_2 = (bf) = used = for = miscellaneous = characters; = it = can = vary = by = keyboard. = windows = 2000/xp: = for = the = us = standard = keyboard, = the = '/?' = key,
                oem_2 = 0xbf,
                // = oem_3 = (c0) = used = for = miscellaneous = characters; = it = can = vary = by = keyboard. = windows = 2000/xp: = for = the = us = standard = keyboard, = the = '`~' = key,
                oem_3 = 0xc0,
                // = oem_4 = (db) = used = for = miscellaneous = characters; = it = can = vary = by = keyboard. = windows = 2000/xp: = for = the = us = standard = keyboard, = the = '[{' = key,
                oem_4 = 0xdb,
                // = oem_5 = (dc) = used = for = miscellaneous = characters; = it = can = vary = by = keyboard. = windows = 2000/xp: = for = the = us = standard = keyboard, = the = '\|' = key,
                oem_5 = 0xdc,
                // = oem_6 = (dd) = used = for = miscellaneous = characters; = it = can = vary = by = keyboard. = windows = 2000/xp: = for = the = us = standard = keyboard, = the = ']}' = key,
                oem_6 = 0xdd,
                // = oem_7 = (de) = used = for = miscellaneous = characters; = it = can = vary = by = keyboard. = windows = 2000/xp: = for = the = us = standard = keyboard, = the = 'single-quote/double-quote' = key,
                oem_7 = 0xde,
                // = oem_8 = (df) = used = for = miscellaneous = characters; = it = can = vary = by = keyboard.,
                oem_8 = 0xdf,
                // = oem_102 = (e2) = windows = 2000/xp: = either = the = angle = bracket = key = or = the = backslash = key = on = the = rt = 102-key = keyboard,
                oem_102 = 0xe2,
                // = windows = 95/98/me, = windows = nt = 4.0, = windows = 2000/xp: = ime = process = key,
                processkey = 0xe5,
                // = windows = 2000/xp: = used = to = pass = unicode = characters = as = if = they = were = keystrokes. = the = packet = key = is = the = low = word = of = a = 32-bit = virtual = key = value = used = for = non-keyboard = input = methods. = for = more = information, = see = remark = in = keybdinput,sendinput, = wm_keydown, = and = wm_keyup,
                packet = 0xe7,
                attn = 0xf6, // = attn = key,
                crsel = 0xf7, // = crsel = key,
                exsel = 0xf8, // = exsel = key,
                ereof = 0xf9, // = erase = eof = key,
                play = 0xfa, // = play = key,
                zoom = 0xfb, // = zoom = key,
                noname = 0xfc, // = reserved = for = future = use,
                pa1 = 0xfd, // = pa1 = (fd) = pa1 = key,
                oem_clear = 0xfe; // = clear = key
        #endif
        #ifdef LINUX
           const unsigned short shift = 0xffe1,
                   escape = 0xff1b;
        #endif
    }
}

#include "../External/Undefines.h"
