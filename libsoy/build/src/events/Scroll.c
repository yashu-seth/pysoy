/* Scroll.c generated by valac 0.18.1, the Vala compiler
 * generated from Scroll.gs, do not modify */

/*
 *  libsoy - soy.events.Scroll
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
#include <float.h>
#include <math.h>


#define SOY_EVENTS_TYPE_SCROLL (soy_events_scroll_get_type ())

#define SOY_TYPE_EVENT_TYPE (soy_event_type_get_type ())

#define SOY_WIDGETS_TYPE_WIDGET (soy_widgets_widget_get_type ())
#define SOY_WIDGETS_WIDGET(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_WIDGETS_TYPE_WIDGET, soywidgetsWidget))
#define SOY_WIDGETS_WIDGET_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_WIDGETS_TYPE_WIDGET, soywidgetsWidgetClass))
#define SOY_WIDGETS_IS_WIDGET(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_WIDGETS_TYPE_WIDGET))
#define SOY_WIDGETS_IS_WIDGET_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_WIDGETS_TYPE_WIDGET))
#define SOY_WIDGETS_WIDGET_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_WIDGETS_TYPE_WIDGET, soywidgetsWidgetClass))

typedef struct _soywidgetsWidget soywidgetsWidget;
typedef struct _soywidgetsWidgetClass soywidgetsWidgetClass;

#define SOY_WIDGETS_TYPE_CONTAINER (soy_widgets_container_get_type ())
#define SOY_WIDGETS_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_WIDGETS_TYPE_CONTAINER, soywidgetsContainer))
#define SOY_WIDGETS_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_WIDGETS_TYPE_CONTAINER, soywidgetsContainerClass))
#define SOY_WIDGETS_IS_CONTAINER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_WIDGETS_TYPE_CONTAINER))
#define SOY_WIDGETS_IS_CONTAINER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_WIDGETS_TYPE_CONTAINER))
#define SOY_WIDGETS_CONTAINER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_WIDGETS_TYPE_CONTAINER, soywidgetsContainerClass))

typedef struct _soywidgetsContainer soywidgetsContainer;
typedef struct _soywidgetsContainerClass soywidgetsContainerClass;

#define SOY_WIDGETS_TYPE_WINDOW (soy_widgets_window_get_type ())
#define SOY_WIDGETS_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_WIDGETS_TYPE_WINDOW, soywidgetsWindow))
#define SOY_WIDGETS_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_WIDGETS_TYPE_WINDOW, soywidgetsWindowClass))
#define SOY_WIDGETS_IS_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_WIDGETS_TYPE_WINDOW))
#define SOY_WIDGETS_IS_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_WIDGETS_TYPE_WINDOW))
#define SOY_WIDGETS_WINDOW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_WIDGETS_TYPE_WINDOW, soywidgetsWindowClass))

typedef struct _soywidgetsWindow soywidgetsWindow;
typedef struct _soywidgetsWindowClass soywidgetsWindowClass;

#define SOY_TYPE_SCROLL_DIRECTION (soy_scroll_direction_get_type ())
typedef struct _soyeventsScroll soyeventsScroll;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

typedef enum  {
	SOY_EVENT_TYPE_KeyPress,
	SOY_EVENT_TYPE_KeyDown,
	SOY_EVENT_TYPE_KeyRelease,
	SOY_EVENT_TYPE_Motion,
	SOY_EVENT_TYPE_ButtonPress,
	SOY_EVENT_TYPE_ButtonRelease,
	SOY_EVENT_TYPE_Scroll,
	SOY_EVENT_TYPE_WiimoteButtonPress
} soyEventType;

typedef enum  {
	SOY_SCROLL_DIRECTION_Up,
	SOY_SCROLL_DIRECTION_Down,
	SOY_SCROLL_DIRECTION_Left,
	SOY_SCROLL_DIRECTION_Right
} soyScrollDirection;

struct _soyeventsScroll {
	soyEventType type;
	soywidgetsWindow* window;
	guint32 time;
	gfloat x;
	gfloat y;
	gfloat x_root;
	gfloat y_root;
	soyScrollDirection direction;
};



GType soy_events_scroll_get_type (void) G_GNUC_CONST;
GType soy_event_type_get_type (void) G_GNUC_CONST;
GType soy_widgets_widget_get_type (void) G_GNUC_CONST;
GType soy_widgets_container_get_type (void) G_GNUC_CONST;
GType soy_widgets_window_get_type (void) G_GNUC_CONST;
GType soy_scroll_direction_get_type (void) G_GNUC_CONST;
soyeventsScroll* soy_events_scroll_dup (const soyeventsScroll* self);
void soy_events_scroll_free (soyeventsScroll* self);
void soy_events_scroll_copy (const soyeventsScroll* self, soyeventsScroll* dest);
void soy_events_scroll_destroy (soyeventsScroll* self);


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void soy_events_scroll_copy (const soyeventsScroll* self, soyeventsScroll* dest) {
	soyEventType _tmp0_;
	soywidgetsWindow* _tmp1_;
	soywidgetsWindow* _tmp2_;
	guint32 _tmp3_;
	gfloat _tmp4_;
	gfloat _tmp5_;
	gfloat _tmp6_;
	gfloat _tmp7_;
	soyScrollDirection _tmp8_;
	_tmp0_ = (*self).type;
	(*dest).type = _tmp0_;
	_tmp1_ = (*self).window;
	_tmp2_ = _g_object_ref0 (_tmp1_);
	_g_object_unref0 ((*dest).window);
	(*dest).window = _tmp2_;
	_tmp3_ = (*self).time;
	(*dest).time = _tmp3_;
	_tmp4_ = (*self).x;
	(*dest).x = _tmp4_;
	_tmp5_ = (*self).y;
	(*dest).y = _tmp5_;
	_tmp6_ = (*self).x_root;
	(*dest).x_root = _tmp6_;
	_tmp7_ = (*self).y_root;
	(*dest).y_root = _tmp7_;
	_tmp8_ = (*self).direction;
	(*dest).direction = _tmp8_;
}


void soy_events_scroll_destroy (soyeventsScroll* self) {
	_g_object_unref0 ((*self).window);
}


soyeventsScroll* soy_events_scroll_dup (const soyeventsScroll* self) {
	soyeventsScroll* dup;
	dup = g_new0 (soyeventsScroll, 1);
	soy_events_scroll_copy (self, dup);
	return dup;
}


void soy_events_scroll_free (soyeventsScroll* self) {
	soy_events_scroll_destroy (self);
	g_free (self);
}


GType soy_events_scroll_get_type (void) {
	static volatile gsize soy_events_scroll_type_id__volatile = 0;
	if (g_once_init_enter (&soy_events_scroll_type_id__volatile)) {
		GType soy_events_scroll_type_id;
		soy_events_scroll_type_id = g_boxed_type_register_static ("soyeventsScroll", (GBoxedCopyFunc) soy_events_scroll_dup, (GBoxedFreeFunc) soy_events_scroll_free);
		g_once_init_leave (&soy_events_scroll_type_id__volatile, soy_events_scroll_type_id);
	}
	return soy_events_scroll_type_id__volatile;
}


