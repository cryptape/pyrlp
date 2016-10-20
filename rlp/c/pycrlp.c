#include <Python.h>
#include "binascii.h"
#include <string.h>

#define MAX_SIZE 68 + 1

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

static PyObject *py_packl(PyObject *self, PyObject *args)
{
    char *lnum;
    int res = PyArg_ParseTuple(args, "s", &lnum);
    if (!res) {
        return NULL;
    }
    uint8_t retValue[MAX_SIZE] = {};
    int len = strlen(lnum) - 3;
    if (len & 1) {
        lnum[1] = '0';
        res = binascii_unhexlify(lnum + 1, len + 2, retValue);
    }
    else {
        res = binascii_unhexlify(lnum + 2, len + 1, retValue);
    }
    if (!res) {
        return NULL;
    }
    return (PyObject *)Py_BuildValue("s", retValue);
}

static PyMethodDef PyextMethods[] = {
    {"unhexlify", py_unhexlify, METH_VARARGS},
    {"packl", py_packl, METH_VARARGS},
    {NULL, NULL,}, 
};

PyMODINIT_FUNC initpycrlp(void)
{
    Py_InitModule("pycrlp", PyextMethods);
}
