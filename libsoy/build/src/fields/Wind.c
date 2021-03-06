/* Wind.c generated by valac 0.18.1, the Vala compiler
 * generated from Wind.gs, do not modify */

/*
 *  libsoy - soy.fields.Wind
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

#define SOY_FIELDS_TYPE_FIELD (soy_fields_field_get_type ())
#define SOY_FIELDS_FIELD(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_FIELDS_TYPE_FIELD, soyfieldsField))
#define SOY_FIELDS_FIELD_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_FIELDS_TYPE_FIELD, soyfieldsFieldClass))
#define SOY_FIELDS_IS_FIELD(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_FIELDS_TYPE_FIELD))
#define SOY_FIELDS_IS_FIELD_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_FIELDS_TYPE_FIELD))
#define SOY_FIELDS_FIELD_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_FIELDS_TYPE_FIELD, soyfieldsFieldClass))

typedef struct _soyfieldsField soyfieldsField;
typedef struct _soyfieldsFieldClass soyfieldsFieldClass;
typedef struct _soyfieldsFieldPrivate soyfieldsFieldPrivate;

#define SOY_FIELDS_TYPE_WIND (soy_fields_wind_get_type ())
#define SOY_FIELDS_WIND(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_FIELDS_TYPE_WIND, soyfieldsWind))
#define SOY_FIELDS_WIND_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_FIELDS_TYPE_WIND, soyfieldsWindClass))
#define SOY_FIELDS_IS_WIND(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_FIELDS_TYPE_WIND))
#define SOY_FIELDS_IS_WIND_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_FIELDS_TYPE_WIND))
#define SOY_FIELDS_WIND_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_FIELDS_TYPE_WIND, soyfieldsWindClass))

typedef struct _soyfieldsWind soyfieldsWind;
typedef struct _soyfieldsWindClass soyfieldsWindClass;
typedef struct _soyfieldsWindPrivate soyfieldsWindPrivate;

#define SOY_ATOMS_TYPE_VECTOR (soy_atoms_vector_get_type ())
#define SOY_ATOMS_VECTOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SOY_ATOMS_TYPE_VECTOR, soyatomsVector))
#define SOY_ATOMS_VECTOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SOY_ATOMS_TYPE_VECTOR, soyatomsVectorClass))
#define SOY_ATOMS_IS_VECTOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SOY_ATOMS_TYPE_VECTOR))
#define SOY_ATOMS_IS_VECTOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SOY_ATOMS_TYPE_VECTOR))
#define SOY_ATOMS_VECTOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SOY_ATOMS_TYPE_VECTOR, soyatomsVectorClass))

typedef struct _soyatomsVector soyatomsVector;
typedef struct _soyatomsVectorClass soyatomsVectorClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

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

struct _soyfieldsField {
	soybodiesBody parent_instance;
	soyfieldsFieldPrivate * priv;
};

struct _soyfieldsFieldClass {
	soybodiesBodyClass parent_class;
	gboolean (*exert) (soyfieldsField* self, soybodiesBody* other);
	void (*give) (soyfieldsField* self, gint data);
	void (*commit) (soyfieldsField* self);
};

struct _soyfieldsWind {
	soyfieldsField parent_instance;
	soyfieldsWindPrivate * priv;
};

struct _soyfieldsWindClass {
	soyfieldsFieldClass parent_class;
};

struct _soyfieldsWindPrivate {
	soyatomsVector* _wind_obj;
	gfloat _density;
};


static gpointer soy_fields_wind_parent_class = NULL;

GType soy_bodies_body_get_type (void) G_GNUC_CONST;
GType soy_scenes_scene_get_type (void) G_GNUC_CONST;
GType soy_fields_field_get_type (void) G_GNUC_CONST;
GType soy_fields_wind_get_type (void) G_GNUC_CONST;
GType soy_atoms_vector_get_type (void) G_GNUC_CONST;
#define SOY_FIELDS_WIND_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SOY_FIELDS_TYPE_WIND, soyfieldsWindPrivate))
enum  {
	SOY_FIELDS_WIND_DUMMY_PROPERTY,
	SOY_FIELDS_WIND_WIND,
	SOY_FIELDS_WIND_DENSITY
};
static gboolean soy_fields_wind_real_exert (soyfieldsField* base, soybodiesBody* other);
GeeHashMap* soy_bodies_body_get_tags (soybodiesBody* self);
soyatomsVector* soy_fields_wind_get_wind (soyfieldsWind* self);
gfloat soy_atoms_vector_get_x (soyatomsVector* self);
soyatomsVector* soy_bodies_body_get_velocity (soybodiesBody* self);
gfloat soy_atoms_vector_get_y (soyatomsVector* self);
gfloat soy_atoms_vector_get_z (soyatomsVector* self);
gfloat soy_fields_wind_get_density (soyfieldsWind* self);
void soy_bodies_body_addForce (soybodiesBody* self, dReal fx, dReal fy, dReal fz);
static void _soy_fields_wind_wind_weak (soyfieldsWind* self, GObject* wind);
soyfieldsWind* soy_fields_wind_new (void);
soyfieldsWind* soy_fields_wind_construct (GType object_type);
soyfieldsField* soy_fields_field_new (void);
soyfieldsField* soy_fields_field_construct (GType object_type);
soyatomsVector* soy_atoms_vector_new (gfloat x, gfloat y, gfloat z);
soyatomsVector* soy_atoms_vector_construct (GType object_type, gfloat x, gfloat y, gfloat z);
static void __soy_fields_wind_wind_weak_gweak_notify (gpointer self, GObject* object);
void soy_fields_wind_set_wind (soyfieldsWind* self, soyatomsVector* value);
void soy_fields_wind_set_density (soyfieldsWind* self, gfloat value);
static void soy_fields_wind_finalize (GObject* obj);
static void _vala_soy_fields_wind_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_soy_fields_wind_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


static gboolean soy_fields_wind_real_exert (soyfieldsField* base, soybodiesBody* other) {
	soyfieldsWind * self;
	gboolean result = FALSE;
	soybodiesBody* _tmp0_;
	GeeHashMap* _tmp1_;
	GeeHashMap* _tmp2_;
	GeeHashMap* _tmp3_;
	gboolean _tmp4_ = FALSE;
	gboolean _tmp5_;
	self = (soyfieldsWind*) base;
	g_return_val_if_fail (other != NULL, FALSE);
	_tmp0_ = other;
	_tmp1_ = soy_bodies_body_get_tags (_tmp0_);
	_tmp2_ = _tmp1_;
	_tmp3_ = _tmp2_;
	_tmp4_ = gee_abstract_map_has_key ((GeeAbstractMap*) _tmp3_, "cd");
	_tmp5_ = _tmp4_;
	_g_object_unref0 (_tmp3_);
	if (_tmp5_) {
		soyatomsVector* _tmp6_;
		soyatomsVector* _tmp7_;
		soyatomsVector* _tmp8_;
		gfloat _tmp9_;
		gfloat _tmp10_;
		soybodiesBody* _tmp11_;
		soyatomsVector* _tmp12_;
		soyatomsVector* _tmp13_;
		soyatomsVector* _tmp14_;
		gfloat _tmp15_;
		gfloat _tmp16_;
		gfloat _tmp17_;
		gfloat dx;
		soyatomsVector* _tmp18_;
		soyatomsVector* _tmp19_;
		soyatomsVector* _tmp20_;
		gfloat _tmp21_;
		gfloat _tmp22_;
		soybodiesBody* _tmp23_;
		soyatomsVector* _tmp24_;
		soyatomsVector* _tmp25_;
		soyatomsVector* _tmp26_;
		gfloat _tmp27_;
		gfloat _tmp28_;
		gfloat _tmp29_;
		gfloat dy;
		soyatomsVector* _tmp30_;
		soyatomsVector* _tmp31_;
		soyatomsVector* _tmp32_;
		gfloat _tmp33_;
		gfloat _tmp34_;
		soybodiesBody* _tmp35_;
		soyatomsVector* _tmp36_;
		soyatomsVector* _tmp37_;
		soyatomsVector* _tmp38_;
		gfloat _tmp39_;
		gfloat _tmp40_;
		gfloat _tmp41_;
		gfloat dz;
		gfloat _tmp42_;
		gfloat _tmp43_;
		gfloat _tmp44_;
		gfloat _tmp45_;
		gfloat _tmp46_;
		gfloat _tmp47_;
		gfloat d2;
		gfloat _tmp48_;
		_tmp6_ = soy_fields_wind_get_wind (self);
		_tmp7_ = _tmp6_;
		_tmp8_ = _tmp7_;
		_tmp9_ = soy_atoms_vector_get_x (_tmp8_);
		_tmp10_ = _tmp9_;
		_tmp11_ = other;
		_tmp12_ = soy_bodies_body_get_velocity (_tmp11_);
		_tmp13_ = _tmp12_;
		_tmp14_ = _tmp13_;
		_tmp15_ = soy_atoms_vector_get_x (_tmp14_);
		_tmp16_ = _tmp15_;
		_tmp17_ = _tmp10_ - _tmp16_;
		_g_object_unref0 (_tmp14_);
		_g_object_unref0 (_tmp8_);
		dx = _tmp17_;
		_tmp18_ = soy_fields_wind_get_wind (self);
		_tmp19_ = _tmp18_;
		_tmp20_ = _tmp19_;
		_tmp21_ = soy_atoms_vector_get_y (_tmp20_);
		_tmp22_ = _tmp21_;
		_tmp23_ = other;
		_tmp24_ = soy_bodies_body_get_velocity (_tmp23_);
		_tmp25_ = _tmp24_;
		_tmp26_ = _tmp25_;
		_tmp27_ = soy_atoms_vector_get_y (_tmp26_);
		_tmp28_ = _tmp27_;
		_tmp29_ = _tmp22_ - _tmp28_;
		_g_object_unref0 (_tmp26_);
		_g_object_unref0 (_tmp20_);
		dy = _tmp29_;
		_tmp30_ = soy_fields_wind_get_wind (self);
		_tmp31_ = _tmp30_;
		_tmp32_ = _tmp31_;
		_tmp33_ = soy_atoms_vector_get_z (_tmp32_);
		_tmp34_ = _tmp33_;
		_tmp35_ = other;
		_tmp36_ = soy_bodies_body_get_velocity (_tmp35_);
		_tmp37_ = _tmp36_;
		_tmp38_ = _tmp37_;
		_tmp39_ = soy_atoms_vector_get_z (_tmp38_);
		_tmp40_ = _tmp39_;
		_tmp41_ = _tmp34_ - _tmp40_;
		_g_object_unref0 (_tmp38_);
		_g_object_unref0 (_tmp32_);
		dz = _tmp41_;
		_tmp42_ = dx;
		_tmp43_ = dx;
		_tmp44_ = dy;
		_tmp45_ = dy;
		_tmp46_ = dz;
		_tmp47_ = dz;
		d2 = ((_tmp42_ * _tmp43_) + (_tmp44_ * _tmp45_)) + (_tmp46_ * _tmp47_);
		_tmp48_ = d2;
		if (_tmp48_ != ((gfloat) 0)) {
			gfloat _tmp49_;
			gfloat _tmp50_;
			gfloat _tmp51_;
			soybodiesBody* _tmp52_;
			GeeHashMap* _tmp53_;
			GeeHashMap* _tmp54_;
			GeeHashMap* _tmp55_;
			gpointer _tmp56_ = NULL;
			gfloat _tmp57_;
			gfloat f;
			gfloat _tmp58_;
			gfloat _tmp59_;
			gfloat _tmp60_ = 0.0F;
			gfloat r;
			gboolean _tmp61_ = FALSE;
			gboolean _tmp62_ = FALSE;
			soybodiesBody* _tmp63_;
			GeeHashMap* _tmp64_;
			GeeHashMap* _tmp65_;
			GeeHashMap* _tmp66_;
			gboolean _tmp67_ = FALSE;
			gboolean _tmp68_;
			gboolean _tmp74_;
			gboolean _tmp80_;
			_tmp49_ = soy_fields_wind_get_density (self);
			_tmp50_ = _tmp49_;
			_tmp51_ = d2;
			_tmp52_ = other;
			_tmp53_ = soy_bodies_body_get_tags (_tmp52_);
			_tmp54_ = _tmp53_;
			_tmp55_ = _tmp54_;
			_tmp56_ = gee_abstract_map_get ((GeeAbstractMap*) _tmp55_, "cd");
			_tmp57_ = ((0.5f * _tmp50_) * _tmp51_) * ((gfloat) (*((gfloat*) _tmp56_)));
			_g_object_unref0 (_tmp55_);
			f = _tmp57_;
			_tmp58_ = f;
			_tmp59_ = d2;
			_tmp60_ = sqrtf (_tmp59_);
			r = _tmp58_ / _tmp60_;
			_tmp63_ = other;
			_tmp64_ = soy_bodies_body_get_tags (_tmp63_);
			_tmp65_ = _tmp64_;
			_tmp66_ = _tmp65_;
			_tmp67_ = gee_abstract_map_has_key ((GeeAbstractMap*) _tmp66_, "cpx");
			_tmp68_ = _tmp67_;
			_g_object_unref0 (_tmp66_);
			if (_tmp68_) {
				soybodiesBody* _tmp69_;
				GeeHashMap* _tmp70_;
				GeeHashMap* _tmp71_;
				GeeHashMap* _tmp72_;
				gboolean _tmp73_ = FALSE;
				_tmp69_ = other;
				_tmp70_ = soy_bodies_body_get_tags (_tmp69_);
				_tmp71_ = _tmp70_;
				_tmp72_ = _tmp71_;
				_tmp73_ = gee_abstract_map_has_key ((GeeAbstractMap*) _tmp72_, "cpy");
				_tmp62_ = _tmp73_;
				_g_object_unref0 (_tmp72_);
			} else {
				_tmp62_ = FALSE;
			}
			_tmp74_ = _tmp62_;
			if (_tmp74_) {
				soybodiesBody* _tmp75_;
				GeeHashMap* _tmp76_;
				GeeHashMap* _tmp77_;
				GeeHashMap* _tmp78_;
				gboolean _tmp79_ = FALSE;
				_tmp75_ = other;
				_tmp76_ = soy_bodies_body_get_tags (_tmp75_);
				_tmp77_ = _tmp76_;
				_tmp78_ = _tmp77_;
				_tmp79_ = gee_abstract_map_has_key ((GeeAbstractMap*) _tmp78_, "cpz");
				_tmp61_ = _tmp79_;
				_g_object_unref0 (_tmp78_);
			} else {
				_tmp61_ = FALSE;
			}
			_tmp80_ = _tmp61_;
			if (_tmp80_) {
				soybodiesBody* _tmp81_;
				gfloat _tmp82_;
				gfloat _tmp83_;
				gfloat _tmp84_;
				gfloat _tmp85_;
				gfloat _tmp86_;
				gfloat _tmp87_;
				_tmp81_ = other;
				_tmp82_ = r;
				_tmp83_ = dx;
				_tmp84_ = r;
				_tmp85_ = dy;
				_tmp86_ = r;
				_tmp87_ = dz;
				soy_bodies_body_addForce (_tmp81_, (dReal) (_tmp82_ * _tmp83_), (dReal) (_tmp84_ * _tmp85_), (dReal) (_tmp86_ * _tmp87_));
			}
		}
	}
	result = TRUE;
	return result;
}


static void _soy_fields_wind_wind_weak (soyfieldsWind* self, GObject* wind) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (wind != NULL);
	self->priv->_wind_obj = NULL;
}


soyfieldsWind* soy_fields_wind_construct (GType object_type) {
	soyfieldsWind * self = NULL;
	self = (soyfieldsWind*) soy_fields_field_construct (object_type);
	return self;
}


soyfieldsWind* soy_fields_wind_new (void) {
	return soy_fields_wind_construct (SOY_FIELDS_TYPE_WIND);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void __soy_fields_wind_wind_weak_gweak_notify (gpointer self, GObject* object) {
	_soy_fields_wind_wind_weak (self, object);
}


soyatomsVector* soy_fields_wind_get_wind (soyfieldsWind* self) {
	soyatomsVector* result;
	soyatomsVector* _tmp0_;
	soyatomsVector* _tmp1_;
	soyatomsVector* value;
	soyatomsVector* _tmp2_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_wind_obj;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	value = _tmp1_;
	_tmp2_ = value;
	if (_tmp2_ == NULL) {
		soyatomsVector* _tmp3_;
		soyatomsVector* _tmp4_;
		soyatomsVector* _tmp5_;
		_tmp3_ = soy_atoms_vector_new (0.0f, 0.0f, 0.0f);
		_g_object_unref0 (value);
		value = _tmp3_;
		_tmp4_ = value;
		g_object_weak_ref ((GObject*) _tmp4_, __soy_fields_wind_wind_weak_gweak_notify, self);
		_tmp5_ = value;
		self->priv->_wind_obj = _tmp5_;
	}
	result = value;
	return result;
}


void soy_fields_wind_set_wind (soyfieldsWind* self, soyatomsVector* value) {
	soyatomsVector* _tmp0_;
	soyatomsVector* _tmp2_;
	soyatomsVector* _tmp3_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->_wind_obj;
	if (_tmp0_ != NULL) {
		soyatomsVector* _tmp1_;
		_tmp1_ = self->priv->_wind_obj;
		g_object_weak_unref ((GObject*) _tmp1_, __soy_fields_wind_wind_weak_gweak_notify, self);
	}
	_tmp2_ = value;
	self->priv->_wind_obj = _tmp2_;
	_tmp3_ = value;
	g_object_weak_ref ((GObject*) _tmp3_, __soy_fields_wind_wind_weak_gweak_notify, self);
	g_object_notify ((GObject *) self, "wind");
}


gfloat soy_fields_wind_get_density (soyfieldsWind* self) {
	gfloat result;
	gfloat _tmp0_;
	g_return_val_if_fail (self != NULL, 0.0F);
	_tmp0_ = self->priv->_density;
	result = _tmp0_;
	return result;
}


void soy_fields_wind_set_density (soyfieldsWind* self, gfloat value) {
	gfloat _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_density = _tmp0_;
	g_object_notify ((GObject *) self, "density");
}


static void soy_fields_wind_class_init (soyfieldsWindClass * klass) {
	soy_fields_wind_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (soyfieldsWindPrivate));
	SOY_FIELDS_FIELD_CLASS (klass)->exert = soy_fields_wind_real_exert;
	G_OBJECT_CLASS (klass)->get_property = _vala_soy_fields_wind_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_soy_fields_wind_set_property;
	G_OBJECT_CLASS (klass)->finalize = soy_fields_wind_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), SOY_FIELDS_WIND_WIND, g_param_spec_object ("wind", "wind", "wind", SOY_ATOMS_TYPE_VECTOR, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), SOY_FIELDS_WIND_DENSITY, g_param_spec_float ("density", "density", "density", -G_MAXFLOAT, G_MAXFLOAT, 0.0F, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void soy_fields_wind_instance_init (soyfieldsWind * self) {
	self->priv = SOY_FIELDS_WIND_GET_PRIVATE (self);
}


static void soy_fields_wind_finalize (GObject* obj) {
	soyfieldsWind * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SOY_FIELDS_TYPE_WIND, soyfieldsWind);
	G_OBJECT_CLASS (soy_fields_wind_parent_class)->finalize (obj);
}


GType soy_fields_wind_get_type (void) {
	static volatile gsize soy_fields_wind_type_id__volatile = 0;
	if (g_once_init_enter (&soy_fields_wind_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (soyfieldsWindClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) soy_fields_wind_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (soyfieldsWind), 0, (GInstanceInitFunc) soy_fields_wind_instance_init, NULL };
		GType soy_fields_wind_type_id;
		soy_fields_wind_type_id = g_type_register_static (SOY_FIELDS_TYPE_FIELD, "soyfieldsWind", &g_define_type_info, 0);
		g_once_init_leave (&soy_fields_wind_type_id__volatile, soy_fields_wind_type_id);
	}
	return soy_fields_wind_type_id__volatile;
}


static void _vala_soy_fields_wind_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	soyfieldsWind * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SOY_FIELDS_TYPE_WIND, soyfieldsWind);
	switch (property_id) {
		case SOY_FIELDS_WIND_WIND:
		g_value_take_object (value, soy_fields_wind_get_wind (self));
		break;
		case SOY_FIELDS_WIND_DENSITY:
		g_value_set_float (value, soy_fields_wind_get_density (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_soy_fields_wind_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	soyfieldsWind * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SOY_FIELDS_TYPE_WIND, soyfieldsWind);
	switch (property_id) {
		case SOY_FIELDS_WIND_WIND:
		soy_fields_wind_set_wind (self, g_value_get_object (value));
		break;
		case SOY_FIELDS_WIND_DENSITY:
		soy_fields_wind_set_density (self, g_value_get_float (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



