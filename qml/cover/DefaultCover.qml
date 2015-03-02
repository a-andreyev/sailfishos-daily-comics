/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

CoverBackground {

    Column {
        spacing: Theme.paddingLarge

        anchors.centerIn: parent

        Label {
            text: "Daily Comics"
            color: Theme.highlightColor
        }

        Image {
            fillMode: Image.PreserveAspectFit
            source: "../../images/cover.png"
            opacity: 0.6
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

}


