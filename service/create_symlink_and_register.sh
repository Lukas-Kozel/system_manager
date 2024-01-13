#!/bin/bash

SERVICE_FILE_PATH="/home/luky/Desktop/Projects/system_manager/system_manager/service/temperature_monitor.service"

SERVICE_NAME="temperature_manager.service"

SYMLINK_DEST="/etc/systemd/system/$SERVICE_NAME"

if [ ! -f "$SERVICE_FILE_PATH" ]; then
    echo "Service file not found: $SERVICE_FILE_PATH"
    exit 1
fi

sudo ln -sf "$SERVICE_FILE_PATH" "$SYMLINK_DEST"

sudo systemctl daemon-reload

sudo systemctl enable "$SERVICE_NAME"

sudo systemctl start "$SERVICE_NAME"