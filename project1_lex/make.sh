#!/bin/bash

(lex rust.l && gcc lex.yy.c)
