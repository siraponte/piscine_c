#!/bin/sh

git status --ignored -s | grep  '!!' | tr -d '!! '
