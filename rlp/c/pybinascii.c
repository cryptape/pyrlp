#include <Python.h>
#include "binascii.h"
#include <string.h>

#define MAX_SIZE 32 + 1

static PyObject *py_unhexlify(PyObject *self, PyObject *args)
{
    int res;
    uint8_t retValue[MAX_SIZE] = {};
    uint8_t *str;
    res = PyArg_ParseTuple(args, "s", &str);
    int i = 0;
    if (!res) {
        return NULL;
    }
    res = binascii_unhexlify(str, strlen(str) + 1, retValue);
    if (!res) {
        return NULL;
    }
    return (PyObject *)Py_BuildValue("s", retValue);
}

static PyMethodDef PyextMethods[] = {
    {"unhexlify", py_unhexlify, METH_VARARGS},
    {NULL, NULL,}, 

};

PyMODINIT_FUNC initpybinascii(void)
{
    Py_InitModule("pybinascii", PyextMethods);
}
