/*
  PySoy - soy.atoms.Area Type
  Copyright (C) 2006,2007,2008,2009,2010,2011,2012 Copyleft Games Group

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU Affero General Public License as published
  by the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Affero General Public License for more details.

  You should have received a copy of the GNU Affero General Public License
  along with this program; if not, see http://www.gnu.org/licenses
*/

#include "pysoy2.h"

#define SELF PySoy_joints_Fixed_Object*

static char
tp_doc[] = "soy.joints.Fixed Type\n"
"\n"
"   :class:`~soy.joints.Fixed` joints maintain a relative position and\n"
"   orientation between two bodies or one body and the scene itself. It's\n"
"   usually a better idea to represent the two bodies as a single body\n"
"   except for debugging.\n"
"\n"
"   Examples:\n"
"       >>> s = soy.scenes.Scene()\n"
"       >>> b = soy.bodies.Body(s)\n"
"       >>> b2 = soy.bodies.Body(s)\n"
"       >>> j = soy.joints.Fixed(b, b2)\n"
"       >>> j\n"
"       <Fixed Joint>\n"
"       >>> j = soy.joints.Fixed(b, s)\n"
"       >>> j\n"
"       <Fixed Joint>";

static PyObject*
tp_new(PyTypeObject* type, PyObject* args, PyObject* kwds) {
    SELF self;

    soyscenesScene* scene;
    PySoy_scenes_Scene_Object* pyscene;
    PySoy_bodies_Body_Object* bodyOne;
    PySoy_bodies_Body_Object* bodyTwo;

    if (PyArg_ParseTuple(args, "O!O!",
                         &PySoy_bodies_Body_Type, &bodyOne,
                         &PySoy_bodies_Body_Type, &bodyTwo))
        scene = bodyTwo->g->scene;
    else {
        PyErr_Clear();
        if (PyArg_ParseTuple(args, "O!O!",
                             &PySoy_bodies_Body_Type, &bodyOne,
                             &PySoy_scenes_Scene_Type, &pyscene))
            scene = pyscene->g;
        else
            return NULL;
    }

    // Ensure bodies are in the same scene
    if (bodyOne->g->scene != scene) {
        PyErr_SetString(PyExc_ValueError, "Bodies must be in the same scene");
        return NULL;
    }

    self = (SELF) PyType_GenericNew(type, args, NULL);

    if(!self)
        return NULL;

    if(!bodyTwo)
        self->g = soy_joints_fixed_new(scene, bodyOne->g, NULL, NULL);
    else
        self->g = soy_joints_fixed_new(scene, bodyOne->g, bodyTwo->g, NULL);


    return (PyObject*) self;
}

static PyObject*
tp_repr(SELF self) {
    PyObject* ret;

    ret = PyUnicode_FromFormat("<Fixed Joint>");

    return ret;
}

///////////////////////////////////////////////////////////////////////////////
// Type structs

static PyGetSetDef tp_getset[] = {
    {NULL},                         // sentinel
};

PyTypeObject PySoy_joints_Fixed_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "soy.joints.Fixed",                                     // tp_name
    sizeof(PySoy_joints_Fixed_Object),                      // tp_basicsize
    0,                                                     // tp_itemsize
    0,                                                     // tp_dealloc
    0,                                                     // tp_print
    (getattrfunc) 0,                                       // tp_getattr
    (setattrfunc) 0,                                       // tp_setattr
    0,                                                     // tp_compare
    (reprfunc) tp_repr,                                    // tp_repr
    0,                                                     // tp_as_number
    0,                                                     // tp_as_sequence
    0,                                                     // tp_as_mapping
    0,                                                     // tp_hash
    0,                                                     // tp_call
    (reprfunc) tp_repr,                                    // tp_str
    (getattrofunc) 0,                                      // tp_getattro
    (setattrofunc) 0,                                      // tp_setattro
    0,                                                     // tp_as_buffer
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,              // tp_flags
    tp_doc,                                                // tp_doc
    0,                                                     // tp_traverse
    0,                                                     // tp_clear
    0,                                                     // tp_richcompare
    0,                                                     // tp_weaklistoffset
    0,                                                     // tp_iter
    0,                                                     // tp_iternext
    0,                                                     // tp_methods
    0,                                                     // tp_members
    tp_getset,                                             // tp_getset
    &PySoy_joints_Joint_Type,                              // tp_base
    0,                                                     // tp_dict
    0,                                                     // tp_descr_get
    0,                                                     // tp_descr_set
    0,                                                     // tp_dictoffset
    0,                                                     // tp_init
    0,                                                     // tp_alloc
    tp_new,                                                // tp_new
    0,                                                     // tp_free
    0,                                                     // tp_is_gc
};

