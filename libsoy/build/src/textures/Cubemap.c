/* Cubemap.c generated by valac 0.18.1, the Vala compiler
 * generated from Cubemap.gs, do not modify */

/*
 *  libsoy - soy.textures.Cubemap
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
#include <GLES/gl.h>
#include <GLES/glext.h>
#include <string.h>


#define SOY_TEXTURES_TYPE_TEXTURE (soy_textures_texture_get_type ())
#define SOY_TEXTURES_TEXTURE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_TEXTURES_TYPE_TEXTURE, soytexturesTexture))
#define SOY_TEXTURES_TEXTURE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_TEXTURES_TYPE_TEXTURE, soytexturesTextureClass))
#define SOY_TEXTURES_IS_TEXTURE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_TEXTURES_TYPE_TEXTURE))
#define SOY_TEXTURES_IS_TEXTURE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_TEXTURES_TYPE_TEXTURE))
#define SOY_TEXTURES_TEXTURE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_TEXTURES_TYPE_TEXTURE, soytexturesTextureClass))

typedef struct _soytexturesTexture soytexturesTexture;
typedef struct _soytexturesTextureClass soytexturesTextureClass;
typedef struct _soytexturesTexturePrivate soytexturesTexturePrivate;

#define SOY_TEXTURES_TYPE_CUBEMAP (soy_textures_cubemap_get_type ())
#define SOY_TEXTURES_CUBEMAP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_TEXTURES_TYPE_CUBEMAP, soytexturesCubemap))
#define SOY_TEXTURES_CUBEMAP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_TEXTURES_TYPE_CUBEMAP, soytexturesCubemapClass))
#define SOY_TEXTURES_IS_CUBEMAP(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_TEXTURES_TYPE_CUBEMAP))
#define SOY_TEXTURES_IS_CUBEMAP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_TEXTURES_TYPE_CUBEMAP))
#define SOY_TEXTURES_CUBEMAP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_TEXTURES_TYPE_CUBEMAP, soytexturesCubemapClass))

typedef struct _soytexturesCubemap soytexturesCubemap;
typedef struct _soytexturesCubemapClass soytexturesCubemapClass;
typedef struct _soytexturesCubemapPrivate soytexturesCubemapPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _soytexturesTexture {
	GObject parent_instance;
	soytexturesTexturePrivate * priv;
	guchar* texels;
};

struct _soytexturesTextureClass {
	GObjectClass parent_class;
	void (*enable) (soytexturesTexture* self);
	void (*disable) (soytexturesTexture* self);
};

struct _soytexturesCubemap {
	soytexturesTexture parent_instance;
	soytexturesCubemapPrivate * priv;
};

struct _soytexturesCubemapClass {
	soytexturesTextureClass parent_class;
};

struct _soytexturesCubemapPrivate {
	GLuint _texture;
	gboolean _updated;
	GMutex _mutex;
	soytexturesTexture* _up;
	soytexturesTexture* _down;
	soytexturesTexture* _left;
	soytexturesTexture* _right;
	soytexturesTexture* _front;
	soytexturesTexture* _back;
};


static gpointer soy_textures_cubemap_parent_class = NULL;

GType soy_textures_texture_get_type (void) G_GNUC_CONST;
GType soy_textures_cubemap_get_type (void) G_GNUC_CONST;
#define SOY_TEXTURES_CUBEMAP_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SOY_TEXTURES_TYPE_CUBEMAP, soytexturesCubemapPrivate))
enum  {
	SOY_TEXTURES_CUBEMAP_DUMMY_PROPERTY,
	SOY_TEXTURES_CUBEMAP_UP,
	SOY_TEXTURES_CUBEMAP_DOWN,
	SOY_TEXTURES_CUBEMAP_LEFT,
	SOY_TEXTURES_CUBEMAP_RIGHT,
	SOY_TEXTURES_CUBEMAP_FRONT,
	SOY_TEXTURES_CUBEMAP_BACK
};
soytexturesCubemap* soy_textures_cubemap_new (void);
soytexturesCubemap* soy_textures_cubemap_construct (GType object_type);
soytexturesTexture* soy_textures_texture_new (void);
soytexturesTexture* soy_textures_texture_construct (GType object_type);
static void soy_textures_cubemap_real_enable (soytexturesTexture* base);
soytexturesTexture* soy_textures_cubemap_get_right (soytexturesCubemap* self);
void soy_textures_texture_update (soytexturesTexture* self, GLenum target);
soytexturesTexture* soy_textures_cubemap_get_left (soytexturesCubemap* self);
soytexturesTexture* soy_textures_cubemap_get_up (soytexturesCubemap* self);
soytexturesTexture* soy_textures_cubemap_get_down (soytexturesCubemap* self);
soytexturesTexture* soy_textures_cubemap_get_front (soytexturesCubemap* self);
soytexturesTexture* soy_textures_cubemap_get_back (soytexturesCubemap* self);
static void soy_textures_cubemap_real_disable (soytexturesTexture* base);
void soy_textures_cubemap_set_up (soytexturesCubemap* self, soytexturesTexture* value);
void soy_textures_cubemap_set_down (soytexturesCubemap* self, soytexturesTexture* value);
void soy_textures_cubemap_set_left (soytexturesCubemap* self, soytexturesTexture* value);
void soy_textures_cubemap_set_right (soytexturesCubemap* self, soytexturesTexture* value);
void soy_textures_cubemap_set_front (soytexturesCubemap* self, soytexturesTexture* value);
void soy_textures_cubemap_set_back (soytexturesCubemap* self, soytexturesTexture* value);
static void soy_textures_cubemap_finalize (GObject* obj);
static void _vala_soy_textures_cubemap_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_soy_textures_cubemap_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static void _vala_clear_GMutex (GMutex * mutex);
static void _vala_clear_GRecMutex (GRecMutex * mutex);
static void _vala_clear_GRWLock (GRWLock * mutex);
static void _vala_clear_GCond (GCond * mutex);


soytexturesCubemap* soy_textures_cubemap_construct (GType object_type) {
	soytexturesCubemap * self = NULL;
	self = (soytexturesCubemap*) soy_textures_texture_construct (object_type);
	_vala_clear_GMutex (&self->priv->_mutex);
	g_mutex_init (&self->priv->_mutex);
	return self;
}


soytexturesCubemap* soy_textures_cubemap_new (void) {
	return soy_textures_cubemap_construct (SOY_TEXTURES_TYPE_CUBEMAP);
}


static void soy_textures_cubemap_real_enable (soytexturesTexture* base) {
	soytexturesCubemap * self;
	GLuint _tmp0_;
	gboolean _tmp4_;
	self = (soytexturesCubemap*) base;
	g_mutex_lock (&self->priv->_mutex);
	glEnable (GL_TEXTURE_CUBE_MAP_OES);
	_tmp0_ = self->priv->_texture;
	if (_tmp0_ == ((GLuint) 0)) {
		GLuint _tmp1_ = 0U;
		GLuint _tmp2_;
		glGenTextures ((GLsizei) 1, &_tmp1_);
		self->priv->_texture = _tmp1_;
		_tmp2_ = self->priv->_texture;
		glBindTexture (GL_TEXTURE_CUBE_MAP_OES, _tmp2_);
		glTexParameteri (GL_TEXTURE_CUBE_MAP_OES, GL_TEXTURE_MAG_FILTER, (GLint) GL_LINEAR);
		glTexParameteri (GL_TEXTURE_CUBE_MAP_OES, GL_TEXTURE_MIN_FILTER, (GLint) GL_LINEAR);
		self->priv->_updated = TRUE;
	} else {
		GLuint _tmp3_;
		_tmp3_ = self->priv->_texture;
		glBindTexture (GL_TEXTURE_CUBE_MAP_OES, _tmp3_);
	}
	_tmp4_ = self->priv->_updated;
	if (_tmp4_) {
		soytexturesTexture* _tmp5_;
		soytexturesTexture* _tmp6_;
		soytexturesTexture* _tmp9_;
		soytexturesTexture* _tmp10_;
		soytexturesTexture* _tmp13_;
		soytexturesTexture* _tmp14_;
		soytexturesTexture* _tmp17_;
		soytexturesTexture* _tmp18_;
		soytexturesTexture* _tmp21_;
		soytexturesTexture* _tmp22_;
		soytexturesTexture* _tmp25_;
		soytexturesTexture* _tmp26_;
		_tmp5_ = soy_textures_cubemap_get_right (self);
		_tmp6_ = _tmp5_;
		if (_tmp6_ != NULL) {
			soytexturesTexture* _tmp7_;
			soytexturesTexture* _tmp8_;
			_tmp7_ = soy_textures_cubemap_get_right (self);
			_tmp8_ = _tmp7_;
			soy_textures_texture_update (_tmp8_, GL_TEXTURE_CUBE_MAP_POSITIVE_X_OES);
		}
		_tmp9_ = soy_textures_cubemap_get_left (self);
		_tmp10_ = _tmp9_;
		if (_tmp10_ != NULL) {
			soytexturesTexture* _tmp11_;
			soytexturesTexture* _tmp12_;
			_tmp11_ = soy_textures_cubemap_get_left (self);
			_tmp12_ = _tmp11_;
			soy_textures_texture_update (_tmp12_, GL_TEXTURE_CUBE_MAP_NEGATIVE_X_OES);
		}
		_tmp13_ = soy_textures_cubemap_get_up (self);
		_tmp14_ = _tmp13_;
		if (_tmp14_ != NULL) {
			soytexturesTexture* _tmp15_;
			soytexturesTexture* _tmp16_;
			_tmp15_ = soy_textures_cubemap_get_up (self);
			_tmp16_ = _tmp15_;
			soy_textures_texture_update (_tmp16_, GL_TEXTURE_CUBE_MAP_POSITIVE_Y_OES);
		}
		_tmp17_ = soy_textures_cubemap_get_down (self);
		_tmp18_ = _tmp17_;
		if (_tmp18_ != NULL) {
			soytexturesTexture* _tmp19_;
			soytexturesTexture* _tmp20_;
			_tmp19_ = soy_textures_cubemap_get_down (self);
			_tmp20_ = _tmp19_;
			soy_textures_texture_update (_tmp20_, GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_OES);
		}
		_tmp21_ = soy_textures_cubemap_get_front (self);
		_tmp22_ = _tmp21_;
		if (_tmp22_ != NULL) {
			soytexturesTexture* _tmp23_;
			soytexturesTexture* _tmp24_;
			_tmp23_ = soy_textures_cubemap_get_front (self);
			_tmp24_ = _tmp23_;
			soy_textures_texture_update (_tmp24_, GL_TEXTURE_CUBE_MAP_POSITIVE_Z_OES);
		}
		_tmp25_ = soy_textures_cubemap_get_back (self);
		_tmp26_ = _tmp25_;
		if (_tmp26_ != NULL) {
			soytexturesTexture* _tmp27_;
			soytexturesTexture* _tmp28_;
			_tmp27_ = soy_textures_cubemap_get_back (self);
			_tmp28_ = _tmp27_;
			soy_textures_texture_update (_tmp28_, GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_OES);
		}
	}
}


static void soy_textures_cubemap_real_disable (soytexturesTexture* base) {
	soytexturesCubemap * self;
	self = (soytexturesCubemap*) base;
	glDisable (GL_TEXTURE_CUBE_MAP_OES);
	g_mutex_unlock (&self->priv->_mutex);
}


soytexturesTexture* soy_textures_cubemap_get_up (soytexturesCubemap* self) {
	soytexturesTexture* result;
	soytexturesTexture* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_up;
	result = _tmp0_;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void soy_textures_cubemap_set_up (soytexturesCubemap* self, soytexturesTexture* value) {
	soytexturesTexture* _tmp0_;
	soytexturesTexture* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->_up);
	self->priv->_up = _tmp1_;
	g_object_notify ((GObject *) self, "up");
}


soytexturesTexture* soy_textures_cubemap_get_down (soytexturesCubemap* self) {
	soytexturesTexture* result;
	soytexturesTexture* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_down;
	result = _tmp0_;
	return result;
}


void soy_textures_cubemap_set_down (soytexturesCubemap* self, soytexturesTexture* value) {
	soytexturesTexture* _tmp0_;
	soytexturesTexture* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->_down);
	self->priv->_down = _tmp1_;
	g_object_notify ((GObject *) self, "down");
}


soytexturesTexture* soy_textures_cubemap_get_left (soytexturesCubemap* self) {
	soytexturesTexture* result;
	soytexturesTexture* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_left;
	result = _tmp0_;
	return result;
}


void soy_textures_cubemap_set_left (soytexturesCubemap* self, soytexturesTexture* value) {
	soytexturesTexture* _tmp0_;
	soytexturesTexture* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->_left);
	self->priv->_left = _tmp1_;
	g_object_notify ((GObject *) self, "left");
}


soytexturesTexture* soy_textures_cubemap_get_right (soytexturesCubemap* self) {
	soytexturesTexture* result;
	soytexturesTexture* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_right;
	result = _tmp0_;
	return result;
}


void soy_textures_cubemap_set_right (soytexturesCubemap* self, soytexturesTexture* value) {
	soytexturesTexture* _tmp0_;
	soytexturesTexture* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->_right);
	self->priv->_right = _tmp1_;
	g_object_notify ((GObject *) self, "right");
}


soytexturesTexture* soy_textures_cubemap_get_front (soytexturesCubemap* self) {
	soytexturesTexture* result;
	soytexturesTexture* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_front;
	result = _tmp0_;
	return result;
}


void soy_textures_cubemap_set_front (soytexturesCubemap* self, soytexturesTexture* value) {
	soytexturesTexture* _tmp0_;
	soytexturesTexture* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->_front);
	self->priv->_front = _tmp1_;
	g_object_notify ((GObject *) self, "front");
}


soytexturesTexture* soy_textures_cubemap_get_back (soytexturesCubemap* self) {
	soytexturesTexture* result;
	soytexturesTexture* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_back;
	result = _tmp0_;
	return result;
}


void soy_textures_cubemap_set_back (soytexturesCubemap* self, soytexturesTexture* value) {
	soytexturesTexture* _tmp0_;
	soytexturesTexture* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->_back);
	self->priv->_back = _tmp1_;
	g_object_notify ((GObject *) self, "back");
}


static void soy_textures_cubemap_class_init (soytexturesCubemapClass * klass) {
	soy_textures_cubemap_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (soytexturesCubemapPrivate));
	SOY_TEXTURES_TEXTURE_CLASS (klass)->enable = soy_textures_cubemap_real_enable;
	SOY_TEXTURES_TEXTURE_CLASS (klass)->disable = soy_textures_cubemap_real_disable;
	G_OBJECT_CLASS (klass)->get_property = _vala_soy_textures_cubemap_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_soy_textures_cubemap_set_property;
	G_OBJECT_CLASS (klass)->finalize = soy_textures_cubemap_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), SOY_TEXTURES_CUBEMAP_UP, g_param_spec_object ("up", "up", "up", SOY_TEXTURES_TYPE_TEXTURE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), SOY_TEXTURES_CUBEMAP_DOWN, g_param_spec_object ("down", "down", "down", SOY_TEXTURES_TYPE_TEXTURE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), SOY_TEXTURES_CUBEMAP_LEFT, g_param_spec_object ("left", "left", "left", SOY_TEXTURES_TYPE_TEXTURE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), SOY_TEXTURES_CUBEMAP_RIGHT, g_param_spec_object ("right", "right", "right", SOY_TEXTURES_TYPE_TEXTURE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), SOY_TEXTURES_CUBEMAP_FRONT, g_param_spec_object ("front", "front", "front", SOY_TEXTURES_TYPE_TEXTURE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), SOY_TEXTURES_CUBEMAP_BACK, g_param_spec_object ("back", "back", "back", SOY_TEXTURES_TYPE_TEXTURE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void soy_textures_cubemap_instance_init (soytexturesCubemap * self) {
	self->priv = SOY_TEXTURES_CUBEMAP_GET_PRIVATE (self);
}


static void soy_textures_cubemap_finalize (GObject* obj) {
	soytexturesCubemap * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SOY_TEXTURES_TYPE_CUBEMAP, soytexturesCubemap);
	_vala_clear_GMutex (&self->priv->_mutex);
	_g_object_unref0 (self->priv->_up);
	_g_object_unref0 (self->priv->_down);
	_g_object_unref0 (self->priv->_left);
	_g_object_unref0 (self->priv->_right);
	_g_object_unref0 (self->priv->_front);
	_g_object_unref0 (self->priv->_back);
	G_OBJECT_CLASS (soy_textures_cubemap_parent_class)->finalize (obj);
}


GType soy_textures_cubemap_get_type (void) {
	static volatile gsize soy_textures_cubemap_type_id__volatile = 0;
	if (g_once_init_enter (&soy_textures_cubemap_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (soytexturesCubemapClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) soy_textures_cubemap_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (soytexturesCubemap), 0, (GInstanceInitFunc) soy_textures_cubemap_instance_init, NULL };
		GType soy_textures_cubemap_type_id;
		soy_textures_cubemap_type_id = g_type_register_static (SOY_TEXTURES_TYPE_TEXTURE, "soytexturesCubemap", &g_define_type_info, 0);
		g_once_init_leave (&soy_textures_cubemap_type_id__volatile, soy_textures_cubemap_type_id);
	}
	return soy_textures_cubemap_type_id__volatile;
}


static void _vala_soy_textures_cubemap_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	soytexturesCubemap * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SOY_TEXTURES_TYPE_CUBEMAP, soytexturesCubemap);
	switch (property_id) {
		case SOY_TEXTURES_CUBEMAP_UP:
		g_value_set_object (value, soy_textures_cubemap_get_up (self));
		break;
		case SOY_TEXTURES_CUBEMAP_DOWN:
		g_value_set_object (value, soy_textures_cubemap_get_down (self));
		break;
		case SOY_TEXTURES_CUBEMAP_LEFT:
		g_value_set_object (value, soy_textures_cubemap_get_left (self));
		break;
		case SOY_TEXTURES_CUBEMAP_RIGHT:
		g_value_set_object (value, soy_textures_cubemap_get_right (self));
		break;
		case SOY_TEXTURES_CUBEMAP_FRONT:
		g_value_set_object (value, soy_textures_cubemap_get_front (self));
		break;
		case SOY_TEXTURES_CUBEMAP_BACK:
		g_value_set_object (value, soy_textures_cubemap_get_back (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_soy_textures_cubemap_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	soytexturesCubemap * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SOY_TEXTURES_TYPE_CUBEMAP, soytexturesCubemap);
	switch (property_id) {
		case SOY_TEXTURES_CUBEMAP_UP:
		soy_textures_cubemap_set_up (self, g_value_get_object (value));
		break;
		case SOY_TEXTURES_CUBEMAP_DOWN:
		soy_textures_cubemap_set_down (self, g_value_get_object (value));
		break;
		case SOY_TEXTURES_CUBEMAP_LEFT:
		soy_textures_cubemap_set_left (self, g_value_get_object (value));
		break;
		case SOY_TEXTURES_CUBEMAP_RIGHT:
		soy_textures_cubemap_set_right (self, g_value_get_object (value));
		break;
		case SOY_TEXTURES_CUBEMAP_FRONT:
		soy_textures_cubemap_set_front (self, g_value_get_object (value));
		break;
		case SOY_TEXTURES_CUBEMAP_BACK:
		soy_textures_cubemap_set_back (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_clear_GMutex (GMutex * mutex) {
	GMutex zero_mutex = { 0 };
	if (memcmp (mutex, &zero_mutex, sizeof (GMutex))) {
		g_mutex_clear (mutex);
		memset (mutex, 0, sizeof (GMutex));
	}
}


static void _vala_clear_GRecMutex (GRecMutex * mutex) {
	GRecMutex zero_mutex = { 0 };
	if (memcmp (mutex, &zero_mutex, sizeof (GRecMutex))) {
		g_rec_mutex_clear (mutex);
		memset (mutex, 0, sizeof (GRecMutex));
	}
}


static void _vala_clear_GRWLock (GRWLock * mutex) {
	GRWLock zero_mutex = { 0 };
	if (memcmp (mutex, &zero_mutex, sizeof (GRWLock))) {
		g_rw_lock_clear (mutex);
		memset (mutex, 0, sizeof (GRWLock));
	}
}


static void _vala_clear_GCond (GCond * mutex) {
	GCond zero_mutex = { 0 };
	if (memcmp (mutex, &zero_mutex, sizeof (GCond))) {
		g_cond_clear (mutex);
		memset (mutex, 0, sizeof (GCond));
	}
}



