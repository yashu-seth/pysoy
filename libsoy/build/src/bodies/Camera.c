/* Camera.c generated by valac 0.18.1, the Vala compiler
 * generated from Camera.gs, do not modify */

/*
 *  libsoy - soy.bodies.Camera
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
#include <soy-1/ode.h>
#include <stdlib.h>
#include <string.h>
#include <gee.h>
#include <GLES/gl.h>
#include <GLES/glext.h>


#define SOY_BODIES_TYPE_BODY (soy_bodies_body_get_type ())
#define SOY_BODIES_BODY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_BODIES_TYPE_BODY, soybodiesBody))
#define SOY_BODIES_BODY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_BODIES_TYPE_BODY, soybodiesBodyClass))
#define SOY_BODIES_IS_BODY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_BODIES_TYPE_BODY))
#define SOY_BODIES_IS_BODY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_BODIES_TYPE_BODY))
#define SOY_BODIES_BODY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_BODIES_TYPE_BODY, soybodiesBodyClass))

typedef struct _soybodiesBody soybodiesBody;
typedef struct _soybodiesBodyClass soybodiesBodyClass;
typedef struct _soybodiesBodyPrivate soybodiesBodyPrivate;

#define SOY_SCENES_TYPE_SCENE (soy_scenes_scene_get_type ())
#define SOY_SCENES_SCENE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_SCENES_TYPE_SCENE, soyscenesScene))
#define SOY_SCENES_SCENE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_SCENES_TYPE_SCENE, soyscenesSceneClass))
#define SOY_SCENES_IS_SCENE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_SCENES_TYPE_SCENE))
#define SOY_SCENES_IS_SCENE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_SCENES_TYPE_SCENE))
#define SOY_SCENES_SCENE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_SCENES_TYPE_SCENE, soyscenesSceneClass))

typedef struct _soyscenesScene soyscenesScene;
typedef struct _soyscenesSceneClass soyscenesSceneClass;

#define SOY_BODIES_TYPE_CAMERA (soy_bodies_camera_get_type ())
#define SOY_BODIES_CAMERA(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_BODIES_TYPE_CAMERA, soybodiesCamera))
#define SOY_BODIES_CAMERA_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_BODIES_TYPE_CAMERA, soybodiesCameraClass))
#define SOY_BODIES_IS_CAMERA(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_BODIES_TYPE_CAMERA))
#define SOY_BODIES_IS_CAMERA_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_BODIES_TYPE_CAMERA))
#define SOY_BODIES_CAMERA_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_BODIES_TYPE_CAMERA, soybodiesCameraClass))

typedef struct _soybodiesCamera soybodiesCamera;
typedef struct _soybodiesCameraClass soybodiesCameraClass;
typedef struct _soybodiesCameraPrivate soybodiesCameraPrivate;

#define SOY_ATOMS_TYPE_POSITION (soy_atoms_position_get_type ())
#define SOY_ATOMS_POSITION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_ATOMS_TYPE_POSITION, soyatomsPosition))
#define SOY_ATOMS_POSITION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_ATOMS_TYPE_POSITION, soyatomsPositionClass))
#define SOY_ATOMS_IS_POSITION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_ATOMS_TYPE_POSITION))
#define SOY_ATOMS_IS_POSITION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_ATOMS_TYPE_POSITION))
#define SOY_ATOMS_POSITION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_ATOMS_TYPE_POSITION, soyatomsPositionClass))

typedef struct _soyatomsPosition soyatomsPosition;
typedef struct _soyatomsPositionClass soyatomsPositionClass;

struct _soybodiesBody {
	GObject parent_instance;
	soybodiesBodyPrivate * priv;
	struct dxBody* body;
	struct dxGeom* geom;
	gchar* key;
	GMutex mutex;
	soyscenesScene* scene;
	GeeHashMap* tags_;
};

struct _soybodiesBodyClass {
	GObjectClass parent_class;
	void (*create_geom) (soybodiesBody* self, GObject* geom_param, gfloat geom_scalar);
	void (*add_extra) (soybodiesBody* self);
	void (*remove_extra) (soybodiesBody* self);
	gfloat (*pointDepth) (soybodiesBody* self, gfloat x, gfloat y, gfloat z);
	gfloat (*volume) (soybodiesBody* self);
	gint (*finite) (soybodiesBody* self);
	void (*mult_model_matrix) (soybodiesBody* self);
	void (*render) (soybodiesBody* self);
	void (*calcFogCoords) (soybodiesBody* self, gfloat _depth);
};

struct _soybodiesCamera {
	soybodiesBody parent_instance;
	soybodiesCameraPrivate * priv;
};

struct _soybodiesCameraClass {
	soybodiesBodyClass parent_class;
};

struct _soybodiesCameraPrivate {
	GLfloat _znear;
	GLfloat _zfar;
	GLfloat _lens;
};


static gpointer soy_bodies_camera_parent_class = NULL;

GType soy_bodies_body_get_type (void) G_GNUC_CONST;
GType soy_scenes_scene_get_type (void) G_GNUC_CONST;
GType soy_bodies_camera_get_type (void) G_GNUC_CONST;
#define SOY_BODIES_CAMERA_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SOY_BODIES_TYPE_CAMERA, soybodiesCameraPrivate))
enum  {
	SOY_BODIES_CAMERA_DUMMY_PROPERTY,
	SOY_BODIES_CAMERA_LENS
};
GType soy_atoms_position_get_type (void) G_GNUC_CONST;
soybodiesCamera* soy_bodies_camera_new (soyatomsPosition* position);
soybodiesCamera* soy_bodies_camera_construct (GType object_type, soyatomsPosition* position);
soybodiesBody* soy_bodies_body_new (soyatomsPosition* position, GObject* geom_param, gfloat geom_scalar);
soybodiesBody* soy_bodies_body_construct (GType object_type, soyatomsPosition* position, GObject* geom_param, gfloat geom_scalar);
void soy_bodies_camera_project (soybodiesCamera* self, GLfloat aspect);
void soy_scenes_scene_render (soyscenesScene* self, GLfloat fov, GLfloat aspect, GLfloat znear, GLfloat zfar);
gfloat soy_bodies_camera_get_lens (soybodiesCamera* self);
void soy_bodies_camera_set_lens (soybodiesCamera* self, gfloat value);
static GObject * soy_bodies_camera_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void soy_bodies_camera_finalize (GObject* obj);
static void _vala_soy_bodies_camera_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_soy_bodies_camera_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


soybodiesCamera* soy_bodies_camera_construct (GType object_type, soyatomsPosition* position) {
	soybodiesCamera * self = NULL;
	soyatomsPosition* _tmp0_;
	_tmp0_ = position;
	self = (soybodiesCamera*) soy_bodies_body_construct (object_type, _tmp0_, NULL, 0.0f);
	return self;
}


soybodiesCamera* soy_bodies_camera_new (soyatomsPosition* position) {
	return soy_bodies_camera_construct (SOY_BODIES_TYPE_CAMERA, position);
}


void soy_bodies_camera_project (soybodiesCamera* self, GLfloat aspect) {
	soyscenesScene* _tmp0_;
	GLfloat* _tmp1_ = NULL;
	GLfloat* mtx;
	gint mtx_length1;
	gint _mtx_size_;
	struct dxBody* _tmp2_;
	dxMatrix3* _tmp3_ = NULL;
	dxMatrix3* rot;
	struct dxBody* _tmp4_;
	dxVector3* _tmp5_ = NULL;
	dxVector3* pos;
	GLfloat* _tmp6_;
	gint _tmp6__length1;
	dxMatrix3* _tmp7_;
	dReal _tmp8_;
	GLfloat _tmp9_;
	GLfloat* _tmp10_;
	gint _tmp10__length1;
	dxMatrix3* _tmp11_;
	dReal _tmp12_;
	GLfloat _tmp13_;
	GLfloat* _tmp14_;
	gint _tmp14__length1;
	dxMatrix3* _tmp15_;
	dReal _tmp16_;
	GLfloat _tmp17_;
	GLfloat* _tmp18_;
	gint _tmp18__length1;
	GLfloat _tmp19_;
	GLfloat* _tmp20_;
	gint _tmp20__length1;
	dxMatrix3* _tmp21_;
	dReal _tmp22_;
	GLfloat _tmp23_;
	GLfloat* _tmp24_;
	gint _tmp24__length1;
	dxMatrix3* _tmp25_;
	dReal _tmp26_;
	GLfloat _tmp27_;
	GLfloat* _tmp28_;
	gint _tmp28__length1;
	dxMatrix3* _tmp29_;
	dReal _tmp30_;
	GLfloat _tmp31_;
	GLfloat* _tmp32_;
	gint _tmp32__length1;
	GLfloat _tmp33_;
	GLfloat* _tmp34_;
	gint _tmp34__length1;
	dxMatrix3* _tmp35_;
	dReal _tmp36_;
	GLfloat _tmp37_;
	GLfloat* _tmp38_;
	gint _tmp38__length1;
	dxMatrix3* _tmp39_;
	dReal _tmp40_;
	GLfloat _tmp41_;
	GLfloat* _tmp42_;
	gint _tmp42__length1;
	dxMatrix3* _tmp43_;
	dReal _tmp44_;
	GLfloat _tmp45_;
	GLfloat* _tmp46_;
	gint _tmp46__length1;
	GLfloat _tmp47_;
	GLfloat* _tmp48_;
	gint _tmp48__length1;
	GLfloat _tmp49_;
	GLfloat* _tmp50_;
	gint _tmp50__length1;
	GLfloat _tmp51_;
	GLfloat* _tmp52_;
	gint _tmp52__length1;
	GLfloat _tmp53_;
	GLfloat* _tmp54_;
	gint _tmp54__length1;
	GLfloat _tmp55_;
	GLfloat* _tmp56_;
	gint _tmp56__length1;
	dxVector3* _tmp57_;
	dReal _tmp58_;
	dxVector3* _tmp59_;
	dReal _tmp60_;
	dxVector3* _tmp61_;
	dReal _tmp62_;
	soyscenesScene* _tmp63_;
	GLfloat _tmp64_;
	GLfloat _tmp65_;
	GLfloat _tmp66_;
	GLfloat _tmp67_;
	g_return_if_fail (self != NULL);
	_tmp0_ = ((soybodiesBody*) self)->scene;
	if (_tmp0_ == NULL) {
		return;
	}
	_tmp1_ = g_new0 (GLfloat, 16);
	mtx = _tmp1_;
	mtx_length1 = 16;
	_mtx_size_ = mtx_length1;
	_tmp2_ = ((soybodiesBody*) self)->body;
	_tmp3_ = dBodyGetRotation (_tmp2_);
	rot = _tmp3_;
	_tmp4_ = ((soybodiesBody*) self)->body;
	_tmp5_ = dBodyGetPosition (_tmp4_);
	pos = _tmp5_;
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
	_tmp6_ = mtx;
	_tmp6__length1 = mtx_length1;
	_tmp7_ = rot;
	_tmp8_ = _tmp7_->m0;
	_tmp6_[0] = (GLfloat) _tmp8_;
	_tmp9_ = _tmp6_[0];
	_tmp10_ = mtx;
	_tmp10__length1 = mtx_length1;
	_tmp11_ = rot;
	_tmp12_ = _tmp11_->m1;
	_tmp10_[1] = (GLfloat) _tmp12_;
	_tmp13_ = _tmp10_[1];
	_tmp14_ = mtx;
	_tmp14__length1 = mtx_length1;
	_tmp15_ = rot;
	_tmp16_ = _tmp15_->m2;
	_tmp14_[2] = (GLfloat) _tmp16_;
	_tmp17_ = _tmp14_[2];
	_tmp18_ = mtx;
	_tmp18__length1 = mtx_length1;
	_tmp18_[3] = (GLfloat) 0.0f;
	_tmp19_ = _tmp18_[3];
	_tmp20_ = mtx;
	_tmp20__length1 = mtx_length1;
	_tmp21_ = rot;
	_tmp22_ = _tmp21_->m4;
	_tmp20_[4] = (GLfloat) _tmp22_;
	_tmp23_ = _tmp20_[4];
	_tmp24_ = mtx;
	_tmp24__length1 = mtx_length1;
	_tmp25_ = rot;
	_tmp26_ = _tmp25_->m5;
	_tmp24_[5] = (GLfloat) _tmp26_;
	_tmp27_ = _tmp24_[5];
	_tmp28_ = mtx;
	_tmp28__length1 = mtx_length1;
	_tmp29_ = rot;
	_tmp30_ = _tmp29_->m6;
	_tmp28_[6] = (GLfloat) _tmp30_;
	_tmp31_ = _tmp28_[6];
	_tmp32_ = mtx;
	_tmp32__length1 = mtx_length1;
	_tmp32_[7] = (GLfloat) 0.0f;
	_tmp33_ = _tmp32_[7];
	_tmp34_ = mtx;
	_tmp34__length1 = mtx_length1;
	_tmp35_ = rot;
	_tmp36_ = _tmp35_->m8;
	_tmp34_[8] = (GLfloat) _tmp36_;
	_tmp37_ = _tmp34_[8];
	_tmp38_ = mtx;
	_tmp38__length1 = mtx_length1;
	_tmp39_ = rot;
	_tmp40_ = _tmp39_->m9;
	_tmp38_[9] = (GLfloat) _tmp40_;
	_tmp41_ = _tmp38_[9];
	_tmp42_ = mtx;
	_tmp42__length1 = mtx_length1;
	_tmp43_ = rot;
	_tmp44_ = _tmp43_->ma;
	_tmp42_[10] = (GLfloat) _tmp44_;
	_tmp45_ = _tmp42_[10];
	_tmp46_ = mtx;
	_tmp46__length1 = mtx_length1;
	_tmp46_[11] = (GLfloat) 0.0f;
	_tmp47_ = _tmp46_[11];
	_tmp48_ = mtx;
	_tmp48__length1 = mtx_length1;
	_tmp48_[12] = (GLfloat) 0.0f;
	_tmp49_ = _tmp48_[12];
	_tmp50_ = mtx;
	_tmp50__length1 = mtx_length1;
	_tmp50_[13] = (GLfloat) 0.0f;
	_tmp51_ = _tmp50_[13];
	_tmp52_ = mtx;
	_tmp52__length1 = mtx_length1;
	_tmp52_[14] = (GLfloat) 0.0f;
	_tmp53_ = _tmp52_[14];
	_tmp54_ = mtx;
	_tmp54__length1 = mtx_length1;
	_tmp54_[15] = (GLfloat) 1.0f;
	_tmp55_ = _tmp54_[15];
	_tmp56_ = mtx;
	_tmp56__length1 = mtx_length1;
	glLoadMatrixf (_tmp56_);
	_tmp57_ = pos;
	_tmp58_ = _tmp57_->x;
	_tmp59_ = pos;
	_tmp60_ = _tmp59_->y;
	_tmp61_ = pos;
	_tmp62_ = _tmp61_->z;
	glTranslatef (-((GLfloat) _tmp58_), -((GLfloat) _tmp60_), -((GLfloat) _tmp62_));
	_tmp63_ = ((soybodiesBody*) self)->scene;
	_tmp64_ = self->priv->_lens;
	_tmp65_ = aspect;
	_tmp66_ = self->priv->_znear;
	_tmp67_ = self->priv->_zfar;
	soy_scenes_scene_render (_tmp63_, _tmp64_, _tmp65_, _tmp66_, _tmp67_);
	mtx = (g_free (mtx), NULL);
}


gfloat soy_bodies_camera_get_lens (soybodiesCamera* self) {
	gfloat result;
	GLfloat _tmp0_;
	g_return_val_if_fail (self != NULL, 0.0F);
	_tmp0_ = self->priv->_lens;
	result = (gfloat) _tmp0_;
	return result;
}


void soy_bodies_camera_set_lens (soybodiesCamera* self, gfloat value) {
	gfloat _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_lens = (GLfloat) _tmp0_;
	g_object_notify ((GObject *) self, "lens");
}


static GObject * soy_bodies_camera_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	soybodiesCamera * self;
	parent_class = G_OBJECT_CLASS (soy_bodies_camera_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SOY_BODIES_TYPE_CAMERA, soybodiesCamera);
	self->priv->_lens = (GLfloat) 45.0f;
	self->priv->_znear = (GLfloat) 1.0f;
	self->priv->_zfar = (GLfloat) 100.0f;
	return obj;
}


static void soy_bodies_camera_class_init (soybodiesCameraClass * klass) {
	soy_bodies_camera_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (soybodiesCameraPrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_soy_bodies_camera_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_soy_bodies_camera_set_property;
	G_OBJECT_CLASS (klass)->constructor = soy_bodies_camera_constructor;
	G_OBJECT_CLASS (klass)->finalize = soy_bodies_camera_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), SOY_BODIES_CAMERA_LENS, g_param_spec_float ("lens", "lens", "lens", -G_MAXFLOAT, G_MAXFLOAT, 0.0F, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void soy_bodies_camera_instance_init (soybodiesCamera * self) {
	self->priv = SOY_BODIES_CAMERA_GET_PRIVATE (self);
}


static void soy_bodies_camera_finalize (GObject* obj) {
	soybodiesCamera * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SOY_BODIES_TYPE_CAMERA, soybodiesCamera);
	G_OBJECT_CLASS (soy_bodies_camera_parent_class)->finalize (obj);
}


GType soy_bodies_camera_get_type (void) {
	static volatile gsize soy_bodies_camera_type_id__volatile = 0;
	if (g_once_init_enter (&soy_bodies_camera_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (soybodiesCameraClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) soy_bodies_camera_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (soybodiesCamera), 0, (GInstanceInitFunc) soy_bodies_camera_instance_init, NULL };
		GType soy_bodies_camera_type_id;
		soy_bodies_camera_type_id = g_type_register_static (SOY_BODIES_TYPE_BODY, "soybodiesCamera", &g_define_type_info, 0);
		g_once_init_leave (&soy_bodies_camera_type_id__volatile, soy_bodies_camera_type_id);
	}
	return soy_bodies_camera_type_id__volatile;
}


static void _vala_soy_bodies_camera_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	soybodiesCamera * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SOY_BODIES_TYPE_CAMERA, soybodiesCamera);
	switch (property_id) {
		case SOY_BODIES_CAMERA_LENS:
		g_value_set_float (value, soy_bodies_camera_get_lens (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_soy_bodies_camera_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	soybodiesCamera * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SOY_BODIES_TYPE_CAMERA, soybodiesCamera);
	switch (property_id) {
		case SOY_BODIES_CAMERA_LENS:
		soy_bodies_camera_set_lens (self, g_value_get_float (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



