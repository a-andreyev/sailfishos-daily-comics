/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

Loader {
    id: loader

    property bool animated: false
    property string source
    property int status

    sourceComponent: animated ? animatedImage : fixedImage

    Component {
        id: animatedImage
        AnimatedImage {
            source: loader.source
            fillMode: Image.PreserveAspectFit
            smooth: true
            clip: true
            asynchronous: true

            Rectangle {
                anchors.fill: parent
                color: "white"
                visible: status == Image.Ready
                z: -10
            }

            onStatusChanged: loader.status = status
        }
    }

    Component {
        id: fixedImage
        Image {
            source: loader.source
            fillMode: Image.PreserveAspectFit
            smooth: true
            clip: true
            asynchronous: true

            sourceSize.width: width
            sourceSize.height: height

            Rectangle {
                anchors.fill: parent
                color: "white"
                visible: status == Image.Ready
                z: -10
            }

            onStatusChanged: loader.status = status
        }
    }
}
