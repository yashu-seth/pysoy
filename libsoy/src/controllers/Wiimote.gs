/*
 *  libsoy - soy.controllers.Wiimote
 *  Copyright (C) 2006,2007,2008,2009,2010,2011,2012 Copyleft Games Group
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as published
 *  by the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program; if not, see http://www.gnu.org/licenses
 *
 */

[indent=4]
uses
    bluez
    Gee
    Posix

class soy.controllers.Wiimote : soy.controllers.Controller
    /*
    Soy Wiimote Controller

    This class controls wiimote input.
    */
    
    event wiimote_button_press(e : soy.events.Wiibutton)

    construct()
        super()

    def toggle_bit (bf : uint8, b : uint8) : uint8
        if (bf & b) is not 0
            bf = bf & ~b
        else
            bf = bf | b
        return bf
