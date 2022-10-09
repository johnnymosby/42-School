#!/bin/bash
find . -name "*.sh" | sed -e "s/\.sh$//" | sed -e "s/\.\///"
