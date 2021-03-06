/* Keyboard.c generated by valac 0.18.1, the Vala compiler
 * generated from Keyboard.gs, do not modify */

/*
 *  libsoy - soy.controllers.Keyboard
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

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gee.h>


#define SOY_CONTROLLERS_TYPE_CONTROLLER (soy_controllers_controller_get_type ())
#define SOY_CONTROLLERS_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_CONTROLLERS_TYPE_CONTROLLER, soycontrollersController))
#define SOY_CONTROLLERS_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_CONTROLLERS_TYPE_CONTROLLER, soycontrollersControllerClass))
#define SOY_CONTROLLERS_IS_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_CONTROLLERS_TYPE_CONTROLLER))
#define SOY_CONTROLLERS_IS_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_CONTROLLERS_TYPE_CONTROLLER))
#define SOY_CONTROLLERS_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_CONTROLLERS_TYPE_CONTROLLER, soycontrollersControllerClass))

typedef struct _soycontrollersController soycontrollersController;
typedef struct _soycontrollersControllerClass soycontrollersControllerClass;
typedef struct _soycontrollersControllerPrivate soycontrollersControllerPrivate;

#define SOY_CONTROLLERS_TYPE_KEYBOARD (soy_controllers_keyboard_get_type ())
#define SOY_CONTROLLERS_KEYBOARD(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_CONTROLLERS_TYPE_KEYBOARD, soycontrollersKeyboard))
#define SOY_CONTROLLERS_KEYBOARD_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_CONTROLLERS_TYPE_KEYBOARD, soycontrollersKeyboardClass))
#define SOY_CONTROLLERS_IS_KEYBOARD(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_CONTROLLERS_TYPE_KEYBOARD))
#define SOY_CONTROLLERS_IS_KEYBOARD_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_CONTROLLERS_TYPE_KEYBOARD))
#define SOY_CONTROLLERS_KEYBOARD_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_CONTROLLERS_TYPE_KEYBOARD, soycontrollersKeyboardClass))

typedef struct _soycontrollersKeyboard soycontrollersKeyboard;
typedef struct _soycontrollersKeyboardClass soycontrollersKeyboardClass;
typedef struct _soycontrollersKeyboardPrivate soycontrollersKeyboardPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define SOY_EVENTS_TYPE_EVENT (soy_events_event_get_type ())
#define SOY_EVENTS_EVENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_EVENTS_TYPE_EVENT, soyeventsEvent))
#define SOY_EVENTS_EVENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_EVENTS_TYPE_EVENT, soyeventsEventClass))
#define SOY_EVENTS_IS_EVENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_EVENTS_TYPE_EVENT))
#define SOY_EVENTS_IS_EVENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_EVENTS_TYPE_EVENT))
#define SOY_EVENTS_EVENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_EVENTS_TYPE_EVENT, soyeventsEventClass))

typedef struct _soyeventsEvent soyeventsEvent;
typedef struct _soyeventsEventClass soyeventsEventClass;

#define SOY_EVENTS_TYPE_DEVICE (soy_events_device_get_type ())
#define SOY_EVENTS_DEVICE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_EVENTS_TYPE_DEVICE, soyeventsDevice))
#define SOY_EVENTS_DEVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_EVENTS_TYPE_DEVICE, soyeventsDeviceClass))
#define SOY_EVENTS_IS_DEVICE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_EVENTS_TYPE_DEVICE))
#define SOY_EVENTS_IS_DEVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_EVENTS_TYPE_DEVICE))
#define SOY_EVENTS_DEVICE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_EVENTS_TYPE_DEVICE, soyeventsDeviceClass))

typedef struct _soyeventsDevice soyeventsDevice;
typedef struct _soyeventsDeviceClass soyeventsDeviceClass;

#define SOY_EVENTS_TYPE_KEY_PRESS (soy_events_key_press_get_type ())
#define SOY_EVENTS_KEY_PRESS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_EVENTS_TYPE_KEY_PRESS, soyeventsKeyPress))
#define SOY_EVENTS_KEY_PRESS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_EVENTS_TYPE_KEY_PRESS, soyeventsKeyPressClass))
#define SOY_EVENTS_IS_KEY_PRESS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_EVENTS_TYPE_KEY_PRESS))
#define SOY_EVENTS_IS_KEY_PRESS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_EVENTS_TYPE_KEY_PRESS))
#define SOY_EVENTS_KEY_PRESS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_EVENTS_TYPE_KEY_PRESS, soyeventsKeyPressClass))

typedef struct _soyeventsKeyPress soyeventsKeyPress;
typedef struct _soyeventsKeyPressClass soyeventsKeyPressClass;

#define SOY_EVENTS_TYPE_KEY_RELEASE (soy_events_key_release_get_type ())
#define SOY_EVENTS_KEY_RELEASE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_EVENTS_TYPE_KEY_RELEASE, soyeventsKeyRelease))
#define SOY_EVENTS_KEY_RELEASE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_EVENTS_TYPE_KEY_RELEASE, soyeventsKeyReleaseClass))
#define SOY_EVENTS_IS_KEY_RELEASE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_EVENTS_TYPE_KEY_RELEASE))
#define SOY_EVENTS_IS_KEY_RELEASE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_EVENTS_TYPE_KEY_RELEASE))
#define SOY_EVENTS_KEY_RELEASE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_EVENTS_TYPE_KEY_RELEASE, soyeventsKeyReleaseClass))

typedef struct _soyeventsKeyRelease soyeventsKeyRelease;
typedef struct _soyeventsKeyReleaseClass soyeventsKeyReleaseClass;

struct _soycontrollersController {
	GObject parent_instance;
	soycontrollersControllerPrivate * priv;
};

struct _soycontrollersControllerClass {
	GObjectClass parent_class;
	gchar* (*tp_repr) (soycontrollersController* self);
};

struct _soycontrollersKeyboard {
	soycontrollersController parent_instance;
	soycontrollersKeyboardPrivate * priv;
};

struct _soycontrollersKeyboardClass {
	soycontrollersControllerClass parent_class;
};

struct _soycontrollersKeyboardPrivate {
	GeeHashSet* _downed_keys;
};


static gpointer soy_controllers_keyboard_parent_class = NULL;

GType soy_controllers_controller_get_type (void) G_GNUC_CONST;
GType soy_controllers_keyboard_get_type (void) G_GNUC_CONST;
#define SOY_CONTROLLERS_KEYBOARD_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SOY_CONTROLLERS_TYPE_KEYBOARD, soycontrollersKeyboardPrivate))
enum  {
	SOY_CONTROLLERS_KEYBOARD_DUMMY_PROPERTY
};
static gchar* soy_controllers_keyboard_real_tp_repr (soycontrollersController* base);
soycontrollersKeyboard* soy_controllers_keyboard_new (void);
soycontrollersKeyboard* soy_controllers_keyboard_construct (GType object_type);
soycontrollersController* soy_controllers_controller_new (void);
soycontrollersController* soy_controllers_controller_construct (GType object_type);
GType soy_events_event_get_type (void) G_GNUC_CONST;
GType soy_events_device_get_type (void) G_GNUC_CONST;
GType soy_events_key_press_get_type (void) G_GNUC_CONST;
GType soy_events_key_release_get_type (void) G_GNUC_CONST;
static GObject * soy_controllers_keyboard_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void soy_controllers_keyboard_finalize (GObject* obj);


static gchar* soy_controllers_keyboard_real_tp_repr (soycontrollersController* base) {
	soycontrollersKeyboard * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	self = (soycontrollersKeyboard*) base;
	_tmp0_ = g_strdup ("Keyboard");
	result = _tmp0_;
	return result;
}


soycontrollersKeyboard* soy_controllers_keyboard_construct (GType object_type) {
	soycontrollersKeyboard * self = NULL;
	self = (soycontrollersKeyboard*) soy_controllers_controller_construct (object_type);
	return self;
}


soycontrollersKeyboard* soy_controllers_keyboard_new (void) {
	return soy_controllers_keyboard_construct (SOY_CONTROLLERS_TYPE_KEYBOARD);
}


static GObject * soy_controllers_keyboard_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	soycontrollersKeyboard * self;
	GeeHashSet* _tmp0_;
	parent_class = G_OBJECT_CLASS (soy_controllers_keyboard_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SOY_CONTROLLERS_TYPE_KEYBOARD, soycontrollersKeyboard);
	_tmp0_ = gee_hash_set_new (G_TYPE_UINT, NULL, NULL, NULL, NULL);
	_g_object_unref0 (self->priv->_downed_keys);
	self->priv->_downed_keys = _tmp0_;
	return obj;
}


static void soy_controllers_keyboard_class_init (soycontrollersKeyboardClass * klass) {
	soy_controllers_keyboard_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (soycontrollersKeyboardPrivate));
	SOY_CONTROLLERS_CONTROLLER_CLASS (klass)->tp_repr = soy_controllers_keyboard_real_tp_repr;
	G_OBJECT_CLASS (klass)->constructor = soy_controllers_keyboard_constructor;
	G_OBJECT_CLASS (klass)->finalize = soy_controllers_keyboard_finalize;
	g_signal_new ("key_press", SOY_CONTROLLERS_TYPE_KEYBOARD, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__OBJECT, G_TYPE_NONE, 1, SOY_EVENTS_TYPE_KEY_PRESS);
	g_signal_new ("key_release", SOY_CONTROLLERS_TYPE_KEYBOARD, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__OBJECT, G_TYPE_NONE, 1, SOY_EVENTS_TYPE_KEY_RELEASE);
}


static void soy_controllers_keyboard_instance_init (soycontrollersKeyboard * self) {
	self->priv = SOY_CONTROLLERS_KEYBOARD_GET_PRIVATE (self);
}


static void soy_controllers_keyboard_finalize (GObject* obj) {
	soycontrollersKeyboard * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SOY_CONTROLLERS_TYPE_KEYBOARD, soycontrollersKeyboard);
	_g_object_unref0 (self->priv->_downed_keys);
	G_OBJECT_CLASS (soy_controllers_keyboard_parent_class)->finalize (obj);
}


GType soy_controllers_keyboard_get_type (void) {
	static volatile gsize soy_controllers_keyboard_type_id__volatile = 0;
	if (g_once_init_enter (&soy_controllers_keyboard_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (soycontrollersKeyboardClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) soy_controllers_keyboard_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (soycontrollersKeyboard), 0, (GInstanceInitFunc) soy_controllers_keyboard_instance_init, NULL };
		GType soy_controllers_keyboard_type_id;
		soy_controllers_keyboard_type_id = g_type_register_static (SOY_CONTROLLERS_TYPE_CONTROLLER, "soycontrollersKeyboard", &g_define_type_info, 0);
		g_once_init_leave (&soy_controllers_keyboard_type_id__volatile, soy_controllers_keyboard_type_id);
	}
	return soy_controllers_keyboard_type_id__volatile;
}



