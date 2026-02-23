#!/bin/bash
# I am just lazy :P
git add .
read comm_msg
git commit -m "$comm_msg"
git push origin main
